#ifndef EVAL_EXPR_TREE_H_
#define EVAL_EXPR_TREE_H_

#include "Visitor_Expr_Node.h"
#include <stdexcept>

class Eval_Expr_Tree : public Visitor_Expr_Node
{
    public:
        /// Default Constructor
        Eval_Expr_Tree (void);

        /// Destructor
        ~Eval_Expr_Tree (void);

        /**
         * Visits Add_Node.
         *
         * @param[in]     Add_Node&        
         */
        virtual void visit_add_node (Add_Node & node);

        /**
         * Visits Div_Node.
         *
         * @param[in]     Div_Node&        
         */
        virtual void visit_div_node (Div_Node & node);

        /**
         * Visits Mod_Node.
         *
         * @param[in]     Mod_Node&        
         */
        virtual void visit_mod_node (Mod_Node & node);

        /**
         * Visits Mult_Node.
         *
         * @param[in]     Mult_Node&        
         */
        virtual void visit_mult_node (Mult_Node & node);

        /**
         * Visits Num_Node.
         *
         * @param[in]     Num_Node&        
         */
        virtual void visit_num_node (Num_Node & node);

        /**
         * Visits Sub_Node.
         *
         * @param[in]     Sub_Node&        
         */
        virtual void visit_sub_node (Sub_Node & node);

        /**
         * Gets result attribute.
         *
         * @return        integer
         */
        int get_result (void);

    private:
        /// Result of tree traversal
        int result;
};

// include the source file
#include "Eval_Expr_Tree.cpp"

#endif // !defined EVAL_EXPR_TREE_H_