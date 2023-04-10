//inserting a node in the binary tree
#include <stdio.h>
#include <stdlib.h>

struct bst_node{
    int key;
    struct bst_node *right_child;
    struct bst_node *left_child;
};

//Create a new BST node and return a pointer to it
struct bst_node *new_node(int data){
    //allocate space for a new bst_node and store the pointer in temp
    struct bst_node *temp = (struct bst_node*)malloc(sizeof(struct bst_node));
    temp->key = data;
    temp->left_child = NULL;
    temp->right_child = NULL;
    return temp;
}

//This function takes data and pointer to root node as an argument and inserts the data in the BST.
struct bst_node* insert(struct bst_node *root, int data){
    //if tree empty return a new node
    if (root == NULL){
        return new_node(data);
    }
    //if data is greater than root
    else if (data > root->key){
        //go left node
        root->right_child = insert(root->right_child, data);
    }
    //if data is less than root
    else if (data < root->key){
        root->left_child = insert(root->left_child, data);
    }
    return root;

}

//print inorder traversal of the bst_tree
void inorder(struct bst_node* root){
    if (root != NULL){
        inorder(root->left_child);
        printf("%d", root->key);
        inorder(root->right_child);
    }
}


int main(){
    struct bst_node *root_ptr;
    root_ptr = NULL;                    //an empty tree is created
    struct bst_node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    return 0;
}
