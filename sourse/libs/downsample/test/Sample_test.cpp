#include <gtest/gtest.h>
#include "../../complex/include/complex.h"
#include <vector>
#include <fstream>

std::vector<float> downSample(std::vector<float> &in, float &sample)
{
    std::vector<float> out((short)(in.size()/sample));
    float * p_first = &in[0];
    float * p_end =  p_first+in.size();
    float * p_out =  &out[0];
    short k = (short)sample;
    for (; p_first<p_end; p_first += k)
    {
        *p_out = *p_first;
        p_out++;

    }
    return out;
}
TEST(VectorTests, WorkingIn) {
    std::vector<float> in(10,1);
    float sample = 2;
    std::vector<float> out = downSample(in,sample);
    std::vector<float> ex(5,1);
    assert(out == ex);
}
TEST(VectorTests, WorkingDo) {
    std::vector<float> in(10,1);
    float sample = 3;
    std::vector<float> out = downSample(in,sample);
    std::vector<float> ex(3,1);
    assert(out == ex);
}
