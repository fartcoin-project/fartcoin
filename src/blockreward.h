// Copyright (c) 2018-2019 The Fartcoin developer
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <iostream>
#include <cstdint>
#include <cinttypes>

using namespace std;

template <class TblockValue>
class nHeightDivided {
    private:
        TblockValue firstValue, secondValue;
    public:
        nHeightDivided (TblockValue a, TblockValue b):
        firstValue(a), secondValue(b) { }
        TblockValue devideValue();
};

template <class TblockValue>
TblockValue nHeightDivided<TblockValue>::devideValue() {
    return (firstValue/secondValue);
}

template <class UblockValue, class VblockValue>
UblockValue SubsidyValue(UblockValue a, VblockValue b) {
    return (a / b);
}

/**************** Explanation of this BlockReward.h *************************
 *                                                                          *
 *          GetBlockSubsidy expects an int64_t to be returned.              *
 *     Because of this we can't make nSubsidy a Floating Point Number.      *
 *    We also can't devide two integers (i.e. 1/5) and return the result,   *
 *   1/5 = 0.2 which is not an int64_t but a float, double or long double.  *
 *                To fix this we need to use templates                      *
 *                                                                          *
 *     We create a template of the class Type    <class TblockValue>,       *
 *     The class nHeightDivided is to hold the two int64_t values.          *
 *  We create a <double> object to store both values as (TblockValue a & b) *
 *                                                                          *
 *  Now we create the double heightresult which sends our object (a & b)    *
 *      to devideValue() and returns the result to double heightresult.     *
 *                                                                          *
 *   To finish the Type Template we change the value of int64_t nSubsidy    *
 *       by sending    int64_t minsub   &   double heightresult   to        *
 *               template <class UblockValue, class VblockValue>            *
 *                                                                          *
 *          Where  int64_t = UblockValue & double = VblockValue             *
 *                                                                          *
 *   Now we use     UblockValue SubsidyValue(UblockValue a, VblockValue b)  *
 *          to return an int64_t to nSubsidy as the result of (a / b)       *
 *                               nSubsidy = SubsidyValue(int64_t / double)  *
 *                                                                          *
 *    GetBlockSubsidy in main.cpp does not work without blockreward.h       *
 *                                                                          *
 ////////////////////////////////////////////////////////////////////////////
 /////////////// GetBlockSubsidy from main.cpp  @ line: 1245 ////////////////
 ////////////////////////////////////////////////////////////////////////////
 //                                                                        //
 // GetBlockSubsidy(int nHeight, const Consensus::Params& consensusParams) //
 //    {                                                                   //
 //       int64_t nSubsidy = 1 * COIN;                                     //
 //       if(nHeight < 10000001)                                           //
 //        {                                                               //
 //            int64_t minsub = 1 * COIN;                                  //
 //            nHeightDivided <double> obj(nHeight, 10000000);             //
 //            double heightresult = obj.devideValue();                    //
 //            nSubsidy = SubsidyValue(minsub,heightresult);               //
 //        }                                                               //
 //        else                                                            //
 //        {                                                               //
 //            nSubsidy = 1 * COIN;                                        //
 //        }                                                               //
 //        return nSubsidy ;                                               //
 //    }                                                                   //
 ////////////////////////////////////////////////////////////////////////////
 *                                                                          *
 *  For most cryptocurrencies the GetBlockSubsidy is written as follows:    *
 *   where >>= is Bit-Shifting the "int64 nSubsidy" every 210000 blocks     *
 *                                                                          *
 *        int64 nSubsidy = 50 * COIN;                                       *
 *        nSubsidy >>= (nHeight / 210000);                                  *
 *                                                                          *
 *      What is Bit-Shifting?  "Halving"                                    *
 *      8-bit Binairy notation of integer 50     = 00110010                 *
 *                  1 Bit-Shift right >>= 25.0   = 00011001.0               *
 *                  2 Bit-Shift right >>= 12.5   = 00001100.10              *
 *                 3 Bit-Shift right >>=  6.25  = 00000110.010              *
 *                  4 Bit-Shift right >>=  3.125 = 00000011.0010            *
 *                        or                                                *
 *                  1 Bit-Shift left  <<= 100    = 01100100                 *
 *                                                                          *
 * Notice all the one's and zero's moving together.                         *
 * This results in Miners doubling their costs per COIN overnight.          *
 *                                                                          *
 * Fartcoin does not use Bit-Shifting in calculating the BlockValue         *
 * We use the following formula to calculate the Miners Block Reward:       *
 *                                                                          *
 *         " BlockReward = 10.000.000 / nHeight "                           *
 *                                                                          *
 * This is the resemblance of the formula y = 1/x                           *
 *            where x takes the reciprocal of each y                        *
 *                                                                          *
 * For Fartcoin we can say:                                                 *
 *            BlockHeight x Reward = always 10.000.000                      *
 *                                                                          *
 * With 1 Block per minute we get approx. 500 000 blocks per year           *
 *                                                                          *
 *             At blockheight    500.000 (+/-year 2020) reward = 20         *
 *             At blockheight  1.000.000 (+/-year 2021) reward = 10         *
 *             At blockheight 10.000.000 (+/-year 2039) reward =  1         *
 *                with the block rewards gradually decline                  *
 *                                                                          *
 * If we would Bit-Shift every 4 years we almost get the same end result.   *
 *            2020 the reward approximately equals 20                       *
 *            2024 the reward approximately equals 10                       *
 *            2028 the reward approximately equals  5                       *
 *            2032 the reward approximately equals  2.5                     *
 *            2036 the reward approximately equals  1.25                    *
 *            2040 the reward approximately equals  0.75                    *
 *                                                                          *
 ****************************************************************************
*/
