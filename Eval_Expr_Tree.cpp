// Constructor
Eval_Expr_Tree::Eval_Expr_Tree(void):
    result(0)
{
	
}

// Destructor
Eval_Expr_Tree::~Eval_Expr_Tree (void)
{
    
}

// Visit Add_Node
void Eval_Expr_Tree::visit_add_node (Add_Node & node)
{
	//if node has 2 children to add
	if (node.get_right_node() != nullptr  &&  node.get_left_node() != nullptr)
	{
		try
        {
			//Visit left node
			node.get_left_node()->accept_visitor(* this);

            //get left node result
			int leftResult = this->result;
            
			//Visit right node
			node.get_right_node()->accept_visitor(* this);

            //get right node result
			int rightResult = this->result;
		
			this->result = leftResult + rightResult;
		}
		catch(std::exception & e)
		{
			throw e;
		}
	}
	else
    {
        throw std::runtime_error("Error: Node does not have 2 children to add");
    }
}

// Visit Div_Node
void Eval_Expr_Tree::visit_div_node (Div_Node & node)
{
	//if node has 2 children to div
	if (node.get_right_node() != nullptr  &&  node.get_left_node() != nullptr)
	{
		try
        {
			//Visit left node
			node.get_left_node()->accept_visitor(* this);

            //get left node result
			int leftResult = this->result;
            
			//Visit right node
			node.get_right_node()->accept_visitor(* this);

            //get right node result
			int rightResult = this->result;
		
			this->result = leftResult / rightResult;
		}
		catch(std::exception & e)
		{
			throw e;
		}
	}
	else
    {
        throw std::runtime_error("Error: Node does not have 2 children to divide");
    }
}

// Visit Mod_Node
void Eval_Expr_Tree::visit_mod_node (Mod_Node & node)
{
	//if node has 2 children to mod
	if (node.get_right_node() != nullptr  &&  node.get_left_node() != nullptr)
	{
		try
        {
			//Visit left node
			node.get_left_node()->accept_visitor(* this);

            //get left node result
			int leftResult = this->result;
            
			//Visit right node
			node.get_right_node()->accept_visitor(* this);

            //get right node result
			int rightResult = this->result;
		
			this->result = leftResult % rightResult;
		}
		catch(std::exception & e)
		{
			throw e;
		}
	}
	else
    {
        throw std::runtime_error("Error: Node does not have 2 children to modulus");
    }
}

// Visit Mult_Node
void Eval_Expr_Tree::visit_mult_node (Mult_Node & node)
{
	//if node has 2 children to mult
	if (node.get_right_node() != nullptr  &&  node.get_left_node() != nullptr)
	{
		try
        {
			//Visit left node
			node.get_left_node()->accept_visitor(* this);

            //get left node result
			int leftResult = this->result;
            
			//Visit right node
			node.get_right_node()->accept_visitor(* this);

            //get right node result
			int rightResult = this->result;
		
			this->result = leftResult * rightResult;
		}
		catch(std::exception & e)
		{
			throw e;
		}
	}
	else
    {
        throw std::runtime_error("Error: Node does not have 2 children to mult");
    }
}

// Visit Sub_Node
void Eval_Expr_Tree::visit_sub_node (Sub_Node & node)
{
	//if node has 2 children to sub
	if (node.get_right_node() != nullptr  &&  node.get_left_node() != nullptr)
	{
		try
        {
			//Visit left node
			node.get_left_node()->accept_visitor(* this);

            //get left node result
			int leftResult = this->result;
            
			//Visit right node
			node.get_right_node()->accept_visitor(* this);

            //get right node result
			int rightResult = this->result;
		
			this->result = leftResult - rightResult;
		}
		catch(std::exception & e)
		{
			throw e;
		}
	}
	else
    {
        throw std::runtime_error("Error: Node does not have 2 children to sub");
    }
}



// Visit Number Node
void Eval_Expr_Tree::visit_num_node (Num_Node & node)
{
	//Retrieve value from the number node
	this->result = node.get_num();
}

// Return result
int Eval_Expr_Tree::get_result (void)
{
	return this->result;
}