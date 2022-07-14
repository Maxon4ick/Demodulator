#include <gtest/gtest.h>
#include "../MyVec.h"
#include <vector>

template<typename t>
void EQUAL_VEC ( t*test, const t*ex,int size)
{
    t* test_end = test+size;
    int sum  = 0;
    for (; test<test_end; test++)
    {
        if (*test == *ex)
        {
            sum+=1;
        }
        ex++;
    }
    assert(sum==size);;
}

TEST(VectorTestsSizeInt, CreatingZero) {
    MyVector<int> test;
    std::vector<int> ex_vec;
    assert(test.GetSize() == ex_vec.size());
}

TEST(VectorTestsSizeInt, CreatingCH) {
    MyVector<int> test(10);
    std::vector<int> ex_vec(10);
    assert(test.GetSize() == ex_vec.size());
}

TEST(VectorTestsSizeDouble, CreatingZero) {
    MyVector<double> test;
    std::vector<double> ex_vec;
    assert(test.GetSize() == ex_vec.size());
}

TEST(VectorTestsSizeShort, CreatingZero) {
    MyVector<short> test;
    std::vector<short> ex_vec;
    assert(test.GetSize() == ex_vec.size());
}

TEST(VectorTestsSizeShort, CreatingCH) {
    MyVector<short> test(10);
    std::vector<short> ex_vec(10);
    assert(test.GetSize() == ex_vec.size());
}

TEST(VectorTestsSizeFloat, CreatingZero) {
    MyVector<float> test;
    std::vector<float> ex_vec;
    assert(test.GetSize() == ex_vec.size());
}

TEST(VectorTestsSizeFloat, CreatingCH) {
    MyVector<float> test(10);
    std::vector<float> ex_vec(10);
    assert(test.GetSize() == ex_vec.size());
}
TEST(VectorTestsSizeDouble, CreatingCH) {
    MyVector<double> test(10);
    std::vector<double> ex_vec(10);
    assert(test.GetSize() == ex_vec.size());
}
TEST(VectorTestsInt, Creating) {
    MyVector<int> test(10,1);
    std::vector<int> ex_vec(10,1);
    int*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsDouble, Creating) {
    MyVector<double> test(10,2.5);
    std::vector<double> ex_vec(10,2.5);
    double*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsShort, Creating) {
    MyVector<short> test(10,2);
    std::vector<short> ex_vec(10,2);
    short*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsFloat, Creating) {
    MyVector<float> test(10,2.5);
    std::vector<float> ex_vec(10,2.5);
    float*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsInt, PopBack) {
    MyVector<int> test(10,1);
    std::vector<int> ex_vec(10,1);
    test.PopBack();
    ex_vec.pop_back();
    int*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsDouble, PopBack) {
    MyVector<double> test(10,1);
    std::vector<double> ex_vec(10,1);
    test.PopBack();
    ex_vec.pop_back();
    double*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsShort, PopBack) {
    MyVector<short> test(10,1);
    std::vector<short> ex_vec(10,1);
    test.PopBack();
    ex_vec.pop_back();
    short*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsFloat, PopBack) {
    MyVector<float> test(10,1);
    std::vector<float> ex_vec(10,1);
    test.PopBack();
    ex_vec.pop_back();
    float*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsInt, PushBack) {
    MyVector<int> test(10,1);
    std::vector<int> ex_vec(10,1);
    test.PushBack(2);
    ex_vec.push_back(2);
    int*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsDouble, PushBack) {
    MyVector<double> test(10,1);
    std::vector<double> ex_vec(10,1);
    test.PushBack(2);
    ex_vec.push_back(2);
    double*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsShort, PushBack) {
    MyVector<short> test(10,1);
    std::vector<short> ex_vec(10,1);
    test.PushBack(2);
    ex_vec.push_back(2);
    short*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsFloat, PushBack) {
    MyVector<float> test(10,1);
    std::vector<float> ex_vec(10,1);
    test.PushBack(2);
    ex_vec.push_back(2);
    float*ex = &ex_vec[0];
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsInt, Copy) {
    MyVector<int> test(10,1);
    MyVector<int> ex_vec(10);
    ex_vec = test.Copy();
    int*ex = ex_vec.GetArr();
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsDouble, Copy) {
    MyVector<double> test(10,1);
    MyVector<double> ex_vec(10);
    ex_vec = test.Copy();
    double*ex = ex_vec.GetArr();
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsShort, Copy) {
    MyVector<short> test(10,1);
    MyVector<short> ex_vec(10);
    ex_vec = test.Copy();
    short*ex = ex_vec.GetArr();
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}

TEST(VectorTestsFloat, Copy) {
    MyVector<float> test(10,1);
    MyVector<float> ex_vec(10);
    ex_vec = test.Copy();
    float*ex = ex_vec.GetArr();
    EQUAL_VEC(test.GetArr(),ex,test.GetSize());
}
