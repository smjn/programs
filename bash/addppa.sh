#!/bin/bash

#add-apt-repository was not working in debian testing so created a small script to add it. This requires sudo priviledge. The actual proplem is
#using the command add-key adv... it is not able to access keyserver.ubuntu.com

[[ $# -ne 2 ]] && { echo "usage: $0 ppa:username/project ubuntu-dist"; exit 1; };
tmp=${1#*:}
username=${tmp%/*}
project=${tmp#*/}
fname="$username-ubuntu-$project-$2.list"
echo "adding new entry in /etc/apt/sources.list.d/$fname"
sudo bash -c "cat > /etc/apt/sources.list.d/$fname << EOF
deb http://ppa.launchpad.net/${username}/${project}/ubuntu $2 main
EOF"
echo "getting the fingerprint for "$tmp"..."
url=https://launchpad.net/~${username}/+archive/ubuntu/${project}
wget -q ${url} -O /tmp/addppa
[[ $? -eq 0 ]] && echo "got page..." || { echo "error in fetching ${url}..."; exit 1; };
keyurl=$(grep -C3 'Signing key:' /tmp/addppa | grep -Eo 'http[^"]+' | sed 's/amp;//g')
echo "fetching key from ${keyurl}..."
puburl="http://keyserver.ubuntu.com:11371"$(wget -q ${keyurl} -O - | grep -Eo '/pks/lookup[^"]+' | head -1 | sed 's/amp;//g')
[[ $? -eq 0 ]] && echo "got pub key url ${puburl}..." || { echo "could not get pub key url :("; exit 1; };
wget -q ${puburl} -O - | sed -n '/BEGIN PGP/,/END PGP/p' > /tmp/release.key
[[ $? -eq 0 ]] && echo "got public key..." || { echo "could not get public key... :("; exit 1; };
sudo apt-key add - < /tmp/release.key
[[ $? -eq 0 ]] && echo "added key..." || { echo "could not add key... :("; exit 1; };
