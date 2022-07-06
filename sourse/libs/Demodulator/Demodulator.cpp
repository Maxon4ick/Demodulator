#include <vector>
#include "../complex/include/complex.h"
#include "../FileManager/FileManager.h"
#include "Demodulator.h"
std::vector<ComplexFloat> diffs(std::vector<ComplexFloat> &in)
{
    ComplexFloat des;
    std::vector<ComplexFloat> out(in.size(),des);
    ComplexFloat *p_in = &in[1];
    ComplexFloat *p_end = p_in + in.size();
    ComplexFloat *p_out = &out[1];
    for (; p_in<p_end; p_in++)
    {
        *p_out = *p_in-*(p_in-1);
        p_out++;
    }
    return out;
}

std::vector<float> DemodulatorAM::Demod(std::vector<ComplexFloat> &input,float &fs)
{
    std::vector<float> output(input.size());
    ComplexFloat *p_first = &input[0];
    ComplexFloat *p_end = p_first+input.size();
    float* p_out = &output[0];
    for (; p_first<p_end; p_first++)
    {
        *p_out = p_first->Abs();
        p_out++;
    }
    return output;
}



std::vector<float> DemodulatorFM::Demod(std::vector<ComplexFloat> &input,float &fs)
{
    std::vector<float> out(input.size());
    std::vector<ComplexFloat> delta = diffs(input);
    float* p_out = &out[0];
    ComplexFloat* p_delta = &delta[0];
    ComplexFloat* p_input = &input[0];
    ComplexFloat* p_end = p_input+input.size();
    for (; p_input<p_end; p_input++)
    {
        *p_out =fs*(p_delta->GetImz()*p_input->GetRez()-p_delta->GetRez()*p_input->GetImz())/(pow(p_input->GetRez(),2)+pow(p_input->GetImz(),2));
        p_delta++;
        p_out++;
    }
    return out;
}






