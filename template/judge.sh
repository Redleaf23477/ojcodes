#!/bin/bash

# variables

probNo=$1
probFolder=./prog8$1
cppFile=$2
testDir="NA"
ansDir="NA"
res="AC!!!"

# check if dir exist

if [ ! -d $probFolder ]
then
    echo "folder $probFolder not exist"
    exit 7122
fi

# compile

echo "compiling $cppFile"
rm ./a.out
g++ -std=c++11 -O3 $cppFile

# loop through test files

for f in $probFolder/*/*.in
do
    tmp=${f%.in}
    tmp=${tmp#*/*/*/}
    ./a.out <$f >$tmp.my
done

# loop through ans files

for f in $probFolder/*/*.out
do
    tmp=${f%.out}          # remove suffix with "a.out"
    tmp=${tmp#*/*/*/}      # remove prefix with "*/*/*/"
    df=$(diff $f $tmp.my)
    if [ ${#df} -eq 0 ]    # get string length
    then
        echo "$tmp AC"
    else
        echo "$tmp WA"
        res="WA"
    fi
    rm $tmp.my
done

# print result

echo $res
