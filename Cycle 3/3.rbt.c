
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int key;
    int color; 
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;


Node* NIL;


Node* createNode(int key, int color) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->color = color;
    newNode->parent = NIL;
    newNode->left = NIL;
    newNode->right = NIL;
    return newNode;
}


void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != NIL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}


void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != NIL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NIL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}


void insertFixup(Node** root, Node* z) {
    while (z->parent->color == 1) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y->color == 1) {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                rightRotate(root, z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y->color == 1) {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = 0;
                z->parent->parent->color = 1;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = 0;
}


void insert(Node** root, int key) {
    Node* z = createNode(key, 1);
    Node* y = NIL;
    Node* x = *root;

    while (x != NIL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == NIL)
        *root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    z->left = NIL;
    z->right = NIL;
    z->color = 1; // Red

    insertFixup(root, z);
}


void inOrderTraversal(Node* root) {
    if (root != NIL) {
        inOrderTraversal(root->left);
        printf("%d (%s) ", root->key, root->color == 0 ? "Black" : "Red");
        inOrderTraversal(root->right);
    }
}

int main() {
    NIL = createNode(0, 0);
    Node* root = NIL;

    int choice, key;

    do {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(&root, key);
                break;
            case 2:
                printf("Red-Black Tree (in-order traversal): \n");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}


