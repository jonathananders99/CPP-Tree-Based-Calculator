#ifndef NUM_NODE_H_
#define NUM_NODE_H_

#include "Expr_Node.h"

class Num_Node : public Expr_Node
{
    public:
        /// Default Constructor
        Num_Node (void);
    
        /**
         * Initializing constructor
         *
         * @param[in]       integer      The number of the node
         */
        Num_Node (int num);

        /// Destructor
        ~Num_Node (void);
    
        /**
         * Evaluate the current portion of the tree. (returns the number represented by the node)
         *
         * @return         integer
         */
        int get_num (void);

        /**
         * Gets precedence of node.
         *
         * @return        Integer representing the precedence
         */
        int get_prec (void);

        /**
         * Accepts visitor.
         *
         * @param[in]     Visitor_Expr_Node&
         */
        virtual void accept_visitor (Visitor_Expr_Node & visitor);

    private:
        int num;
};

// include the source file
#include "Num_Node.cpp"

#endif // !defined NUM_NODE_H_