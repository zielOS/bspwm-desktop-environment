#!/bin/bash

cd && git clone https://aur.archlinux.org/yay-bin.git
cd yay-bin
makepkg -si -r && cd

echo "Installing Aur packages"
yay -S bspwm-git
yay -S sxhkd-git
yay -S eww-x11-git 
yay -S papirus-folders-catppuccin-git.git
yay -S catppuccin-gtk-theme-mocha
yay -S nodejs-neovim
yay -S catppuccin-cursors-mocha
yay -S betterlockscreen
yay -S fnm
yay -S insync
yay -S acct
yay -S aide
yay -S ckb-next
yay -S stacer
yay -S pamac-all
yay -S jgmenu-git
yay -S mullvad-vpn
yay -S picom-ftlabs-git
yay -S zramd

echo "setup lunarvim"
cd && mkdir ~/.npm-global && npm config set prefix '~/.npm-global'
LV_BRANCH='release-1.3/neovim-0.9' bash <(curl -s https://raw.githubusercontent.com/LunarVim/LunarVim/release-1.3/neovim-0.9/utils/installer/install.sh) 

zsh <(curl -s https://raw.githubusercontent.com/zap-zsh/zap/master/install.zsh) --branch release-v1
sudo rm -R $HOME/.zshrc

echo "Setup Systemd"
sudo systemctl set-default graphical.target 
systemctl --user enable --now wireplumber.service pipewire-pulse.socket pipewire.socket pipewire-pulse.service pipewire.service pipewire-pulse.socket pipewire.socket pipewire-pulse.service pipewire.service 

echo "snapd & flatpak setup"
cd && sudo systemctl enable --now snapd.socket && sudo ln -s /var/lib/snapd/snap /snap 



echo "Setting up dotfiles0"
cd && cd bspwm-desktop-environment 
stow .
