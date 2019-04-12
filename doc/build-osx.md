Mac OS X Build Instructions and Notes
This guide will show you how to build fartcoin-qt for OSX. Tested on OSX 10.9 on 64-bit Intel processors only.

All of the commands should be executed in a Terminal application. (cmd+space) then type terminal.

Preparation
You need to install Xcode, when you type “git” in Terminal an installation popup will appear. The installation for Xcode will be done in the AppStore, and needs to download at least 5 GB.

While downloading you can already install Homebrew www.brew.sh After Xcode is installed you can install MacPorts www.macports.com We need this in order to install library dependencies. Installing the dependencies using MacPorts and Brew is very straightforward.

The installation of the actual dependencies is covered in the Instructions sections below.

Instructions: MacPorts
sudo port install boost openssl miniupnpc autoconf pkgconfig automake qt4-mac qrencode protobuf-cpp
Instructions: Homebrew
brew install autoconf automake berkeley-db boost miniupnpc openssl pkg-config protobuf qt
Instructions: Building Fartcoin-Core
Clone the github tree to get the source code and go into the directory. git clone https://github.com/fartcoin/fartcoin.git cd fartcoin

Build Berkeley-db-5.1.29.NC in /Users/OSX_USER/fartcoin/:

Download berkeley-db from oracle, 
http://download.oracle.com/berkeley-db/db-5.1.29.NC.tar.gz
and extract it into /fartcoin/
In the fartcoin folder type:

BITCOIN_ROOT=$(pwd)
BDB_PREFIX=”${BITCOIN_ROOT}/db5″
mkdir -p $BDB_PREFIX
cd db-5.1.29.NC/
curl -OL https://raw.github.com/narkoleptik/os-x-berkeleydb-patch/master/atomic.patch
patch src/dbinc/atomic.h < atomic.patch
cd build_unix/
../dist/configure –enable-cxx –disable-shared –with-pic –prefix=$BDB_PREFIX
make install
cd $BITCOIN_ROOT
Build fartcoin-core:

./autogen.sh
./configure LDFLAGS=”-L$(pwd)/db5/lib/ -L/opt/local/libexec/qt4/lib” CPPFLAGS=”-I$(pwd)/db5/include/ -I/opt/local/libexec/qt4/include” PKG_CONFIG_PATH=”/opt/local/libexec/qt4/lib/pkgconfig”
make
make deploy
It is a good idea to build and run the unit tests, too:

make check
Creating a release build
You can ignore this section if you are building fartcoind for your own use.

fartcoind/fartcoin-cli binaries are not included in the Fartcoin-Qt.app bundle.

If you are building fartcoind or Fartcoin-Qt for others, your build machine should be set up as follows for maximum compatibility:

All dependencies should be compiled with these flags:

-mmacosx-version-min=10.6 -arch x86_64 -isysroot $(xcode-select --print-path)/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk

For MacPorts, that means editing your macports.conf and setting macosx_deployment_target and build_arch:

macosx_deployment_target=10.6
build_arch=x86_64
... and then uninstalling and re-installing, or simply rebuilding, all ports.

As of December 2012, the boost port does not obey macosx_deployment_target. Download http://gavinandresen-bitcoin.s3.amazonaws.com/boost_macports_fix.zip for a fix.

Once dependencies are compiled, see release-process.md for how the Fartcoin-Qt.app bundle is packaged and signed to create the .dmg disk image that is distributed.

Use Qt Creator as IDE
------------------------
You can use Qt Creator as IDE, for debugging and for manipulating forms, etc.
Download Qt Creator from http://www.qt.io/download/. Download the "community edition" and only install Qt Creator (uncheck the rest during the installation process).

1. Make sure you installed everything through homebrew mentioned above 
2. Do a proper ./configure --with-gui=qt5 --enable-debug
3. In Qt Creator do "New Project" -> Import Project -> Import Existing Project
4. Enter "fartcoin-qt" as project name, enter src/qt as location
5. Leave the file selection as it is
6. Confirm the "summary page"
7. In the "Projects" tab select "Manage Kits..."
8. Select the default "Desktop" kit and select "Clang (x86 64bit in /usr/bin)" as compiler
9. Select LLDB as debugger (you might need to set the path to your installtion)
10. Start debugging with Qt Creator

Creating a release build
------------------------
You can ignore this section if you are building `fartcoind` for your own use.

fartcoind/fartcoin-cli binaries are not included in the Fartcoin-Qt.app bundle.

If you are building `fartcoind` or `Fartcoin-Qt` for others, your build machine should be set up
as follows for maximum compatibility:

All dependencies should be compiled with these flags:

 -mmacosx-version-min=10.7
 -arch x86_64
 -isysroot $(xcode-select --print-path)/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk

Once dependencies are compiled, see [doc/release-process.md](release-process.md) for how the Fartcoin-Qt.app
bundle is packaged and signed to create the .dmg disk image that is distributed.

Running
-------

It's now available at `./fartcoind`, provided that you are still in the `src`
directory. We have to first create the RPC configuration file, though.

Run `./fartcoind` to get the filename where it should be put, or just try these
commands:

    echo -e "rpcuser=fartcoinrpc\nrpcpassword=$(xxd -l 16 -p /dev/urandom)" > "/Users/${USER}/Library/Application Support/Fartcoin/fartcoin.conf"
    chmod 600 "/Users/${USER}/Library/Application Support/Fartcoin/fartcoin.conf"

The next time you run it, it will start downloading the blockchain, but it won't
output anything while it's doing this. This process may take several hours;
you can monitor its process by looking at the debug.log file, like this:

    tail -f $HOME/Library/Application\ Support/Fartcoin/debug.log

Other commands:
-------

    ./fartcoind -daemon # to start the fartcoin daemon.
    ./fartcoin-cli --help  # for a list of command-line options.
    ./fartcoin-cli help    # When the daemon is running, to get a list of RPC commands
