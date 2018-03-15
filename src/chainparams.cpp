// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2013-2014 The Dogecoin developers
// Copyright (c)      2014 The Inutoshi developers
// Copyright (c)      2018 The Fartcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;



//
// Main network
//

unsigned int pnSeed[] =
{
   0x149d8418, 0xb6a15c56, 0x7ebda053
};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
	pchMessageStart[0] = 0xf2;
        pchMessageStart[1] = 0xca;
        pchMessageStart[2] = 0xb4;
        pchMessageStart[3] = 0xdb;
	

        vAlertPubKey = ParseHex("04ec41caf04e7863171bfb4ecfa6aca2e46c9cd8eeb13366a25fb40864614b2c92028e575d17d41b83d3c8c8c1b23232a564b5ebd586eaf9747dc0e00b4736d645");
        nDefaultPort = 9339;
        nRPCPort = 9338;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        
        // Genesis Fart:
	// CBlock( 
        //           hash=30ab0676db11ce93d84e1ed42699cda2f8c118146e1eb42e51acc1f822f09da5,
	// input=010...05243169a4f3baedd833f63c51d4f7761e516fb1d222907421d672b3ab58f0712cbec755af0ff0f1e3da70500,        
	//            PoW=000000e3987d05a114ab713251169d7e6a8fb69c2a19a65c1304225820076170, ver=1, 
	//  hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000,
	// hashMerkleRoot=12078fb53a2b671d420729221dfb16e561774f1dc5633f83ddae3b4f9a164352 
	// nTime=1517677771, nBits=1e0ffff0, nNonce=370493, vtx=1
	//        )
        // CTransaction(hash=12078fb53a2b671d420729221dfb16e561774f1dc5633f83ddae3b4f9a164352,
	// ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //     CTxIn(COutPoint(0000, 4294967295),
	// coinbase 04ffff001d01041b476f6f64627965204d6f6f6e6d656e202d20323031382046415254)
        //     CTxOut(nValue=100, scriptPubKey=04e5b299024f1ddc80fc2d0113b684)
        //  vMerkleTree: 12078fb53a2b671d420729221dfb16e561774f1dc5633f83ddae3b4f9a164352 

        const char* pszTimestamp = "Goodbye Moonmen - 2018 FART";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 100 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04e5b299024f1ddc80fc2d0113b684cd6ccf1d65079062646f24c16e4d4da86d0179fafd1952262b15ba6096ebe21c14d7643373c8efdd2842e3bd2b76fe1fab8a") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1517677771;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 370493;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x30ab0676db11ce93d84e1ed42699cda2f8c118146e1eb42e51acc1f822f09da5"));
        assert(genesis.hashMerkleRoot == uint256("0x12078fb53a2b671d420729221dfb16e561774f1dc5633f83ddae3b4f9a164352"));

	vSeeds.push_back(CDNSSeedData("omariskandarani.com", "dnsseed.omariskandarani.com"));

        // Workaround for Boost not being quite compatible with C++11;
        std::vector<unsigned char> pka = list_of(35); //Fartcoin address starts with F
        base58Prefixes[PUBKEY_ADDRESS] = pka;        
	std::vector<unsigned char> sca = list_of(5);
        base58Prefixes[SCRIPT_ADDRESS] = sca;        
        std::vector<unsigned char> sk  = list_of(176);
        base58Prefixes[SECRET_KEY]     = sk;      
        std::vector<unsigned char> epk = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_PUBLIC_KEY] = epk;        
        std::vector<unsigned char> esk = list_of(0x04)(0x88)(0xAD)(0xE4);
        base58Prefixes[EXT_SECRET_KEY] = esk;
        


        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const uint64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v3)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
	pchMessageStart[0] = 0xf2;
        pchMessageStart[1] = 0xca;
        pchMessageStart[2] = 0xb4;
        pchMessageStart[3] = 0xdb;
        vAlertPubKey = ParseHex("04a494b9e29eda5e93a42615cabfc3badbb900a672c3eb2b630924173538a057768520cb0c05961753e6c2be771956c80a48627b0571dcbf5d59f6f9895ee60b8e");
        nDefaultPort = 19339;
        nRPCPort = 19338;
        strDataDir = "testnet3";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1517677746;
        genesis.nNonce = 192177;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0xd01f76532b71814710dade3c232590b3da00f3087cdb9a57b7fa19b8b9bde492"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("testfartomariskandarani.com", "testnet.omariskandarani.com"));


        // Boost sucks, and should not be used. Workaround for Boost not being compatible with C++11;
        
        std::vector<unsigned char> pka = list_of(95);
        base58Prefixes[PUBKEY_ADDRESS] = pka;
        std::vector<unsigned char> sca = list_of(196);
        base58Prefixes[SCRIPT_ADDRESS] = sca;
        std::vector<unsigned char> sk  = list_of(239);
        base58Prefixes[SECRET_KEY]     = sk;
        std::vector<unsigned char> epk = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_PUBLIC_KEY] = epk;
        std::vector<unsigned char> esk = list_of(0x04)(0x35)(0x83)(0x94);
        base58Prefixes[EXT_SECRET_KEY] = esk;


    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
	pchMessageStart[0] = 0xf2;
        pchMessageStart[1] = 0xca;
        pchMessageStart[2] = 0xb4;
        pchMessageStart[3] = 0xdb;
        nSubsidyHalvingInterval = 20;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        genesis.nTime = 1517777777;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 377778;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 19337;
        strDataDir = "regtest";
        assert(hashGenesisBlock == uint256("0x004297a2851977b5726d0cd8b7f82d29b62a5bd8ae898074458122e4f2c4c732"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual bool SimplifiedRewards() const { return true; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
