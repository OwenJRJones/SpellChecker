#include "BST.h"
#include <iostream>

using namespace std;

void BST::insert(string word) {
    // Use recursive insert function
    insert(word, m_root);
}

void BST::insert(string word, NodePtr &node) {
    // Recursive insert function
    if (node == nullptr) {
        // Create new node and store data
        node = new Node();
        node->m_data = word;
    } else if (compare(word, node) == -1) {
        // Go left
        insert(word, node->m_left);
    } else if (compare(word, node) == 1) {
        // Go right
        insert(word, node->m_right);
    } else {
        // Duplicate value
    }
}

int BST::compare(string word, NodePtr &node) {
    // Use string compare() to determine string comparison
    int result = word.compare(node->m_data);
    return result;
}

void BST::print_tree(ostream &output, NodePtr &node, int indent) {
    // Recursive printing function
    if (node != nullptr) {
        // Pass in right side first
        print_tree(output, node->m_right, indent + 4);
        // Add current node to output
        output << setw(indent) << node->m_data << endl;
        // Pass in left side
        print_tree(output, node->m_left, indent + 4);
    }
}

ostream &operator<<(ostream &output, BST &bst) {
    // Use recursive print_tree function
    bst.print_tree(output, bst.m_root, 0);
    return output;
}
