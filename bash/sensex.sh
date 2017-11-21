#!/usr/bin/env bash
echo -n Sensex:; wget -q -O - "https://www.google.com/finance/info?q=INDEXBOM:SENSEX" | grep -E '"l" :|"c" :'|cut -d: -f2|tr '\n' '"'|sed 's/"//g'

