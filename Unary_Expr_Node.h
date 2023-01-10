#ifndef UNARY_EXPR_NODE_H_
#define UNARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Unary_Expr_Node : public Expr_Node
{
    public:
        /// Default Constructor
        Unary_Expr_Node (void);

        /// Destructor
        ~Unary_Expr_Node (void);
    
        /**
         * Evaluate the current portion of the tree.
         *
         * @return         integer
         */
        virtual int eval (void) = 0;

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
        virtual void accept_visitor (Visitor_Expr_Node & visitor) = 0;

    protected:
        // Child Node
        Expr_Node * child;
};

// include the source file
#include "Unary_Expr_Node.cpp"

#endif // !defined UNARY_EXPR_NODE_H_