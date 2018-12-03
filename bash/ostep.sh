#!/usr/bin/env bash

if ! which pdfunite >/dev/null 2>&1; then
    echo 'pdfunite is required. For debian based install popplar-utils, for others check the internet'
    exit 1
fi

url='http://pages.cs.wisc.edu/~remzi/OSTEP/'
odir=/tmp/ostep"$RANDOM"
mkdir -p "$odir" && pushd "$odir"
# wget -r -l1 -A"*.pdf" -nd "$url"
curl -sS "$url" |grep -iEo '<small>[0-9]+.*[.]pdf'>fpdf
while read line; do
    num=$(echo $line|grep -iEo '[0-9]+')
    f=$(echo $line|grep -iEo '=.*pdf'|tr -d '=')
    echo $num $f
done <fpdf|sort -k1 -n|awk '{print $2}'>fs
echo final.pdf >>fs
cat fs|xargs pdfunite
mv final.pdf ~/ostep.pdf
popd
