#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "sourse/libs/Demodulator/Demodulator.h"
#include "sourse/libs/complex/include/complex.h"
#include "sourse/libs/FileManager/FileManager.h"
#include "sourse/libs/Filter/Filter.h"
#include "sourse/libs/downsample/downsample.cpp"
#include "sourse/libs/myVec/MyVec.h"
#include "sourse/libs/list/List_lib.h"
#include "sourse/libs/matrix/Matrix.h"

int main()
{
    /*Ам демодулятор*/
    std::vector<ComplexInt> inAm= FileManager::readSignal<ComplexInt>("am_sound.dat");
    std::vector<ComplexFloat> tempAm = FileManager::convertSignal(inAm);
    float fsAm =12e3;
    Demodulate *demAm = new DemodulatorAM;
    std::vector<float> outAm = demAm->Demod(tempAm,fsAm);
    FileManager::saveWav(12e3,"testAm.wav",outAm);
    delete demAm;

    /* Фм демодулятор*/
    std::vector<ComplexFloat> inFm = FileManager::readSignal<ComplexFloat>("file1EuropaPlus.bin");
    Demodulate *demFm = new DemodulatorFM;
    float fsFm = 500*10e5;
    std::vector<float> tempFm = demFm->Demod(inFm,fsFm);
    Filter<float> sko(4);
    std::vector<float> filt = sko.FiltFilt(tempFm);
    std::vector<float> outFm = downSample::downSample(filt,10);
    FileManager::saveWav(54e3,"testFm.wav",outFm);
    delete demFm;

    return 0;
}

