#include <gtest/gtest.h>
#include "complex.h"
#include <vector>

template<typename t>
void EQUAL_VEC (std::vector<t> Vec1, std::vector<t> Vec2)
{
    int size = Vec1.size();
    int ex = 0;
    for (int i = 0; i<=size; i++)
    {
        if (Vec1[i].GetRez() == Vec2[i].GetRez() & Vec1[i].GetImz() == Vec2[i].GetImz())
        {
            ex+=1;
        }
    }
    EXPECT_DOUBLE_EQ(ex,size);
}

/**
 * Тестирование безусловного конструктора
 */
TEST(ComplexTests, CreatingDouble) {
    ComplexDouble tes;
    EXPECT_DOUBLE_EQ(tes.GetRez(),0);
    EXPECT_DOUBLE_EQ(tes.GetImz(),0);
}
TEST(ComplexTests, CreatingInt)
{
    ComplexInt tes;
    EXPECT_DOUBLE_EQ(tes.GetRez(),0);
    EXPECT_DOUBLE_EQ(tes.GetImz(),0);
}
TEST(ComplexTests, CreatingShort) {
    ComplexShort tes;
    EXPECT_DOUBLE_EQ(tes.GetRez(),0);
    EXPECT_DOUBLE_EQ(tes.GetImz(),0);
}
TEST(ComplexTests, CreatingFloat)
{
    ComplexFloat tes;
    EXPECT_DOUBLE_EQ(tes.GetRez(),0);
    EXPECT_DOUBLE_EQ(tes.GetImz(),0);
}
/**
 * Тестирование условного конструктора
 */
TEST(ComplexTests, Creating_ConDouble)
{
    ComplexDouble tes(5.37,1.071);
    EXPECT_DOUBLE_EQ(tes.GetRez(),5.37);
    EXPECT_DOUBLE_EQ(tes.GetImz(),1.071);
}
TEST(ComplexTests, Creating_ConInt)
{
    ComplexInt tes(5,1);
    EXPECT_DOUBLE_EQ(tes.GetRez(),5);
    EXPECT_DOUBLE_EQ(tes.GetImz(),1);
}
TEST(ComplexTests, Creating_ConShort)
{
    ComplexShort tes(5,1);
    EXPECT_DOUBLE_EQ(tes.GetRez(),5);
    EXPECT_DOUBLE_EQ(tes.GetImz(),1);
}
TEST(ComplexTests, Creating_ConFloat)
{
    ComplexFloat tes(5,1);
    EXPECT_DOUBLE_EQ(tes.GetRez(),5);
    EXPECT_DOUBLE_EQ(tes.GetImz(),1);
}
/**
 * Тестирование перегруженного оператора сложения
 */
