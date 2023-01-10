// Constructor
Add_Node::Add_Node(void):
    Binary_Expr_Node()
{
	
}

// Destructor
Add_Node::~Add_Node (void)
{
    
}

// Get Precedence
int Add_Node::get_prec (void)
{
    return 2;
}

///Accept Visitor
void Add_Node::accept_visitor (Visitor_Expr_Node & visitor)
{
	visitor.visit_add_node (*this);
}