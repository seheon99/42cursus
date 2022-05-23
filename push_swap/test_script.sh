# /bin/bash

if [ ! -f "checker" ] || [ ! -f "push_swap" ]; then
	make
	if [ $? -ne 0 ]; then
		echo
		echo "\033[0;31mFailed\033[0m to build sources"
		exit $?
	fi
fi

if [ "$1" == "random" ]; then
	ARG=$(ruby -e "puts (1..$2).to_a.shuffle.join(' ')")
	echo "Random set: $ARG"
else
	for num in $@
	do
		ARG="$ARG $num"
	done
fi

echo $ARG | pbcopy

INSTRUCTIONS=$(./push_swap $ARG)
echo $INSTRUCTIONS | tr " " "\n" | wc | awk '{printf "%d instructions\n", $1}'

CHECKER=$(echo $INSTRUCTIONS | tr " " "\n" | ./checker $ARG)
echo "checker: $CHECKER"
if [[ -z $INSTRUCTIONS ]]; then
	CHECKER_MAC=$(./checker_Mac $ARG < /dev/null)
else
	CHECKER_MAC=$(echo $INSTRUCTIONS | tr " " "\n" | ./checker_Mac $ARG)
fi
echo "checker_Mac: $CHECKER_MAC"

if [[ $CHECKER -ne "OK" ]] || [[ $CHECKER_MAC -ne "OK" ]]; then
	exit 1
fi
