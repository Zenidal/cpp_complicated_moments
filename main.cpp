#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

#include "Homework5/Task2/InputParser.h"

template<class Iterator>
void showUniqueWords(Iterator begin, Iterator end)
{
    std::unordered_set<std::string> uniqueWords;
    for (auto i = begin; i < end; i++) {
        uniqueWords.insert(*i);
    }

    for (const auto &word: uniqueWords) {
        std::cout << word << std::endl;
    }

    std::cout << std::endl;
}


int main()
{
    { // task 1
        std::vector words({"dog", "cat", "catalog", "dog", "animal", "anima", "cat"});
        showUniqueWords(words.begin(), words.end());
        showUniqueWords(words.cbegin(), words.cend());
        showUniqueWords(words.rbegin(), words.rend());
    }

    { // task 2
        InputParser inputParser;
        inputParser.read(1024);
        inputParser.displaySentences();
    }
}
