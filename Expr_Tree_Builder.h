#ifndef EXPR_TREE_BUILDER_H_
#define EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Expr_Tree.h"

class Expr_Tree_Builder : public Expr_Builder
{
    public:
        /// Default Constructor
        Expr_Tree_Builder (void);

        /// Destructor
        ~Expr_Tree_Builder (void);
        
        /// Builds Add_Node.
        void build_add_node (void);
        
        /// Builds Div_Node.
        void build_div_node (void);
        
        /// Builds Mod_Node.
        void build_mod_node (void);
        
        /// Builds Mult_Node.
        void build_mult_node (void);
        
        /// Builds Sub_Node.
        void build_sub_node (void);

        /**
         * Builds Num_Node.
         *
         * @param[in]     Integer
         */
        void build_num_node (int num);

        /**
         * Recursively goes through the tree and inserts the node where its supposed to go.
         *
         * @param[in]     Expr_Node*    The main node
         * @param[in]     Expr_Node*    The node to be inserted
         * @return        boolean (false on successful insertion of node)
         */
        bool search_and_insert (Expr_Node * mNode, Expr_Node * iNode);

        /**
         * Inserts the given node.
         *
         * @param[in]     Expr_Node*    The node to be inserted
         */
        void insert_node (Expr_Node * node);

        /**
         * Sets the integer representation of the tree levels.
         *
         * @param[in]     integer       Level of nodes for tree
         */
        void set_tree_level (int num);

        /**
         * Gets the integer representation of the tree levels.
         *
         * @return        integer of the tree levels
         */
        int get_tree_level (void);

        /**
         * Gets the main tree pointer.
         *
         * @return        Expr_Tree*
         */
        Expr_Tree * get_main_tree (void);

    private:
        /// Main Expression Tree
        Expr_Tree * tree;

        /// How many Levels the Expression Tree is currently
        int tree_level;
};

// include the source file
#include "Expr_Tree_Builder.cpp"

#endif // !defined EXPR_TREE_BUILDER_H_