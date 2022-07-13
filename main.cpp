#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "sourse/libs/Demodulator/Demodulator.h"
#include "sourse/libs/complex/include/complex.h"
#include "sourse/libs/FileManager/FileManager.h"
#include "sourse/libs/Filter/Filter.h"
#include "sourse/libs/downsample/downsample.cpp"

int main()
{
    /*Ам демодулятор*/
    std::vector<ComplexInt> inAm= FileManager::readSignal<ComplexInt>("am_sound.dat");
    std::vector<ComplexFloat> tempAm = FileManager::convertSignal(inAm);
    float fsAm =12e3;
    Demodulate *demAm = new DemodulatorAM;
    std::vector<float> outAm = demAm->Demod(tempAm,fsAm);
    FileManager::saveSignal(outAm,"testAm.bin");

    /* Фм демодулятор*/
    std::vector<ComplexFloat> inFm = FileManager::readSignal<ComplexFloat>("file1EuropaPlus.bin");
    Demodulate *dem = new DemodulatorFM;
    float fsFm = 500*10e5;
    std::vector<float> outFm = dem->Demod(inFm,fsFm);
    FileManager::saveSignal(outFm,"testFm.bin");


    return 0;
}
