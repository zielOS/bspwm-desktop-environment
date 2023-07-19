#!/bin/bash

cd && echo "Installing yay-bin"
git clone https://aur.archlinux.org/yay.git
cd yay
makepkg -si

echo "Installing aur packages"
yay -S sxhkd-git bspwm-git fnm eww-x11-git papirus-folders-catppuccin-git catppuccin-gtk-theme-mocha catppuccin-cursors-mocha ckb-next aide insync acct ueberzugpp

echo "Setting Up npm"
cd 
mkdir ~/.npm-global 
npm config set prefix '~/.npm-global' 

echo "Setting up systemd"
sudo systemctl set-default graphical.target 
systemctl --user enable --now wireplumber.service pipewire-pulse.socket pipewire.socket pipewire-pulse.service pipewire.service pipewire-pulse.socket pipewire.socket pipewire-pulse.service pipewire.service

echo "Setting Up zsh shell"
zsh <(curl -s https://raw.githubusercontent.com/zap-zsh/zap/master/install.zsh)
chsh -s $(which zsh)
sudo rm -R .zshrc

