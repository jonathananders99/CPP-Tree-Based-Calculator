#include "Visitor_Expr_Node.h"

// Constructor
Expr_Node::Expr_Node(void):
    marker(-1)
{
	
}

// Destructor
Expr_Node::~Expr_Node (void)
{
    
}

// Get Right Node
Expr_Node * Expr_Node::get_right_node (void)
{
    return nullptr;
}

// Get Left Node
Expr_Node * Expr_Node::get_left_node (void)
{
    return nullptr;
}

// Set Left Node
void Expr_Node::set_left_node (Expr_Node * node)
{
    
}

// Set Right Node
void Expr_Node::set_right_node (Expr_Node * node)
{
    
}

// Set Marker
void Expr_Node::set_marker (int num)
{
    this->marker = num;
}