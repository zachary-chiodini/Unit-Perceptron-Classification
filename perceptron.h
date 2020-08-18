#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>

class Network {
    /*
    Unit Perceptron Network
    */
public:
    Network();
    int perceptron(
        const std::vector<float>& x, // input vector
        const std::vector<float>& w, // weights
        const float& b               // bias
    );
    void train(
        const std::vector<std::vector<float>>& x, // i input vectors
        const std::vector<int>& t,                // i outputs
        const float b,                            // bias
        const float r                             // learning rate
    );
    void test(
        std::vector<std::vector<float>>& x // i input vectors
    );
    std::vector<int> get_output();
    std::vector<float> get_network();
    void show_output();
    void show_network();
private:
    float bias;
    std::vector<int> results;
    std::vector<float> network;

    std::vector<float> update(
        const std::vector<float>& xi, // ith unput array
        std::vector<float>& w,        // current network
        const int& ti,                // target value
        const int& ai,                // output of ith array
        const float& r                // learning rate
    );
    std::vector<int> output(
        const std::vector<std::vector<float>>& x, // i input arrays
        const std::vector<float>& w               // current netork
    );
};
#endif