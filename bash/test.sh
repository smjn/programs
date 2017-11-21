#! /bin/bash
echo $0
echo ${0##*/}
basename $0

function test(){
	echo $*
	return 5
}

test "hello" "world"

XVAR1="sushant mahajan"
declare -x XVAR1
