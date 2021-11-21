#include <algorithm>

#include "VowelsCounter.h"
#include "Timer.h"

int VowelsCounter::calculateByCountIfAndFind(std::string &text)
{
    size_t count = 0;

    auto calculator = [text, &count]() -> void {
        count = std::count_if(text.begin(), text.end(), [](char letter) -> bool {
            return std::string("aAeEiIoOuU").find(letter) == std::string::npos;
        });
    };

    return Timer::calculateExecutionTimeInSeconds(calculator);
}

int VowelsCounter::calculateByCountIfAndFor(std::string &text)
{
    size_t count = 0;

    auto calculator = [text, &count]() -> void {
        count = std::count_if(text.begin(), text.end(), [](char letter) -> bool {
            const char vowels[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

            for (auto vowel: vowels) {
                if (letter == vowel) {
                    return true;
                }
            }

            return false;
        });
    };

    return Timer::calculateExecutionTimeInSeconds(calculator);
}

int VowelsCounter::calculateForAndFind(std::string &text)
{
    size_t count = 0;

    auto calculator = [text, &count]() -> void {
        for (auto letter: text) {
            if (std::string("aAeEiIoOuU").find(letter) == std::string::npos) {
                ++count;
            }
        }
    };

    return Timer::calculateExecutionTimeInSeconds(calculator);
}

int VowelsCounter::calculateForAndFor(std::string &text)
{
    size_t count = 0;

    auto calculator = [text, &count]() -> void {
        const char vowels[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        for (auto letter: text) {
            for (auto vowel: vowels) {
                if (letter == vowel) {
                    count++;
                }
            }
        }
    };

    return Timer::calculateExecutionTimeInSeconds(calculator);
}