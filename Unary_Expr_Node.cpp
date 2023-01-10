// Constructor
Unary_Expr_Node::Unary_Expr_Node(void):
    child(nullptr)
{
	
}

// Destructor
Unary_Expr_Node::~Unary_Expr_Node (void)
{
    
}

// Get Precedence
int Unary_Expr_Node::get_prec (void)
{
    return 6;
}