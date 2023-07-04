#include <iostream>
using namespace std;

struct node
{
    node *left;
    int info;
    node *right;
};

class BST
{
private:
    node *tree;
    void insert(node **p, int val);
    void preorder(node *p);
    void inorder(node *p);
    void postorder(node *p);

public:
    BST();
    void insert(int val);
    void preorder();
    void inorder();
    void postorder();
};
BST::BST()
{
    tree = NULL;
}

void BST::insert(node **p, int val)
{
    if (*p == NULL)
    {
        node *q;
        q = new node;
        q->info = val;
        q->left = NULL;
        q->right = NULL;
        *p = q;
    }
    else
    {
        if ((*p)->info > val)
        {
            insert(&(*p)->left, val);
        }
        else
        {
            insert(&(*p)->right, val);
        }
    }
}

void BST::preorder(node *p)
{
    if (p != NULL)
    {
        std::cout << p->info << "\t";
        preorder(p->left);
        preorder(p->right);
    }
}
void BST::inorder(node *p)
{
    if (p != NULL)
    {
        preorder(p->left);
        std::cout << p->info << "\t";
        preorder(p->right);
    }
}
void BST::postorder(node *p)
{
    if (p != NULL)
    {
        preorder(p->left);
        preorder(p->right);
        std::cout << p->info << "\t";
    }
}

void BST::insert(int val)
{
    insert(&tree, val);
}
void BST::preorder()
{
    preorder(tree);
}
void BST::inorder()
{
    inorder(tree);
}
void BST::postorder()
{
    postorder(tree);
}

int main(int argc, char **argv)
{
    BST tree;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int x = rand() % 100;
        tree.insert(x);
        std::cout << x << "\t";
    }
    std::cout << endl;
    std::cout << "Preorder->";
    tree.preorder();
    std::cout << endl;
    std::cout << "Inorder->";
    tree.inorder();
    std::cout << endl;
    std::cout << "Postorder->";
    tree.postorder();
    return 0;
}