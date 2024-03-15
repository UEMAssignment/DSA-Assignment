#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} BST;

BST *createNode(int value)
{
    BST *newNode = (BST *)malloc(sizeof(BST));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BST *insert(BST *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->key)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->key)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void InOrderTraversal(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    printf("%d ", root->key);
    InOrderTraversal(root->right);
}

BST *search(BST *root, int x)
{
    if (root == NULL || root->key == x)
    {
        return root;
    }

    if (root->key < x)
    {
        return search(root->right, x);
    }
    else
    {
        return search(root->left, x);
    }
}

BST *deleteNode(BST *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (value < root->key)
    {
        root->left = deleteNode(root->left, value);
        return root;
    }
    else if (value > root->key)
    {
        root->right = deleteNode(root->right, value);
        return root;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            BST *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            BST *parent = root;
            BST *child = root->right;

            while (child->left != NULL)
            {
                parent = child;
                child = child->left;
            }

            if (parent != root)
            {
                parent->left = child->right;
            }
            else
            {
                parent->right = child->right;
            }

            root->key = child->key;

            free(child);
            return root;
        }
    }
    return root;
}

int main()
{
    BST *root = NULL;
    BST *searchRes = NULL;
    int choice, value;

    do
    {
        printf("\nMenu: \n---------------------\n1. Insert a node\n2. Search a node\n3. DisplayInOrder\n4. Delete a node\n5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            InOrderTraversal(root);
            break;

        case 2:
            printf("Enter the key to search : ");
            scanf("%d", &value);
            searchRes = search(root, value);

            if (searchRes != NULL)
            {
                printf("%d found in the BST.\n", value);
            }
            else
            {
                printf("%d not found in the BST.\n", value);
            }
            break;

        case 3:
            InOrderTraversal(root);
            break;

        case 4:
            printf("Enter the key to delete : ");
            scanf("%d", &value);
            searchRes = search(root, value);

            if (searchRes == NULL)
            {
                printf("%d not found in the BST.\n", value);
            }
            else
            {
                root = deleteNode(root, value);
                printf("%d deleted from the BST.\n", value);
            }
            InOrderTraversal(root);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!!!");
        }

    } while (choice != 5);

    return 0;
}