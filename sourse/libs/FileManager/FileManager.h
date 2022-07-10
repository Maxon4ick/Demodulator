#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "../complex/include/complex.h"
#include <vector>
#include <fstream>

namespace FileManager
{
template<typename t>
void saveSignal(const std::vector<t>& savedSignal,const std::string& fileName)
{
    std::ofstream fout;
    const uint32_t len= savedSignal.size();
    fout.open(fileName,std::ios::trunc|std::ios::binary);
    fout.write(reinterpret_cast<char *>(&savedSignal),(len*sizeof(float)));
    fout.close();
}
template<typename T>
std::vector<T> readSignal(const std::string& fileName)
{
    std::ifstream fin;
    fin.open(fileName,std::ios::binary);
    fin.seekg(0,fin.end);
    uint32_t actualLength = fin.tellg() / sizeof(T);
    std::vector<T> out(actualLength);
    fin.read(reinterpret_cast<char *>(&out), actualLength * sizeof(T));
    fin.close();
    return out;

}
template<typename t>
std::vector<ComplexFloat> convertSignal( const std::vector<t>& in,size_t signal_size)
{
    std::vector<ComplexFloat> out(signal_size);
    for (int i =0; i < signal_size; i++)
    {
        out[i] = static_cast<ComplexFloat>( in[i]);
    }

    return out;

}
};
#endif // FILEMANAGER_H
