# ƒartcoin [ƒ⌂┌†] 
==========================
                                                                     
    
![ƒartcoin](https://image.ibb.co/gC3Wcx/bitcoin.png)


## What is ƒartcoin? 
Fartcoin is a cryptocurrency like Bitcoin, although it does not use SHA256 as its proof of work (POW). Taking development cues from Litecoin & Dogecoin, Fartcoin currently employs a simplified variant of scrypt.

# The websites, Fartcoin-project.com  MemesExchange.com, the BlockExplorer and the MiningPool are all servers that are build at home and are not 24/7 online. Please do not mine or trade Fartcoins, since you might lose them. 

This Project is currently Under Construction, this means that while you can download the Fartcoin-Core wallet and play around with it if interested. Keep in mind that this project is in Alpha state and thus the Blockchain might be rebuild / restarted at the official launch.



## Frequently Asked Questions

### How much ƒarticles will ever exist? 

With every block mined the reward drops, this means that instead of halving the reward suddenly every 200k blocks Fartcoin mining reward drops constant until block 10.000.000 where it stays at a constant 1 FART per block + miningfee.
```
BlockReward= 100.000.000*COIN / ( height / 10.000.000)
```
```
Calculate the exact reward per Block: 
https://github.com/fartcoin-project/Calculate_FART_Mining_Reward 
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
or you can trade Fartcoin at www.MemesExchange.com 

### Used ports
P2P 9339

### Mining Fartcoins

To Mine the coin you should connect to the Fartcoin mining pool

Download a miner: https://github.com/pooler/cpuminer/releases

Windows: run the miner in CMD

### minerd.exe -a scrypt -o stratum+tcp://fartcoin-project.com:4444  -O YOUR_FARTCOIN_ADDRESS:x

