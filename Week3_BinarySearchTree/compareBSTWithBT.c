#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode *createNode(int key)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into a Binary Search Tree
struct TreeNode *insertBST(struct TreeNode *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insertBST(root->left, key);
    else if (key > root->data)
        root->right = insertBST(root->right, key);

    return root;
}

// Function to create a regular Binary Tree (not a search tree)
struct TreeNode *insertBT(struct TreeNode *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (root->left == NULL)
        root->left = insertBT(root->left, key);
    else
        root->right = insertBT(root->right, key);

    return root;
}

// Function to perform an in-order traversal of a tree
void inOrderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct TreeNode *bstRoot = NULL;
    struct TreeNode *btRoot = NULL;

    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    // Insert keys into Binary Search Tree
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
    {
        bstRoot = insertBST(bstRoot, keys[i]);
    }

    // Insert keys into Binary Tree
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
    {
        btRoot = insertBT(btRoot, keys[i]);
    }

    printf("In-order traversal of Binary Search Tree: ");
    inOrderTraversal(bstRoot);
    printf("\n");

    printf("In-order traversal of Binary Tree: ");
    inOrderTraversal(btRoot);
    printf("\n");

    return 0;
}
