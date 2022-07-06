#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "../complex/include/complex.h"
#include <vector>
#include <fstream>

namespace FileManager
{
template<typename t>
void SaveSignal(const std::vector<t>& savedSignal,const std::string& fileName)
{
    std::ofstream fout;
    fout.open(fileName);
    for (int i =0; i <savedSignal.size(); i++)
    {
        fout.write((char*)&savedSignal[i],sizeof(t));
    }
    fout.close();
}
template<typename t>
std::vector<t> *ReadSignal(const std::string& fileName)
{
    std::vector<t> vecOut;
    std::ifstream fin;

    fin.open(fileName);
    t temp;
    while (!fin.eof())
    {
        fin.read((char*)&temp,sizeof(t));
        vecOut.push_back(temp);
    }
    fin.close();

    return vecOut;
}
template<typename t>
void ConvertSignal(const t* in,size_t signal_size, ComplexFloat *out)
{
    for (int i =0; i < signal_size; i++)
    {
        out[i] = (ComplexFloat) in[i];
    }
}
};
#endif // FILEMANAGER_H
