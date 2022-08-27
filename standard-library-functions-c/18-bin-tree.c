#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;

/* newNode() allocates a new node with the given data and NULL left and
right pointers. */
Node* newNode(int data)
{
    // Allocate memory for new node
    Node* node = (Node*)malloc(sizeof(Node));

    // Assign data to this node
    node->data = data;

    // Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;
    return(node);
}

Node *insert(Node *root, Node *node)
{
    if (root == NULL)
        root = node;
    else if (node->data > root->data)
        root->right = insert(root->right, node);
    else
        root->left = insert(root->left, node);
    return root;
}

void printtree(Node *root)
{
    Node *tmp = root;
    if (tmp == NULL) {
        //~ printf("Empty tree\n");
        return;
    }
    printf("%d ", tmp->data);
    printtree(tmp->left);
    printtree(tmp->right);
    //~ printf("\n");
}

Node *searchNode(Node *root, int value)
{
    Node *tmp = root;
    while (tmp != NULL)
    {
        if (value > tmp->data)
            tmp = tmp->right;
        else if (value < tmp->data)
            tmp = tmp->left;
        else
            return tmp;
    }
    return tmp;
}

int main()
{
    time_t t;
    int i, n, r;
    Node *root = NULL;
    Node *tmp;

    n = 10;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    /* Print 5 random numbers from 0 to 50 */
    for ( i = 0 ; i < n ; i++ ) {
        printf("Create node from: %d\n", r = rand() % 50);
        root = insert(root, newNode(r));
    }
    printtree(root);
    printf("\n");

    printf("Find number %d\n", r = rand() % 50);
    tmp = searchNode(root, r);
    if (tmp != NULL)
        printf("found Node at address %x\n", tmp);
    else
        printf("Value not found in the tree\n");

    return 0;
}

