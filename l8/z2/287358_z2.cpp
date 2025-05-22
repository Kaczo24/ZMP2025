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
            if(other.left != nullptr) left = new Node(*other.left);
            if(other.right != nullptr) right = new Node(*other.right);
        }
        Node(Node&& other) : key(other.key) {
            if(other.left != nullptr) left = new Node(*other.left);
            if(other.right != nullptr) right = new Node(*other.right);
        }
        ~Node(){
            cout << "deleting " << key << endl; 
            delete left;
            delete right;
        }
        
        void show_node(){
            if (left!=nullptr)
                (*left).show_node();
            cout << key << " ";
            if (right!=nullptr)
                (*right).show_node();
        }
        
        Node& operator=(Node& other) = default;
        
        bool operator==(Node &other) {
            if(this == nullptr && &other == nullptr)  return true;
            if(this == nullptr || &other == nullptr)  return false;
            return (*left == *other.left) && (*right == *other.right);
        }
        
        Node& operator+(Node &other) {
            cout << "adding " << key << endl; 
            Node a, b, result;
            result.key = key + other.key;
            if(left != nullptr) {
                a = (*left) + (*other.left);
                result.left = &a;
            }
            if(right != nullptr) {
                b = (*right) + (*other.right);
                result.right = &b;
            }
            return result;
        }
    };
    
    Node* root = nullptr;
    
public:
    
    Btree() {}
    //Btree(Btree& other) {
    //    root = new Node(*other.root);
    //}
    //Btree(Btree&& other) {
    //    *root = move(*other.root);
    //}
    ~Btree(){
        delete root;
    }
    
    void insert(int new_key){
        insert_node_aux(root,new_key);
    }
    
    void insert_node_aux(Node*& node, int new_key) {
        if (node == nullptr) 
            node=new Node(new_key);
        else if (new_key < node->key)
            insert_node_aux(node->left,new_key);
        else 
            insert_node_aux(node->right,new_key);
    }
    
    void show_tree() {
      root->show_node();
      cout << "\n";
    }
    
    bool operator==(Btree &other) {
        if(this->root == nullptr && other.root == nullptr) return true;
        return *(this->root)==*(other.root);
    }
    bool operator!=(Btree &other) {return !(*this == other);}
    
    Btree& operator+(Btree &other) {
        if(*this != other) return *this;
        Btree result;
        Node r = *this->root + *other.root;
        cout << "adding done" << endl;
        result.root = &r;
        return result;
    }
    
};

int main(){
  Btree tree = Btree();
  tree.insert(10);
  tree.insert(8);
  tree.insert(19);
  tree.show_tree();
  
  Btree tree2 = Btree();
  tree2.insert(10);
  tree2.insert(8);
  tree2.insert(19);
  tree2.show_tree();
  
  
  
  Btree res = (tree + tree);
  res.show_tree();
  
  return 0;
}