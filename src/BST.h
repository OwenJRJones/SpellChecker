#ifndef ASSIGNMENT_3_BST_H
#define ASSIGNMENT_3_BST_H

#include "Node.h"

class BST {
    using NodePtr = Node *;

private:
    NodePtr m_root{nullptr};

    void insert(std::string &, NodePtr &);

    void print_tree(std::ostream &, NodePtr &, int);

public:
    int height(NodePtr &);

    int max(int, int);

    void insert(std::string &);

    NodePtr rotate_right(NodePtr &);

    NodePtr rotate_left(NodePtr &);

    int balance_factor(NodePtr &);

    static int compare(std::string &, NodePtr &);

    bool find(std::string &);

    friend std::ostream &operator<<(std::ostream &, BST &);
};

#endif //ASSIGNMENT_3_BST_H