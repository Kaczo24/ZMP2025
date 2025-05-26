#include <iostream>

using namespace std;

class Btree {
private:
    struct Node {
        int key = 0;
        Node* left = nullptr;
        Node* right = nullptr;
          
        Node(){}
        Node(int val) : key(val) {}
        Node(Node& other) : key(other.key) {
            if(other.left != nullptr) 
                left = new Node(*other.left);
            if(other.right != nullptr) 
                right = new Node(*other.right);
        }
        Node(Node&& other) : key(other.key) {
            if(other.left != nullptr) 
                left = other.left;
            if(other.right != nullptr) 
                right = other.right;
            other.left = other.right = nullptr;
        }
        ~Node(){
            delete left;
            delete right;
        }
        
        void show_node() {
            if (left != nullptr)
                (*left).show_node();
            cout << key << " ";
            if (right != nullptr)
                (*right).show_node();
        }

        int node_count() {
            if(this == nullptr) return 0;
            return 1 + (*left).node_count() + (*right).node_count();
        }
        
        Node& operator=(Node& other) = default;
        
        bool operator==(const Node& other) {
            if(this == nullptr && &other == nullptr)  return true;
            if(this == nullptr || &other == nullptr)  return false;
            return (*left == *other.left) && (*right == *other.right);
        }
        
        Node operator+(const Node& other) {
            Node result(key + other.key);
            if(left != nullptr)
                result.left = new Node((*left) + (*other.left));
            if(right != nullptr)
                result.right = new Node((*right) + (*other.right));
            return result;
        }
        
        Node operator-(const Node& other) {
            Node result(key - other.key);
            if(left != nullptr)
                result.left = new Node((*left) - (*other.left));
            if(right != nullptr)
                result.right = new Node((*right) - (*other.right));
            return result;
        }
        
        friend ostream& operator<<(ostream& os, const Node& node)
        {
            if (node.left != nullptr)
                os << *node.left;
            os << node.key << " ";
            if (node.right != nullptr)
                os << *node.right;
            return os;
        }
    };
    
    Node* root = nullptr;
    
    void insert_node_aux(Node*& node, int new_key) {
        if (node == nullptr) 
            node = new Node(new_key);
        else if (new_key < node->key)
            insert_node_aux(node->left, new_key);
        else 
            insert_node_aux(node->right, new_key);
    }

public:
    
    Btree() {}
    Btree(Btree& other) {
        root = new Node(*other.root);
    }
    Btree(Btree&& other) {
        root = other.root;
        other.root = nullptr;
    }
    ~Btree() {
        delete root;
    }
    
    void insert(int new_key) {
        insert_node_aux(root, new_key);
    }
    
    void show_tree() {
      root->show_node();
      cout << "\n";
    }
    
    int node_count() { return (*root).node_count(); }
    
    bool operator==(const Btree& other) {
        if(this->root == nullptr && other.root == nullptr) return true;
        return *(this->root)==*(other.root);
    }
    bool operator!=(const Btree& other) { return !(*this == other); }
    
    Btree& operator=(const Btree& other) = default;
    
    Btree operator+(const Btree& other) {
        if(*this != other) return *this;
        Btree result;
        result.root = new Node(*this->root + *other.root);
        return result;
    }
    
    Btree operator-(const Btree& other) {
        if(*this != other) return *this;
        Btree result;
        result.root = new Node(*this->root - *other.root);
        return result;
    }
    
    friend ostream& operator<<(ostream& os, const Btree& tree)
    {
        os << *tree.root << endl;
        return os;
    }
    
    friend istream& operator>>(istream& is, Btree& tree)
    {
        int count, temp;
        is >> count;
        for(int n = 0; n < count; n++) {
            is >> temp;
            tree.insert(temp);
        }
        return is;
    }
    
    int& operator[](int index) {
        Node* current = root;
        while(index > 0) {
            int left = (*current->left).node_count();
            if(left >= index) {
                index--;
                current = current->left;
            } else {
                index -= left + 1;
                current = current->right;
            }
        }
        return current->key;
    }
};

int main() {
    Btree tree;
    cin >> tree;
    cout << tree;
    
    Btree tree2;
    cin >> tree2;
    cout << tree2;
    
    if(tree == tree2)
        cout << "Są izomorficzne" << endl << tree + tree2 << tree - tree2;
    else 
        cout << "Nie są izomorficzne" << endl;
        
    for(int n = 0; n < tree.node_count(); n++) 
        cout << tree[n] << endl;
    
    return 0;
}