// Binary Search Tree operations in C

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct node {
  int data;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}
struct node *insert(struct node *node, int data) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(data);

  // Traverse to the right place and insert the node
  if (data < node->data)
    node->left = insert(node->left, data);
  else
    node->right = insert(node->right, data);

  return node;
}
// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
  }
}
void preorder(struct node *root) {
  if (root != NULL) {
    // Traverse left 
    printf("%d -> ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(struct node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ", root->data);

  }
}
// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int data) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (data < root->data)
    root->left = deleteNode(root->left, data);
  else if (data > root->data)
    root->right = deleteNode(root->right, data);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

// Driver code
int main() {
//clrscr();
  struct node *root = NULL;
int n;
  printf("Enter no of elements: ");
  scanf("%d",&n);
   printf("Enter elements: ");
 
  int data;
  for(int i=0;i<n;i++)
    {
	scanf("%d",&data) ;
        root = insert(root,data);
    }
  printf("Inorder traversal: ");
  inorder(root);
  printf("\npreorder: ");
  preorder(root);
  printf("\npostorder: ");
  postorder(root);
  printf("\nAfter deleting 2\n");
  root = deleteNode(root, 2);
  printf("Inorder traversal: ");
  inorder(root);
  return 0;
}
