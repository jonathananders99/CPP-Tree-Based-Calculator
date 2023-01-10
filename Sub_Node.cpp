// Constructor
Sub_Node::Sub_Node(void):
    Binary_Expr_Node()
{
	
}

// Destructor
Sub_Node::~Sub_Node (void)
{
    
}

// Get Precedence
int Sub_Node::get_prec (void)
{
    return 2;
}

///Accept Visitor
void Sub_Node::accept_visitor (Visitor_Expr_Node & visitor)
{
	visitor.visit_sub_node (*this);
}