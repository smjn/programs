#! /bin/bash
a=( `pgrep -f dropdown` )
err=$?
terminator -H -b --layout=dropdown --profile=solar 
if [[ ${err} -eq 0 ]]; then
	zenity --title Killer --text "Kill existing drop downs?" --question >& /dev/null
	[[ $? -eq 0 ]] && kill -9 $a
fi
