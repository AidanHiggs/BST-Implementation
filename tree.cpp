#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

Tree::Tree() : root(nullptr){} //isntantiates a root node and sets it to nullptr 

/* 
Insert takes a name and data and inserts it into the tree.
it takes a root ptr, name, and data, if the node is null, it creates a new root node 
if not, it checks if the data is less than the root node data if so it calls itself on the left ptr
if not it calls itself on the right ptr, and does this untill either the left or right ptr is null,
if so it it creates a new node, takes the name and datat of the node and sets the left and right ptrs to null
these are new leaf nodes
*/
void Tree::insert(string name, double data, Tree::Node *node) {
    if (node == nullptr) {
        root= new Tree::Node; //creates a new node if node is null
        root->name = name; //sets the naeme of the new node to the name data passed in
        root->data = data; //same for data 
        root->left= nullptr; //sets the left ptr of the new node to null
        root->right = nullptr; //sets the right ptr of the new node to null
    }
    else if (data < node->data) { 
        if (node->left == nullptr){//if the data is les than the data in the root node
            node->left = new Tree::Node; //creates a new node of the node type and assigns it to the left ptr of the root, or the prev node 
            node->left->name = name; //sets the name of the new node to the name passed in
            node->left->data = data; //same as abvove but for data 
            node->left->left = nullptr; //sets the left ptr of the new node to nullW
            node->left->right = nullptr; //same as above for the right ptr 

        }else{
            insert(name, data, node->left); //recursivly calls the insert function on the left ptr and inserts the name and data passed in
        }
    }else if ( data > node->data) { //if the data is greater than the data in the root node
        if (node->right == nullptr){//if the right ptr if null
            node->right = new Tree::Node; //creates a new node and assigns it to the right ptr
            node->right->name = name;
            node->right->data = data;
            node->right->left = nullptr;
            node->right->right = nullptr;
        }else{
            insert(name, data, node->right); //recursivly calls the insert function on the riht ptr and inserts the name and data passed in
        }
    }
}

void Tree::insert(string name, double data){ //inser helper function
    if (root == nullptr){ //if the root is null
        root = new Tree::Node; //creates a new node
        root->name = name;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }else{
        insert(name, data, root);
    }
}

void Tree::deleteNode(string name, double data,Tree::Node *node, Tree::Node *parent){
   if (node == nullptr){ //if the node is null, return
       return;
   }
   
   else if(data > node->data && node->name != name){ //if data is greater than current node's data and names don't match
       deleteNode(name, data, node->right, node); //recursively search right subtree, current node becomes parent
   }
   else if(data < node->data){ //if data is less than current node's data
       deleteNode(name, data, node->left, node); //recursively search left subtree, current node becomes parent
   }
   
   else if(node->name == name){ //node found
       if (node->left == nullptr && node->right == nullptr){ //case where the node has no children
           if (parent){ //if node has a parent (not root)
               if(parent->left == node){ //if the parent's left ptr is the current node
                   parent->left = nullptr; //set the parent's left ptr to null
               }else{
                   parent->right = nullptr; //set the parent's right ptr to null
               }
           }
           delete node; //free the memory of the leaf node
       }
       
       else if(node->left != nullptr && node->right != nullptr){ //case where the node has two children
           Tree::Node *successor = node->right; //creates a new node and sets it to the right ptr
           Tree::Node *successorParent = node; //creates a new node and sets it to current node as parent
           
           while (successor->left != nullptr){ //find the smallest value in right subtree
               successorParent = successor; //update parent before moving successor
               successor = successor->left; //traverse to next left child
           }
           
           node->data = successor->data; //copy successor's data to node being "deleted"
           node->name = successor->name; //copy successor's name to node being "deleted"
           
           deleteNode(successor->name, successor->data, successor, successorParent); //recursively delete the successor node
       }
       
       else if (node->left == nullptr){ //node with only right child
           Tree::Node *temp = node->right; //store right child to preserve it
           if (parent){ //if node has a parent (not root)
               if(parent->left == node){ //if we're deleting parent's left child
                   parent->left = temp; //connect parent's left to right child
               }else{
                   parent->right = temp; //connect parent's right to right child
               }
               if (temp){ //if the right child exists
                   temp->parent = parent; //update its parent pointer
               }
           }
           delete node; //free the memory of the deleted node
       }
       
       else if(node->right == nullptr){ //node with only left child
           Tree::Node *temp = node->left; //store left child to preserve it
           if (parent){ //if node has a parent (not root)
               if(parent->left == node){ //if we're deleting parent's left child
                   parent->left = temp; //connect parent's left to left child
               }else{
                   parent->right = temp; //connect parent's right to left child
               }
               if (temp){ //if the left child exists
                   temp->parent = parent; //update its parent pointer
               }
           }
           delete node; //free the memory of the deleted node
       }
   }
}
void Tree::print(Tree::Node *node){
    if (node == nullptr){
        return;
    }else{
        print(node->left);
        cout << node->name << " " << node->data << endl;
        print(node->right);
    }
    
}

void Tree::print() {
    print(root);
}

// Single parameter deleteNode implementation
void Tree::deleteNode(std::string name, double data, Node* node) {
    deleteNode(name, data, node, nullptr);
}

// Proper destructor implementation
void deleteTreeHelper(Tree::Node* node) {
    if (node == nullptr) return;
    
    deleteTreeHelper(node->left);   // Delete left subtree
    deleteTreeHelper(node->right);  // Delete right subtree
    delete node;                    // Delete current node
}
 
