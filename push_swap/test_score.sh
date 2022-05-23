# /bin/bash

LINE_CLEAR=$'\33[2K\r'
UNDERBAR=$'\033[4m'
CLEAR=$'\033[0m'

if [ "$1" == "" -o "$2" == "" ]; then
	echo "Evaluation criteria:"
	echo "  value_size = 3,   limit_size = 3"
	echo "  value_size = 5,   limit_size = 12"
	echo "  value_size = 100, limit_size = [700, 900, 1100, 1300, 1500]"
	echo "  value_size = 500, limit_size = [5500, 7000, 8500, 10000, 11500]"
	echo "Usage: ./test_score.sh "$UNDERBAR"value_size"$CLEAR" "$UNDERBAR"limit_size"$CLEAR" ["$UNDERBAR"test_scale"$CLEAR]
	exit 1
fi

CUTLINE=$2
if [ "$3" == "" ]; then
	LOOP=1000
else
	LOOP=$3
fi

make re

if [ ! -f "checker" ] || [ ! -f "push_swap" ]; then
	echo
	echo "\033[1;31merror:\033[0m Failed to build"
	exit 1
fi

/bin/echo -n "Loading ..."
./test_script.sh random 3 > /dev/null

SET=$(seq 0 $(expr $LOOP - 1))
FAILED=0
SUM=0
for i in $SET
do
	/bin/echo -n "$LINE_CLEAR"Calculating $(expr $i \* 100 / $LOOP)% ... "(Success: $(expr $i - $FAILED), Failed: $FAILED)"
	RESULT=$(./test_script.sh random $1 | tail -n 3)
	if [ -z "$(echo $RESULT | grep "OK")" ]; then
		echo
		echo "\033[1;31merror:\033[0m Failed to sorting values"
		exit 1
	fi
	SCORE=$(echo $RESULT | awk '{print $1}')
	SUM=$(expr $SUM + $SCORE)
	if [[ $SCORE -ge $CUTLINE ]]; then
		FAILED=$(expr $FAILED + 1)
	fi
done
echo $LINE_CLEAR

if [[ $FAILED -eq 0 ]]; then
	echo "   ______                __  ______"
	echo "  / ____/_______  ____ _/ /_/ / / /"
	echo " / / __/ ___/ _ \/ __ \`/ __/ / / / "
	echo "/ /_/ / /  /  __/ /_/ / /_/_/_/_/  "
	echo "\____/_/   \___/\__,_/\__(_|_|_)   "
	echo
	echo "<$1 random values> $LOOP times all under $CUTLINE (Average: $(echo $SUM $LOOP | awk '{printf "%.2f", $1 / $2}'))"
else
	echo "    ______      _ __         __   "
	echo "   / ____/___ _(_) /__  ____/ /   "
	echo "  / /_  / __ \`/ / / _ \/ __  /    "
	echo " / __/ / /_/ / / /  __/ /_/ / _ _ "
	echo "/_/    \__,_/_/_/\___/\__,_(_|_|_)"
	echo
	echo "<$1 random values> $LOOP times"
	echo "$(expr $FAILED \* 100 / $LOOP)% is over $CUTLINE (Average: $(echo $SUM $LOOP | awk '{printf "%.2f", $1 / $2}'))"
fi

rm -rf **/*\ *
