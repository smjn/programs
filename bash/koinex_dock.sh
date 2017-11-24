#!/usr/bin/env bash
declare -a coins
coins=(BTC ETH BCH XRP LTC)
declare -a curInfo
declare -a oldInfo
price=$(curl -s -o - https://koinex.in/api/ticker)
[[ $? -ne 0 ]] && { echo "koinex refusing, lets wait"; sleep 20; }
len=${#coins[@]}
bashcol=$1
[[ -e ".prices2" ]] && isFile=true || isFile=false

if [[ $isFile = true ]]; then
	i=0
	while read line; do
		oldInfo[$i]=$line
		((i++))
	done <".prices2"
fi

rm -f ".prices2"

for (( i=0; $i<$len; i++ )); do
	curInfo[0]=$(echo $price|jq .prices.${coins[$i]}|tr -d '"\n\r')
	[[ -n $bashcol ]] && reset="\e[39m" || reset=''
	escape=''
	if [[ $isFile = true ]]; then
		a=${curInfo[0]}
		b=${oldInfo[$i]}
		arrow=''

		if [[ $(echo "$a == $b"|bc) -eq 1 ]]; then
			[[ -n $bashcol ]] && escape="\e[33m" || escape=''
			arrow='•'
		elif [[ $(echo "$a < $b"|bc) -eq 1 ]]; then
			[[ -n $bashcol ]] && escape="\e[31m" || escape=''
			arrow='↓'
		else
			[[ -n $bashcol ]] && escape="\e[32m" || escape=''
			arrow='↑'
		fi
	fi

	if [[ $i -lt $len ]]; then
		echo "${curInfo[@]}"|tr ' ' '\n' >> ".prices2"
	fi
	printf "${coins[$i]}:$escape$arrow%-10s$reset" "${curInfo[0]}"
done
