#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else
    {
        if (data <= root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    struct Node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear)
    {
        struct Node *current = queue[++front];
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

int getHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int getDegree(struct Node *root, int key)
{
    if (root == NULL)
    {
        return -1; // Node not found
    }

    if (root->data == key)
    {
        int degree = 0;
        if (root->left != NULL)
        {
            degree++;
        }
        if (root->right != NULL)
        {
            degree++;
        }
        return degree;
    }
    else
    {
        int leftDegree = getDegree(root->left, key);
        int rightDegree = getDegree(root->right, key);

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

int countLeafNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countInternalNodes(struct Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

int countNodesLinkedList(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodesLinkedList(root->left) + countNodesLinkedList(root->right);
}

int countNodesArray(struct Node *arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != NULL)
        {
            count++;
        }
    }
    return count;
}

int countSiblings(struct Node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if ((root->left != NULL && root->left->data == key && root->right != NULL) ||
        (root->right != NULL && root->right->data == key && root->left != NULL))
    {
        return 1;
    }
    return countSiblings(root->left, key) + countSiblings(root->right, key);
}

void displayMenu()
{
    printf("\nMenu:\n");
    printf("1. Create a binary tree using recursive function and display level wise\n");
    printf("2. Create a binary tree using non-recursive function and display level wise\n");
    printf("3. Create a binary tree using array only and display level wise\n");
    printf("4. Identify the height of a binary tree\n");
    printf("5. Identify degree of a given node\n");
    printf("6. Count number of leaf nodes present in a binary tree\n");
    printf("7. Count number of internal nodes present in a binary tree\n");
    printf("8. Count number of nodes present in a given binary tree using linked list\n");
    printf("9. Count number of nodes present in a given binary tree using array\n");
    printf("10. Count number of siblings present in a binary tree\n");
    printf("0. Exit\n");
}

int main()
{
    struct Node *root = NULL;
    int choice, data, key, result;

    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data for the binary tree (enter -1 to stop): ");
            while (1)
            {
                scanf("%d", &data);
                if (data == -1)
                {
                    break;
                }
                root = insertNode(root, data);
            }
            printf("Binary tree created successfully.\n");
            printf("Level Order Traversal: ");
            levelOrderTraversal(root);
            break;

        case 2:
            // Add code for non-recursive binary tree creation
            break;

        case 3:
            // Add code for array-based binary tree creation
            break;

        case 4:
            result = getHeight(root);
            printf("Height of the binary tree: %d\n", result);
            break;

        case 5:
            printf("Enter the node data to find its degree: ");
            scanf("%d", &key);
            result = getDegree(root, key);
            if (result == -1)
            {
                printf("Node not found in the binary tree.\n");
            }
            else
            {
                printf("Degree of the node %d: %d\n", key, result);
            }
            break;

        case 6:
            result = countLeafNodes(root);
            printf("Number of leaf nodes in the binary tree: %d\n", result);
            break;

        case 7:
            result = countInternalNodes(root);
            printf("Number of internal nodes in the binary tree: %d\n", result);
            break;

        case 8:
            result = countNodesLinkedList(root);
            printf("Number of nodes in the binary tree (using linked list): %d\n", result);
            break;

        case 9:
            // Add code for counting nodes using array
            break;

        case 10:
            printf("Enter the node data to find its siblings: ");
            scanf("%d", &key);
            result = countSiblings(root, key);
            printf("Number of siblings of the node %d: %d\n", key, result);
            break;

        case 0:
            printf("Exiting the program. Thank you!\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
