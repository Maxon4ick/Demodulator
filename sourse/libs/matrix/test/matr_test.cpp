#include <gtest/gtest.h>
#include "../Matrix.h"
template<typename t>
t ** CreateMatr(size_t a, size_t b, t data)
{
    t **m = new t *[a];
    m[0] = new t [a*b];
    for (size_t i=1; i != a; i++)
    {
        m[i] = m[i-1]+b;
    }
    for ( size_t i = 0; i < a; i++ )
        for ( size_t j = 0; j < b; j++ )
        {
            m[ i ][ j ] = data;

        }
    return m;
}
template<typename t>
void EQUAL_MAT ( t*test[],t*ex[],size_t rows, size_t cols)
{
    int si = rows+cols;
    int r = 0;
    for (int i =0; i!=rows; i++)
    {
        for (int j =0; j!=cols; j++)
        {
            if (test[i][j] == ex[i][j])
            {
                r++;
            }
        }
    }
    assert(r == si);
}

TEST(MatrixTestInt, CreatingDef) {
    size_t rows = 2;
    size_t cols = 2;
    MyMatrix<int> a(rows,cols);
    int ** test = a.GetFirst();
    int ** ex = CreateMatr(rows,cols,0);
    EQUAL_MAT(test,ex,rows,cols);
}
TEST(MatrixTestDo, CreatingDef) {
    size_t rows = 2;
    size_t cols = 2;
    double data = 0;
    MyMatrix<double> a(rows,cols);
    double ** test = a.GetFirst();
    double ** ex = CreateMatr(rows,cols,data);
    EQUAL_MAT(test,ex,rows,cols);
}
TEST(MatrixTestSH, CreatingDef) {
    size_t rows = 2;
    size_t cols = 2;
    short data = 0;
    MyMatrix<short> a(rows,cols);
    short ** test = a.GetFirst();
    short ** ex = CreateMatr(rows,cols,data);
    EQUAL_MAT(test,ex,rows,cols);
}
TEST(MatrixTestFL, CreatingDef) {
    size_t rows = 2;
    size_t cols = 2;
    float data = 0;
    MyMatrix<float> a(rows,cols);
    float ** test = a.GetFirst();
    float ** ex = CreateMatr(rows,cols,data);
    EQUAL_MAT(test,ex,rows,cols);
}
TEST(MatrixTestInt, CreatingDate) {
    size_t rows = 2;
    size_t cols = 2;
    int data = 5;
    MyMatrix<int> a(rows,cols,data);
    int ** test = a.GetFirst();
    int ** ex = CreateMatr(rows,cols,data);
    EQUAL_MAT(test,ex,rows,cols);
}
TEST(MatrixTestDo, CreatingDate) {
    size_t rows = 2;
    size_t cols = 2;
    double data = 5;
    MyMatrix<double> a(rows,cols,data);
    double ** test = a.GetFirst();
    double ** ex = CreateMatr(rows,cols,data);
    EQUAL_MAT(test,ex,rows,cols);
}
TEST(MatrixTestSH, CreatingDate) {
    size_t rows = 2;
    size_t cols = 2;
    short data = 5;
    MyMatrix<short> a(rows,cols,data);
    short ** test = a.GetFirst();
    short ** ex = CreateMatr(rows,cols,data);
    EQUAL_MAT(test,ex,rows,cols);
}
TEST(MatrixTestFL, CreatingDate) {
    size_t rows = 2;
    size_t cols = 2;
    float data = 5;
    MyMatrix<float> a(rows,cols,data);
    float ** test = a.GetFirst();
    float ** ex = CreateMatr(rows,cols,data);
    EQUAL_MAT(test,ex,rows,cols);
}