TEST(ComplexTests, Compl_AddDouble)
{
    ComplexDouble tes1(5.25,1.05);
    ComplexDouble tes2(5.1,1.15);
    ComplexDouble tes;
    ComplexDouble ex;
    ex.SetRez(tes1.GetRez() + tes2.GetRez());
    ex.SetImz(tes1.GetImz() + tes2.GetImz());
    tes = tes1+tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_AddInt)
{
    ComplexInt tes1(5,1);
    ComplexInt tes2(5,1);
    ComplexInt tes;
    ComplexInt ex;
    ex.SetRez(tes1.GetRez() + tes2.GetRez());
    ex.SetImz(tes1.GetImz() + tes2.GetImz());
    tes = tes1+tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_AddShort)
{
    ComplexShort tes1(5,1);
    ComplexShort tes2(5,1);
    ComplexShort tes;
    ComplexShort ex;
    ex.SetRez(tes1.GetRez() + tes2.GetRez());
    ex.SetImz(tes1.GetImz() + tes2.GetImz());
    tes = tes1+tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_AddFloat)
{
    ComplexFloat tes1(5.37,1.89);
    ComplexFloat tes2(5.34,1.45);
    ComplexFloat tes;
    ComplexFloat ex;
    ex.SetRez(tes1.GetRez() + tes2.GetRez());
    ex.SetImz(tes1.GetImz() + tes2.GetImz());
    tes = tes1+tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
/**
 * Тестирование перегруженного оператора вычитания
 */
TEST(ComplexTests, Compl_SubDouble)
{
    ComplexDouble tes1(7.87,2.25);
    ComplexDouble tes2(5.45,1.45);
    ComplexDouble tes;
    ComplexDouble ex;
    ex.SetRez(tes1.GetRez() - tes2.GetRez());
    ex.SetImz(tes1.GetImz() - tes2.GetImz());
    tes = tes1-tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_SubInt)
{
    ComplexInt tes1(7,2);
    ComplexInt tes2(5,1);
    ComplexInt tes;
    ComplexInt ex;
    ex.SetRez(tes1.GetRez() - tes2.GetRez());
    ex.SetImz(tes1.GetImz() - tes2.GetImz());
    tes = tes1-tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_SubShort)
{
    ComplexShort tes1(7,2);
    ComplexShort tes2(5,1);
    ComplexShort tes;
    ComplexShort ex;
    ex.SetRez(tes1.GetRez() - tes2.GetRez());
    ex.SetImz(tes1.GetImz() - tes2.GetImz());
    tes = tes1-tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_SubFloat)
{
    ComplexFloat tes1(7.98,2.27);
    ComplexFloat tes2(5.56,1.45);
    ComplexFloat tes;
    ComplexFloat ex;
    ex.SetRez(tes1.GetRez() - tes2.GetRez());
    ex.SetImz(tes1.GetImz() - tes2.GetImz());
    tes = tes1-tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
/**
 * Тестирование перегруженного оператора умножения
 */
TEST(ComplexTests, Compl_MulDouble)
{
    ComplexDouble tes1(2.032,3.058);
    ComplexDouble tes2(-1.58,1.52);
    ComplexDouble tes;
    ComplexDouble ex;
    ex.SetRez(tes1.GetRez()*tes2.GetRez() - tes1.GetImz()*tes2.GetImz());
    ex.SetImz(tes1.GetRez()*tes2.GetImz() + tes1.GetImz()*tes2.GetRez());
    tes = tes1*tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_MulInt)
{
    ComplexInt tes1(2,3);
    ComplexInt tes2(-1,1);
    ComplexInt tes;
    ComplexInt ex;
    ex.SetRez(tes1.GetRez()*tes2.GetRez() - tes1.GetImz()*tes2.GetImz());
    ex.SetImz(tes1.GetRez()*tes2.GetImz() + tes1.GetImz()*tes2.GetRez());
    tes = tes1*tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_MulShort)
{
    ComplexShort tes1(2,3);
    ComplexShort tes2(-1,1);
    ComplexShort tes;
    ComplexShort ex;
    ex.SetRez(tes1.GetRez()*tes2.GetRez() - tes1.GetImz()*tes2.GetImz());
    ex.SetImz(tes1.GetRez()*tes2.GetImz() + tes1.GetImz()*tes2.GetRez());
    tes = tes1*tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_MulFloat)
{
    ComplexFloat tes1(2.23,3.34);
    ComplexFloat tes2(-1.25,1.52);
    ComplexFloat tes;
    ComplexFloat ex;
    ex.SetRez(tes1.GetRez()*tes2.GetRez() - tes1.GetImz()*tes2.GetImz());
    ex.SetImz(tes1.GetRez()*tes2.GetImz() + tes1.GetImz()*tes2.GetRez());
    tes = tes1*tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
/**
 * Тестирование перегруженного оператора деления
 */
TEST(ComplexTests, Compl_DivDouble)
{
    ComplexDouble tes1(-2.35,1.78);
    ComplexDouble tes2(1.1,-1.27);
    ComplexDouble ex;
    ComplexDouble tes;
    ex.SetRez((tes1.GetRez()*tes2.GetRez() + tes1.GetImz()*tes2.GetImz())/(tes2.GetRez()*tes2.GetRez()+tes2.GetImz()*tes2.GetImz()));
    ex.SetImz((tes1.GetImz()*tes2.GetRez() - tes1.GetRez()*tes2.GetImz())/(tes2.GetRez()*tes2.GetRez()+tes2.GetImz()*tes2.GetImz()));
    tes = tes1/tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_DivInt)
{
    ComplexInt tes1(-2,1);
    ComplexInt tes2(1,-1);
    ComplexInt ex;
    ComplexInt tes;
    ex.SetRez((tes1.GetRez()*tes2.GetRez() + tes1.GetImz()*tes2.GetImz())/(tes2.GetRez()*tes2.GetRez()+tes2.GetImz()*tes2.GetImz()));
    ex.SetImz((tes1.GetImz()*tes2.GetRez() - tes1.GetRez()*tes2.GetImz())/(tes2.GetRez()*tes2.GetRez()+tes2.GetImz()*tes2.GetImz()));
    tes = tes1/tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_DivShort)
{
    ComplexShort tes1(-2,1);
    ComplexShort tes2(1,-1);
    ComplexShort ex;
    ComplexShort tes;
    ex.SetRez((tes1.GetRez()*tes2.GetRez() + tes1.GetImz()*tes2.GetImz())/(tes2.GetRez()*tes2.GetRez()+tes2.GetImz()*tes2.GetImz()));
    ex.SetImz((tes1.GetImz()*tes2.GetRez() - tes1.GetRez()*tes2.GetImz())/(tes2.GetRez()*tes2.GetRez()+tes2.GetImz()*tes2.GetImz()));
    tes = tes1/tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_DivFloat)
{
    ComplexFloat tes1(-2.22,1.007);
    ComplexFloat tes2(1.56,-1.32);
    ComplexFloat ex;
    ComplexFloat tes;
    ex.SetRez((tes1.GetRez()*tes2.GetRez() + tes1.GetImz()*tes2.GetImz())/(tes2.GetRez()*tes2.GetRez()+tes2.GetImz()*tes2.GetImz()));
    ex.SetImz((tes1.GetImz()*tes2.GetRez() - tes1.GetRez()*tes2.GetImz())/(tes2.GetRez()*tes2.GetRez()+tes2.GetImz()*tes2.GetImz()));
    tes = tes1/tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
/**
 * Тестирование метода вычисления аргумента
 */
TEST(ComplexTests, Compl_ArgDouble)
{
    ComplexDouble tes1(5.78,7.64);
    double ex;
    double tes4;
    ex = atan(tes1.GetImz()/tes1.GetRez());
    if (tes1.GetRez() < 0 & tes1.GetImz() >=0)
    {
        ex = pi + ex;
    }
    if (tes1.GetRez()< 0 & tes1.GetImz() < 0)
    {
        ex = ex - pi;
    }
    tes4 = tes1.Arg();
    EXPECT_DOUBLE_EQ(tes4,ex);
}
TEST(ComplexTests, Compl_ArgInt)
{
    ComplexInt tes1(5,7);
    int ex;
    int tes4;
    ex = atan(tes1.GetImz()/tes1.GetRez());
    if (tes1.GetRez() < 0 & tes1.GetImz() >=0)
    {
        ex = pi + ex;
    }
    if (tes1.GetRez()< 0 & tes1.GetImz() < 0)
    {
        ex = ex - pi;
    }
    tes4 = tes1.Arg();
    EXPECT_DOUBLE_EQ(tes4,ex);
}
TEST(ComplexTests, Compl_ArgShort)
{
    ComplexShort tes1(5,7);
    short ex;
    short tes4;
    ex = atan(tes1.GetImz()/tes1.GetRez());
    if (tes1.GetRez() < 0 & tes1.GetImz() >=0)
    {
        ex = pi + ex;
    }
    if (tes1.GetRez()< 0 & tes1.GetImz() < 0)
    {
        ex = ex - pi;
    }
    tes4 = tes1.Arg();
    EXPECT_DOUBLE_EQ(tes4,ex);
}
TEST(ComplexTests, Compl_ArgFloat)
{
    ComplexFloat tes1(5.32,7.12);
    float ex;
    float tes4;
    ex = atan(tes1.GetImz()/tes1.GetRez());
    if (tes1.GetRez() < 0 & tes1.GetImz() >=0)
    {
        ex = pi + ex;
    }
    if (tes1.GetRez()< 0 & tes1.GetImz() < 0)
    {
        ex = ex - pi;
    }
    tes4 = tes1.Arg();
    EXPECT_DOUBLE_EQ(tes4,ex);
}
/**
 * Тестирование метода вычисления модуля
 */
TEST(ComplexTests, Compl_AbsDouble)
{
    ComplexDouble tes1(3.75,1.45);
    double tes4;
    double ex;
    ex = sqrt(tes1.GetRez()*tes1.GetRez()+tes1.GetImz()*tes1.GetImz());
    tes4 = tes1.Abs();
    EXPECT_DOUBLE_EQ(tes4,ex);
}
TEST(ComplexTests, Compl_AbsInt)
{
    ComplexDouble tes1(3,1);
    int tes4;
    int ex;
    ex = sqrt(tes1.GetRez()*tes1.GetRez()+tes1.GetImz()*tes1.GetImz());
    tes4 = tes1.Abs();
    EXPECT_DOUBLE_EQ(tes4,ex);
}
TEST(ComplexTests, Compl_AbsShort)
{
    ComplexShort tes1(3,1);
    short tes4;
    short ex;
    ex = sqrt(tes1.GetRez()*tes1.GetRez()+tes1.GetImz()*tes1.GetImz());
    tes4 = tes1.Abs();
    EXPECT_DOUBLE_EQ(tes4,ex);
}
TEST(ComplexTests, Compl_AbsFloat)
{
    ComplexFloat tes1(3.75,1.45);
    float tes4;
    float ex;
    ex = sqrt(tes1.GetRez()*tes1.GetRez()+tes1.GetImz()*tes1.GetImz());
    tes4 = tes1.Abs();
    EXPECT_DOUBLE_EQ(tes4,ex);
}
/**
 * Тестирование метода сопряжения
 */
TEST(ComplexTests, Compl_ConjDouble)
{
    ComplexDouble tes1(-2.32,1.12);
    ComplexDouble tes;
    ComplexDouble ex;
    ex.SetRez(tes1.GetRez());
    ex.SetImz(tes1.GetImz()*(-1));
    tes = tes1.Conj();
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_ConjInt)
{
    ComplexInt tes1(-2,1);
    ComplexInt tes;
    ComplexInt ex;
    ex.SetRez(tes1.GetRez());
    ex.SetImz(tes1.GetImz()*(-1));
    tes = tes1.Conj();
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_ConjShort)
{
    ComplexShort tes1(-2,1);
    ComplexShort tes;
    ComplexShort ex;
    ex.SetRez(tes1.GetRez());
    ex.SetImz(tes1.GetImz()*(-1));
    tes = tes1.Conj();
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_ConjFloat)
{
    ComplexFloat tes1(-2.78,1.15);
    ComplexFloat tes;
    ComplexFloat ex;
    ex.SetRez(tes1.GetRez());
    ex.SetImz(tes1.GetImz()*(-1));
    tes = tes1.Conj();
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
/**
 * Тестирование метода сопряженного умножения
 */
TEST(ComplexTests, Compl_ConjMpyDouble)
{
    ComplexDouble tes1(5.65,8.97);
    ComplexDouble tes2(4.12,1.12);
    ComplexDouble tes;
    ComplexDouble ex;
    ex = tes1*tes2;
    ex = ex.Conj();
    tes = tes.ConjMpy(tes1,tes2);
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_ConjMpyInt)
{
    ComplexInt tes1(4,1);
    ComplexInt tes2(45,7);
    ComplexInt tes;
    ComplexInt ex;
    ex = tes1*tes2;
    ex = ex.Conj();
    tes = tes.ConjMpy(tes1,tes2);
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_ConjMpyFloat)
{
    ComplexFloat tes1(4.978,5.981);
    ComplexFloat tes2(1.112,1.236);
    ComplexFloat tes;
    ComplexFloat ex;
    ex = tes1*tes2;
    ex = ex.Conj();
    tes = tes.ConjMpy(tes1,tes2);
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, Compl_ConjMpyShort)
{
    ComplexShort tes1(5,7);
    ComplexShort tes2(7,9);
    ComplexShort tes;
    ComplexShort ex;
    ex = tes1*tes2;
    ex = ex.Conj();
    tes = tes.ConjMpy(tes1,tes2);
    EXPECT_DOUBLE_EQ(tes.GetRez(),ex.GetRez());
    EXPECT_DOUBLE_EQ(tes.GetImz(),ex.GetImz());
}
TEST(ComplexTests, EXUA) {
    ComplexDouble tes(5,1);
    ComplexDouble tes2(0,0);
    tes = tes2;
    EXPECT_DOUBLE_EQ(tes.GetRez(),0);
    EXPECT_DOUBLE_EQ(tes.GetImz(),0);
}

TEST(ComplexTests, BeqF) {
    ComplexDouble tes(5,1);
    ComplexDouble tes2(0,0);
    assert(!(tes == tes2));
}
TEST(ComplexTests, BeqT) {
    ComplexDouble tes(5,1);
    ComplexDouble tes2(5,1);
    assert(tes == tes2);
}
TEST(ComplexTests, DivDO) {
    ComplexDouble tes(5,5);
    ComplexDouble tes2(1,1);
    double a = 5;
    tes = tes/a;
    assert(tes == tes2);
}
