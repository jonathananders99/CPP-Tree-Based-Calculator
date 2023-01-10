// Constructor
Expr_Tree_Builder::Expr_Tree_Builder(void):
    tree(nullptr),
    tree_level(1)
{
	this->tree = new Expr_Tree();
}

// Destructor
Expr_Tree_Builder::~Expr_Tree_Builder (void)
{
    //main tree destructor
    if (this->tree != nullptr)
    {
        delete this->tree;
    }
}

// Add_Node Builder
void Expr_Tree_Builder::build_add_node (void)
{
	//creates node
    Add_Node * node = new Add_Node();

    //inserts node
	insert_node(node);
}

// Div_Node Builder
void Expr_Tree_Builder::build_div_node (void)
{
	//creates node
    Div_Node * node = new Div_Node();

    //inserts node
	insert_node(node);
}

// Mod_Node Builder
void Expr_Tree_Builder::build_mod_node (void)
{
	//creates node
    Mod_Node * node = new Mod_Node();

    //inserts node
	insert_node(node);
}

// Mult_Node Builder
void Expr_Tree_Builder::build_mult_node (void)
{
	//creates node
    Mult_Node * node = new Mult_Node();

    //inserts node
	insert_node(node);
}

// Sub_Node Builder
void Expr_Tree_Builder::build_sub_node (void)
{
	//creates node
    Sub_Node * node = new Sub_Node();

    //inserts node
	insert_node(node);
}

// Num_Node Builder
void Expr_Tree_Builder::build_num_node (int num)
{
	//creates node
    Num_Node * node = new Num_Node(num);

    //inserts node
	insert_node(node);
}

// Search tree and insert node
bool Expr_Tree_Builder::search_and_insert (Expr_Node * mNode, Expr_Node * iNode)
{
    bool keepGoing = true;
    //binary node
    if (mNode->get_prec() == 2  ||  mNode->get_prec() == 3)
    {
        //if right node is null and keepGoing is true insert_node
        if (mNode->get_right_node() == nullptr  &&  keepGoing)
        {
            mNode->set_right_node(iNode);
            return false;
        }
        
        //if left node is null and keepGoing is true insert_node
        if (mNode->get_left_node() == nullptr  &&  keepGoing)
        {
            mNode->set_left_node(iNode);
            return false;
        }

        //if right node is not null and keepGoing is true search thru node again
        if (mNode->get_right_node() != nullptr  &&  keepGoing)
        {
            keepGoing = search_and_insert(mNode->get_right_node(), iNode);
        }

        //if left node is not null and keepGoing is true search thru node again
        if (mNode->get_left_node() != nullptr  &&  keepGoing)
        {
            keepGoing = search_and_insert(mNode->get_left_node(), iNode);
        }
    }
    return true;
}

// Insert node
void Expr_Tree_Builder::insert_node (Expr_Node * node)
{
    //temporary node pointer
    Expr_Node * nodeT;

    //number nodes first
    if (node->get_prec() == 1)
    {
        //if head node needs to be set
        if (this->tree->get_main_node() == nullptr)
        {
            this->tree->set_main_node(node);
        }
        //if it needs to be inserted into tree as not the main/head node
        else
        {
            search_and_insert(this->tree->get_main_node(), node);
        }
    }

    //if node isnt a number
    else
    {
        //if main node is a number or if the precedence is less then the current main node 
        //put current node as input node and set left as old main node
        if ((this->tree->get_main_node()->get_prec() == 1)  ||  (this->tree->get_main_node()->get_prec() >= node->get_prec()  &&  node->get_left_node() == nullptr))
        {
            nodeT = this->tree->get_main_node();
            this->tree->set_main_node(node);
            this->tree->get_main_node()->set_left_node(nodeT);
        }
        
        //everything else
        else
        {
            //if trees right node isnt null and node input's left node is null
            //put current node as right node and set its left as old node
            if (this->tree->get_main_node()->get_right_node() != nullptr  &&  node->get_left_node() == nullptr)
            {
                nodeT = this->tree->get_main_node()->get_right_node();
                this->tree->get_main_node()->set_right_node(node);
                this->tree->get_main_node()->get_right_node()->set_left_node(nodeT);
            }
            
            //if node input's left node is null
            //add as right node of main node
            else if (node->get_left_node() == nullptr)
            {
                this->tree->get_main_node()->set_right_node(node);
            }
            
            //beginning of subexpression
            else
            {
                nodeT = this->tree->get_main_node();
				while(nodeT->get_right_node() != nullptr  &&  nodeT->get_prec() != 1)
				{
					nodeT = nodeT->get_right_node();
				}
				
				if(nodeT->get_right_node() == nullptr)
                {
                    nodeT->set_right_node(node);
                }
            }
        }
    }
}

// Set Tree Level
void Expr_Tree_Builder::set_tree_level(int num)
{
	this->tree_level = num;
}

// Get Tree Level
int Expr_Tree_Builder::get_tree_level (void)
{
	return this->tree_level;
}

// Get Main Tree
Expr_Tree * Expr_Tree_Builder::get_main_tree (void)
{
	return this->tree;
}