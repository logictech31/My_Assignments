#include "neural_network.hxx"

Neural_Network::Neural_Network() {
    this->bias = 1.0;
    this->hidden_layers = 2;
}

Neural_Network::Neural_Network(double bias) {
    this->bias = bias;
    this->hidden_layers = 2;
    this->number_activs_each_layer = new double[this->hidden_layers];
}

Neural_Network::Neural_Network(double bias, int hidden_layers) {
    this->bias = bias;
    this->hidden_layers = hidden_layers;
    this->number_activs_each_layer = new double[this->hidden_layers];
}

Neural_Network::~Neural_Network() {
    delete this->number_activs_each_layer;
}

double product(std::vector<double> theta[], std::vector<double> x) {
    
}

double sigmoid_function(std::vector<double> theta[], std::vector<double> x) {

}