#!/bin/bash
function showQues {
	#in gui
	if [[ "$TERM" = "linux" ]]; then
		dialog --yesno "$1" 10 50
	else
		zenity --question --text "$1" --display=:0.0 >/dev/null 2>&1
	fi
	ret=$?
}

function showInfo {
	#in gui
	if [[ "$TERM" = "linux" ]]; then
		dialog --infobox "$1" 10 50
	else
		zenity --info --text "$1" --display=:0.0 >/dev/null 2>&1
	fi
	ret=$?
}

per=0
ret=0
acpi|grep 'Discharging' > /dev/null
if [[ $? -eq 0 ]]; then
	per=`acpi|grep -iPo '[0-9]+(?=%)'`
	if [[ $per -lt 10 ]]; then
		echo "low"
		showQues "Battery Low - $per, do something!!"
		[[ $ret -eq 0 ]] && { showInfo "suspending!"; sudo systemctl suspend; };
	fi
fi


