#ifndef COMPLEX_H
#define COMPLEX_H
#include <cmath>



const double pi = acos(-1.0);

template<typename t>

class Complex {

public:
Complex()
{
    this->rez = 0;
    this->imz = 0;
}

Complex( t rez, t imz)
{
    this->rez = rez;
    this->imz = imz;
}

void SetRez(t rez)
{
    this->rez = rez;
}

void SetImz(t imz)
{
    this->imz = imz;
}

t GetRez()
{
    return this->rez;
}

t GetImz()
{
    return this->imz;
}


Complex & operator =(const Complex<t> & ohter)
{
    this->rez = ohter.rez;
    this->imz = ohter.imz;
    return *this;
}

Complex operator +(const Complex<t> & ohter)
{
    Complex temp;
    temp.rez = this->rez + ohter.rez;
    temp.imz = this->imz + ohter.imz;
    return temp;
}

Complex operator -(const Complex<t> & ohter)
{
    Complex temp;
    temp.rez = this->rez - ohter.rez;
    temp.imz = this->imz - ohter.imz;
    return temp;
}

Complex operator *(const Complex<t> & ohter)
{
    Complex temp;
    temp.rez = this->rez*ohter.rez - this->imz*ohter.imz;
    temp.imz = this->rez*ohter.imz + this->imz*ohter.rez;
    return temp;
}

Complex operator /(const Complex<t> & ohter)
{
    Complex temp;
    temp.rez = (this->rez*ohter.rez + this->imz*ohter.imz)/(ohter.rez*ohter.rez+ohter.imz*ohter.imz);
    temp.imz = (this->imz*ohter.rez - this->rez*ohter.imz)/(ohter.rez*ohter.rez+ohter.imz*ohter.imz);
    return temp;
}
Complex operator /(const t & ohter )
{
    Complex temp;
    temp.rez = this->rez/ohter;
    temp.imz = this->imz/ohter;
    return temp;
}
t Arg()
{
    t temp;
    temp = atan(imz/rez);
    if (rez < 0 & imz >=0)
    {
        temp = pi + temp;
    }
    if (rez< 0 & imz < 0)
    {
        temp = temp - pi;
    }
    return temp;
}

t Abs()
{
    t temp;
    temp = sqrt(rez*rez+imz*imz);
    return temp;
}

Complex Conj()
{
    Complex temp;
    temp.rez = rez;
    temp.imz = -imz;
    return temp;
}

Complex ConjMpy(const Complex C1, const Complex C2)
{
    Complex temp;
    temp.rez = C1.rez*C2.rez - C1.imz*C2.imz;
    temp.imz = C1.rez*C2.imz + C1.imz*C2.rez;
    temp = temp.Conj();
    return temp;
}
template<class t2>
explicit operator Complex<t2>() const
{
    t2 rez = static_cast<t2>(this->rez);
    t2 imz = static_cast<t2>(this->imz);
    return Complex<t2>(rez,imz);
}
bool operator == (const Complex & ohter)
{
    if (this->rez == ohter.rez && this->imz == ohter.imz) {return true;}
    else {return false;}

}
private:
t rez;

t imz;
};
using ComplexInt = Complex<int>;
using ComplexDouble = Complex<double>;
using ComplexFloat = Complex<float>;
using ComplexShort = Complex<short>;




#endif
