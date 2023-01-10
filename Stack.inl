//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return this->start;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    //if array is empty it throws error
    if (this->is_empty())
    {
        throw Stack<T>::empty_exception();
    }
    
    return this->array.get(start);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    //if its empty
    if (this->start == 0)
    {
        return true;
    }
    
    return false;
}
