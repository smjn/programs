#!/usr/bin/env bash

declare -A urls
urls=(['graph-rx580-8g']='http://bwindia.net/catalog/hardwares/graphics-card/radeon-rx-500-series/graphics-card-ati-radeon-rx-580-8gb' ['graph-gtx1060-6gb']='http://bwindia.net/catalog/hardwares/graphics-card-latest-models-suggested/nvidia-geforce-10-series/graphics-card-nvid-2' ['graph-gtx1060-6gb-oc']='http://bwindia.net/catalog/hardwares/graphics-card/nvidia-geforce-10-series/graphics-card-nvidia-gtx-1060-6gb' ['cpu']='http://bwindia.net/catalog/hardwares/cpu/cpu-amd/ryzen' ['ram-stick-8']='http://bwindia.net/catalog/hardwares/memory-ddr4/memory-ddr4-8gb' ['ram-kit-16']='http://bwindia.net/catalog/hardwares/memory-ddr4/memory-ddr4-16gb-kit' ['smps']='http://bwindia.net/catalog/hardwares/smps/smps-advanced-performance-machines/true-psu-smps-650-watts' ['cabinet']='http://bwindia.net/catalog/hardwares/cabinets/cabinets-desktop/good-ones-range-computer-cabinets' ['ssd']='http://bwindia.net/catalog/hardwares/hdd-desktop-solid-state-drive-ssd/ssd-standard-medium-capacity/ssd-standard-240gb' ['hdd']='http://bwindia.net/catalog/hardwares/hdd-desktop-sata-type-hard-disk/hard-disk-sata-1tb' ['mobo']='http://bwindia.net/catalog/hardwares/motherboard/mb-amd-cpus/am4-socket-based-mb-amd-cpu/amd-b450-chipset-motherboard')

for comp in "${!urls[@]}"; do
    echo -n $comp " "
    case $comp in
    cpu)
        val=$(wget -L ${urls[$comp]} -O - 2>/dev/null|grep -i ' 2600 '|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1)
        echo $val
        ;;
    ram-stick*)
        echo -n "3000-"
        val1=$(wget -L ${urls[$comp]} -O - 2>/dev/null|grep -i ' 3000'|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1)
        echo -n $val1 
        val2=$(wget -L ${urls[$comp]} -O - 2>/dev/null|grep -i ' 3200'|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1)
        echo -n ", 3200-"
        echo $val2
        ;;
    ram-kit*)
        echo -n "3000-" 
        val=$(wget -L ${urls[$comp]} -O - 2>/dev/null|grep -i ' 3000'|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1)
        echo -n $val
        echo -n ",3200-"
        val=$(wget -L ${urls[$comp]} -O - 2>/dev/null|grep -i ' 3200'|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1)
        echo $val
        ;;
    graph*)
        val=$(wget -L ${urls[$comp]} -O - 2>/dev/null|grep -vi 'mini'|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1)
        echo $val
        ;;
    smps)
        val=$(wget -L ${urls[$comp]} -O - 2>/dev/null|egrep -i 'cooler master|corsair'|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1)
        echo $val
        ;;
    cabinet)
        val=$(wget -L ${urls[$comp]} -O - 2>/dev/null|grep -i 'spec-01'|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1)
        echo $val
        ;;
    ssd)
        val=$(wget -L ${urls[$comp]} -O - 2>/dev/null|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1)
        echo $val
        ;;
    hdd)
        val=$(wget -L ${urls[$comp]} -O - 2>/dev/null|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1)
        echo $val
        ;;
    mobo)
        wget -L ${urls[$comp]} -O - 2>/dev/null|egrep -i 'b450 tomahawk'|egrep -o 'Rs.[0-9]+,?[0-9]+'|tr -d 'Rs.,'|sort -n|head -1
        ;;
    *)
        echo "Not found"
        ;;
    esac
done

echo $total1 $total2
