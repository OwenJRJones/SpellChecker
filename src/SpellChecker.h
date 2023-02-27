#ifndef ASSIGNMENT_3_SPELLCHECKER_H
#define ASSIGNMENT_3_SPELLCHECKER_H

#include "BST.h"

class SpellChecker {
private:
    BST m_bst;
public:
    ~SpellChecker();

    void read_dictionary(std::string &);

    void check_words(std::string&);

    void display_tree();
};

#endif //ASSIGNMENT_3_SPELLCHECKER_H