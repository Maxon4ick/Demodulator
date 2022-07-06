#ifndef DEMOD_H
#define DEMOD_H
#include <vector>
#include "../complex/include/complex.h"

class Demodulate
{
public:
virtual std::vector<float> Demod(std::vector<ComplexFloat> &input,float &fs) = 0;
};
class DemodulatorAM : public Demodulate
{
public:
std::vector<float> Demod(std::vector<ComplexFloat> &input,float &fs) override;
};
class DemodulatorFM : public Demodulate
{
std::vector<float> Demod(std::vector<ComplexFloat> &input,float &fs) override;

};
std::vector<ComplexFloat> diffs(std::vector<ComplexFloat> &in);
#endif // DEMOD_H
