#!/bin/zsh

if [ $1 = "delete" ]
then
        echo "Suppression de la minilibx"
rm -rf minilibx
fi

if [ $1 = "install" ]
then
        echo "Installation de la minilix"
git clone https://github.com/42Paris/minilibx-linux.git
mv minilibx-linux minilibx
cd minilibx
./configure
fi
