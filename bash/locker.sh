#!/bin/bash
#turn off screen after n seconds and then run i3lock
[[ $# -ne 2 ]] && { echo "usage: ./locker.sh <seconds> <path/to/png/image>"; exit 1; }
revert() {
  xset dpms 0 0 0
}
trap revert SIGHUP SIGINT SIGTERM
xset +dpms dpms 5 5 5
i3lock -n -i $2
revert
