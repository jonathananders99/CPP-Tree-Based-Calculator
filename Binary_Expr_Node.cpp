// Constructor
Binary_Expr_Node::Binary_Expr_Node(void):
    left(nullptr),
    right(nullptr)
{
	
}

// Destructor
Binary_Expr_Node::~Binary_Expr_Node (void)
{
    if(right != nullptr)
    {
        delete right;
    }

    if(left != nullptr)
    {
        delete left;
    }
}

// Get Right Node
Expr_Node * Binary_Expr_Node::get_right_node (void)
{
    return this->right;
}

// Get Left Node
Expr_Node * Binary_Expr_Node::get_left_node (void)
{
    return this->left;
}

// Set Left Node
void Binary_Expr_Node::set_left_node (Expr_Node * node)
{
    this->left = node;
}

// Set Right Node
void Binary_Expr_Node::set_right_node (Expr_Node * node)
{
    this->right = node;
}