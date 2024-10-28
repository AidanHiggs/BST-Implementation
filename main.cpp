#include <iostream>
#include <cassert>
#include "tree.h"


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
    
    // Build a more complex tree for testing
    tree.insert("root", 50);
    tree.insert("l1", 30);
    tree.insert("r1", 70);
    tree.insert("l2", 20);
    tree.insert("l3", 40);
    tree.insert("r2", 60);
    tree.insert("r3", 80);
    
    // Verify initial structure
    verifyNode(tree.getRoot(), "root", 50);
    verifyNode(tree.getRoot()->left, "l1", 30);
    verifyNode(tree.getRoot()->right, "r1", 70);
    
    // Test deletions
    tree.deleteNode("l3", 40, tree.getRoot());  // Delete leaf
    assert(tree.getRoot()->left->right == nullptr);  // Verify l3 is gone
    
    tree.deleteNode("r1", 70, tree.getRoot());  // Delete with two children
    verifyNode(tree.getRoot()->right, "r2", 60);  // Verify r2 replaced r1
    
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