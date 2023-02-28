#include "BST.h"
#include <iostream>

using namespace std;

int BST::height(NodePtr &node) {
    // Return height of subtree
    if (node == nullptr)
        return -1;
    return max(height(node->m_left), height(node->m_right)) + 1;
}

int BST::max(int a, int b) {
    // Return greater value of two ints
    return (a > b) ? a : b;
}

int BST::balance_factor(NodePtr &node) {
    // Return balance factor of left and right subtrees of given node
    if (node == nullptr)
        return 0;
    return height(node->m_left) - height(node->m_right);
}

Node::NodePtr BST::rotate_right(NodePtr &y) {
    // Rotate left
    NodePtr x = y->m_left;
    NodePtr T2 = x->m_right;
    // Rotate values
    x->m_right = y;
    y->m_left = T2;

    return x;
}

Node::NodePtr BST::rotate_left(NodePtr &x) {
    // Rotate right
    NodePtr y = x->m_right;
    NodePtr T2 = y->m_left;
    // Rotate values
    y->m_left = x;
    x->m_right = T2;

    return y;
}

void BST::insert(string &word) {
    // Use recursive insert function
    m_root = insert(word, m_root);
}

Node::NodePtr BST::insert(string &word, NodePtr &node) {
    // Recursive insert function
    if (node == nullptr) {
        // Create new node and store data
        node = new Node();
        node->m_data = word;
        return node;
    } else if (word.compare(node->m_data) < 0) {
        // Go left
        node->m_left = insert(word, node->m_left);
    } else if (word.compare(node->m_data) > 0) {
        // Go right
        node->m_right = insert(word, node->m_right);
    } else {
        return node;
    }

    // Run balancing
    int bf = balance_factor(node);

    // Left-Left rotate
    if (bf > 1 && compare(word, node->m_left) < 0) {
        return rotate_right(node);
    }
    //Right-Right rotate
    if (bf < -1 && compare(word, node->m_right) > 0) {
        return rotate_left(node);
    }
    // Left-Right rotate
    if (bf > 1 && compare(word, node->m_left) > 0) {
        node->m_left = rotate_left(node->m_left);
        return rotate_right(node);
    }
    // Right-Left rotate
    if (bf < -1 && compare(word, node->m_right) < 0) {
        node->m_right = rotate_right(node->m_right);
        return rotate_left(node);
    }

    return node;
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
            break;
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
        output << setw(indent + node->m_data.length());
        output << node->m_data << endl;
        // Pass in left side
        print_tree(output, node->m_left, indent + 4);
    }
}

ostream &operator<<(ostream &output, BST &bst) {
    // Use recursive print_tree function
    bst.print_tree(output, bst.m_root, 0);
    return output;
}
