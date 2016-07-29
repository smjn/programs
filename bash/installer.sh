#! /bin/bash
sudo add-apt-repository -y ppa:numix/ppa
sudo add-apt-repository -y ppa:webupd8team/java
sudo apt-get update
sudo apt-get install vim bmon iotop clementine terminator vlc smplayer build-essential oracle-java8-installer numix-gtk-theme gnome-tweak-tool numix-icon-theme-circle lm-sensors zsh

sudo sensors-detect --auto
sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
chsh -s zsh
