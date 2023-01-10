// Constructor
Num_Node::Num_Node(void):
    num(0)
{
	
}

// Initializing Constructor
Num_Node::Num_Node(int num):
    num(num)
{
	
}

// Destructor
Num_Node::~Num_Node (void)
{
    
}

///Accept Visitor
void Num_Node::accept_visitor (Visitor_Expr_Node & visitor)
{
	visitor.visit_num_node (*this);
}

///Evaluate
int Num_Node::get_num(void)
{
	return this->num;
}

///Get Precedence
int Num_Node::get_prec(void)
{
	return 1;
}