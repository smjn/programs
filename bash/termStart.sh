#! /bin/bash
a=( `pgrep -f dropdown` )
if [[ $? -eq 0 ]]; then
	zenity --title Killer --text "Kill existing drop downs?" --question >& /dev/null
	if [[ $? -eq 0 ]]; then
		terminator -bH --layout=dropdown --profile=solar & 
		! [[ -z $a ]] && kill -9 $a
	else 
		terminator -bH --layout=dropdown --profile=solar &
	fi
else
	terminator -bH --layout=dropdown --profile=solar &
fi
