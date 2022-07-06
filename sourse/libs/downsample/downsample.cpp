#include <vector>

namespace downSample
{
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
}
