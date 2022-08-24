
Debian
====================
This directory contains files used to package fartcoind/fartcoin-qt
for Debian-based Linux systems. If you compile fartcoind/fartcoin-qt yourself, there are some useful files here.

## fartcoin: URI support ##


fartcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install fartcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your fartcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/fartcoin128.png` to `/usr/share/pixmaps`

fartcoin-qt.protocol (KDE)

