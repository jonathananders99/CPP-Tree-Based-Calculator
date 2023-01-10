#include "Fixed_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void):
    Array_Base<T>()
{
    
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr):
    Array_Base<T>(N)
{
	
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill):
    Array_Base<T>(N, fill)
{
    
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
    delete[] this->data_;
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	//checks for self assignment
    if (this == &rhs)
    {
        return *this;
    }

    //checks if size is different
    if (rhs.curSize != this->curSize)
    {
        throw std::runtime_error("Array size does not match");
    }

    //sets new data to the data from rhs
    for (size_t i=0; i<this->cur_size_; i++)
    {
        this->data_[i] = rhs.data_[i];
    }

    return *this;
}
