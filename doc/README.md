Fartcoin 0.9
====================

* Copyright (c) 2009-2014 Bitcoin Developers
* Copyright (c) 2011-2013 Litecoin Developers
* Copyright (c) 2013-2014 Dogecoin Developers
* Copyright (c) 2018 Fartcoin Developer


Setup
---------------------
[Fartcoin Core](http://fartcoin.com/en/download) is the original Fartcoin client and it builds the backbone of the network. However, it downloads and stores the entire history of Fartcoin transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once. If you would like the process to go faster you can [download the blockchain directly](bootstrap.md)

Running
---------------------
The following are some helpful notes on how to run Fartcoin on your native platform. 

### Unix

You need the Qt4 run-time libraries to run Fartcoin-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/fartcoin-qt (GUI, 32-bit) or bin/32/fartcoind (headless, 32-bit)
- bin/64/fartcoin-qt (GUI, 64-bit) or bin/64/fartcoind (headless, 64-bit)



### Windows

Unpack the files into a directory, and then run fartcoin-qt.exe.

### OSX

Drag Fartcoin-Qt to your applications folder, and then run Fartcoin-Qt.

### Need Help?

* See the documentation at the [Fartcoin Wiki](http://fartco.in/)
for help and more information.
* Ask for help on [#fartcoin](http://webchat.freenode.net?channels=fartcoin) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=fartcoin).
* Ask for help on the [/r/fartducation subreddit](http://reddit.com/r/fartducation).

Building
---------------------
The following are developer notes on how to build Fartcoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-msw.md)

Development
---------------------
The Fartcoin repo's [root README](https://github.com/fartcoin/fartcoin/blob/master/README.md) contains relevant information on the development process and automated testing.

- [Coding Guidelines](coding.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/bitcoin/doxygen/)
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)

### Resources
* Discuss on the [/r/fartcoindev](http://www.reddit.com/r/fartcoindev) subreddit.
* Discuss on [#fartcoin-dev](http://webchat.freenode.net/?channels=fartcoin-dev) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=fartcoin-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
