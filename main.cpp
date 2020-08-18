#include "perceptron.h"
#include "sample.h"

int main() {
    std::vector<std::vector<float>> setosa = {
    {1.4, 5.1}, {1.4, 4.9}, {1.3, 4.7}, {1.5, 4.6}, {1.4, 5.0},
    {1.7, 5.4}, {1.4, 4.6}, {1.5, 5.0}, {1.4, 4.4}, {1.5, 4.9},
    {1.5, 5.4}, {1.6, 4.8}, {1.4, 4.8}, {1.1, 4.3}, {1.2, 5.8},
    {1.5, 5.7}, {1.3, 5.4}, {1.4, 5.1}, {1.7, 5.7}, {1.5, 5.1},
    {1.7, 5.4}, {1.5, 5.1}, {1.0, 4.6}, {1.7, 5.1}, {1.9, 4.8},
    {1.6, 5.0}, {1.6, 5.0}, {1.5, 5.2}, {1.4, 5.2}, {1.6, 4.7},
    {1.6, 4.8}, {1.5, 5.4}, {1.5, 5.2}, {1.4, 5.5}, {1.5, 4.9},
    {1.2, 5.0}, {1.3, 5.5}, {1.5, 4.9}, {1.3, 4.4}, {1.5, 5.1},
    {1.3, 5.0}, {1.3, 4.5}, {1.3, 4.4}, {1.6, 5.0}, {1.9, 5.1},
    {1.4, 4.8}, {1.6, 5.1}, {1.4, 4.6}, {1.5, 5.3}, {1.4, 5.0}
    };
    std::vector<std::vector<float>> others = {
    {4.7, 7.0}, {4.5, 6.4}, {4.9, 6.9}, {4.0, 5.5}, {4.6, 6.5},
    {4.5, 5.7}, {4.7, 6.3}, {3.3, 4.9}, {4.6, 6.6}, {3.9, 5.2},
    {3.5, 5.0}, {4.2, 5.9}, {4.0, 6.0}, {4.7, 6.1}, {3.6, 5.6},
    {4.4, 6.7}, {4.5, 5.6}, {4.1, 5.8}, {4.5, 6.2}, {3.9, 5.6},
    {4.8, 5.9}, {4.0, 6.1}, {4.9, 6.3}, {4.7, 6.1}, {4.3, 6.4},
    {4.4, 6.6}, {4.8, 6.8}, {5.0, 6.7}, {4.5, 6.0}, {3.5, 5.7},
    {3.8, 5.5}, {3.7, 5.5}, {3.9, 5.8}, {5.1, 6.0}, {4.5, 5.4},
    {4.5, 6.0}, {4.7, 6.7}, {4.4, 6.3}, {4.1, 5.6}, {4.0, 5.5},
    {4.4, 5.5}, {4.6, 6.1}, {4.0, 5.8}, {3.3, 5.0}, {4.2, 5.6},
    {4.2, 5.7}, {4.2, 5.7}, {4.3, 6.2}, {3.0, 5.1}, {4.1, 5.7},
    {6.0, 6.3}, {5.1, 5.8}, {5.9, 7.1}, {5.6, 6.3}, {5.8, 6.5},
    {6.6, 7.6}, {4.5, 4.9}, {6.3, 7.3}, {5.8, 6.7}, {6.1, 7.2},
    {5.1, 6.5}, {5.3, 6.4}, {5.5, 6.8}, {5.0, 5.7}, {5.1, 5.8},
    {5.3, 6.4}, {5.5, 6.5}, {6.7, 7.7}, {6.9, 7.7}, {5.0, 6.0},
    {5.7, 6.9}, {4.9, 5.6}, {6.7, 7.7}, {4.9, 6.3}, {5.7, 6.7},
    {6.0, 7.2}, {4.8, 6.2}, {4.9, 6.1}, {5.6, 6.4}, {5.8, 7.2},
    {6.1, 7.4}, {6.4, 7.9}, {5.6, 6.4}, {5.1, 6.3}, {5.6, 6.1},
    {6.1, 7.7}, {5.6, 6.3}, {5.5, 6.4}, {4.8, 6.0}, {5.4, 6.9},
    {5.6, 6.7}, {5.1, 6.9}, {5.1, 5.8}, {5.9, 6.8}, {5.7, 6.7},
    {5.2, 6.7}, {5.0, 6.3}, {5.2, 6.5}, {5.4, 6.2}, {5.1, 5.9}
    };
    int set_n = choose_n("setosa", 1, 50);
    int oth_n = choose_n("others", 1, 100);

    std::vector<std::vector<float>> sample1 = sample(setosa, set_n);
    std::vector<std::vector<float>> sample2 = sample(others, oth_n);

    std::vector<std::vector<float>> samples;
    samples.insert(samples.begin(), sample1.begin(), sample1.end());
    // delete sample1
    std::vector<std::vector<float>>().swap(sample1);
    samples.insert(samples.end(), sample2.begin(), sample2.end());
    // delete sample2
    std::vector<std::vector<float>>().swap(sample2);

    std::vector<int> targets;
    for (int i = 0; i < set_n; ++i) {
        targets.push_back(1);
    }
    for (int i = 0; i < oth_n; ++i) {
        targets.push_back(0);
    }
    // train perceptron on samples
    Network network = Network();
    network.train(samples, targets, 1, 0.01);
    // combine setosa and others into one data set
    std::vector<std::vector<float>> data;
    data.reserve(setosa.size() + others.size());
    data.insert(data.begin(), setosa.begin(), setosa.end());
    data.insert(data.begin() + setosa.size() - 1, others.begin(), others.end());
    // test perceptron on all data
    network.test(data);
    // show computed network and output
    network.show_network();
    network.show_output();
    // prompt user
    std::string ans = play_again();
    if (ans == "y") {
        return main();
    }
    return 0;
}