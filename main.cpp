#include <iostream>
#include <cassert>
#include "tree.h"

using namespace std;
void testInsert() {
    Tree tree;
    
    // Test 1: Insert into empty tree
    tree.insert("root", 10);
    assert(tree.getRoot() != nullptr);
    assert(tree.getRoot()->data == 10);
    assert(tree.getRoot()->name == "root");
    
    // Test 2: Insert smaller value (should go left)
    tree.insert("left", 5);
    assert(tree.getRoot()->left != nullptr);
    assert(tree.getRoot()->left->data == 5);
    assert(tree.getRoot()->left->name == "left");
    
    // Test 3: Insert larger value (should go right)
    tree.insert("right", 15);
    assert(tree.getRoot()->right != nullptr);
    assert(tree.getRoot()->right->data == 15);
    assert(tree.getRoot()->right->name == "right");
    
    std::cout << "Insert tests completed successfully\n";
}

void verifyNode(Tree::Node* node, const std::string& expectedName, double expectedData) {
    assert(node != nullptr);
    assert(node->name == expectedName);
    assert(node->data == expectedData);
}

void testComplexTree() {
    Tree tree;
    
    // Build a more complex tree with 10 values
    tree.insert("root", 50);
    tree.insert("l1", 30);
    tree.insert("r1", 70);
    tree.insert("l2", 20);
    tree.insert("l3", 40);
    tree.insert("r2", 60);
    tree.insert("r3", 80);
    tree.insert("l4", 10);
    tree.insert("r4", 65);
    tree.insert("l5", 35);
    
    cout << "\nTree before deletions:\n";
    tree.print();
    
    cout << "\nDeleting l3 (40):\n";
    tree.deleteNode("l3", 40, tree.getRoot());
    cout << "Tree after deleting l3:\n";
    tree.print();
    
    cout << "\nDeleting r1 (70):\n";
    tree.deleteNode("r1", 70, tree.getRoot());
    cout << "Tree after deleting r1:\n";
    tree.print();
    
    // Changed this line - we expect r3 (80) to be the new value here
    verifyNode(tree.getRoot()->right, "r3", 80);
    
    std::cout << "Complex tree tests completed successfully\n";
}
int main() {
    std::cout << "Starting BST tests...\n\n";
    
    testInsert();
    std::cout << "-----------------\n";
    
    testComplexTree();
    std::cout << "-----------------\n";
    
    std::cout << "All tests completed!\n";
    return 0;
}