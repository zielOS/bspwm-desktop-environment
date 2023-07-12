#!/bin/bash

echo "Installing dot files"
cd && cd bspwm-desktop-environment
ln -s bspwm/ $HOME/.config/
ln -s dunst/ $HOME/.config/
ln -s eww/ $HOME/.config/
ln -s gammastep/ $HOME/.config/
ln -s jgmenu/ $HOME/.config/
ln -s lazygit/ $HOME/.config/
ln -s lsd/ $HOME/.config/
ln -s ranger/ $HOME/.config/
ln -s rofi/ $HOME/.config/
ln -s suckless/ $HOME/.config/
ln -s vifm/ $HOME/.config/
ln -s wallpappers/ $HOME/.config/
ln -s xsettingsd/ $HOME/.config/
ln -s zathura/ $HOME/.config/
ln -s zsh/ $HOME/.config/
ln -s .Xresources $HOME/
ln -s .zshrc $HOME/

echo "Setting Up npm"
cd 
mkdir ~/.npm-global 
npm config set prefix '~/.npm-global' 

echo "Setting Up zsh shell"
curl -fsSL https://fnm.vercel.app/install | bash
zsh <(curl -s https://raw.githubusercontent.com/zap-zsh/zap/master/install.zsh)
chsh -s $(which zsh)
sudo rm -R .zshrc
mv .zshrc.bak .zshrc
