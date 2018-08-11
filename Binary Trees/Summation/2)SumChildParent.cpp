#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};
Node* getNode(int data)
{
    // allocate memory for the node
    Node *newNode = (Node*)malloc(sizeof(Node));

    // put in the data
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int sumOfParentOfXUtil(Node* root, int x){
  queue<Node*> Q;
  Q.push(root);
  Node * temp;
  int sum=0;
  while(!Q.empty()){
    temp=Q.front();
    Q.pop();
    if(temp->left)
    Q.push(temp->left);
    if(temp->right)
    Q.push(temp->right);

    if(temp->left&&temp->left->data==x){
        sum+=temp->data;
    }

  else if(temp->right&&temp->right->data==x){
      sum+=temp->data;
  }
}
return sum;
}
int main(){
    Node *root = getNode(4);           /*        4        */
   root->left = getNode(2);           /*       / \       */
   root->right = getNode(5);          /*      2   5      */
   root->left->left = getNode(7);     /*     / \ / \     */
   root->left->right = getNode(2);    /*    7  2 2  3    */
   root->right->left = getNode(2);
   root->right->right = getNode(3);

   int x = 2;

   cout << "Sum = "
        << sumOfParentOfXUtil(root, x);

   return 0;

}
