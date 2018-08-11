//https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1

{
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	Node* left, *right;
};
/* utility that allocates a new Node with the given key */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}
long int sumBT(Node* root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
child = newNode(n2);
   if (lr == 'L')
     parent->left = child;
   else
     parent->right = child;
   m[n2]  = child;
}
cout<<sumBT(root)<<endl;
}
return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Structure of the node of the binary tree
struct Node
{
int key;
Node* left, *right;
};
*/
// Function should return the sum of all the elements
// of the binary tree
long int sumBT(Node* root)
{
// Code here
if(!root)
return 0;
queue<struct Node*> Q;
Q.push(root);

long int sum=0;
struct Node* temp;

while(!Q.empty()){
   temp=Q.front();
   sum+=temp->key;
   Q.pop();
   if(temp->left){
   Q.push(temp->left);
   }
   if(temp->right){
   Q.push(temp->right);
   }


}
return sum;
}