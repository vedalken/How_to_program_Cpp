#!/bin/bash

START_NUM=$1
END_NUM=$2
N=$3

[ -z $START_NUM ] && START_NUM=1
[ -z $END_NUM ] && END_NUM=10
[ -z $N ] && N=10

shuf -i $START_NUM-$END_NUM -n $N > data.txt
