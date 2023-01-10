#include "Stack.h"

//
// Stack
//
template <typename T>
Stack <T>::Stack (void):
    start(0)
{
    this->array = Array<T>(10);
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack):
    start(stack.start)
{
    this->array = new Array<T>(stack.array);
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    //if there needs to be more space in the array it adds 10 more spaces
    if (this->start >= this->array.max_size())
    {
        this->array.resize(this->start+10);
    }

    this->array.set(this->start, element);

    this->start = this->start + 1;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    //if array is empty it throws error
    if (this->is_empty())
    {
        throw Stack<T>::empty_exception();
    }
    
    this->start = this->start - 1;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    //checks for self assignment
    if (this == &rhs){
        return *this;
    }
    
    array = Array<T>(rhs.array);
    
    this->start = rhs.start;

    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    this->start = 0;
}
