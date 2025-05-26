#include <iostream>
#include <string>

using namespace std;

class BinTree {
    private:

    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        int value = 0;
        
        Node(){}
        Node(int val) : value(val) {}
        Node(int val, int leftValue, int rightValue) : value(val) {
            left = new Node(leftValue);
            right = new Node(rightValue);
        }
        Node(int val, Node* leftNode, Node* rightNode) : value(val) {
            left = new Node(*leftNode);
            right = new Node(*rightNode);
        }
        Node(Node& other) : value(other.value) {
            if(other.left != nullptr) 
                left = new Node(*other.left);
            if(other.right != nullptr) 
                right = new Node(*other.right);
        }
        Node(Node&& other) : value(other.value) {
            left = other.left;
            right = other.right;
            other.left = other.right = nullptr;
        }
        ~Node() {
            delete left;
            delete right;
        }
        
        Node& operator=(Node& other) = default;
    };

    BinTree(Node* node) : root(node) {}

    void printAug(Node* r, int depth, string arr[]) {
        arr[depth] += to_string(r->value);
        int h = height();
        for(int n = 0; n < (1 << (h - depth - 1)); n++)
            arr[depth] += "\t";

        if(r->left != nullptr) 
            printAug(r->left, depth + 1, arr);
        else for(int m = 1; depth + m < h; m++)
            for(int n = 0; n < (1 << (h - depth - 2)); n++) 
                arr[depth + m] += "\t";

        if(r->right != nullptr) 
            printAug(r->right, depth + 1, arr);
        else for(int m = 1; depth + m < h; m++)
            for(int n = 0; n < (1 << (h - depth - 2)); n++) 
                arr[depth + m] += "\t";
    }

    int height(Node* trace) {
        if(trace == nullptr) return 0;
        int size1 = 0, size2 = 0;
        if(trace->left != nullptr) size1 = height(trace->left);
        if(trace->right != nullptr) size2 = height(trace->right);
        return 1 + (size1 > size2 ? size1 : size2);
    }

    bool includes(int val, Node* trace) {
        if(trace->value == val) return true;
        bool b1, b2;
        if(trace->left != nullptr) b1 = includes(val, trace->left);
        if(trace->right != nullptr) b2 = includes(val, trace->right);
        return b1 || b2;
    }

    int countNodes(Node* trace) {
        if(trace == nullptr) return 0;
        return 1 + countNodes(trace->left) + countNodes(trace->right);
    }
    
    int countLeaves(Node* trace) {
        if(trace == nullptr) return 0;
        if(trace->left == nullptr && trace->right == nullptr) return 1;
        return countLeaves(trace->left) + countLeaves(trace->right);
    }

    Node* root = nullptr;
    public:
    
    BinTree() {}
    BinTree(int val) {
        root = new Node(val);
    }
    BinTree(BinTree& other) {
        if(other.root != nullptr) root = new Node(*other.root);
    }
    BinTree(BinTree&& other) {
        root = other.root;
        other.root = nullptr;
    }
    ~BinTree() {
        delete root;
    }
    
    static BinTree Glue(int root, const BinTree& left, const BinTree& right) {
        return BinTree(new Node(root, left.root, right.root));
    }
    
    static BinTree FromArray(int arr[], int size) {
        if(size == 0) return BinTree();
        
        int sectionSize = 1, index = size - 1, sectionPlace = 0;
        BinTree tree(arr[index--]);

        Node** list = new Node*[sectionSize] {tree.root};
        Node** list2 = new Node*[sectionSize<<1];
        
        while(index >= 0) {
            if((sectionPlace&1) == 0) 
                list2[sectionPlace] = (list[sectionPlace>>1]->left = new Node(arr[index--]));
            else 
                list2[sectionPlace] = (list[sectionPlace>>1]->right = new Node(arr[index--]));
            
            sectionPlace++;
            if((sectionPlace>>1) == sectionSize) {
                delete[] list;
                list = list2;
                sectionSize <<= 1;
                list2 = new Node*[sectionSize<<1];
                sectionPlace = 0;
            }
        }
        delete[] list;
        delete[] list2;
        return tree;
    }
    
    int height() { return height(root); }
    
    void print() {
        string out[height()];
        printAug(root, 0, out);

        for(int n = 0; n < height(); n++)
            cout << out[n] << endl;
    }
    
    bool includes(int value) { return includes(value, root); }
    
    int countNodes() { return countNodes(root); }

    int countLeaves() { return countLeaves(root); }

    BinTree& operator=(BinTree& other) = default;
    
};


int main()
{
    int n1, n2, r, s;
    cin >> n1 >> n2 >> r >> s;
    int arr1[n1], arr2[n2];
    
    for(int n = 0; n < n1; n++) cin >> arr1[n];
    for(int n = 0; n < n2; n++) cin >> arr2[n];
    
    BinTree tree1 = BinTree::FromArray(arr1, n1), tree2 = BinTree::FromArray(arr2, n2);
    BinTree tree = BinTree::Glue(r, tree1, tree2);
    tree.print();
    
    cout << "\n\n";

    cout << "Węzły: " << tree.countNodes() << endl;
    cout << "Liście: " << tree.countLeaves() << endl;
    cout << "Zawiera " << s << ": " << (tree.includes(s) ? "tak" : "nie") << endl;
    return 0;
}