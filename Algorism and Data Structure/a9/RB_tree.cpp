#include <iostream>
using namespace std;

enum Color {RED, BLACK};
struct Node{
    int data;
    Color color;
    Node *left, *right, *parent;
    Node* sibling(){
        if(parent==NULL)
            return NULL;
        if(this == parent->left)
            return parent->right;
        return parent->left;
    }
};
class RedBlackTree{
    private:
        Node *root;
    protected:
        void rotateLeft(Node *);       //let the current input becomes the child of its left child
        void rotateRight(Node *);      //let the current input becomes the child of its right child
    public:
        RedBlackTree();                 //default constructor
        void Insert(int);               //insert a node with data
        void Delete(Node *);           //delete a node of given pointer
        Node* predecessor(const Node *);   //returns the predecessor
        Node* successor(const Node *);     //returns the successor
        Node* TREE_MIN(Node*);              //returns the MIN of the given root
        Node* TREE_MAX(Node*);              //returns the MAX of the given root
        Node* search(int);                  //returns the node of the given data
        void RB_INSERT_FIXUP(Node*);        //6 cases of insert fix up when violates RBT
        void RB_TRANSPLANT(Node*, Node*);   //make the parent of first node becomes the parent of the second
        void RB_DELETE_FIXUP(Node*);        //8 cases of delete fix up when violates RBT
        void inorder(Node *x) {             //print the tree in order
            if (x == NULL)
              return;
            inorder(x->left);
            cout << x->data << " " << x->color << endl;
            inorder(x->right);
        }
        Node* getroot(){                    //returns the root
            return root;
        }
};

void RedBlackTree::rotateLeft(Node* x){
    Node* temp = x->right;
    x->right = temp->left;
    if(temp->left!=NULL)
        temp->left->parent = x;
    temp->parent = x->parent;
    if(x->parent==NULL)
        root = temp;
    else if(x==x->parent->left)
        x->parent->left = temp;
    else
        x->parent->right = temp;

    temp->left = x;
    x->parent = temp;
}

void RedBlackTree::rotateRight(Node* y){
    Node* temp = y->left;
    y->left = temp->right;
    if(temp->right!=NULL)
        temp->right->parent = y;
    temp->parent = y->parent;
    if(y->parent==NULL)
        root = temp;
    else if(y==y->parent->left)
        y->parent->left = temp;
    else
        y->parent->right = temp;
    temp->right = y;
    y->parent = temp;
}

RedBlackTree::RedBlackTree(){
    root = NULL;
}

