#!/bin/bash

function assignRole() {
	cf set-space-role $1 sap $1 $2
	while [[ $? -ne 0 ]]
	do
		sleep 1
		echo "re trying"
		cf set-space-role $1 sap $1 $2
	done	
}

[[ $# -ne 1 ]] && { echo "only username as argument! Usage: $0 <username>"; exit 1; };

cf create-user $1 $1
cf create-space -o sap $1
assignRole $1 "SpaceManager"
assignRole $1 "SpaceAuditor"
assignRole $1 "SpaceDeveloper"
