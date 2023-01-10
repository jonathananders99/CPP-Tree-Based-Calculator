#ifndef _CS507_Queue_H_
#define _CS507_Queue_H_

#include "Array.h"

#include <exception>

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
{
    public:
        /// Type definition of the type.
        typedef T type;

        /**
         * @class empty_exception
         *
         * Exception thrown to indicate the queue is empty.
         */
        class empty_exception : public std::exception
        {
        public:
            /// Default constructor.
            empty_exception (void)
            : std::exception () { }
        };

        /// Default constructor.
        Queue (void);

        /// Copy constructor.
        Queue (const Queue & s);

        /// Destructor.
        ~Queue (void);

        /**
         * Assignment operator
         *
         * @param[in]      rhs           Right-hand side of operator
         * @return         Reference to self
         */
        const Queue & operator = (const Queue & rhs);

        /**
         * Push a new \a element onto the queue. The element is inserted
         * after all the other elements in the list.
         *
         * @param[in]      element       Element to add to the list
         */
        void enqueue (T element);

        /**
         * Remove the front-most element from the queue.
         * 
         * @return         Element front of the queue.
         * @exception      empty_exception    The queue is empty.
         */
        T dequeue (void);

        /**
         * Test if the queue is empty
         *
         * @retval         true          The queue is empty
         * @retval         false         The queue is not empty
         */
        bool is_empty (void) const;

        /**
         * Number of element on the queue.
         *
         * @return         Size of the queue.
         */
        size_t size (void) const;

        /// Remove all elements from the queue.
        void clear (void);

    private:
        /// Array
        Array<T> array;

        ///Start of Queue
        size_t start;

        ///End of Queue
        size_t end;
    
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_Queue_H_