#include <iostream>

using namespace std;

class Btree {
private:
    struct Node {
        int key = 0;
        Node* left = nullptr;
        Node* right = nullptr;
          
        Node(){}
        Node(int val){
            key = val;
        }
        Node(int val, Node* _left, Node* _right){
            key = val;
            left = _left;
            right = _right;
        }
        ~Node(){
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
        
        bool operator==(Node &other) {
            if(this == nullptr && &other == nullptr)  return true;
            if(this == nullptr || &other == nullptr)  return false;
            return (*left == *other.left) && (*right == *other.right);
        }
        
        Node operator+(Node &other) {
            if(this == nullptr || &other == nullptr)  return *this;
            
            Node a, b, result = Node(key + other.key);
            if(left != nullptr) {
                a = (*left) + (*other.left);
                result.left = &a;
            }
            if(right != nullptr) {
                a = (*right) + (*other.right);
                result.right = &a;
            }
            return Node(key + other.key, &a, &b);
        }
    };
    
    Node* root = nullptr;
    
public:
    
    Btree(){}
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
    bool operator!=(Btree other) {return !(*this == other);}
    
    Btree operator+(Btree &other) {
        if(*this != other) return *this;
        Btree result = Btree();
        *result.root = (*this->root + *other.root);
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
  
  
  
  auto res = (tree + tree2);
  res.show_tree();
  
  return 0;
}