#include <iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* createNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode* getMin(BstNode* root) {
    while(root->left != NULL) root = root->left;
    return root;
}

BstNode* getMax(BstNode* root) {
    while(root->right != NULL) root = root->right;
    return root;
}

BstNode* Delete(BstNode* root, int data) {
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if(root->left == NULL) {
            BstNode* temp = root;
            root = root->right;
            delete temp;
        } else if(root->right == NULL) {
            BstNode* temp = root;
            root = root->right;
            delete temp;
        } else {
            BstNode* temp = getMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
}

BstNode* insert(BstNode* root,int data) {
	if(root == NULL) root = createNode(data);
	else if(data <= root->data)
		root->left = insert(root->left,data);
	else
		root->right = insert(root->right,data);
	return root;
}

void Iterable(BstNode* root) {
    if(root == NULL) return;
    Iterable(root->left);
    cout << root->data << " ";
    Iterable(root->right);
}

BstNode* get(BstNode* root, int data) {
    if(root == NULL) return root;
    else if(root->data == data) return root;
    else if(data <= root->data) return get(root->left, data);
    else return get(root->right, data);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    BstNode* root = NULL;
    root = insert(root, rand() % 100);
    root = insert(root, rand() % 100);
    root = insert(root, rand() % 100);
    root = insert(root, rand() % 100);
    root = insert(root, rand() % 100);

    root = Delete(root, rand() % 100);
    cout << root->data << " was deleted\n";
    cout << "Inorder traversal:\n";
    Iterable(root);
    cout << "\n";
    cout << get(root, rand() % 100);
    return 0;
}