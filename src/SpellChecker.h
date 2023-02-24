#ifndef ASSIGNMENT_3_SPELLCHECKER_H
#define ASSIGNMENT_3_SPELLCHECKER_H

#include <iostream>

class SpellChecker {
private:

public:
    ~SpellChecker();

    void read_file(std::string &);

    void read_dictionary(std::string &);

    void check_words();

    void display_tree();
};

#endif //ASSIGNMENT_3_SPELLCHECKER_H