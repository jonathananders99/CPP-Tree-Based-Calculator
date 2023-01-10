#ifndef VISITOR_EXPR_NODE_H_
#define VISITOR_EXPR_NODE_H_

class Add_Node;
class Div_Node;
class Mod_Node;
class Mult_Node;
class Num_Node;
class Sub_Node;
class Expr_Node;
class Binary_Expr_Node;
class Unary_Expr_Node;

class Visitor_Expr_Node
{
    public:
        /// Default Constructor
        Visitor_Expr_Node (void);

        /// Destructor
        ~Visitor_Expr_Node (void);

        /**
         * Visits Add_Node.
         *
         * @param[in]     Add_Node&        
         */
        virtual void visit_add_node (Add_Node & node) = 0;

        /**
         * Visits Div_Node.
         *
         * @param[in]     Div_Node&        
         */
        virtual void visit_div_node (Div_Node & node) = 0;

        /**
         * Visits Mod_Node.
         *
         * @param[in]     Mod_Node&        
         */
        virtual void visit_mod_node (Mod_Node & node) = 0;

        /**
         * Visits Mult_Node.
         *
         * @param[in]     Mult_Node&        
         */
        virtual void visit_mult_node (Mult_Node & node) = 0;

        /**
         * Visits Num_Node.
         *
         * @param[in]     Num_Node&        
         */
        virtual void visit_num_node (Num_Node & node) = 0;

        /**
         * Visits Sub_Node.
         *
         * @param[in]     Sub_Node&        
         */
        virtual void visit_sub_node (Sub_Node & node) = 0;
};

// include the source file
#include "Visitor_Expr_Node.cpp"

#endif // !defined VISITOR_EXPR_NODE_H_