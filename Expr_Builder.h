#ifndef EXPR_BUILDER_H_
#define EXPR_BUILDER_H_

#include "Add_Node.h"
#include "Div_Node.h"
#include "Mod_Node.h"
#include "Mult_Node.h"
#include "Num_Node.h"
#include "Sub_Node.h"

class Expr_Builder
{
    public:
        /// Default Constructor
        Expr_Builder (void);

        /// Destructor
        ~Expr_Builder (void);
        
        /// Builds Add_Node.
        virtual void build_add_node (void) = 0;
        
        /// Builds Div_Node.
        virtual void build_div_node (void) = 0;
        
        /// Builds Mod_Node.
        virtual void build_mod_node (void) = 0;
        
        /// Builds Mult_Node.
        virtual void build_mult_node (void) = 0;
        
        /// Builds Sub_Node.
        virtual void build_sub_node (void) = 0;

        /**
         * Builds Num_Node.
         *
         * @param[in]     Integer
         */
        virtual void build_num_node (int num) = 0;
};

// include the source file
#include "Expr_Builder.cpp"

#endif // !defined EXPR_BUILDER_H_