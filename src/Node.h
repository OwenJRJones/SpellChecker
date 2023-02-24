#ifndef ASSIGNMENT_3_NODE_H
#define ASSIGNMENT_3_NODE_H

#include <iomanip>

struct Node {
    using NodePtr = Node *;

    std::string m_data{"NULL"};
    NodePtr m_left{nullptr};
    NodePtr m_right{nullptr};
};

#endif //ASSIGNMENT_3_NODE_H
