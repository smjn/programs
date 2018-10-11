#!/bin/bash
#increase or decrease brightness in linux systems in platform independant way.
#assusmes you've added:
#ALL	ALL = (ALL)	NOPASSWD: /usr/bin/tee /sys/class/backlight/intel_backlight/brightness
#in /etc/sudoers

#no args - increse brightness by 400
#arg 0 - default brightness of 800
#arg !0 - decrese brightness by 400

pref="/sys/class/backlight/intel_backlight"
old=$(cat $pref/brightness)
mx=$(cat $pref/max_brightness)
(( new=$old+400 ))
if [[ $# -eq 1 ]]; then
    new=$(( $1==0?800:$old - 400 ))
fi
echo $1 $new
new=$(( $new>$mx?$mx:($new<0?400:$new) ))
echo $new|sudo /usr/bin/tee /sys/class/backlight/intel_backlight/brightness


