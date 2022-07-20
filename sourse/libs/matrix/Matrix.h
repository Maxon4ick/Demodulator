#ifndef MATRIX_H
#define MATRIX_H
#include <cstdlib>
#include <iostream>
template <typename T>
class Matrix
{
public:

/* конструктор по умолчанию*/

Matrix() : m(nullptr),rows(0),cols(0){
}

/* Дальше два условных конструктора, которые, создают матрицу заданного размера
 * и инициализируют ее, либо нулями, либо заданной датой*/

Matrix(size_t rows,size_t cols) : Matrix(rows,cols,0){
}
Matrix(size_t rows,size_t cols, T data) : rows(rows),cols(cols)
{
    m = new T*[rows];
    m[0] = new T[rows*cols];
    for (size_t i = 1; i!= rows; i++)
    {
        m[i] = m[i-1]+cols;
    }
    for ( size_t i = 0; i < rows; i++ )
        for ( size_t j = 0; j < cols; j++ )
        {
            m[ i ][ j ] = data;

        }
}
/* Геттеры добавил для удобства работы с тестированием */

T GetElem(size_t rows,size_t cols)
{
    return m[rows][cols];
}
T ** GetFirst()
{
    return this->m;
}
Matrix operator +(const Matrix & other)
{
    for ( size_t i = 0; i < rows; i++ ) {
        for ( size_t j = 0; j < cols; j++ )
        {
            this->m[ i ][ j ] += other.m[i][j];
        }
    }

    return *this;
}
Matrix operator -(const Matrix & other)
{
    for ( size_t i = 0; i < rows; i++ ) {
        for ( size_t j = 0; j < cols; j++ )
        {
            this->m[ i ][ j ] -= other.m[i][j];
        }
    }

    return *this;
}
Matrix operator *(const Matrix & other)
{
    Matrix temp(this->rows,other.cols,0);
    for ( size_t i = 0; i < this->rows; i++ ) {
        for ( size_t j = 0; j < other.cols; j++ )
        {
            for (size_t k = 0; k<this->cols; k++)
            {
                temp.m[i][j] += this->m[i][k]*other.m[k][j];
            }
        }
    }
    return Matrix(temp);
}
Matrix operator *(const T & other)
{
    for ( size_t i = 0; i < rows; i++ )
        for ( size_t j = 0; j < cols; j++ )
        {
            this->m[i][j]*=other;
        }

    return *this;
}
Matrix operator /(const Matrix & other)
{
    Matrix temp(this->rows,other.cols,0);
    for ( size_t i = 0; i < this->rows; i++ ) {
        for ( size_t j = 0; j < other.cols; j++ )
        {
            for (size_t k = 0; k<this->cols; k++)
            {
                temp.m[i][j] += this->m[i][k]/other.m[k][j];
            }
        }
    }
    return Matrix(temp);
}

Matrix &operator =(const Matrix &other)
{

    this->m = other.m;
    this->rows = other.rows;
    this->cols = other.cols;

    return *this;
}
Matrix Transpose()
{
    Matrix out(this->rows,this->cols);
    for (unsigned i = 0; i < cols; i++)
    {
        for (unsigned j = 0; j < rows; j++)
        {
            out.m[i][j] = this->m[j][i];
        }
    }
    return out;
}
~Matrix() = default;
private:
T ** m;
size_t rows;
size_t cols;
};
#endif // MATRIX_H
