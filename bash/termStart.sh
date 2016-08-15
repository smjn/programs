#! /bin/bash
zenity --title Killer --text "Kill existing drop downs?" --question >& /dev/null
if [[ $? -eq 0 ]]; then
	a=$(pgrep -f dropdown);
	terminator -b --layout=dropdown --profile=solar &
	kill -9 $a
else 
	terminator -b --layout=dropdown --profile=solar &
fi
