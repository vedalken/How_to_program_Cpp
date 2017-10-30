#!/bin/bash

make

exec 2>/dev/null

echo "(800) 555-1212" | ./main && echo " OK" || exit 1
echo "(100) 555-1212" | ./main && exit 1  || echo OK
echo "(800) 155-1212" | ./main && exit 1  || echo OK
echo "(800) 055-1212" | ./main && exit 1  || echo OK
echo "(000) 555-1212" | ./main && exit 1  || echo OK
