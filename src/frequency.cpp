#include "frequency.h"

#include <stdexcept>
#include <unordered_map>

namespace algorithm_lab {

// change code
int mostFrequentNaive(const std::vector<int>& values) {
    if (values.empty()) {
        throw std::invalid_argument("values must not be empty");
    }

    int best_value = values.front();
    int best_count = 0;

    for (std::size_t i = 0; i < values.size(); ++i) {
        int current = values[i];
        int count = 0;
        for (std::size_t j = 0; j < values.size(); ++j) {
            if (values[j] == current) {
                ++count;
            }
        }

        if (count > best_count || (count == best_count && current != best_value)) {
            best_count = count;
            best_value = current;
        }
    }

    return best_value;
}
//add code unordered map
int mostFrequentEfficient(const std::vector<int>& values) {
    if (values.empty()) {
        throw std::invalid_argument("values must not be empty");
    }
    std::unordered_map <int, int> frequencyMap;
    int best_efficient_value = values[0];
    int high_count = 0;
    for(int num: values) {
        frequencyMap[num]++;
        if(frequencyMap[num] > high_count) {
            high_count = frequencyMap[num];
            best_efficient_value = num;
        }

    }
    return best_efficient_value;
}

}
