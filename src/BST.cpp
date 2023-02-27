#include "BST.h"
#include <iostream>

using namespace std;

int BST::height(NodePtr &node) {
    if (node == nullptr)
        return 0;
    return node->m_height;
}

int BST::max(int a, int b) {
    return (a > b) ? a : b;
}

int BST::balance_factor(NodePtr &node) {
    if (node == nullptr)
        return 0;
    return height(node->m_left) - height(node->m_right);
}

Node::NodePtr BST::rotate_right(NodePtr &y) {
    // Rotate left
    NodePtr x = y->m_left;
    NodePtr T2 = x->m_right;

    x->m_right = y;
    y->m_left = T2;

    y->m_height = max(height(y->m_right), height(y->m_left)) + 1;
    x->m_height = max(height(x->m_right), height(x->m_left)) + 1;

    return x;
}

Node::NodePtr BST::rotate_left(NodePtr &x) {
    // Rotate right
    NodePtr y = x->m_right;
    NodePtr T2 = y->m_left;

    y->m_left = x;
    x->m_right = T2;

    y->m_height = max(height(y->m_right), height(y->m_left)) + 1;
    x->m_height = max(height(x->m_right), height(x->m_left)) + 1;

    return y;
}

void BST::insert(string &word) {
    // Use recursive insert function
    insert(word, m_root);
}

void BST::insert(string &word, NodePtr &node) {
    // Recursive insert function
    if (node == nullptr) {
        // Create new node and store data
        node = new Node();
        node->m_height = 1;
    } else if (compare(word, node) < 0) {
        // Go left
        insert(word, node->m_left);
    } else if (compare(word, node) > 0) {
        // Go right
        insert(word, node->m_right);
    }

    // Run balance code here
    node->m_height = 1 + max(height(node->m_left), height(node->m_right));

    int bf = balance_factor(node);

    // Left-Left rotate
    if (bf < -1 && compare(word, node->m_left) < 0) {
        rotate_right(node);
    }
    //Right-Right rotate
    if (bf > 1 && compare(word, node->m_right) > 0) {
        rotate_left(node);
    }
    // Left-Right rotate
    if (bf > 1 && compare(word, node->m_left) < 0) {
        node->m_left = rotate_left(node->m_left);
        rotate_right(node);
    }
    // Right-Left rotate
    if (bf < -1 && compare(word, node->m_right) > 0) {
        node->m_right = rotate_right(node->m_right);
        rotate_left(node);
    }
}

bool BST::find(string &word) {
    // Check if word is in dictionary
    NodePtr node = m_root;
    bool found = false;

    // Look for desired node
    while (node != nullptr) {
        if (compare(word, node) < 0) {
            // Continue left
            node = node->m_left;
        } else if (compare(word, node) > 0) {
            // Continue right
            node = node->m_right;
        } else if (compare(word, node) == 0) {
            // Found desired node
            found = true;
        }
    }
    return found;
}

int BST::compare(string &word, NodePtr &node) {
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
        output << setw(indent + node->m_data.length() - 1) << node->m_data << endl;
        // Pass in left side
        print_tree(output, node->m_left, indent + 4);
    }
}

ostream &operator<<(ostream &output, BST &bst) {
    // Use recursive print_tree function
    bst.print_tree(output, bst.m_root, 0);
    return output;
}
