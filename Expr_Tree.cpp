// Constructor
Expr_Tree::Expr_Tree(void):
    main(nullptr)
{
	
}

// Initializer
Expr_Tree::Expr_Tree(Expr_Node * node):
    main(node)
{
	
}

// Destructor
Expr_Tree::~Expr_Tree (void)
{
    if (main != nullptr)
    {
        delete this->main;
    }
}

// Get Main Node
Expr_Node * Expr_Tree::get_main_node (void)
{
    return this->main;
}

// Set Left Node
void Expr_Tree::set_main_node (Expr_Node * node)
{
    this->main = node;
}