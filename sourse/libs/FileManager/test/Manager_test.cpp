#include <gtest/gtest.h>
#include "../../complex/include/complex.h"
#include <vector>
#include <fstream>


template<typename t>
void EQUAL_VEC (t* test, t* ex, size_t size)
{
    int num = 0;
    for (int i = 0; i<=size; i++)
    {
        if (test[i] == ex[i])
        {
            num+=1;
        }
    }
    assert(num == size);
}

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
std::vector<t> ReadSignal(const std::string& fileName)
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

TEST(VectorTests, WorkingDouble) {
    ComplexDouble a(1.57,1.2);
    std::vector<ComplexDouble> sam1(100000,a);
    SaveSignal(sam1,"test.bin");
    std::vector<ComplexDouble> sam2 = ReadSignal<ComplexDouble>("test.bin");
    ComplexDouble * test = &sam1[0];
    ComplexDouble * ex = &sam2[0];
    EQUAL_VEC(test,ex,sam1.size());
}

TEST(VectorTests, WorkingFloat) {
    ComplexFloat a(1,1);
    std::vector<ComplexFloat> sam1(1000,a);
    SaveSignal(sam1,"test.bin");
    std::vector<ComplexFloat> sam2 = ReadSignal<ComplexFloat>("test.bin");
    ComplexFloat * test = &sam1[0];
    ComplexFloat * ex = &sam2[0];
    EQUAL_VEC(test,ex,sam1.size());
}
TEST(VectorTests, WorkingInt) {
    ComplexInt a(1,1);
    std::vector<ComplexInt> sam1(100000,a);
    SaveSignal(sam1,"test.bin");
    std::vector<ComplexInt> sam2 = ReadSignal<ComplexInt>("test.bin");
    ComplexInt * test = &sam1[0];
    ComplexInt * ex = &sam2[0];
    EQUAL_VEC(test,ex,sam1.size());
}

TEST(VectorTests, WorkingShort) {
    ComplexShort a(1,1);
    std::vector<ComplexShort> sam1(1000,a);
    SaveSignal(sam1,"test.bin");
    std::vector<ComplexShort> sam2 = ReadSignal<ComplexShort>("test.bin");
    ComplexShort * test = &sam1[0];
    ComplexShort * ex = &sam2[0];
    EQUAL_VEC(test,ex,sam1.size());
}
TEST(VectorTests, Convert) {
    ComplexInt a(1,1);
    std::vector<ComplexInt> vec1(3,a);
    ComplexFloat b(1,1);
    std::vector<ComplexFloat> ex(3,b);
    std::vector<ComplexFloat> vec3(3);
    ComplexInt *in = &vec1[0];
    ComplexFloat *out = &vec3[0];
    ComplexFloat *ex1 = &ex[0];
    ConvertSignal(in,vec1.size(),out);
    EQUAL_VEC(ex1,out,ex.size());
}
