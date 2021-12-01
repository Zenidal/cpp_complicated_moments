#include <iostream>
#include <algorithm>

#include "InputParser.h"

InputParser::InputParser()
{
    sentences = std::set<std::string, decltype(compare) *>(compare);
}

void InputParser::read(int textCapacity)
{
    char input[textCapacity];

    std::cout << "Please input text: " << std::endl;
    std::cin.get(input, textCapacity);

    auto text = std::string(input);

    size_t start = 0;
    size_t finish = text.find_first_of("?!.", start);
    std::string sentence;

    while (start != std::string::npos && finish != std::string::npos) {
        sentence = text.substr(start, finish - start + 1);
        sentences.insert(sentence);

        start = text.find_first_not_of(' ', finish + 1);
        finish = text.find_first_of("?!.", start);
    }
}

void InputParser::displaySentences() const
{
    for (const auto &sentence: sentences) {
        std::cout << sentence << std::endl;
    }
}

bool compare(const std::string &sentence1, const std::string &sentence2)
{
    return sentence1.size() != sentence2.size()
           ? sentence1.size() > sentence2.size()
           : sentence1 > sentence2;
}