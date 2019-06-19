#!/usr/bin/env bash

theme_dir=""
termite_config="$HOME/.config/termite/config"
[[ $# -eq 1 ]] && [[ -d "$1" ]] && theme_dir="$1" || theme_dir="$HOME/.config/termite/base16-termite/themes"
echo "theme dir: $theme_dir"

declare -a themes
ind=1
for theme in `ls $theme_dir`
do
    themes[$ind]=$theme
    printf "%2d. %-25s\n" "$ind" "$theme"
    ((ind++))
done
((ind--))
choice=0
echo "current theme: " $(grep '########THEME_NAME' "$termite_config"|cut -d '%' -f2|cut -d '.' -f1)
until [[ $choice -ge 1 ]] && [[ $choise -le $ind ]]; do
    read -p "Choice [1-$ind]? " choice
done

[[ -f "$termite_config" ]] && sed -i '/\[colors\]/,$d' $termite_config
sed -i '/THEME_NAME/d' "$termite_config"
echo "########THEME_NAME###%${themes[$choice]}%#####" >> "$termite_config"
cat "$theme_dir/${themes[$choice]}" >> "$termite_config"

#transparent background
toks=$(grep 'background' "$termite_config"|grep -o ","|wc -l)
[[ $toks -eq 2 ]] && sed -i '/background/ s/)/,0)/' "$termite_config"

echo "reload termite"
