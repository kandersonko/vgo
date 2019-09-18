#!/bin/bash

#some varibles for the future
output=${1}
progname=${2}
input=${3}
trash="/dev/null"

# execute the prog and putting output to out file
valgrind ./${progname} < ${input} >${output} 2>&1
# cheking for patters that indicate err
grep -q "ERROR SUMMARY: 0 errors" "$output"

# grab exit status of grep (0 if all good ,1 if not)
ret=$?

# write appropriate message as per return status value
((ret == 0)) && echo "Memory V" || echo "Memory X"

# return the exit status of testMem
exit $ret
