#!/bin/bash

TIMEFORMAT=%R

CONTAINER_DIRECTORY="./containers"
COMPILE_DIRECTORY="./temp"
LOG_DIRECTORY="./logs"
DIFF_DIRECTORY="./diff"
TEST_DIRECTORY="./test"

CC='clang++'
CFLAGS='-Wall -Wextra -Werror -std=c++98 -pedantic -O3 -I./containers -I./iterators -I./nodes -I./utilities'

# Echo Colors
NOCOLOR=$'\033[0m'
RED=$'\033[31m'
GREEN=$'\033[32m'

# Echo Characters
LINE_CLEAR=$'\33[2K'$'\r'

CONTAINER_LIST=("vector" "map" "stack" "set")
CONTAINER_IMPLEMENTED=()

if [ $# -eq 0 ]; then
	for container in ${CONTAINER_LIST[@]}; do
		if [ -f  "${CONTAINER_DIRECTORY}/${container}.hpp" ]; then
			CONTAINER_IMPLEMENTED+=(${container})
		fi
	done
else
	for target in "$@"; do
		for container in "${CONTAINER_LIST[@]}"; do
			if [ "${target}" == "${container}" -a -f "${CONTAINER_DIRECTORY}/${container}.hpp" ]; then
				CONTAINER_IMPLEMENTED+=(${container})
				break
			fi
		done
	done
fi

echo "Containers to check (${#CONTAINER_IMPLEMENTED[@]}/${#CONTAINER_LIST[@]}):"
for name in "${CONTAINER_IMPLEMENTED[@]}"; do
	echo -n " ${GREEN}v${NOCOLOR} ${name}"
done
echo
echo

rm -f my
rm -f std
rm -rf ${LOG_DIRECTORY}
rm -rf ${DIFF_DIRECTORY}
mkdir -p ${LOG_DIRECTORY}
mkdir -p ${DIFF_DIRECTORY}
mkdir -p ${COMPILE_DIRECTORY}

for container in "${CONTAINER_IMPLEMENTED[@]}"; do
	${CC} ${CFLAGS} -c "${TEST_DIRECTORY}/${container}_test.cpp" -o "${COMPILE_DIRECTORY}/ft_${container}_test.o" >> "${LOG_DIRECTORY}/ft_${container}.compile.log" 2>&1
	${CC} ${CFLAGS} -c "${TEST_DIRECTORY}/${container}_test.cpp" -o "${COMPILE_DIRECTORY}/std_${container}_test.o" -D STL >>"${LOG_DIRECTORY}/std_${container}.compile.log" 2>&1
	${CC} ${CFLAGS} "${COMPILE_DIRECTORY}/ft_${container}_test.o" -o my >> "${LOG_DIRECTORY}/ft_${container}.compile.log" 2>&1
	${CC} ${CFLAGS} "${COMPILE_DIRECTORY}/std_${container}_test.o" -o std -D STL >> "${LOG_DIRECTORY}/std_${container}.compile.log" 2>&1
	./my >> "${LOG_DIRECTORY}/ft_${container}.execute.log" 2>&1
	./std >> "${LOG_DIRECTORY}/std_${container}.execute.log" 2>&1
	diff "${LOG_DIRECTORY}/ft_${container}.execute.log" "${LOG_DIRECTORY}/std_${container}.execute.log" > "${DIFF_DIRECTORY}/${container}.diff"
	if [ -s "${DIFF_DIRECTORY}/${container}.diff" ]; then
		echo ${container}: KO!
	else
		echo ${container}: OK!
		if [ -f "${TEST_DIRECTORY}/${container}_benchmark.cpp" ]; then
			SEED=$RANDOM
			${CC} ${CFLAGS} -c "${TEST_DIRECTORY}/${container}_benchmark.cpp" -o "${COMPILE_DIRECTORY}/ft_${container}_benchmark.o" -D SEED=${SEED} >> "${LOG_DIRECTORY}/ft_${container}_benchmark.compile.log" 2>&1
			${CC} ${CFLAGS} -c "${TEST_DIRECTORY}/${container}_benchmark.cpp" -o "${COMPILE_DIRECTORY}/std_${container}_benchmark.o" -D STL -D SEED=${SEED} >> "${LOG_DIRECTORY}/std_${container}_benchmark.compile.log" 2>&1
			${CC} ${CFLAGS} "${COMPILE_DIRECTORY}/ft_${container}_benchmark.o" -o my -D SEED=${SEED} >> "${LOG_DIRECTORY}/ft_${container}_benchmark.compile.log" 2>&1
			${CC} ${CFLAGS} "${COMPILE_DIRECTORY}/std_${container}_benchmark.o" -o std -D STL -D SEED=${SEED} >> "${LOG_DIRECTORY}/std_${container}_benchmark.compile.log" 2>&1
			echo -n ${LINE_CLEAR}Testing optimization of STL ${container} container ...
			STLTIME=$( { time ./std ; } 2>&1 )
			echo ${STLTIME} >> "${LOG_DIRECTORY}/std_${container}_benchmark.execute.log"
			echo -n ${LINE_CLEAR}Testing optimization of user\'s ${container} container ...
			MYTIME=$( { time ./my ; } 2>&1 )
			echo ${MYTIME} >> "${LOG_DIRECTORY}/ft_${container}_benchmark.execute.log"
			printf "${LINE_CLEAR}ft::${container} is %.1f times slower than std::${container} (user %.1fs, std %.1fs)\n" $(echo "scale=1; ${MYTIME} / ${STLTIME}" | bc -l) ${MYTIME} ${STLTIME}
			rm my
			rm std
		fi
	fi
done
