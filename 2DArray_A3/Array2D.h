//
//  Array2D.h
//  2DArray_A3
//
//  Created by Ian Murphy on 1/9/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//
#pragma once
#include "Row.h"
#include "Array.h"
#include "Exception.h"
template <typename T>
class Array2D
{
public:
    friend class Row<T>;
    Array2D();
    Array2D(int row, int col);
    Array2D(const Array2D<T> & cp);
    ~Array2D();
    
    Array2D & operator = (const Array2D & rhs);
    Row<T> operator [] (int index);
    int getRow();
    void setRow(int rows);
    int getColumn();
    void setColumn(int col);
    T & Select(int row, int col);
    
private:
    Array<T> m_array;
    int _row;
    int _col;
};

template <typename T>
Array2D<T>::Array2D() : _col(0), _row(0)
{
    m_array.setLength(0);
}

template <typename T>
Array2D<T>::Array2D(int row, int col) : _col(col), _row(row)
{
    m_array.setLength(row*col);
}

template <typename T>
Array2D<T>::Array2D(const Array2D<T> & cp) : _col(cp._col), _row(cp._row), m_array(cp.m_array)
{
    
}

template <typename T>
Array2D<T>::~Array2D()
{
    
}


template <typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D<T> &rhs)
{
    if(this != &rhs)
    {
        _row = rhs._row;
        _col = rhs._col;
        m_array = rhs.m_array;
    }
    return *this;
}


template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
    Row<T> row(*this, index);
    return row;
}


template <typename T>
int Array2D<T>::getRow()
{
    return _row;
}

template <typename T>
void Array2D<T>::setRow(int rows)
{
    if(rows > 0)
    {
        _row = rows;
    }
    else{
        throw Exception("InvalidRowNumberException");
    }
}

template <typename T>
int Array2D<T>::getColumn()
{
    return _col;
}

template <typename T>
void Array2D<T>::setColumn(int col)
{
    if(col > 0)
    {
        _col = col;
    }
    else{
        throw Exception("InvalidColumnNumberException");
    }
}

template <typename T>
T & Array2D<T>::Select(int row, int col)
{
    return m_array[row*col+col];
}



