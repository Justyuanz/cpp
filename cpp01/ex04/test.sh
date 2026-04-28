#! /bin/bash

./replace tests/test1.txt hello HELLO
./replace tests/test2.txt cat dog
./replace tests/test3.txt notfound anything
./replace tests/test4.txt a b
./replace tests/test5 cat dog
./replace tests/test6.txt cat REPLACED

cat tests/test1.txt.replace
cat tests/test2.txt.replace
cat tests/test3.txt.replace
cat tests/test4.txt.replace
cat tests/test5.replace
cat tests/test6.txt.replace

 
