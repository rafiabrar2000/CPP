#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

TreeNode* root = NULL;

TreeNode* createTreeNode(int data)
{
    TreeNode* temp = new TreeNode();
    temp->value = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
}

void Insert(int data)
{
    if(root==NULL)
    {
        root = createTreeNode(data);
        return;
    }

    TreeNode* tempExtra = NULL;
    TreeNode* temp = root;

    while(temp!=NULL)
    {
        tempExtra = temp;
        if(data<temp->value)
            temp = temp->leftChild;
        else
            temp = temp->rightChild;
    }

    if(data < tempExtra->value)
        tempExtra->leftChild = createTreeNode(data);
    else
        tempExtra->rightChild = createTreeNode(data);
}

TreeNode* Search(int data)
{
    TreeNode* temp = root;

    while(temp!=NULL)
    {
        if(data==temp->value){
            return temp;
        }
        else if(data<temp->value){
            temp = temp->leftChild;
        }
        else{
            temp = temp->rightChild;
        }
    return NULL;
    }
}

void Inorder(TreeNode* root)
{
    if(root!=NULL)
    {
        Inorder(root->leftChild);
        cout << root->value << " ";
        Inorder(root->rightChild);
    }
}

void Delete(int data)
{
    TreeNode* PresentNode=root;
    TreeNode* PreviousNodeOfPresentNode=root;

    //To find out the location of the node to be deleted and the location of its previous node
    while((PresentNode!=NULL) && (PresentNode->value!=data)){
        PreviousNodeOfPresentNode=PresentNode;
        if(data<PresentNode->value){
            PresentNode=PresentNode->leftChild;
        }
        else if(data>PresentNode->value){
            PresentNode=PresentNode->rightChild;
        }
    }
    //If the node to be deleted has 2 children
    if(PresentNode->leftChild!=NULL && PresentNode->rightChild!=NULL){
        PreviousNodeOfPresentNode=PresentNode;
        TreeNode* descendants = PresentNode->rightChild;
        while(descendants->leftChild!=NULL){
            PreviousNodeOfPresentNode=descendants;
            descendants=descendants->leftChild;
        }
        PresentNode->value=descendants->value;
        if(PreviousNodeOfPresentNode->leftChild==descendants){
            PreviousNodeOfPresentNode->leftChild=NULL;
        }
        else{
            PreviousNodeOfPresentNode->rightChild=NULL;
        }
        delete(PresentNode);
        cout << "After deletion";
        cout << "\n";
        Inorder(root);
    }
    //If the node to be deleted has only one leftchild
    else if(PresentNode->leftChild!=NULL && PresentNode->rightChild==NULL){
        if(PreviousNodeOfPresentNode->leftChild==PresentNode){
            PreviousNodeOfPresentNode->leftChild=PresentNode->leftChild;
        }
        else{
            PreviousNodeOfPresentNode->rightChild=PresentNode->rightChild;
        }
        delete(PresentNode);
        cout << "After deletion";
        cout << "\n";
        Inorder(root);
    }
    //If the node to be deleted has only one rightchild
    else if(PresentNode->leftChild==NULL && PresentNode->rightChild!=NULL){
        if(PreviousNodeOfPresentNode->leftChild==PresentNode){
            PreviousNodeOfPresentNode->leftChild=PresentNode->rightChild;
        }
        else{
            PreviousNodeOfPresentNode->rightChild=PresentNode->rightChild;
        }
        delete(PresentNode);
        cout << "After deletion";
        cout << "\n";
        Inorder(root);
    }
    //If the node to be deleted has no child or it is a leaf node
    else if(PresentNode->leftChild==NULL && PresentNode->rightChild==NULL){
        if(PreviousNodeOfPresentNode->leftChild==PresentNode){
            PreviousNodeOfPresentNode->leftChild=NULL;
        }
        else{
            PreviousNodeOfPresentNode->rightChild=NULL;
        }
        delete(PresentNode);
        cout << "After deletion";
        cout << "\n";
        Inorder(root);
    }




}

int main()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin >> temp;
        Insert(temp);
    }

    Inorder(root);
    cout << "\n";
    Delete(15);
    return 0;
}
