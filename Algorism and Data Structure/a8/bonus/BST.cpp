#include <iostream>
using namespace std;

class BST{
    private:
        int data;
        BST* left;
        BST* right;
    public:
        BST();
        BST(int root);
        BST* Insert(BST* root, int value);      //insert a value
        int getData();
        void Inorder(BST*);
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

int BST::getData(){
    return data;
}
void BST::Inorder(BST* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);

    cout << root->data << endl;

    Inorder(root->right);
}

class Node{
    private:
        int data;
        Node* next;
    public:
        Node();
        Node(int);
        Node* append(Node*, int);       //add a node to the end
        int getData(Node*);
        void setData(Node*, int n);
        void makeNext(Node*&);          //make the pointer goes to next node
        Node* getNext(Node*);
        int Length(Node*);              //returns the length of the linked list
        BST* Convert(Node*, int, int, BST, BST*);   // convert a linked list into a BST
};

Node::Node():data(0), next(NULL){}

Node::Node(int d):data(d), next(NULL){}

Node* Node::append(Node* N, int n){
    if(!N)
        return new Node(n);
    Node* temp = new Node;
    temp->data = n;
    temp->next = NULL;
    while(N->next!=NULL){
        N = N->next;
    }
    N->next = temp;
    return N;
}

int Node::getData(Node* N){
    return N->data;
}

void Node::setData(Node* N, int n){
    N->data = n;
}

void Node::makeNext(Node* &N){
    N = N->next;
}

Node* Node::getNext(Node* N){
    return N->next;
}

int Node::Length(Node* N){
    if(!N)
        return 0;
    int count = 1;
    while(N->next!=NULL){
        count++;
        N = N->next;
    }
    return count;
}

BST* Node::Convert(Node* N, int head, int tail, BST B, BST* root){
    Node* temp = N;
    for(int i=0; i<head; i++)
        temp = temp->next;
    int value;
    for(int i=0; i<(tail-head)/2; i++){
        temp = temp->next;
    }
    value = temp->data;
    if(!root){
        root = B.Insert(root, value);
    }else{
        B.Insert(root, value);
    }

    if(tail-head<=2){
        if(tail==Length(N)-1){
            temp = temp->next;
            B.Insert(root, temp->data);
        }
        return root;
    }
    Convert(N, head, (tail-head)/2+head, B, root);
    Convert(N, head+(tail-head)/2, tail, B, root);
    return root;
}




int main(){
    Node n;
    Node* N = NULL;
    N = n.append(N, 10);
    n.append(N, 45);
    n.append(N, 78);
    n.append(N, 24);
    n.append(N, 8);
    n.append(N, 82);
    n.append(N, 99);
    n.append(N, 36);

    BST B;
    BST* root = NULL;
    int tail = n.Length(N)-1;
    root = n.Convert(N, 0, tail, B, root);

    B.Inorder(root);

}
