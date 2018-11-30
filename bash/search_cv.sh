#!/usr/bin/env bash

(( flag=0x0000 ))
(( initf=0x1110 ))
(( keyf=0x0011 ))
src=''
dst=''
keyw=''
checkPreReq() {
    which pdftotext >/dev/null 2>&1|| { echo "use: brew install psdtotext; pdftotext not present"; exit 1; }
    which grep >/dev/null 2>&1 || { echo "grep not present"; exit 1; }
    which find >/dev/null 2>&1 || { echo "find not present"; exit 1; }
}

usage() {
    echo "$0 [-i -s -d]|[-k -d]"
    exit 2
}

initialize() {
    if ! [[ -d "$src" ]]; then
        echo "source does not exist/is not a directory"
        exit 3
    fi

    if ! [[ -d "$dst" ]]; then
        echo "destination does not exist/is not a directory"
        exit 3
    fi

    find "$src" -iname "*.pdf" >/tmp/names3.txt
    while read line; do
        fname=$(echo $(basename "$line")|tr ' ' '_')
        pdftotext "$line" "$dst/$fname".txt
    done </tmp/names3.txt
}

finder() {
    orig=$IFS
    IFS=","
    read -ra kws <<< "$keyw"
    echo "${kws[@]}"
    IFS=$orig
    echo "individual"
    for k in "${kws[@]}"; do
        echo "$k:"
        grep -irl "$k" "$dst"|sort|uniq
    done

    echo "or'ed keywords"
    cmd="grep -irl"
    for k in "${kws[@]}"; do
        cmd=" $cmd -e $k"
    done
    cmd="$cmd $dst|sort|uniq"
    eval $cmd

    echo "anded keywords"
    ind=0
    for k in "${kws[@]}"; do
        (( ind++ ))
        if [[ $ind -eq 1 ]]; then 
            grep -irl "$k" "$dst" >/tmp/names1.dat
        fi
        cat /tmp/names1.dat|xargs grep -il "$k" >/tmp/names2.dat
        exit 0
        mv /tmp/names{2.dat,1.dat}
    done
    cat /tmp/names1.dat|sort|uniq
}

if [[ $# -eq 0 ]]; then
    usage
fi

checkPreReq

while [[ $# -gt 0 ]]; do
    arg="$1"
    case $arg in
        "-i")
            (( flag=flag|0x1000 ))
            shift
            ;;
        "-s")
            (( flag=flag|0x0100 ))
            shift
            src="$1"
            shift
            ;;
        "-d")
            (( flag=flag|0x0010 ))
            shift
            dst="$1"
            shift
            ;;
        "-k")
            (( flag=flag|0x0001 ))
            shift
            keyw="$1"
            shift
            ;;
        *)
            echo "invalid arg: $arg"
            exit 1
            ;;
    esac
done

if (( (flag&initf) == flag )); then
    initialize
elif (( (flag&keyf) == flag )); then
    finder
else
    echo "invalid flag combination"
    usage
fi


