#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
struct Queue {
    struct Node** arr;
    int front, rear, size, capacity;
};
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return q;
}

int isFull(struct Queue* q) {
    return (q->size == q->capacity);
}

int isEmpty(struct Queue* q) {
    return (q->size == 0);
}

void enqueue(struct Queue* q, struct Node* node) {
    if (isFull(q)) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = node;
    q->size++;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    struct Queue* q = createQueue(100);
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* temp = dequeue(q);
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(q, temp->left);
        if (temp->right != NULL)
            enqueue(q, temp->right);
    }
}
int main() {
    /* Example Tree:
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Level-order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
