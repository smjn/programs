#!/usr/bin/env bash
declare -a coins
coins=(BTC ETH BCH XRP LTC REQ OMG BAT ZRX)
declare -a curInfo
declare -a oldInfo
while [[ true ]]; do 
	price=$(curl -s -o - https://koinex.in/api/ticker)
	len=${#coins[@]}
	printf "\e[34mCurrent\t\tDelta\t\tMin\t\tMax\e[39m\n"
	[[ -e ".prices" ]] && isFile=true || isFile=false

	if [[ $isFile  = true ]]; then
		i=0
		while read line; do
			oldInfo[$i]=$line
			((i++))
		done <".prices"
	fi

	rm -f ".prices"

	for (( i=0; $i<$len; i++ )); do
		echo $price|jq .prices >/dev/null 2>&1
		[[ $? -ne 0 ]] && { echo "koinex refusing, lets wait"; sleep 20; break; }

		curInfo[0]=$(echo $price|jq .prices.${coins[$i]}|tr -d '"\n\r' 2>/dev/null)
		curInfo[1]=$(echo $price|jq .stats.${coins[$i]}.last_traded_price|tr -d '"\n\r' 2>/dev/null)
		curInfo[2]=$(echo $price|jq .stats.${coins[$i]}.min_24hrs|tr -d '"\n\r' 2>/dev/null)
		curInfo[3]=$(echo $price|jq .stats.${coins[$i]}.max_24hrs|tr -d '"' 2>/dev/null)

		((index=i*4))
		reset="\e[39m"
		escape=''
		delta=0.0
		if [[ $isFile = true ]]; then
			a=${curInfo[0]}
			b=${oldInfo[$index]}
			arrow=''
			delta=$(echo $a - $b|bc 2>/dev/null)
			if [[ $(echo "$a == $b"|bc 2>/dev/null) -eq 1 ]]; then
				escape="\e[33m"
				arrow='•'
			elif [[ $(echo "$a < $b"|bc 2>/dev/null) -eq 1 ]]; then
				escape="\e[31m"
				arrow='↓'
			else
				escape="\e[32m"
				arrow='↑'
			fi
		fi

		if [[ $i -lt $len ]]; then
			echo "${curInfo[@]}"|tr ' ' '\n' >> ".prices"
		fi
		printf "${coins[$i]}:$escape%-10s$arrow\t%-10s$reset\t%-10s\t%-10s\n" "${curInfo[0]}" "$delta" "${curInfo[2]}" "${curInfo[3]}"
	done

	sleep 16
	clear
done
