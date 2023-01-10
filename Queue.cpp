#include "Queue.h"

//
// Queue
//
template <typename T>
Queue <T>::Queue (void):
    start(0),
    end(0)
{
    this->array = Array<T>();
}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & queue):
    start(queue.start),
    end(queue.end)
{
    this->array = new Array<T>(queue.array);
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
    delete[] this->array.data_;
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    size_t oldSize = this->size();

    //if there needs to be more space in the array it adds 3 more spaces
    if (oldSize >= this->array.max_size())
    {
        this->array.resize(oldSize+3);
    }

    //adds element into queue
    this->array.set(this->end, element);
    
    this->end++;
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue (void)
{
    //if array is empty it throws error
    if (this->is_empty())
    {
        throw Queue<T>::empty_exception();
    }

    //val to return at end
    T retVal = this->array.get(start);

    this->start++;

    //if there are 3 or more unused spaces in the beginning of the queue
    if (this->start > 2)
    {
        Array<T>* tempArray = new Array<T>(this->size());
        //cycles thru old array and puts those values into new array
        for (size_t i=0; i<this->size(); i++)
        {
            tempArray->set(i, this->array.get(i+this->start));
        }
        this->array = *tempArray;
        this->end = this->size();
        this->start = 0;
    }

    return retVal;
}


//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    //checks for self assignment
    if (this == &rhs){
        return *this;
    }
    
    array = new Array<T>(rhs.array);
    
    this->start = rhs.start;

    this->end = rhs.end;

    return *this;
}


//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{   
    this->start = 0;
    this->end = 0;
}