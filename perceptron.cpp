#include <vector>
#include <assert.h>
#include <random>
#include <iostream>
#include "perceptron.h"

Network::Network() {
    bias = 0.0;
    results = {};
    network = {};
}
int Network::perceptron(
    const std::vector<float>& x, // input vector
    const std::vector<float>& w, // weights
    const float& b               // bias
) {
    /*
    Perceptron Unit with Step Function
    */
    float dot_product = b;
    for (int i = 0; i < x.size(); ++i) {
        dot_product += x[i] * w[i];
    }
    return int(dot_product > 0);
}
void Network::train(
    const std::vector<std::vector<float>>& x, // i input vectors
    const std::vector<int>& t,                // i outputs
    const float b,                            // bias
    const float r                             // learning rate
) {
    /*
    Perceptron Training Algorithm
    */
    bias = b;
    // generate random weights
    std::random_device random;
    std::uniform_real_distribution<float> uniform(-0.5, 0.5);
    std::vector<float> w;
    for (int i = 0; i < x[0].size(); ++i) {
        w.push_back(uniform(random));
    }
    // training algorithm
    while (output(x, w) != t) {
        for (int i = 0; i < x.size(); ++i) {
            int ai = perceptron(x[i], w, bias);
            w = update(x[i], w, t[i], ai, r);
        }
    }
    network = w;
    return;
}
void Network::test(std::vector<std::vector<float>>& x) {
    /*
    Test Perceptron on Test Data After Trainig
    */
    assert(!network.empty(), 'Network must be trained.');
    results = output(x, network);
    return;
}
std::vector<int> Network::get_output() {
    return results;
}
std::vector<float> Network::get_network() {
    std::vector<float> net = network;
    net.insert(net.begin(), bias);
    return net;
}
void Network::show_output() {
    std::cout << "Unit output: ";
    for (int i = 0; i != results.size(); ++i) {
        std::cout << results[i] << " ";
    }
    std::cout << std::endl;
    return;
}
void Network::show_network() {
    std::cout << "Unit network: ";
    std::cout << bias << " ";
    for (int i = 0; i < network.size(); ++i) {
        std::cout << network[i] << " ";
    }
    std::cout << std::endl;
    return;
}
std::vector<float> Network::update(
    const std::vector<float>& xi, // ith unput array
    std::vector<float>& w,        // current network
    const int& ti,                // target value
    const int& ai,                // output of ith array
    const float& r                // learning rate
) {
    /*
    Update the Weights and Bias of the Current Network
    */
    bias += r * (ti - ai);
    for (int j = 0; j < w.size(); ++j) {
        w[j] += r * (ti - ai) * xi[j];
    }
    return w;
}
std::vector<int> Network::output(
    const std::vector<std::vector<float>>& x, // i input arrays
    const std::vector<float>& w               // current netork
) {
    /*
    Output of Unit Perceptron while using the Current Network
    */
    std::vector<int> out;
    for (int i = 0; i < x.size(); ++i) {
        out.push_back(perceptron(x[i], w, bias));
    }
    return out;
}
