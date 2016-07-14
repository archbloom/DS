#!/bin/bash
# $ bash sleepsort.sh 1 9 8 2 3 7 5 4 6
function fun()
{
	sleep "$1"
	echo "$1"
}
while [ -n "$1" ]
do
	fun "$1" &
	shift
done
wait
