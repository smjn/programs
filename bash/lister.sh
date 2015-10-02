#! /bin/bash
OIFS=$IFS
IFS=''
data='abc.docxls def fgi.xls      xyax     skadjas    sals.ppt'
IFS=','
for i in $(echo $data|sed 's/[.]\([^ ]\+\)\+[ ]\+/.\1,/g')
do 
	#$i has good value
	echo $i
done
IFS=$OIFS
