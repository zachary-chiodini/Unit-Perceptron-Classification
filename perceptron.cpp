#include <vector> // dynamic array
#include <assert.h>
#include <random>
#include <iostream>

class Network {
    /* 
    Unit Perceptron Network 
    */
private:
    float bias = 0.0;
    std::vector<int> results = {};
    std::vector<float> network = {};

    std::vector<float> update(
        const std::vector<float>& xi, // ith unput array
        std::vector<float>& w,        // current network
        const int& ti,                // target value
        const int& ai,                // output of ith array
        const float& r                // learning rate
    ) {
        /*
        Update the Weights and Bias of the Current Network
        */
        bias += r*( ti - ai );
        for ( int j = 0; j < w.size(); ++j ) {
            w[ j ] += r*( ti - ai )*xi[ j ];
        }
        return w;
    }
    std::vector<int> output(
        const std::vector<std::vector<float>>& x, // i input arrays
        const std::vector<float>& w               // current netork
    ) {
        /*
        Output of Unit Perceptron while using the Current Network
        */
        std::vector<int> out;
        out.reserve( x.size() );
        for ( int i = 0; i < x.size(); ++i ) {
            out.push_back( perceptron( x[ i ], w, bias ) );
        }
        return out;
    }
public:
    int perceptron(
        const std::vector<float>& x,
        const std::vector<float>& w,
        const float& b
    ) {
        /*
        Perceptron Unit with Step Function
        */
        float dot_product = b;
        for ( int i = 0; i < x.size(); ++i ) {
            dot_product += x[ i ]*w[ i ];
        }
        return int( dot_product > 0 );
    }
    void train(
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
        std::random_device random; // int random number generator
        std::uniform_real_distribution<float> uniform( -0.5, 0.5 );
        std::vector<float> w;
        w.reserve( x[0].size() );
        for ( int i = 0; i < x[0].size(); ++i ) {
            w.push_back( uniform( random ) );
        }
        // training algorithm
        while ( output( x, w ) != t ) {
            for ( int i = 0; i < x.size(); ++i ) {
                int ai = perceptron( x[ i ], w, bias );
                w = update( x[ i ], w, t[ i ], ai, r );
            }
        }
        network = w;
        return;
    }
    void test( std::vector<std::vector<float>>& x ) {
        /*
        Test Perceptron on Test Data After Trainig
        */
        assert( !network.empty(), 'Network must be trained.' );
        results = output( x, network );
        return;
    }
    std::vector<int> get_output() {
        return results;
    }
    void show_output() {
        std::cout << "Unit output: ";
        for ( int i = 0; i != results.size(); ++i ) {
            std::cout << results[ i ] << " ";
        }
        std::cout << std::endl;
        return;
    }
    std::vector<float> get_network() {
        std::vector<float> net = network;
        net.insert( net.begin(), bias );
        return net;
    }
    void show_network() {
        std::cout << "Unit network: ";
        std::cout << bias << " ";
        for ( int i = 0; i < network.size(); ++i ) {
            std::cout << network[ i ] << " ";
        }
        std::cout << std::endl;
        return;
    }
};