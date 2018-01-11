#!/bin/bash
value=$(<storage.txt)
((value+=8))
if [ $value -lt 100 ]
then
echo "$value" > storage.txt
echo "from producer: Current total is $value"
./consumer
else
echo "from producer: Now I will take a rest!"


fi

