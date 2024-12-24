#!/bin/bash
date
current_time=`date +%s`
echo $current_time
let current_time_2=current_time+current_time
echo $current_time_2
for i in {1..20}; do
	echo "$i"
done
