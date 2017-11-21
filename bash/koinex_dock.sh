#!/usr/bin/env bash
declare -a coins
coins=(BTC ETH BCH XRP LTC)
declare -a curInfo
while [[ true ]]; do 
	price=$(curl -s -o - https://koinex.in/api/ticker)
	len=${#coins[@]}
	
	for (( i=0; $i<$len; i++ )); do
		curInfo[0]=$(echo $price|jq .prices.${coins[$i]}|tr -d '"\n\r')

		reset="\e[39m"
		escape=''
		printf "${coins[$i]}:$escape%-10s$arrow$reset" "${curInfo[0]}"
	done

	sleep 16
	clear
done
