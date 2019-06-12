Release Process
====================

* update translations (ping wumpus, Diapolo or tcatm on IRC)
* see https://github.com/bitcoin/bitcoin/blob/master/doc/translation_process.md#syncing-with-transifex

* * *

###update (commit) version in sources

	contrib/verifysfbinaries/verify.sh
	doc/README*
	share/setup.nsi
	src/clientversion.h (change CLIENT_VERSION_IS_RELEASE to true)

###tag version in git

	git tag -s v(new version, e.g. 0.8.0)

###write release notes. git shortlog helps a lot, for example:

	git shortlog --no-merges v(current version, e.g. 0.7.2)..v(new version, e.g. 0.8.0)

* * *

##perform gitian builds

 From a directory containing the fartcoin source, gitian-builder and gitian.sigs
  
	export SIGNER=(your gitian key, ie bluematt, sipa, etc)
	export VERSION=(new version, e.g. 0.8.0)
	pushd ./fartcoin
	git checkout v${VERSION}
	popd
	pushd ./gitian-builder

 Fetch and build inputs: (first time, or when dependency versions change)

	mkdir -p inputs; cd inputs/
	wget 'http://miniupnp.free.fr/files/download.php?file=miniupnpc-1.9.20151008.tar.gz' -O miniupnpc-1.9.20151008.tar.gz
	wget 'https://www.openssl.org/source/openssl-1.0.1l.tar.gz'
	wget 'http://download.oracle.com/berkeley-db/db-5.1.29.NC.tar.gz'
	wget 'https://zlib.net/fossils/zlib-1.2.8.tar.gz'
	wget 'https://sourceforge.net/projects/libpng/files/libpng16/older-releases/1.6.8/libpng-1.6.8.tar.gz'
	wget 'https://fukuchi.org/works/qrencode/qrencode-3.4.3.tar.bz2'
	wget 'https://downloads.sourceforge.net/project/boost/boost/1.55.0/boost_1_55_0.tar.bz2'
	wget 'https://svn.boost.org/trac/boost/raw-attachment/ticket/7262/boost-mingw.patch' -O \
	     boost-mingw-gas-cross-compile-2013-03-03.patch
	wget 'http://ftp1.nluug.nl/languages/qt/archive/qt/5.2/5.2.0/single/qt-everywhere-opensource-src-5.2.0.tar.gz'
	wget 'http://ftp1.nluug.nl/languages/qt/archive/qt/4.6/qt-everywhere-opensource-src-4.6.4.tar.gz'
	wget 'https://github.com/protocolbuffers/protobuf/releases/download/v2.5.0/protobuf-2.5.0.tar.bz2'
	cd ..
	./bin/gbuild ../fartcoin/contrib/gitian-descriptors/boost-linux.yml
	mv build/out/boost-*.zip inputs/
	./bin/gbuild ../fartcoin/contrib/gitian-descriptors/deps-linux.yml
	mv build/out/fartcoin-deps-*.zip inputs/
	./bin/gbuild ../fartcoin/contrib/gitian-descriptors/qt-linux.yml
	mv build/out/qt-*.tar.gz inputs/
	./bin/gbuild ../fartcoin/contrib/gitian-descriptors/boost-win.yml
	mv build/out/boost-*.zip inputs/
	./bin/gbuild ../fartcoin/contrib/gitian-descriptors/deps-win.yml
	mv build/out/fartcoin-deps-*.zip inputs/
	./bin/gbuild ../fartcoin/contrib/gitian-descriptors/qt-win.yml
	mv build/out/qt-*.zip inputs/
	./bin/gbuild ../fartcoin/contrib/gitian-descriptors/protobuf-win.yml
	mv build/out/protobuf-*.zip inputs/



 Build fartcoind and fartcoin-qt on Linux32, Linux64, and Win32:
  
	./bin/gbuild --commit fartcoin=v${VERSION} ../fartcoin/contrib/gitian-descriptors/gitian-linux.yml
	./bin/gsign --signer $SIGNER --release ${VERSION} --destination ../gitian.sigs/ ../fartcoin/contrib/gitian-descriptors/gitian-linux.yml
	pushd build/out
	zip -r fartcoin-${VERSION}-linux-gitian.zip *
	mv fartcoin-${VERSION}-linux-gitian.zip ../../../
	popd

	./bin/gbuild --commit fartcoin=v${VERSION} ../fartcoin/contrib/gitian-descriptors/gitian-win.yml
	./bin/gsign --signer $SIGNER --release ${VERSION}-win --destination ../gitian.sigs/ ../fartcoin/contrib/gitian-descriptors/gitian-win.yml
	pushd build/out
	zip -r fartcoin-${VERSION}-win-gitian.zip *
	mv fartcoin-${VERSION}-win-gitian.zip ../../../
	popd
	popd

  Build output expected:

  1. linux 32-bit and 64-bit binaries + source (fartcoin-${VERSION}-linux-gitian.zip)
  2. windows 32-bit and 64-bit binaries + installer + source (fartcoin-${VERSION}-win-gitian.zip)
  3. Gitian signatures (in gitian.sigs/${VERSION}[-win]/(your gitian key)/

repackage gitian builds for release as stand-alone zip/tar/installer exe

**Linux .tar.gz:**

	unzip fartcoin-${VERSION}-linux-gitian.zip -d fartcoin-${VERSION}-linux
	tar czvf fartcoin-${VERSION}-linux.tar.gz fartcoin-${VERSION}-linux
	rm -rf fartcoin-${VERSION}-linux

**Windows .zip and setup.exe:**

	unzip fartcoin-${VERSION}-win-gitian.zip -d fartcoin-${VERSION}-win
	mv fartcoin-${VERSION}-win/fartcoin-*-setup.exe .
	zip -r fartcoin-${VERSION}-win.zip fartcoin-${VERSION}-win
	rm -rf fartcoin-${VERSION}-win

**Perform Mac build:**

  OSX binaries are created by Gavin Andresen on a 64-bit, OSX 10.6 machine.

	./autogen.sh
        SDK=$(xcode-select --print-path)/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk
        CXXFLAGS="-mmacosx-version-min=10.6 -isysroot $SDK" ./configure --enable-upnp-default
	make
	export QTDIR=/opt/local/share/qt4  # needed to find translations/qt_*.qm files
	T=$(contrib/qt_translations.py $QTDIR/translations src/qt/locale)
        export CODESIGNARGS='--keychain ...path_to_keychain --sign "Developer ID Application: FARTCOIN FOUNDATION, INC., THE"'
	python2.7 contrib/macdeploy/macdeployqtplus Fartcoin-Qt.app -sign -add-qt-tr $T -dmg -fancy contrib/macdeploy/fancy.plist

 Build output expected: Fartcoin-Qt.dmg

###Next steps:

* Code-sign Windows -setup.exe (in a Windows virtual machine using signtool)
 Note: only Gavin has the code-signing keys currently.

* upload builds to SourceForge

* create SHA256SUMS for builds, and PGP-sign it

* update fartcoin.com version
  make sure all OS download links go to the right versions
  
* update forum version

* update wiki download links

* update wiki changelog: [https://en.bitcoin.it/wiki/Changelog](https://en.bitcoin.it/wiki/Changelog)

Commit your signature to gitian.sigs:

	pushd gitian.sigs
	git add ${VERSION}-linux/${SIGNER}
	git add ${VERSION}-win/${SIGNER}
	git add ${VERSION}-osx/${SIGNER}
	git commit -a
	git push  # Assuming you can push to the gitian.sigs tree
	popd

-------------------------------------------------------------------------

### After 3 or more people have gitian-built and their results match:

From a directory containing fartcoin source, gitian.sigs and gitian zips

	export VERSION=(new version, e.g. 0.8.0)
	mkdir fartcoin-${VERSION}-linux-gitian
	pushd fartcoin-${VERSION}-linux-gitian
	unzip ../fartcoin-${VERSION}-linux-gitian.zip
	mkdir gitian
	cp ../fartcoin/contrib/gitian-downloader/*.pgp ./gitian/
	for signer in $(ls ../gitian.sigs/${VERSION}/); do
	 cp ../gitian.sigs/${VERSION}/${signer}/fartcoin-build.assert ./gitian/${signer}-build.assert
	 cp ../gitian.sigs/${VERSION}/${signer}/fartcoin-build.assert.sig ./gitian/${signer}-build.assert.sig
	done
	zip -r fartcoin-${VERSION}-linux-gitian.zip *
	cp fartcoin-${VERSION}-linux-gitian.zip ../
	popd
	mkdir fartcoin-${VERSION}-win-gitian
	pushd fartcoin-${VERSION}-win-gitian
	unzip ../fartcoin-${VERSION}-win-gitian.zip
	mkdir gitian
	cp ../fartcoin/contrib/gitian-downloader/*.pgp ./gitian/
	for signer in $(ls ../gitian.sigs/${VERSION}-win/); do
	 cp ../gitian.sigs/${VERSION}-win/${signer}/fartcoin-build.assert ./gitian/${signer}-build.assert
	 cp ../gitian.sigs/${VERSION}-win/${signer}/fartcoin-build.assert.sig ./gitian/${signer}-build.assert.sig
	done
	zip -r fartcoin-${VERSION}-win-gitian.zip *
	cp fartcoin-${VERSION}-win-gitian.zip ../
	popd

    - Code-sign MacOSX .dmg

  Note: only Gavin has the code-signing keys currently.

- Create `SHA256SUMS.asc` for builds, and PGP-sign it. This is done manually.
  Include all the files to be uploaded. The file has `sha256sum` format with a
  simple header at the top:

```
Hash: SHA256

0060f7d38b98113ab912d4c184000291d7f026eaf77ca5830deec15059678f54  bitcoin-x.y.z-linux.tar.gz
...
```

- Upload gitian zips to SourceForge

- Announce the release:

  - Add the release to fartcoin.com

  - Announce on reddit /r/fartcoin, /r/fartcoindev

  - Release sticky on discuss fartcoin: https://discuss.fartcoin.com/categories/announcements

- Celebrate 
