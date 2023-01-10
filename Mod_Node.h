#ifndef MOD_NODE_H_
#define MOD_NODE_H_

#include "Binary_Expr_Node.h"

class Mod_Node : public Binary_Expr_Node
{
    public:
        /// Default Constructor
        Mod_Node (void);

        /// Destructor
        ~Mod_Node (void);

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
#include "Mod_Node.cpp"

#endif // !defined MOD_NODE_H_