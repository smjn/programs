#!/bin/bash
#increase or decrease brightness in linux systems in platform independant way.
#assusmes you've added:
#ALL	ALL = (ALL)	NOPASSWD: /usr/bin/tee /sys/class/backlight/intel_backlight/brightness
#in /etc/sudoers

pref="/sys/class/backlight/intel_backlight"
old=$(cat $pref/brightness)
mx=$(cat $pref/max_brightness)
new=$(($#==0?$old + 400:$old - 400))
new=$(($new>$mx?$mx:($new<0?400:$new)))
echo $new|sudo /usr/bin/tee /sys/class/backlight/intel_backlight/brightness


