declare -a arr
i=1
l=0
while read line
do
	((l++))
    for word in $line
    do
        arr[$i]=$word
		((i++))
    done
done < file.txt

col=$( cat file.txt|head -1|wc -w )

for (( k=1; k<=$col; k++ ))
do
	index=1
	for (( s=$k; s<=$i; s+=$col ))
	do
		echo -n ${arr[$s]}
		[[ $index -ne $l ]] && echo -n " "
		((index++))
	done
	echo
done



