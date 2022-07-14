#ifndef FILTER_H
#define FILTER_H
#include <cstdlib>
#include <vector>
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

std::vector<t> FiltFilt(std::vector<t>&in)
{
    std::vector<t> out(in.size());
    for (int i = 0; i<in.size(); i++)
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
    return out;
}
private:
int ord;
};
#endif // FILTER_H
