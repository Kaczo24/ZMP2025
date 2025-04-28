#include <iostream>
#include <string>

using namespace std;

class BinTree {
    
    public:
    struct Node {
        Node* left;
        Node* right;
        int value = 0;
    };
    void printAug(Node* r, int depth, string arr[]) {
        arr[depth] += to_string(r->value);
        for(int n = 0; n < (1 << (height() - depth - 1)); n++) arr[depth] += "\t";
        if(r->left != nullptr) printAug(r->left, depth + 1, arr);
        if(r->right != nullptr) printAug(r->right, depth + 1, arr);
    }
    
    Node* root;
    
    int height() {
    
        return 3;
    }
    
    void print() {
        string out[height()];
        printAug(root, 0, out);

        for(int n = 0; n < height(); n++)
            cout << out[n] << endl;
    }
    
};


int main()
{
    /*int size, temp;
    cin >> size;
    
    Vector<int> arr;
    
    for(int n = 0; n < size; n++) {
        cin >> temp;
        arr.push(temp);
    }*/
    
    BinTree tree;
    
    tree.root = new BinTree::Node();
    tree.root->value = 1;
    tree.root->left = new BinTree::Node();
    tree.root->right = new BinTree::Node();
    
    tree.root->left->value = 2;
    tree.root->left->left = new BinTree::Node();
    tree.root->left->right = new BinTree::Node();
    
    tree.root->right->value = 3;
    tree.root->right->left = new BinTree::Node();
    tree.root->right->right = new BinTree::Node();
    
    tree.root->left->left->value = 4;
    tree.root->left->right->value = 5;
    tree.root->right->left->value = 6;
    tree.root->right->right->value = 7;
    
    tree.print();
    
    return 0;
}