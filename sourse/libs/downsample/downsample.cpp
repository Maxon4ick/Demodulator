#include <vector>
#include <ios>
namespace downSample
{
std::vector<float> downSample(std::vector<float> &in,  uint32_t sample)
{
    size_t len = in.size()/sample;
    std::vector<float> out(len);
    uint32_t j = 0;
    for (int i = 0; i<len; i++)
    {
        out[i] = in[j];
        j+=sample;
    }
    return out;
}
}
