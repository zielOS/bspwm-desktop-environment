#!/bin/sh

# git aliases
alias cl='git clone'
alias g='lazygit'

# zsh aliases
alias zsh-update="find "$ZDOTDIR/plugins" -type d -exec test -e '{}/.git' ';' -print0 | xargs -I {} -0 git -C {} pull -q"
alias f='zi'

# Pacman-related alias
alias em-sync='sudo emerge --sync'
alias em-update='sudo emerge -auvDN @world'
alias em-install='sudo emerge -av --jobs=5'
alias em-remove='sudo emerge --depclean'
alias em-search='sudo emerge -Ss'
alias em-clean='sudo eclean-dist --deep && sudo emerge --depclean'
alias pac-cleanup='sudo pacman -Qtdq | sudo pacman -Rns -'
alias pac-up-key='sudo pacman-key --init && sudo pacman-key --populate && sudo pacman -Sy archlinux-keyring'
alias pac-add-key='gpg --keyserver keyserver.ubuntu.com --recv'
alias pac-sha='sha256sum'
alias keywords='sudo lvim /etc/portage/package.accept_keywords'
alias use='sudo lvim /etc/portage/package.use'
alias conf='sudo lvim /etc/portage/make.conf'

# scripts-related aliases
alias hyprbar='sudo lvim /usr/local/bin/hyprbar'
alias hyprhotkeys='sudo lvim /usr/local/bin/hyprhotkeys'
alias hypridle='sudo lvim /usr/local/bin/hypridle'
alias hyprkeyring='sudo lvim /usr/local/bin/hyprkeyring'
alias hyprland-nvidia='sudo lvim /usr/local/bin/hyprland-nvidia'
alias hyprlock='sudo lvim /usr/local/bin/hyprlock'
alias hyprlogout='sudo lvim /usr/local/bin/hyprlogout'
alias hyprmenu='sudo lvim /usr/local/bin/hyprmenu'
alias hyprpolkit='sudo lvim /usr/local/bin/hyprpolkit'
alias hyprshot='sudo lvim /usr/local/bin/hyprshot'
alias hyprsome='sudo lvim /usr/local/bin/hyprsome'
alias hyprstart='sudo lvim /usr/local/bin/hyprstart'
alias hyprterm='sudo lvim /usr/local/bin/hyprterm'
alias hyprtheme='sudo lvim /usr/local/bin/hyprtheme'
alias hyprwall='sudo lvim /usr/local/bin/hyprwall'


# makepkg-related aliases
alias mkpkg='makepkg -si  --noconfirm'
alias mkpkg-conf='makepkg -si --noconfirm --config $HOME/.config/makepkg/makepkg.conf'

# Misc-related aliases
alias audit='sudo lynis audit system'
alias update-grub='sudo grub-mkconfig -o /boot/grub/grub.cfg'
alias Rm='sudo rm -rf'
alias htkey-load='sudo pkill -HUP swhkd'
alias emacs_stop='emacsclient -e "(kill-emacs)"'
alias snapper='sudo lvim /etc/snapper/configs/root'

if [[ $TERM == "xterm-kitty" ]]; then
  alias ssh="kitty +kitten ssh"
fi

case "$(uname -s)" in

Darwin)
	# echo 'Mac OS X'
	alias ls='ls -G'
	;;

Linux)
	alias ls='ls --color=auto'
	;;

CYGWIN* | MINGW32* | MSYS* | MINGW*)
	# echo 'MS Windows'
	;;
*)
	# echo 'Other OS'
	;;
esac
