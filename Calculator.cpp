// Constructor
Calculator::Calculator(void)
{
	
}

// Destructor
Calculator::~Calculator ()
{
    if(this->builder != nullptr)
    {
        delete this->builder;
    }
}

// Start
void Calculator::start (const std::string & infix)
{
    //for errors
    bool errorFree = true;

    Expr_Tree_Builder * curBuilder = nullptr;

    if (errorFree)
    {
        try
        {
            //evaluation of postfix
            curBuilder = eval(infix, 1);
            Eval_Expr_Tree tree;
            curBuilder->get_main_tree()->get_main_node()->accept_visitor(tree);
            std::cout << tree.get_result() << std::endl;
        }

        catch(const std::exception & e)
        {
            std::cout << e.what() << '\n';
            errorFree = false;
        }
        
        catch(...)
        {
            std::cout << "Error occurred during evaluation of postfix" << std::endl;
            errorFree = false;
        }
    }
    delete curBuilder;
}

// Infix to Postfix
Expr_Tree_Builder * Calculator::eval (const std::string & infix, int treeLevel)
{
    //for parsing
    std::istringstream parser(infix);

    this->builder = new Expr_Tree_Builder();

    this->builder->set_tree_level(treeLevel);

    Expr_Tree_Builder * tempBuilder1;
    Expr_Tree_Builder * tempBuilder2;

    //string used for infix parsing
    std::string token;

    int curPrec, subExprLen, curNum, curPars = 0;

    //if the token is a number or not
    bool isNum;

    //for recursive parsing
    bool keepGoing = true;

    //cycles through each input in between spaces
    while (!parser.eof())
    {
        
        //reset necessary variables
        curPrec = 0;
        parser >> token;
        isNum = false;
        curNum = 0;
		Expr_Node * subExprNode;

        //tries to convert token into number
        try
        {
            curNum = std::stoi(token);
            isNum = true;
        }
        catch(const std::exception& e)
        {
            //do nothing
        }

        //if its a addition symbol, build it
        if (token == "+")
        {
            this->builder->build_add_node();
        }

        //if its a division symbol, build it
        else if (token == "/")
        {
            this->builder->build_div_node();
        }

        //if its a modulus symbol, build it
        else if (token == "%")
        {
            this->builder->build_mod_node();
        }

        //if its a multiplication symbol, build it
        else if (token == "*")
        {
            this->builder->build_mult_node();
        }

        //if its a subtraction symbol, build it
        else if (token == "-")
        {
            this->builder->build_sub_node();
        }

        //if its a number, build it
        else if (isNum)
        {
            this->builder->build_num_node(curNum);
        }

        //if its left parenthesis symbol, parse the sub expression with recursive call to this method
        else if (token == "(")
        {
            curPars++;
            //goes thru the entire sub expression to skip it
            while (curPars != 0  && !parser.eof())
            {
                parser >> token;
                //if left parenthesis add one and continue
                if (token == "(")
                {
                    curPars++;
                }
                //if right parenthesis subtract one and continue
                else if (token == ")")
                {
                    curPars--;
                }
            }

            //get length of the sub expression to use later
            subExprLen = infix.rfind(")") - infix.find("(");
            
            tempBuilder1 = this->builder;

            //double parenthesis, adds 0+ to sub expr
            if (this->builder->get_main_tree()->get_main_node() == nullptr)
			{
				this->builder->build_num_node(0);
				this->builder->build_add_node();
			}

            tempBuilder2 = eval(infix.substr(infix.find("(") + 1, subExprLen - 2),   this->builder->get_tree_level() + 1);

            subExprNode = tempBuilder2->get_main_tree()->get_main_node();

            //insert right if right child is nullptr
            if (tempBuilder1->get_main_tree()->get_main_node()->get_right_node() == nullptr)
			{
				tempBuilder1->get_main_tree()->get_main_node()->set_right_node(subExprNode);
			}
            //insert normally
			else
			{
			    tempBuilder1->insert_node(subExprNode);
			}
			
			this->builder = tempBuilder1;
        }
    }
    return this->builder;
}