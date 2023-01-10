// Constructor
Div_Node::Div_Node(void):
    Binary_Expr_Node()
{
	
}

// Destructor
Div_Node::~Div_Node (void)
{
    
}

// Get Precedence
int Div_Node::get_prec (void)
{
    return 3;
}

///Accept Visitor
void Div_Node::accept_visitor (Visitor_Expr_Node & visitor)
{
	visitor.visit_div_node (*this);
}