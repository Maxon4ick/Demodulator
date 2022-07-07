#include <iostream>
#include <vector>
#include <cstdlib>
#include "sourse/libs/Demodulator/Demodulator.h"
#include "sourse/libs/complex/include/complex.h"
#include "sourse/libs/FileManager/FileManager.h"
#include "sourse/libs/Filter/Filter.h"


int main()
{
    /*Ам демодулятор*/
    std::vector<ComplexInt> inAm= FileManager::ReadSignal<ComplexInt>("am_sound.dat");
    std::vector<ComplexFloat> temp(inAm.size());
    ComplexFloat *tempPtr = &temp[0];
    ComplexInt *inPtr = &inAm[0];
    FileManager::ConvertSignal(inPtr,inAm.size(),tempPtr);
    float fsAm =8e3;
    Demodulate *demAm = new DemodulatorAM;
    std::vector<float> outAm = demAm->Demod(temp,fsAm);
    FileManager::SaveSignal(outAm,"testAm.bin");

    /* Фм демодулятор*/
    std::vector<ComplexFloat> inFm = FileManager::ReadSignal<ComplexFloat>("file1EuropaPlus.bin");
    Demodulate *dem = new DemodulatorFM;
    float fs = 500*10e5;
    std::vector<float> out = dem->Demod(inFm,fs);
    FileManager::SaveSignal(out,"testFm.bin");


    return 0;
}
