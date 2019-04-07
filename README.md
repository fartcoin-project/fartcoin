# ƒartcoin [ƒ⌂┌†] 
==========================
                                                                     
    
![ƒartcoin](https://avatars3.githubusercontent.com/u/35861169?s=400&u=a744bdd313b4b982995a35cd38c7700ac06f7c86&v=4)


## What is ƒartcoin? 
Fartcoin is a cryptocurrency like Bitcoin, although it does not use SHA256 but Fartcoin currently employs a simplified variant of scrypt as its proof of work (POW). We are taking development cues from Bitcoin, Litecoin & Dogecoin.
This is the first V1.0-Beta release of the fartcoin-core wallet. The Fartcoin blockchain is implemented in the dogecoin-1.14-beta-1 wallet and got a graphical upgrade to the "Space Police" theme.

# The website, Fartcoin-project.com  MemesExchange.com, the BlockExplorer and the MiningPool are all servers that are being build at home and are not 24/7 online.  Please do not mine or trade Fartcoins, since you might lose them. 

This Project is currently Under Construction, this means that while you can download the Fartcoin-Core wallet and play around with it if interested. Keep in mind that this project is under construction and thus the Blockchain might be rebuild / restarted multiple times before the official launch.


## Frequently Asked Questions

### How much ƒarticles will ever exist? 

The mining block reward is different from any other coin, since it is a reciprocal graph (y=1/x) it gradually decreases the mining reward every block. This means that instead of Bitcoin's bitshifting (halving the reward suddenly every 210k blocks) Fartcoin mining reward drops constant until block 10.000.000 where it stays at a constant 1 FART per block + miningfee.
```
BlockReward= 1*COIN / ( height / 10000000)
```

## Total Fartcoins at block 10,000,000 (20 Years) = 166,953,103.60862600
```
1 Block per minute = 43800 Blocks per Month = 525600 Blocks per Year 
* Month1 = 112.6 Million FartCoins 
* Month2 = 119.6 
* Month3 = 123.6
* Month4 = 126.5
* Month5 = 128.7
* Month6 = 130.6

* Year1  = 137.5 
* Year2  = 143.9
* Year3  = 147.9 
* Year4  = 151.3
* Year10 = 160.5

After block 10 million a fixed reward of 1 FART per block 
Year20 = 166,953,113 FartCoins = block 10512000 
```

### How to get ƒartcoins?
You can mine Fartcoins with your fartcoin-core wallet 
or you can trade Fartcoins at www.MemesExchange.com 

### Used ports
P2P 13377

### Mining Fartcoins

To mine the coin you should connect to the Fartcoin mining pool

Download a miner: https://github.com/pooler/cpuminer/releases

Windows: run the miner in CMD

### minerd.exe -a scrypt -o stratum+tcp://fartcoin-project.com:4444  -O YOUR_FARTCOIN_ADDRESS:x

