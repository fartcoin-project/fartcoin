// Copyright (c)      2018 The Fartcoin developer
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include <iostream>

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


