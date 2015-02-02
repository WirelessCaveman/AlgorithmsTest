#!/bin/sh

rm file*
a=0

while [ $a -lt 1000 ]
do
    touch file$a
	echo "cock-a-doodle-doo" >> file$a
	n=`expr $a % 5`
    if [ "$n" == 0 ]
	then
        echo "192.168.$a.10" >> file$a
	else
		echo "gobble-de-gook" >> file$a
    fi
	n=`expr $a % 6`
    if [ "$n" == 0 ]
	then
        echo "bow-wow $a.26.10.10 ka-ka" >> file$a
    fi
	n=`expr $a % 7`
    if [ "$n" == 0 ]
	then
        echo "bow-wow 192.$a.10.10 ka-ka" >> file$a
    fi
	n=`expr $a % 8`
    if [ "$n" == 0 ]
	then
        echo "bow-wow 10.26.10.$a ka-ka" >> file$a
    fi
	echo $n >> file$a
    a=`expr $a + 1`
done


