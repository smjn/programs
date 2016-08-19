#!/bin/bash
wget -O - 'http://122.160.230.125:8080/planupdate/' 2>/dev/null | grep -P -A2 'You are left <|No. of days left'|grep -Pio '\d+[.]\d+\s+GB|\d+ day\(s\)'
