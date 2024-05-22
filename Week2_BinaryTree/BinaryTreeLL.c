// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     int data;
//     struct node *left, *right;
// } tree;

// tree *createNode()
// {
//     int x;
//     tree *newNode;

//     printf("Enter the data(-1 for no node) : ");
//     scanf("%d", &x);
//     if (x == -1)
//     {
//         return 0;
//     }

//     newNode = (tree *)malloc(sizeof(tree));
//     newNode->data = x;
//     printf("Enter the data for the left child : %d , ", x);
//     newNode->left = createNode();
//     printf("Enter the data for the right child : %d , ", x);
//     newNode->right = createNode();

//     return newNode;
// }

// void preOrder(tree *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     printf("%d ", root->data);
//     preOrder(root->left);
//     preOrder(root->right);
// }

// void inOrder(tree *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     inOrder(root->left);
//     printf("%d ", root->data);
//     inOrder(root->right);
// }

// void postOrder(tree *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     postOrder(root->left);
//     postOrder(root->right);
//     printf("%d ", root->data);
// }

// int height(tree *node)
// {
//     if (node == NULL)
//     {
//         return 0;
//     }
//     else
//     {
//         int lHeight = height(node->left);
//         int rHeight = height(node->right);

//         if (lHeight > rHeight)
//         {
//             return (lHeight + 1);
//         }
//         else
//         {
//             return (rHeight + 1);
//         }
//     }
// }

// void main()
// {
//     tree *root;
//     root = NULL;
//     root = createNode();
//     printf("\nPreOrder is : ");
//     preOrder(root);
//     printf("\nInOrder is : ");
//     inOrder(root);
//     printf("\nPostOrder is : ");
//     postOrder(root);
//     int h = height(root);
//     printf("\nHeight of this Binary Tree : %d", h);
// }

#include <stdio.h>
#include <stdlib.h>

int node_count = 0;
int leaf_count = 0;
int internal_count = 0;

typedef struct node
{
    int data;
    struct node *left, *right;
} tree;

tree *createNode()
{
    int x;
    tree *newNode;

    printf("Enter the data(-1 for no node) : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }

    newNode = (tree *)malloc(sizeof(tree));
    newNode->data = x;
    printf("Enter the data for the left child of %d: ", x);
    newNode->left = createNode();
    printf("Enter the data for the right child of %d: ", x);
    newNode->right = createNode();

    return newNode;
}

void levelOrderTraversal(tree *root)
{
    if (root == NULL)
    {
        return;
    }

    tree *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear)
    {
        tree *current = queue[++front];
        printf("%d ", current->data);

        if (current->left != NULL)
        {
            queue[++rear] = current->left;
        }
        if (current->right != NULL)
        {
            queue[++rear] = current->right;
        }
    }
}

void preOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int height(tree *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int lHeight = height(node->left);
        int rHeight = height(node->right);

        if (lHeight > rHeight)
        {
            return (lHeight + 1);
        }
        else
        {
            return (rHeight + 1);
        }
    }
}

int getDegree(tree *node, int key)
{
    if (node == NULL)
    {
        return -1; // Node not found
    }

    if (node->data == key)
    {
        int degree = 0;
        if (node->left != NULL)
        {
            degree++;
        }
        if (node->right != NULL)
        {
            degree++;
        }
        return degree;
    }
    else
    {
        int leftDegree = getDegree(node->left, key);
        int rightDegree = getDegree(node->right, key);

        if (leftDegree != -1)
        {
            return leftDegree;
        }
        else
        {
            return rightDegree;
        }
    }
}

int countnodes(tree *node)
{
    if (node != NULL)
    {
        countnodes(node->left);
        node_count++;
        countnodes(node->right);
    }
    return node_count;
}

int leafnodes(tree *node)
{
    if (node != NULL)
    {
        leafnodes(node->left);
        if ((node->left == NULL) && (node->right == NULL))
        {
            leaf_count++;
        }
        leafnodes(node->right);
    }
    return leaf_count;
}

int internalnodes(tree *node)
{

    if (node != NULL)
    {
        internalnodes(node->left);
        if ((node->left != NULL) || (node->right != NULL))
        {
            internal_count++;
        }
        internalnodes(node->right);
    }
    return internal_count;
}

int countSiblings(tree *node, int key)
{
    if (node == NULL)
    {
        return 0;
    }
    if ((node->left != NULL && node->left->data == key && node->right != NULL) ||
        (node->right != NULL && node->right->data == key && node->left != NULL))
    {
        return 1;
    }
    return countSiblings(node->left, key) + countSiblings(node->right, key);
}

int main()
{
    tree *root;
    root = NULL;
    int choice, node, degree;
    do
    {
        printf("\n---------------------\nBinary Tree Operations:\n");
        printf("1. Create Tree\n");
        // printf("2. PreOrder Traversal\n");
        // printf("3. InOrder Traversal\n");
        // printf("4. PostOrder Traversal\n");
        printf("4. Height of Tree\n");
        printf("5. Degree of given nodes in Tree\n");
        printf("6. Count of nodes in Tree\n");
        printf("7. Count of leaf nodes in Tree\n");
        printf("8. Count of internal nodes in Tree\n");
        printf("9. Sibling of the given node in Tree\n");
        printf("0. Exit\n---------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            root = createNode();
            levelOrderTraversal(root);
            break;
        // case 2:
        //     printf("PreOrder is : \n");
        //     preOrder(root);
        //     break;
        // case 3:
        //     printf("InOrder is : \n");
        //     inOrder(root);
        //     break;
        // case 4:
        //     printf("PostOrder is : \n");
        //     postOrder(root);
        //     break;
        case 4:
            printf("Height of this Binary Tree : %d\n", height(root));
            break;
        case 5:
            printf("Enter the node data to find its degree: ");
            scanf("%d", &node);
            degree = getDegree(root, node);
            if (degree == -1)
            {
                printf("Node not found in the binary tree.\n");
            }
            else
            {
                printf("Degree of the node %d: %d\n", node, degree);
            }
            break;
        case 6:
            printf("Count of nodes of this Binary Tree : %d\n", countnodes(root));
            break;
        case 7:
            printf("Count of leaf nodes of this Binary Tree : %d\n", leafnodes(root));
            break;
        case 8:
            printf("Count of internal nodes of this Binary Tree : %d\n", internalnodes(root));
            break;
        case 9:
            printf("Enter the data : ");
            scanf("%d", &node);
            printf("Sibling of the given node in this Binary Tree : %d\n", countSiblings(root, node));
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
