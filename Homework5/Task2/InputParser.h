#ifndef CPP_COMPLICATED_MOMENTS_INPUTPARSER_H
#define CPP_COMPLICATED_MOMENTS_INPUTPARSER_H

#include <set>
#include <string>

bool compare(const std::string &sentence1, const std::string &sentence2);

class InputParser
{
    private:
        std::set<std::string, decltype(compare) *> sentences;
    public:
        InputParser();

        void read(int textCapacity);

        void displaySentences() const;
};


#endif //CPP_COMPLICATED_MOMENTS_INPUTPARSER_H
