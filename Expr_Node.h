#ifndef EXPR_NODE_H_
#define EXPR_NODE_H_

#include <exception>
#include <string>
#include <iostream>

class Visitor_Expr_Node;

class Expr_Node
{
    public:
        /// Default Constructor
        Expr_Node (void);

        /// Destructor
        virtual ~Expr_Node (void);

        /**
         * Gets precedence of node.
         *
         * @return        Integer representing the precedence
         */
        virtual int get_prec (void) = 0;

        /**
         * Gets right node.
         *
         * @return        Expr_Node
         */
        virtual Expr_Node * get_right_node (void);

        /**
         * Gets left node.
         *
         * @return        Expr_Node
         */
        virtual Expr_Node * get_left_node (void);

        /**
         * Sets left node.
         *
         * @param[in]     Expr_Node*        Pointer to the node that's to be set as the left node
         */
        virtual void set_left_node (Expr_Node * node);

        /**
         * Sets right node.
         *
         * @param[in]     Expr_Node*        Pointer to the node that's to be set as the right node
         */
        virtual void set_right_node (Expr_Node * node);

        /**
         * Sets marker.
         *
         * @param[in]     int               where in the tree to add the node
         */
        void set_marker (int num);

        /**
         * Accepts visitor.
         *
         * @param[in]     Visitor_Expr_Node&
         */
        virtual void accept_visitor (Visitor_Expr_Node & visitor) = 0;
    
    protected:
        // Marks where in the tree to add the node
        int marker;
};

// include the source file
#include "Expr_Node.cpp"

#endif // !defined EXPR_NODE_H_