#include "Array_Base.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void):
    cur_size_(0),
    data_(nullptr)
{
    
}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length):
    cur_size_(length),
    data_(nullptr)
{
    this->data_ = new T[this->cur_size_];
}

//
// Array_Base (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill):
    cur_size_(length),
    data_(nullptr)
{
    this->data_ = new T[this->cur_size_];
    this->fill(fill);
}

//
// Array_Base (const Array &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & arr):
    cur_size_(arr.cur_size_),
    data_(nullptr)
{
    this->data_ = new T[this->cur_size_];
    //puts each array's character in the right spot in the new array
    for (size_t i=0; i<this->cur_size_; i++)
    {
        this->data_[i] = arr.data_[i];
    }
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
    delete[] this->data_;
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
    //checks for self assignment
    if (this == &rhs)
    {
        return *this;
    }

    //deletes old data
    delete [] this->data_;
    
    //changes sizes to the correct new size
    this->cur_size_ = rhs.cur_size_;
    
    //makes new temp array to copy rhs
    T *temp = new T[rhs.cur_size_];

    //sets temp to the characters from rhs
    for (size_t i=0; i<this->cur_size_; i++)
    {
        temp[i] = rhs.data_[i];
    }

    //sets the array's new data to the temp
    this->data_ = temp;

    return *this;
}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
    //sees if index is within limits of array size
    if (index < this->cur_size_)
    {
        return this->data_[index];
    }
    
    //throws error if its not in array's range
    throw std::out_of_range("Index is out of range.");
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
    //sees if index is within limits of array size
    if (index < this->cur_size_)
    {
        return this->data_[index];
    }
    
    //throws error if its not in array's range
    throw std::out_of_range("Index is out of range.");
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
    //sees if index is within limits of array size
    if (index < this->cur_size_)
    {
        return this->data_[index];
    }
    
    //throws error if its not in array's range
    throw std::out_of_range("Index is out of range.");
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
    //sees if index is not within limits of array size
    if (index >= this->cur_size_)
    {
        //throws error if its not in array's range
        throw std::out_of_range("Index is out of range.");
    }
    
    this->data_[index] = value;
}

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
    //cycles through length of array and if thwe character is found it returns the index
    for (size_t i=0; i<this->cur_size_; i++)
    {
        if (this->data_[i] == value)
        {
            return i;
        }
    }
    
    //returns -1 if not found
    return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
    //checks if start is within array range
    if (start < this->cur_size_)
    {
        //cycles through length of array and if the character is found it returns the index
        for (size_t i=start; i<this->cur_size_; i++)
        {
            if (this->data_[i] == val)
            {
                return i;
            }
        }
        
        //returns -1 if not found
        return -1;
    }
    
    //throws error if its not in array's range
    throw std::out_of_range("Index is out of range.");
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
    //compare sizes of the arrays
    if (this->cur_size_ != rhs.cur_size_)
    {
        return false;
    }
    
    //cycles size of arrays, and checks if they are !=
    for (size_t i=0; i<this->cur_size_; i++)
    {
        if (this->data_[i] != rhs.data_[i])
        {
            return false;
        }
    }

    return true;
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
    //compare sizes of the arrays
    if (this->cur_size_ != rhs.cur_size_)
    {
        return true;
    }
    
    //cycles size of arrays, and checks if they are !=
    for (size_t i=0; i<this->cur_size_; i++)
    {
        if (this->data_[i] != rhs.data_[i])
        {
            return true;
        }
    }

    return false;
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    //cycles through length of array and assigns each element to the fill character
    for (size_t i=0; i<this->cur_size_; i++)
    {
        this->data_[i] = value;
    }
}
