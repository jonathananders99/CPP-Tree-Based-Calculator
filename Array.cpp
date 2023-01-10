#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void):
    Array_Base<T>(),
    max_size_(0)
{
    
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length):
    Array_Base<T>(length),
    max_size_(length)
{
    
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill):
    Array_Base<T>(length, fill),
    max_size_(length)
{
    
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):
    Array_Base<T>(& array),
    max_size_(array.length)
{
    
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    delete[] this->data_;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    //checks for self assignment
    if (this == &rhs)
    {
        return *this;
    }

    //deletes old data
    delete [] this->data_;
    
    //changes sizes to the correct new size
    this->max_size_ = rhs.cur_size_;
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
T & Array <T>::operator [] (size_t index)
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
const T & Array <T>::operator [] (size_t index) const
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
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    //if smaller than current max_size_ just change cur_size_ to new_size
    if (this->max_size_ >= new_size)
    {
        this->cur_size_ = new_size;
    }
    
    else
    {
        //makes new temp array to copy old data
        T *temp = new T[new_size];

        //sets temp to the characters from old data
        for (size_t i=0; i<this->cur_size_; i++)
        {
            temp[i] = this->data_[i];
        }
        
        //deletes old data
        delete [] this->data_;

        //sets the array's new data to the temp
        this->data_ = temp;
        
        //changes sizes to the correct new sizes
        this->max_size_ = new_size;
        this->cur_size_ = new_size;
    }
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
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
bool Array <T>::operator != (const Array & rhs) const
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
