#include <gtest/gtest.h>
#include "../../complex/include/complex.h"
#include <vector>
#include <fstream>
#include "../Demodulator.h"
using namespace std;
const char* fname = "test.bin";


template<typename t>
void EQUAL_VEC (std::vector<t> Vec1, std::vector<t> Vec2)
{
    int size = (Vec1.size()>Vec2.size()) ? Vec1.size() : Vec2.size();
    int ex = 0;
    for (int i = 0; i<=size; i++)
    {
        if (Vec1[i] == Vec2[i])
        {
            ex+=1;
        }
    }
    EXPECT_DOUBLE_EQ(ex,size);
}

std::vector<float> diffs(vector<float> &in)
{
    std::vector<float> out(in.size());
    float *p_in = &in[1];
    float *p_end = p_in + in.size();
    out[0] = 0;
    float *p_out = &out[1];
    for (; p_in<p_end; p_in++)
    {
        *p_out = *p_in-*(p_in-1);
        p_out++;
    }
    return out;
}

TEST(VectorTests, Creating) {
    vector<float> arr = {1,1,2,3,5,8,13,21};
    vector<float> a = diffs(arr);
    vector<float> ex = {0,0,1,1,2,3,5,8};
    assert(a==ex);
}
TEST(VectorTests, DemodAM) {
    ComplexFloat b(1,0);
    vector<ComplexFloat> insig(10,b);
    Demodulate *p = new DemodulatorAM;
    float fs = 5;
    vector<float> out = p->Demod(insig,fs);
    vector<float> ex(10,1);
    assert(out==ex);
}
TEST(VectorTests, DemodFM) {
    vector<ComplexFloat> insig(10);

    for (int i =0; i<insig.size(); i++)
    {
        ComplexFloat temp(i+1,i+1);
        insig[i] = temp;
    }
    Demodulate *p = new DemodulatorFM;
    float fs = 5;
    vector<float> out = p->Demod(insig,fs);
    vector<float> ex(10,0);
    assert(out==ex);
}
