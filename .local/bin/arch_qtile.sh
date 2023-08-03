#!/bin/bash
git clone https://aur.archlinux.org/yay-bin.git
cd yay-bin
makepkg -si && cd

yay -S qtile-extras
yay -S pamac-all
yay -S planify
yay -S papirus-folders-catppuccin-git 
yay -S catppuccin-gtk-theme-mocha 
yay -S catppuccin-cursors-mocha 
yay -S ckb-next 
yay -S insync 
yay -S picom-ftlabs-git 
yay -S brave-bin
yay -S aide
yay -S snapper 
yay -S snap-pac-grub
yay -S fnm
yay -S snapd
yay -S zoom
yay -S mullvad-vpn
yay -S zramd
yay -S nodejs-neovim
yay -S eww-x11-git
yay -S texlive-latexindent-meta
 
sudo systemctl set-default graphical.target 
systemctl --user enable --now wireplumber.service pipewire-pulse.socket pipewire.socket pipewire-pulse.service pipewire.service pipewire-pulse.socket pipewire.socket pipewire-pulse.service pipewire.service emacs-28 && sudo systemctl enable zramd ckb-next-daemon


cd && mkdir ~/.npm-global 
npm config set prefix '~/.npm-global' 
LV_BRANCH='release-1.3/neovim-0.9' bash <(curl -s https://raw.githubusercontent.com/LunarVim/LunarVim/release-1.3/neovim-0.9/utils/installer/install.sh)

echo "Setting Up zsh shell"
zsh <(curl -s https://raw.githubusercontent.com/zap-zsh/zap/master/install.zsh)
chsh -s $(which zsh)
sudo rm -R $HOME/.zshrc

echo "Setting Up tmux"
mkdir -p $HOME/.tmux/plugins
git clone https://github.com/tmux-plugins/tpm $HOME/.tmux/plugins/tpm
tmux source $HOME/.tmux.conf


