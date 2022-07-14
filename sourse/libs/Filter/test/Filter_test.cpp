#include <gtest/gtest.h>
#include "../../complex/include/complex.h"
#include <vector>
#include <fstream>
#include "../Filter.h"

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
template<class t>
void FiltFilt(int ord, size_t size,t *in,t*out )
{

    for (int i = 0; i<size; i++)
    {
        for (int j = 0; j<ord; j++)
        {
            if (i<j)
            {
                out[i] =out[i] + t();
            }
            else
            {
                out[i] =out[i]+in[i-j]/ord;
            }
        }
    }
}
TEST(FilterTests, CreateFloat) {
    Filter<float> a(4);
    assert(a.GetOrd() == 4);
}
TEST(FilterTests, CreateComFloat) {
    Filter<ComplexFloat> a(4);
    assert(a.GetOrd() == 4);
}

