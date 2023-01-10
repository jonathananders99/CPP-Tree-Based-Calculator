// Size
template <typename T>
inline
size_t Queue <T>::size (void) const
{
    return this->end - this->start;
}


// Is_empty
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    //if its empty
    if (this->end - this->start <= 0)
    {
        return true;
    }
    
    return false;
}
