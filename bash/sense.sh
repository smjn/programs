#!/bin/bash
echo -n "Core: "
sensors 2>/dev/null|grep -iEo 'physical id 0:\s+\+[0-9]{2}'|grep -iEo '\+[0-9]+'|tr '\n' '.'
echo -n "0°C Fan: "
sensors 2>/dev/null|grep -io 'fan.*RPM'|grep -Eo '[0-9]+ RPM'|tr '\n' ' '
