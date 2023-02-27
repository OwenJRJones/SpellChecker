#include <iostream>
#include "SpellChecker.h"

using namespace std;

int main() {

    SpellChecker sc;
    string dic = "../docs/dictionary.txt";
    string file = "../docs/mispelled.txt";
    sc.read_dictionary(dic);
    sc.display_tree();
    //sc.check_words(file);
    return 0;
}