// Copyright (c) 2018 The Fartcoin developer

#include <iostream>
using namespace std;


// calculate double HeightDevided where nHeight is divided by total coins 
// We need a double because the awser is always between 0 and 1  
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

// Devide int_64t nSubsidy by double HeightDevided for the final blockreward
template <class UblockValue, class VblockValue>
UblockValue SubsidyValue(UblockValue a, VblockValue b) {
    return (a / b);
}

