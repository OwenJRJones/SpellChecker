#ifndef ASSIGNMENT_3_BST_H
#define ASSIGNMENT_3_BST_H

#include "Node.h"

class BST {
    using NodePtr = Node *;

private:
    NodePtr m_root{nullptr};

public:
    void insert(std::string);

    int compare(std::string, NodePtr &node);

    friend std::ostream &operator<<(std::ostream &, BST &);

private:
    void insert(std::string, NodePtr &);

    void print_tree(std::ostream &, NodePtr &, int);
};

#endif //ASSIGNMENT_3_BST_H