#ifndef ADD_NODE_H_
#define ADD_NODE_H_

#include "Binary_Expr_Node.h"

class Add_Node : public Binary_Expr_Node
{
    public:
        /// Default Constructor
        Add_Node (void);

        /// Destructor
        ~Add_Node (void);

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
#include "Add_Node.cpp"

#endif // !defined ADD_NODE_H_