void RedBlackTree::Insert(int d){
    Node* z = new Node;
    z->data = d;

    Node *y = NULL;
    Node *x = root;
    while(x!=NULL){
        y = x;
        if(z->data<x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if(y==NULL)
        root = z;
    else if(z->data<y->data)
        y->left = z;
    else
        y->right = z;
    z->left = NULL;
    z->right = NULL;
    z->color = RED;
    RB_INSERT_FIXUP(z);
}

void RedBlackTree::Delete(Node* z){
    if(z==NULL){
        cout << "Error: tree is empty!" << endl;
        return;
    }
    Node* rep;
    if(z->right!=NULL && z->left!=NULL)
        rep = successor(z->right);
    else if(z->right==NULL && z->left==NULL)
        rep = NULL;
    else if(z->right!=NULL)
        rep = z->right;
    else rep = z->left;


    if(rep==NULL){
        if(z==root)
            root=NULL;
        else{
            if((rep==NULL || rep->color==BLACK)&&(z->color==BLACK))
                RB_DELETE_FIXUP(z);
            else{
                if(z->sibling()!=NULL)
                    z->sibling()->color = RED;
            }
            if(z==z->parent->left)
                z->parent->left = NULL;
            else
                z->parent->right = NULL;
        }

    delete z;
    return;
    }
    int num;
    num = z->data;
    z->data = rep->data;
    rep->data = num;
    Delete(rep);
}
Node* RedBlackTree::predecessor(const Node* x){
    if(x->left==NULL){
        if(x==TREE_MIN(root))
            return NULL;
        if(x==x->parent->right)
            return x->parent;
        else
            return x->parent->parent;
    }
    else{
        return TREE_MAX(x->left);
    }
}

Node* RedBlackTree::successor(const Node* x){
    if(x->right==NULL){
        if(x==TREE_MAX(root))
            return NULL;
        if(x==x->parent->left)
            return x->parent;
        else
            return x->parent->parent;
    }
    else{
        return TREE_MIN(x->right);
    }
}

Node* RedBlackTree::TREE_MIN(Node* x){
    while(x->left!=NULL){
        x = x->left;
    }
    return x;
}

Node* RedBlackTree::TREE_MAX(Node* x){
    while(x->right!=NULL){
        x = x->right;
    }
    return x;
}

Node* RedBlackTree::search(int d){
    Node* temp = root;
    while(temp->data!=d){
        if(temp->data>d)
            temp = temp->left;
        else
            temp = temp->right;
        if(temp==NULL){
            cout << "Error: no such number in the tree!" << endl;
        return NULL;
        }
    }
    return temp;
}

void RedBlackTree::RB_INSERT_FIXUP(Node* z){
    if(z==root){
        z->color = BLACK;
        return;
    }

    if(z->parent->color==RED){
        if(z->parent == z->parent->parent->left){
            Node* y = z->parent->parent->right;
            Color y_color;
            if(y==NULL)
                y_color = BLACK;
            else
                y_color = RED;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                RB_INSERT_FIXUP(z->parent->parent);
            }
            else{
                if(z == z->parent->right){
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(z->parent->parent);
            }
        }
        else{
            Node* y = z->parent->parent->left;
            Color y_color;
            if(y==NULL)
                y_color = BLACK;
            else
                y_color = RED;
            if(y_color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                RB_INSERT_FIXUP(z->parent->parent);
            }
            else{
                if(z == z->parent->left){
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}
void RedBlackTree::RB_TRANSPLANT(Node* x, Node* y){
    if(x==root){
        y = root;
        return;
    }
    y->parent = x->parent;
    if(x==x->parent->left)
        y->parent->left = y;
    else
        y->parent->right = y;
}

void RedBlackTree::RB_DELETE_FIXUP(Node* x){
    if(x==root)
        return;
    if(x->sibling()==NULL)
        RB_DELETE_FIXUP(x->parent);
    else{
        if(x->sibling()->color==RED){
            x->parent->color = RED;
            x->sibling()->color = BLACK;
            if(x->sibling()==x->parent->left)
                rotateRight(x->parent);
            else rotateLeft(x->parent);
            RB_DELETE_FIXUP(x);
        }else{
            if((x->sibling()->left!=NULL && x->sibling()->left->color==RED)
            ||(x->sibling()->right!=NULL && x->sibling()->right->color==RED)){
                if(x->sibling()->left!=NULL && x->sibling()->left->color){
                    if(x->sibling()==x->parent->left){
                        x->sibling()->left->color = x->sibling()->color;
                        x->sibling()->color = x->parent->color;
                    }else{
                        x->sibling()->left->color = x->parent->color;
                        rotateRight(x->sibling());
                        rotateLeft(x->parent);
                    }
                }
                else{
                    if(x->sibling()==x->parent->left){
                        x->sibling()->right->color = x->parent->color;
                        rotateLeft(x->sibling());
                        rotateRight(x->parent);
                    }else{
                        x->sibling()->right->color = x->sibling()->color;
                        x->sibling()->color = x->parent->color;
                        rotateLeft(x->parent);
                    }
                }
                x->parent->color = BLACK;
            }else{
                x->sibling()->color = RED;
                if(x->parent->color==BLACK)
                    RB_DELETE_FIXUP(x->parent);
                else
                    x->parent->color = BLACK;
            }
        }
    }
}

int main(){
    RedBlackTree a;
    a.Insert(10);
    a.Insert(8);
    a.Insert(15);
    a.Insert(18);
    a.Insert(20);
    a.Insert(9);
    a.Insert(1);
    a.Insert(30);

    Node* temp = a.search(18);
    temp = a.search(10);
    a.Delete(temp);

    a.inorder(a.getroot());
//    Node* r = a.getroot();
//    cout << r->data;
}
