#include<stdio.h>
#include<stdlib.h>

// A node of binary tree
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

// A utility function to create a new Binary Tree node
node* newnode(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// A utility function to find min and max distances with respect
// to root.
void findMinMax(node *node, int *min, int *max, int hd){
    // Base case
    if (node == NULL) return;

    // Update min and max
    if (hd < *min)  *min = hd;
    else if (hd > *max) *max = hd;

    // Recur for left and right subtrees
    findMinMax(node->left, min, max, hd-1);
    findMinMax(node->right, min, max, hd+1);
}

// A utility function to print all nodes on a given line_no.
// hd is horizontal distance of current node with respect to root.
void printVerticalLine(node *node, int line_no, int hd){
    // Base case
    if (node == NULL) return;

    // If this node is on the given line number
    if (hd == line_no) printf("%d ",node->data);

    // Recur for left and right subtrees
    printVerticalLine(node->left, line_no, hd-1);
    printVerticalLine(node->right, line_no, hd+1);
}

// The main function that prints a given binary tree in
// vertical order
void verticalOrder(node *root){
    // Find min and max distances with resepect to root
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    // Iterate through all possible vertical lines starting
    // from the leftmost line and print nodes line by line
    for (int line_no = min; line_no <= max; line_no++){
        printVerticalLine(root, line_no, 0);
        printf("\n");
    }
}

// Driver program to test above functions
int main(){
    // Create binary tree shown in above figure
    node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);
    root->right->right->right = newnode(9);
    
    printf("verticalOrder traversal yields\n");
    verticalOrder(root);
    return 0;
}
