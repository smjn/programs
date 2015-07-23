#! /bin/bash
#####download videos from youtube using vlc####
while read line
do
	name=$(echo $line|cut -d, -f1)
	url=$(echo $line|cut -d, -f2)
	vlc -I dummy "$url" --no-sout-video --sout '#transcode{acodec=mp3,ab=192,channels=2,samplerate=44100}:standard{mux=mp3,dst="'$name'.mp3",access=file}' vlc://quit
done < urls
