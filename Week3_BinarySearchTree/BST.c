#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} BST;

BST *createNode(int data)
{
    BST *newNode = (BST *)malloc(sizeof(BST));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST *insertNode(BST *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
}

BST *insertNodeNonRecursive(BST *root, int data)
{
    BST *newNode = createNode(data);
    if (root == NULL)
    {
        return newNode;
    }

    BST *current = root;
    while (1)
    {
        if (data < current->data)
        {
            if (current->left == NULL)
            {
                current->left = newNode;
                break;
            }
            else
            {
                current = current->left;
            }
        }
        else if (data > current->data)
        {
            if (current->right == NULL)
            {
                current->right = newNode;
                break;
            }
            else
            {
                current = current->right;
            }
        }
        else
        {
            // Handle duplicates
            // You can decide whether to insert on the left or right subtree
            // For example, let's insert duplicates on the right subtree
            if (current->right == NULL)
            {
                current->right = newNode;
                break;
            }
            else
            {
                current = current->right;
            }
        }
    }

    return root;
}

BST *searchElement(BST *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return searchElement(root->left, key);
    }

    return searchElement(root->right, key);
}

void displayBST_InOrderForCharacters(BST *root)
{
    if (root != NULL)
    {
        displayBST_InOrderForCharacters(root->left);
        printf("%c ", root->data);
        displayBST_InOrderForCharacters(root->right);
    }
}

void displayBST_InOrder(BST *root)
{
    if (root != NULL)
    {
        displayBST_InOrder(root->left);
        printf("%d ", root->data);
        displayBST_InOrder(root->right);
    }
}

void displayBST_PreOrder(BST *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        displayBST_PreOrder(root->left);
        displayBST_PreOrder(root->right);
    }
}

void displayBST_PostOrder(BST *root)
{
    if (root != NULL)
    {
        displayBST_PostOrder(root->left);
        displayBST_PostOrder(root->right);
        printf("%d ", root->data);
    }
}

void sortingCharactersInBST(BST *root)
{
    char charElement;
    printf("Enter characters (type '$' to stop): ");
    while (1)
    {
        scanf(" %c", &charElement);
        if (charElement == '$')
            break;
        root = insertNode(root, charElement);
    }
    printf("Sorted sequence of characters using BST: ");
    displayBST_InOrderForCharacters(root);
    printf("\n");
}

void sortingTheSetOfIntegers(BST *root)
{
    int element;
    printf("Enter integers (type -1 to stop): ");
    while (1)
    {
        scanf("%d", &element);
        if (element == -1)
            break;
        root = insertNode(root, element);
    }
    printf("Sorted sequence of integers using BST: ");
    displayBST_InOrder(root);
}

int countNodes(BST *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        return leftCount + rightCount + 1;
    }
}

int findHighestElement(BST *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int main()
{
    int choice, element, key;
    char charElement;
    BST *root = NULL;
    do
    {
        printf("\n\n---------------------------------------\nMenu\n---------------------------------------\n");
        printf("1.Create a BST using recursive function and display\n");
        printf("2.Create a BST using non-recursive function and display\n");
        printf("3.Insert a specific element\n");
        printf("4.Search an element\n");
        printf("5.Take input from user and display the sorted sequence of characters using BST\n");
        printf("6.Sort a set of integers using binary search tree\n");
        printf("7.Dislay a BST using pre-order, post-order, in-order\n");
        printf("8.Count the number of nodes in BST and display highest element\n");
        printf("0.Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            printf("Enter the element : ");
            scanf("%d", &element);
            root = insertNode(root, element);
            displayBST_InOrder(root);
            break;
        case 2:
            printf("Enter the element : ");
            scanf("%d", &element);
            root = insertNodeNonRecursive(root, element);
            displayBST_InOrder(root);
            break;
        case 3:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            root = insertNode(root, element);
            displayBST_InOrder(root);
            break;
        case 4:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            if (searchElement(root, key) != NULL)
                printf("Element found in the BST.\n");
            else
                printf("Element not found in the BST.\n");
            break;
        case 5:
            sortingCharactersInBST(root);
            break;
        case 6:
            sortingTheSetOfIntegers(root);
            break;
        case 7:
            printf("\nIn-Order Traversal : ");
            displayBST_InOrder(root);
            printf("\nPre-Order Traversal : ");
            displayBST_PreOrder(root);
            printf("\nPost-Order Traversal : ");
            displayBST_PostOrder(root);
            break;
        case 8:
            printf("Number of nodes in BST: %d\n", countNodes(root));
            printf("Highest element in BST: %d\n", findHighestElement(root));
            break;
        }
    } while (choice != 0);
    return 0;
}