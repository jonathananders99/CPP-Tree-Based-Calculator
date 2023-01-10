#ifndef BINARY_EXPR_NODE_H_
#define BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node
{
    public:
        /// Default Constructor
        Binary_Expr_Node (void);

        /// Destructor
        ~Binary_Expr_Node (void);

        /**
         * Gets right node.
         *
         * @return        Expr_Node
         */
        Expr_Node * get_right_node (void);

        /**
         * Gets left node.
         *
         * @return        Expr_Node
         */
        Expr_Node * get_left_node (void);

        /**
         * Sets left node.
         *
         * @param[in]     Expr_Node*        Pointer to the node that's to be set as the left node
         */
        void set_left_node (Expr_Node * node);

        /**
         * Sets right node.
         *
         * @param[in]     Expr_Node*        Pointer to the node that's to be set as the right node
         */
        void set_right_node (Expr_Node * node);

        /**
         * Accepts visitor.
         *
         * @param[in]     Visitor_Expr_Node&
         */
        virtual void accept_visitor (Visitor_Expr_Node & visitor) = 0;

    protected:
        // Left Node
        Expr_Node * left;

        // Right Node
        Expr_Node * right;
};

// include the source file
#include "Binary_Expr_Node.cpp"

#endif // !defined BINARY_EXPR_NODE_H_