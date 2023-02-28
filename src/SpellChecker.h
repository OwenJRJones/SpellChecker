#ifndef ASSIGNMENT_3_SPELLCHECKER_H
#define ASSIGNMENT_3_SPELLCHECKER_H

#include "BST.h"

class SpellChecker {
private:
    BST m_bst;
public:
    ~SpellChecker();

    void check_words(std::string &, std::string &, std::string &);

    void read_dictionary(std::string &);

    std::string remove_chars(std::string &);

    void save_tree(std::string &);

    void display_tree();
};

#endif //ASSIGNMENT_3_SPELLCHECKER_H