#pragma once
#include <cmath>
#include <vector>

class Neural_Network {
private:
    double bias, *number_activs_each_layer;
    int hidden_layers; ;
public:
    // by default sets bias to 1.0 and hidden_layers to 2
    Neural_Network();
    // by default sets hidden_layers to 2 while bias is passed
    Neural_Network(double bias);
    Neural_Network(double bias, int hidden_layers);

    double activation_function(std::vector<double> theta[], std::vector<double> x);

    ~Neural_Network();

    friend double sigmoid_function(std::vector<double> theta[], std::vector<double> x);
};

double sigmoid_function(std::vector<double> theta[], std::vector<double> x);