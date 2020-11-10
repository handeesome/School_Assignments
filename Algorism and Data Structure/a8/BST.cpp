#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
};

class BST{
    private:
        int data;
        BST* left;
        BST* right;
    public:
        BST();
        BST(int root);
        BST* Insert(BST* root, int value);      //insert a value
        void Inorder(BST* root, Node* &tail);   //convert BST into sorted linked list start from tail->next
};

BST::BST():data(0), left(NULL), right(NULL){}

BST::BST(int root):data(root), left(NULL), right(NULL){}

BST* BST::Insert(BST* root, int value){
    if(root==NULL)
        return new BST(value);
    if(value < root->data){
        root->left = Insert(root->left, value);
    }else{
        root->right = Insert(root->right, value);
    }
    return root;
}

void BST::Inorder(BST* root, Node* &tail){
    if(root==NULL){
        return;
    }
    Inorder(root->left, tail);

    Node* temp = new Node;
    temp->data = root->data;
    temp->next = NULL;
    tail->next = temp;
    tail = tail->next;

    Inorder(root->right, tail);
}



int main(){
    BST b;
    BST* root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);


    Node* N = new Node;
    N->data = 0;
    N->next = NULL;
    Node* tail = N;

    b.Inorder(root, tail);

    for(int i=0; i<7; i++){
        N = N->next;
        cout << N->data << endl;
    }
}
