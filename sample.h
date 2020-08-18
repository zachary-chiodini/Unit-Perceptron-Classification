#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>
#include <vector>

std::vector<std::vector<float>> sample(
    std::vector<std::vector<float>>& data,
    int& n
);
int choose_n(
    const std::string& s,
    const int& mn,
    const int& mx
);
std::string play_again();

#endif