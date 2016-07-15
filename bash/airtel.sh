wget -O - 'http://122.160.230.125:8080/planupdate/' 2>/dev/null | grep -A2 'You are left <'|grep -Pio '\d+[.]\d+\s+GB'
