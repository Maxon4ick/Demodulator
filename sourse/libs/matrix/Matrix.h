#ifndef MATRIX_H
#define MATRIX_H
#include <cstdlib>
#include <iostream>
template <typename T>
class MyMatrix
{
public:

/* конструктор по умолчанию*/

MyMatrix()
{
    this->m= nullptr;
    this->rows = 0;
    this->cols = 0;
}

/* Дальше два условных конструктора, которые, создают матрицу заданного размера
 * и инициализируют ее, либо нулями, либо заданной датой*/

MyMatrix(size_t rows,size_t cols)
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
            m[ i ][ j ] = 0;

        }
}
MyMatrix(size_t rows,size_t cols, T data)
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

/* Геттеры добавил для удобства работы с тестированием и выводом в консоль,
 * но в конечной версии программы вывод решил убрать, если надо добавлю*/

T GetElem(size_t rows,size_t cols)
{
    return m[rows][cols];
}
T ** GetFirst()
{
    return this->m;
}

private:
T ** m;
size_t rows;
size_t cols;
};
#endif // MATRIX_H
