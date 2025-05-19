#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
      
    Node(){
        key=0;
        left=nullptr;
        right=nullptr;
    }
    Node(int val){
        key=val;
        left=nullptr;
        right=nullptr;
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
    
    bool operator==(Node* other) {
        if(this == nullptr && other == nullptr)  return true;
        if(this == nullptr && other != nullptr)  return false;
        if(this != nullptr && other == nullptr)  return false;
        return (this->left == other->left) && (this->right == other->right);
    }
  
};

class Btree {
  private:
    Node* root;
  public:
    Btree(){
      root=nullptr;
    }
    ~Btree(){
      delete root;
    }
    void insert(int new_key){
      insert_node_aux(root,new_key);
    }
    void insert_node_aux(Node*& node, int new_key){
      if (node == nullptr){
        node=new Node(new_key);
      }
      else if (new_key < node->key){
        insert_node_aux(node->left,new_key);
      }
      else {
        insert_node_aux(node->right,new_key);
      }
    }
    void show_tree(){
      root->show_node();
      cout << "\n";
    }
    
    bool operator==(Btree* other) {
        if(this->root == nullptr && other->root == nullptr) return true;
        return *(this->root)==(other->root);
    }
    
};

int main(){
  Btree tree;
  tree.insert(10);
  tree.insert(8);
  tree.insert(15);
  tree.insert(7);
  tree.insert(9);
  tree.insert(12);
  tree.insert(19);
  tree.show_tree();
  
  Btree tree2;
  tree2.insert(10);
  tree2.insert(8);
  tree2.insert(15);
  tree2.insert(7);
  tree2.insert(9);
  tree2.insert(12);
  
  
  cout << (tree == &tree2);
  
  tree2.insert(19);
  
  cout << (tree == &tree2);
  
  
  return 0;
}