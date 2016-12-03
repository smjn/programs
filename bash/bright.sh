#!/bin/bash
#increase or decrease brightness in linux systems in platform independant way.
#assusmes you've added:
#ALL	ALL = (ALL)	NOPASSWD: /usr/bin/tee /sys/class/backlight/intel_backlight/brightness
#in /etc/sudoers

old=$(cat /sys/class/backlight/intel_backlight/brightness)
mx=$(cat /sys/class/backlight/intel_backlight/max_brightness)
tobe=0
if [[ $# -eq 0 ]]; then
	tobe=$(($old+400))
else
	tobe=$(($old-400))
fi

new=$(($tobe>$mx?$mx:($tobe<0?400:$tobe)))
echo $new|sudo /usr/bin/tee /sys/class/backlight/intel_backlight/brightness


