#!/bin/bash
#turn off screen after n seconds and then run i3lock
[[ $# -ne 2 ]] && { echo "usage: ./locker.sh <seconds> <path/to/png/image>"; exit 1; }
xset dpms $1
i3lock -f -i $2 
xset dpms 0 0 0
