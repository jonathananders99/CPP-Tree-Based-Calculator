#ifndef DIV_NODE_H_
#define DIV_NODE_H_

#include "Binary_Expr_Node.h"

class Div_Node : public Binary_Expr_Node
{
    public:
        /// Default Constructor
        Div_Node (void);

        /// Destructor
        ~Div_Node (void);
    
        /**
         * Evaluate the current portion of the tree.
         *
         * @return         integer
         */
        int eval (void);

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
};

// include the source file
#include "Div_Node.cpp"

#endif // !defined DIV_NODE_H_