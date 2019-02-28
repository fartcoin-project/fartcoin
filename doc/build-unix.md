UNIX BUILD NOTES
====================
Some notes on how to build Fartcoin in Unix. 

System requirements
--------------------

C++ compilers are memory-hungry. It is recommended to have at least 1 GB of
memory available when compiling Fartcoin Core. With 512MB of memory or less,
compilation will take much longer due to swap thrashing.

Dependency Build Instructions: Ubuntu & Debian
----------------------------------------------
Fartcoind Build requirements:
```bash
sudo apt-get install build-essential libtool autotools-dev autoconf pkg-config libssl1.0-dev libboost-all-dev libminiupnpc-dev
```	
Dependencies for the GUI: Ubuntu & Debian
-----------------------------------------
To build with Graphical User Interface (Fartcoin-QT wallet)
```bash
sudo apt-get install libqt4-dev libprotobuf-dev protobuf-compiler libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev libqrencode-dev
```
Berkeley DB
-----------
It is recommended to use Berkeley DB 5.1. Fetch the source and verify that it is not tampered with:

```bash
wget 'http://download.oracle.com/berkeley-db/db-5.1.29.NC.tar.gz'
echo '08238e59736d1aacdd47cfb8e68684c695516c37f4fbe1b8267dde58dc3a576c db-5.1.29.NC.tar.gz' | sha256sum -c
tar -xzvf db-5.1.29.NC.tar.gz

BITCOIN_ROOT=$(pwd)
BDB_PREFIX="${BITCOIN_ROOT}/db5"
mkdir -p $BDB_PREFIX

cd db-5.1.29.NC/build_unix/
../dist/configure --enable-cxx --disable-shared --with-pic --prefix=$BDB_PREFIX
make install

cd $BITCOIN_ROOT
./autogen.sh
./configure LDFLAGS="-L${BDB_PREFIX}/lib/" CPPFLAGS="-I${BDB_PREFIX}/include/"
make
```

**Note**: You only need Berkeley DB if the wallet is enabled (see the section *Disable-Wallet mode* below).
Once these are installed, they will be found by configure and a fartcoin-qt executable will be
built by default.


Dependencies
---------------------

These dependencies are required:

 Library     | Purpose          | Description
 ------------|------------------|----------------------
 libssl      | SSL Support      | Secure communications
 libboost    | Boost            | C++ Library

Optional dependencies:

 Library     | Purpose          | Description
 ------------|------------------|----------------------
 miniupnpc   | UPnP Support     | Firewall-jumping support
 libdb5.1    | Berkeley DB      | Wallet storage (only needed when wallet enabled)
 qt          | GUI              | GUI toolkit (only needed when GUI enabled)
 protobuf    | Payments in GUI  | Data interchange format used for payment protocol (only needed when GUI enabled)
 libqrencode | QR codes in GUI  | Optional for generating QR codes (only needed when GUI enabled)

For the versions used in the release, see [release-process.md](release-process.md) under *Fetch and build inputs*.
