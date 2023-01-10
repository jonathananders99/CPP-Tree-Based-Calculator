#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "Eval_Expr_Tree.h"
#include "Expr_Node.h"
#include "Expr_Tree_Builder.h"
#include <sstream>

class Calculator
{
    public:
        /// Default Constructor
        Calculator (void);

        /// Destructor
        ~Calculator (void);

        /**
         * Start the calculator.
         *
         * @param[in]      infix      String containing the infix
         */
        void start (const std::string & infix);

    
    private:
        /// Tree Builder
	    Expr_Tree_Builder * builder;
        
        /**
         * Converts infix to postfix and uses creates all necessary nodes and goes through the tree.
         *
         * @param[in]      int        Tree's level
         * @return         Expr_Tree_Builder*    
         */
        Expr_Tree_Builder * eval (const std::string & infix, int treeLevel);

};

// include the source file since template class
#include "Calculator.cpp"

#endif // !defined CALCULATOR_H_