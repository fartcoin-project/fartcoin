#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.fartcoincore/fartcoind.pid file instead
fartcoin_pid=$(<~/.fartcoincore/testnet3/fartcoind.pid)
sudo gdb -batch -ex "source debug.gdb" fartcoind ${fartcoin_pid}
