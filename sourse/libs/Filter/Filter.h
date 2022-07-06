#ifndef FILTER_H
#define FILTER_H
#include <cstdlib>
template<class t>
class Filter
{
public:
Filter(int ord)
{
    this->ord = ord;

}
int GetOrd(){
    return this->ord;
}

void FiltFilt(size_t size,t*in,  t *out)
{
    for (int i = 0; i<size; i++)
    {
        for (int j = 0; j<ord; j++)
        {
            if (i<j)
            {
                out[i] =out[i]+ t();
            }
            else
            {
                out[i] = out[i]+ in[i-j]/ord;
            }
        }
    }
}
private:
int ord;
};
#endif // FILTER_H
