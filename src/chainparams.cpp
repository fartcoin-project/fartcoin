// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2013-2014 The Dogecoin developers
// Copyright (c)      2014 The Inutoshi developers
// Copyright (c) 2018-2019 The Fartcoin developer
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
        pchMessageStart[0] = 0xdb;
        pchMessageStart[1] = 0xc4;
        pchMessageStart[2] = 0xb2;
        pchMessageStart[3] = 0xac;
	

        vAlertPubKey = ParseHex("045a092e454abc99958e369d9171e001bc4a0b5fb6ce68bf9818b1af53259f62c1498de495aed313be8a57d60fa86c30ab3176a556d75a8a2801c62bbbb782af7e");
        nDefaultPort = 13377;
        nRPCPort = 13378;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        
        // Genesis Fart:
	// CBlock( 
        //           hash=14feca84e18174ba0a1ca55be48f1a14a1dd0bef9be56a7e431da09b1854be75,
        // input=010...04f038a1401808f4fa585e82e04d90e580e80e5ab385ae4fef32bad391a42556fb1fd6e5cf0ff0f1e30840700,
        //            PoW=0000003dca2d4edf6b0f05cdaec2bed97e28c281aa68bb99f1881f03e44d936b, ver=1,
	//  hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000,
        // hashMerkleRoot=6f55421a39ad2bf3fee45a38abe5800e580ed9042ee885a54f8f8001148a034f
        // nTime=1550777777, nBits=1e0ffff0, nNonce=492592, vtx=1
	//        )
        // CTransaction(hash=6f55421a39ad2bf3fee45a38abe5800e580ed9042ee885a54f8f8001148a034f,
	// ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //     CTxIn(COutPoint(0000, 4294967295),
        // coinbase 04ffff001d0104114920676f742061204620666f7220617274)
        //     CTxOut(nValue=100, scriptPubKey=045a092e454abc99958e369d9171e0)
        //  vMerkleTree: 6f55421a39ad2bf3fee45a38abe5800e580ed9042ee885a54f8f8001148a034f

        const char* pszTimestamp = "I got a F for art";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 100 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("045a092e454abc99958e369d9171e001bc4a0b5fb6ce68bf9818b1af53259f62c1498de495aed313be8a57d60fa86c30ab3176a556d75a8a2801c62bbbb782af7e") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1550777777;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 492592;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x14feca84e18174ba0a1ca55be48f1a14a1dd0bef9be56a7e431da09b1854be75"));
        assert(genesis.hashMerkleRoot == uint256("0x6f55421a39ad2bf3fee45a38abe5800e580ed9042ee885a54f8f8001148a034f"));

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
        pchMessageStart[0] = 0xac;
        pchMessageStart[1] = 0xc4;
        pchMessageStart[2] = 0xb2;
        pchMessageStart[3] = 0xdb;
        vAlertPubKey = ParseHex("045a092e454abc99958e369d9171e001bc4a0b5fb6ce68bf9818b1af53259f62c1498de495aed313be8a57d60fa86c30ab3176a556d75a8a2801c62bbbb782af7e");
        nDefaultPort = 23377;
        nRPCPort = 23378;
        strDataDir = "testnet3";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1550777778;
        genesis.nNonce = 1565800;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x8db3d6e7e2ae596ea3336c6a8f37a7c6b144ab6628dbbd0aba35933ece717c4b"));

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
        pchMessageStart[0] = 0xac;
        pchMessageStart[1] = 0xb2;
        pchMessageStart[2] = 0xc4;
        pchMessageStart[3] = 0xdb;
        nSubsidyHalvingInterval = 20;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        genesis.nTime = 1550777779;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 2;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 37337;
        strDataDir = "regtest";
        assert(hashGenesisBlock == uint256("0xbb630961d19d81f66b0018d78c293cd2d788a46639d062bec7fec37e23743882"));

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
