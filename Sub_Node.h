#ifndef SUB_NODE_H_
#define SUB_NODE_H_

#include "Binary_Expr_Node.h"

class Sub_Node : public Binary_Expr_Node
{
    public:
        /// Default Constructor
        Sub_Node (void);

        /// Destructor
        ~Sub_Node (void);

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
#include "Sub_Node.cpp"

#endif // !defined SUB_NODE_H_