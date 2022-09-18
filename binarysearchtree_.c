// search tree.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
 int data;
 struct node *left, *right;
}sn;

sn* newNode(int item)
{
 sn* temp = (sn*)malloc(sizeof(sn));
 temp->data = item;
 temp->left = temp->right = NULL;
 return temp;
}

int search(sn* node,int data){  
    if (node==NULL) return 0;
    else if (node->data == data) return 1;
    else if (data <= node->data) return search (node->left,data);
    else return search (node->right,data);

}

sn* insert(sn* node, int data)
{
 /* If the tree is empty, return a new node */
 if (node == NULL)
  return newNode(data);

 /* Otherwise, recur down the tree */
 if (data < node->data)
  node->left = insert(node->left, data);
 else if (data > node->data)
  node->right = insert(node->right, data);

 /* return the (unchanged) node pointer */
 return node;
}

int main()
{
 /* 
   50
  /  \
  30  70
  / \ / \
 20 40 60 80 */
 sn* root = NULL;
 root = insert(root, 50);
 insert(root, 30);
 insert(root, 20);
 insert(root, 40);
 insert(root, 70);
 insert(root, 60);
 insert(root, 80);

 int n;
 printf("enter the number to be searched:\n");
 scanf("%d",&n);
 if (search(root,n)== 1) printf("Found");
 else printf("Not Found");

 return 0;
}
