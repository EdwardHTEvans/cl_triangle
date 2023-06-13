#!/bin/bash

# args 
#   1: test command
#   2: expected output 
run_test () {
    area=$($1)
    if [ "${area}" != "${2}" ]; then
        echo "fail    ${1} => ${area} == ${2}"
        fail=true
    else
        echo "pass    ${1} => ${area} == ${2}"
    fi
}

cd "$(dirname "$0")"
bin_path="build/"
binary_name="cl_triangle"
fail=false

if [ -f "${bin_path}${binary_name}" ]; then
    echo "binary available"
else
    echo "binary missing form ${bin_path}"
    exit
fi

# testing integers with various units
run_test "${bin_path}${binary_name} 3 4 5" "6.000"
run_test "${bin_path}${binary_name} -u m 3 4 5" "6.000 m^2"
run_test "${bin_path}${binary_name} 3 4 5 -u m" "6.000 m^2"
run_test "${bin_path}${binary_name} -u cm 3 4 5" "6.000 cm^2"

# testing decimals with various units
run_test "${bin_path}${binary_name} 3.0 4.0 5.0" "6.000"
run_test "${bin_path}${binary_name} -u m 3.0 4.0 5.0" "6.000 m^2"
run_test "${bin_path}${binary_name} 3.0 4.0 5.0 -u m" "6.000 m^2"
run_test "${bin_path}${binary_name} -u cm 3.0 4.0 5.0" "6.000 cm^2"

# testing high precision
run_test "${bin_path}${binary_name} 6.21 6.22 7.1" "18.120"
# run_test "${bin_path}${binary_name} 15.342454987327143 7.23227943262 9.3291754131" ""
# run_test "${bin_path}${binary_name} " ""

# run_test "${bin_path}${binary_name} " ""

echo
if $fail ; then
    echo "Testing failed"
else
    echo "Testing passed"
fi
