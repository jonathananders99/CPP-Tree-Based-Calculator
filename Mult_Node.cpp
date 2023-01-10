// Constructor
Mult_Node::Mult_Node(void):
    Binary_Expr_Node()
{
	
}

// Destructor
Mult_Node::~Mult_Node (void)
{
    
}

// Get Precedence
int Mult_Node::get_prec (void)
{
    return 3;
}

///Accept Visitor
void Mult_Node::accept_visitor (Visitor_Expr_Node & visitor)
{
	visitor.visit_mult_node (*this);
}