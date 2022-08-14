### Usage

To build dependencies for the current arch+OS:

    make

To build for another arch/OS:

    make HOST=host-platform-triplet

For example:

    make HOST=x86_64-w64-mingw32 -j4

A prefix will be generated that's suitable for plugging into Bitcoin's
configure. In the above example, a dir named i686-w64-mingw32 will be
created. To use it for Bitcoin:

    ./configure --prefix=`pwd`/depends/x86_64-w64-mingw32

Common `host-platform-triplets` for cross compilation are:

- `i686-w64-mingw32` for Win32
- `x86_64-w64-mingw32` for Win64
- `x86_64-apple-darwin11` for MacOSX
- `arm-linux-gnueabihf` for Linux ARM

No other options are needed, the paths are automatically configured.

Dependency Options:
The following can be set when running make: make FOO=bar

    SOURCES_PATH: downloaded sources will be placed here
    BASE_CACHE: built packages will be placed here
    SDK_PATH: Path where sdk's can be found (used by OSX)
    FALLBACK_DOWNLOAD_PATH: If a source file can't be fetched, try here before giving up
    NO_QT: Don't download/build/cache qt and its dependencies
    NO_WALLET: Don't download/build/cache libs needed to enable the wallet
    NO_UPNP: Don't download/build/cache packages needed for enabling upnp
    DEBUG: disable some optimizations and enable more runtime checking

If some packages are not built, for example `make NO_WALLET=1`, the appropriate
options will be passed to bitcoin's configure. In this case, `--disable-wallet`.

Additional targets:

    download: run 'make download' to fetch all sources without building them
    download-osx: run 'make download-osx' to fetch all sources needed for osx builds
    download-win: run 'make download-win' to fetch all sources needed for win builds
    download-linux: run 'make download-linux' to fetch all sources needed for linux builds

#############################################################################################
## WINDOWS Cross-compilation notes for Linux Ubuntu-18.04                                  ##
#############################################################################################

[ First, install the general dependencies: ]
```
sudo apt-get install 
build-essential libtool autotools-dev automake pkg-config bsdmainutils curl git 
libboost-all-dev autoconf libssl1.0-dev libminiupnpc-dev libqrencode-dev libqt4-dev 
libprotobuf-dev protobuf-compiler libqt5gui5 libqt5dbus5 qttools5-dev qttools5-dev-tools nsis
```
[ Second, make sure Ubuntu's general dependencies are updated and upgraded: ]
[ If for some reason an error occured with the first general dependencies, retry after upgrade ] 
```
sudo apt update
sudo apt upgrade
```
[ Third, install mingw, the Cross-Compilers for windows 32 or 64 bit ] 
```
[64-bit]        sudo apt install g++-mingw-w64-x86-64
[32-bit]	sudo apt install g++-mingw-w64-i686   mingw-w64-i686-dev
```
[ Set the default mingw32 g++ compilers option to posix choose (1) ]
```
[64-bit]	sudo update-alternatives --config x86_64-w64-mingw32-g++ 
[32-bit]	sudo update-alternatives --config i686-w64-mingw32-g++ 
```
[ Fourth, get a clean source code, and make sure you have permissions ]
```
		sudo git clone https://github.com/fartcoin-project/fartcoin.git
		sudo chmod -R a+rw fartcoin
```
[ Fifth, set the right PATH for windows, and install the dependencies for windows ]
```
		PATH=$(echo "$PATH" | sed -e 's/:\/mnt.*//g')
		cd fartcoin/depends
[64-bit]	make HOST=x86_64-w64-mingw32 -j4
[32-bit]	make HOST=i686-w64-mingw32 -j4
		cd ..
```
[ Sixth, configure the source code for crosscompiling and make fartcoin-core ]
```
		./autogen.sh
[64-bit]	CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site
[32-bit] 	CONFIG_SITE=$PWD/depends/i686-w64-mingw32/share/config.site
[64-bit]	./configure --prefix=`pwd`/depends/x86_64-w64-mingw32
[32-bit]	./configure --prefix=`pwd`/depends/i686-w64-mingw32	
		make
		make install DESTDIR=~/Desktop/WIN64_fartcoin
		make deploy
```

### Other documentation

- [description.md](description.md): General description of the depends system
- [packages.md](packages.md): Steps for adding packages

