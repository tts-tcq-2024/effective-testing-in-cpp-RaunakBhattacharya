#include <iostream>
#include <assert.h>
#include <vector>
#include <tuple>

std::vector<std::tuple<int, const char*, const char*>> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<std::tuple<int, const char*, const char*>> colorMap;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            colorMap.push_back(std::make_tuple(i * 5 + j, majorColor[i], minorColor[j]));
        }
    }
    return colorMap;
}

void printColorMap(const std::vector<std::tuple<int, const char*, const char*>>& colorMap) {
    for(const auto& color : colorMap) {
        std::cout << std::get<0>(color) << " | " << std::get<1>(color) << " | " << std::get<2>(color) << "\n";
    }
}

int main() {
    auto colorMap = generateColorMap();
    printColorMap(colorMap);
    for(int i = 0; i < colorMap.size(); i++) {
        assert(std::get<2>(colorMap[i]) != "Blue");
    }
    std::cout << "All is well (maybe!)\n";
    return 0;
}
