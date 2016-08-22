#! /bin/bash
#synclient TouchpadOff=1
#mid=$(xinput |grep -iE 'microsoft.*slave[ ]+pointer'|grep -oE 'id=[0-9]+'|tail -1|cut -d= -f2)
#mid2=$(xinput |grep -iE 'microsoft.*slave[ ]+pointer'|grep -oE 'id=[0-9]+'|head -1|cut -d= -f2)
#xinput --set-prop $mid "Device Accel Constant Deceleration" 2.7
#xinput --set-prop $mid2 "Device Accel Constant Deceleration" 2.7
xmodmap /home/sushant/.Xmodmap
notify-send --hint=int:transient:1 "Stuff is set"


