#!/bin/bash

number=$1

[ -z "$number" ] && number=10

shuf -i 1-$number | tr -d '\n'

echo
