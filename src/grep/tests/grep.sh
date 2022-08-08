#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
FILENAME1="main.c"
FILENAME2="s21_grep.c"
FILENAME3="s21_grep.h"

cat /dev/null > log.txt

for var in -v -c -l -n -i
do
    TEST1="$var struct $FILENAME1 $FILENAME2 $FILENAME3"
    echo "$TEST1"
    ./s21_grep $TEST1 > s21_grep.txt
    grep $TEST1 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST1" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
    rm s21_grep.txt grep.txt

    TEST2="$var   $FILENAME1 $FILENAME2 $FILENAME3"
    echo "$TEST2"
    ./s21_grep $TEST2 > s21_grep.txt
    grep $TEST2 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST2" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
    rm s21_grep.txt grep.txt

    TEST3="$var -e struct $FILENAME1 $FILENAME2 $FILENAME3"
    echo "$TEST3"
    ./s21_grep $TEST3 > s21_grep.txt
    grep $TEST3 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST3" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
    rm s21_grep.txt grep.txt

    TEST4="$var -e ^int $FILENAME1 $FILENAME2 $FILENAME3"
    echo "$TEST4"
    ./s21_grep $TEST4 > s21_grep.txt
    grep $TEST4 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST4" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
    rm s21_grep.txt grep.txt

    TEST5="$var rakamakafo $FILENAME1 $FILENAME2 $FILENAME3"
    echo "$TEST5"
    ./s21_grep $TEST5 > s21_grep.txt
    grep $TEST5 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST5" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
    rm s21_grep.txt grep.txt

    TEST6="$var $FILENAME1 $FILENAME2 $FILENAME3"
    echo "$TEST6"
    ./s21_grep $TEST6 > s21_grep.txt
    grep $TEST6 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST6" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
    rm s21_grep.txt grep.txt
done

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
