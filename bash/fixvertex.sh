#! /bin/bash
loc=(/usr/share/themes/Vertex /usr/share/themes/Vertex-Dark /usr/share/themes/Vertex-Light)
file=(gtk.css gtk-dark.css)
for i in ${loc[@]}
do
	for f in ${file[@]}
	do
		name=$i/gtk-3.0/$f
		if ! [[ -e "$name" ]]; then
			echo $name does not exit
			continue
		fi
		sudo sed -i 's/\(-gtk.*pan-.*;\)\s\+\}$/\/\*\1\*\/ \}/g' $name
		sudo sed -i 's/\(-gtk.*pan-.*;$\)/\/\*\1\*\//g' $name
	done
done

