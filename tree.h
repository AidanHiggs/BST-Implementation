#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <vector>

#define TREE_H

class Tree{
    public:
        struct Node {
            std::string name;
            Node* left;
            Node* right;
            Node* parent;
            double data;
            double balanceFactor;
        };
        Node* getRoot(){
            return root;
        };
        Tree();
        ~Tree();
        void insert(std::string name, double data);
        void insert(std::string name, double data, Node* node);
        void print();
        void print(Node* node);
        void deleteNode(std::string name, double data,Node* node, Node* parent);
        void deleteNode(std::string name, double data,Node* node);
        void deleteTreeHelper(Node* node);
    private:
        Node* root;
        


};

#endif
