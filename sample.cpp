#include <iostream>
#include <vector>
#include <random>
#include "sample.h"

std::vector<std::vector<float>> sample(
    std::vector<std::vector<float>>& data,
    int& n
) {
    /*
    Takes a Random Sample of N from Data
    */
    int i = 0;
    std::vector<int> js;
    std::vector<std::vector<float>> samp;
    std::random_device random; // int random number generator
    std::uniform_int_distribution<int> uniform(0, data.size() - 1);
    while (i < n) {
        int j = uniform(random);
        if (count(js.begin(), js.end(), j) == 0) {
            js.push_back(j);
            samp.push_back(data[j]);
            i += 1;
        }
    }
    return samp;
}

int choose_n(
    const std::string& s,
    const int& mn,
    const int& mx
) {
    /*
    Prompts the User to Choose the Number of Data Points in Each Sample
    */
    std::cout << "Enter the number of data points to sample for ";
    std::cout << s << std::endl;
    int n;
    std::cin >> n;
    if (std::cin.fail()) {
        std::cout << "Please choose an integer value." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return choose_n(s, mn, mx);
    }
    if (n < mn or n > mx) {
        std::cout << s << " contains " << mn << " to ";
        std::cout << mx << " data points." << std::endl;
        return choose_n(s, mn, mx);
    }
    return n;
}

std::string play_again() {
    /*
    Prompts the User if They Would like to try Again
    */
    std::cout << "Would you like to try again (Y/N)?" << std::endl;
    std::string input;
    std::cin >> input;
    if (std::cin.fail()) {
        std::cout << "Please enter either Y or N." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return play_again();
    }
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    if ( input != "y" and input != "n") {
        std::cout << "Please enter either Y or N." << std::endl;
        std::cin.clear();
        return play_again();
    }
    return input;
}