#ifndef EXPR_TREE_H_
#define EXPR_TREE_H_

#include "Expr_Node.h"

class Expr_Tree
{
    public:
        /// Default Constructor
        Expr_Tree (void);
    
        /**
         * Initializing constructor
         *
         * @param[in]       Expr_Node*      A pointer to the designated main node of the tree
         */
        Expr_Tree (Expr_Node * node);

        /// Destructor
        ~Expr_Tree (void);

        /**
         * Gets main node.
         *
         * @return        Expr_Node
         */
        Expr_Node * get_main_node (void);

        /**
         * Sets main node.
         *
         * @param[in]     Expr_Node*        Pointer to the node that's to be set as the main node
         */
        void set_main_node (Expr_Node * node);
    
    private:
        // Head Node
        Expr_Node * main;
};

// include the source file
#include "Expr_Tree.cpp"

#endif // !defined EXPR_TREE_H_