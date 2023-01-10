// Constructor
Mod_Node::Mod_Node(void):
    Binary_Expr_Node()
{
	
}

// Destructor
Mod_Node::~Mod_Node (void)
{
    
}

// Get Precedence
int Mod_Node::get_prec (void)
{
    return 3;
}

///Accept Visitor
void Mod_Node::accept_visitor (Visitor_Expr_Node & visitor)
{
	visitor.visit_mod_node (*this);
}