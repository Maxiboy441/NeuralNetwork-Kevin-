#include "NeuralNetwork.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

/* NETWORK */

/*
* Network Constructor
*/
Network::Network() {
    // initialize PRNG
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    m_nLayers = 0;
}

/*
* Network Destructor
*/
Network::~Network() {
    /*pass*/
}

/*
* Initialize a network manually
*/
void Network::initialize_network(int n_inputs, int n_hidden, int n_outputs) {
    // Add a hidden layer (n_hidden neurons connected to all inputs)
    this->add_layer(n_hidden, n_inputs + 1);

    // Add an output layer (one neuron per output connected to previous layer's neurons)
    this->add_layer(n_outputs, n_hidden + 1);
}

/*
* Add another layer to the network
*/
void Network::add_layer(int n_neurons, int n_weights) {
    m_layers.push_back(Layer(n_neurons, n_weights));
    m_nLayers++;
}

/*
* Forward propagate an input
*/
std::vector<float> Network::forward_propagate(std::vector<float> inputs) {
    std::vector<float> new_inputs;
    for (size_t i = 0; i < m_nLayers; i++) {
        new_inputs.clear();

        // Reference the layer neurons directly
        std::vector<Neuron>& layer_neurons = m_layers[i].get_neurons();
        for (size_t n = 0; n < layer_neurons.size(); n++) {
            layer_neurons[n].activate(inputs);
            layer_neurons[n].transfer();
            new_inputs.push_back(layer_neurons[n].get_output());
        }
        inputs = new_inputs;
    }
    return inputs;
}

/*
* Backward propagate error
*/
void Network::backward_propagate_error(std::vector<float> expected) {
    // Reverse traverse the layers
    for (size_t i = m_nLayers; i-- > 0;) {
        std::vector<Neuron>& layer_neurons = m_layers[i].get_neurons();

        for (size_t n = 0; n < layer_neurons.size(); n++) {
            float error = 0.0f;
            if (i == m_nLayers - 1) {
                error = expected[n] - layer_neurons[n].get_output();
            } else {
                for (auto& neu : m_layers[i + 1].get_neurons()) {
                    error += (neu.get_weights()[n] * neu.get_delta());
                }
            }
            layer_neurons[n].set_delta(error * layer_neurons[n].transfer_derivative());
        }
    }
}

/*
* Update weights
*/
void Network::update_weights(std::vector<float> inputs, float l_rate) {
    for (size_t i = 0; i < m_nLayers; i++) {
        std::vector<float> new_inputs = {};
        if (i != 0) {
            for (auto& neuron : m_layers[i - 1].get_neurons()) {
                new_inputs.push_back(neuron.get_output());
            }
        } else {
            new_inputs = std::vector<float>(inputs.begin(), inputs.end() - 1);
        }

        std::vector<Neuron>& layer_neurons = m_layers[i].get_neurons();

        for (size_t n = 0; n < layer_neurons.size(); n++) {
            std::vector<float>& weights = layer_neurons[n].get_weights();
            for (size_t j = 0; j < new_inputs.size(); j++) {
                weights[j] += l_rate * layer_neurons[n].get_delta() * new_inputs[j];
            }
            // Update bias
            weights.back() += l_rate * layer_neurons[n].get_delta();
        }
    }
}

/*
* Train the network
*/
void Network::train(std::vector<std::vector<float>> trainings_data, float l_rate, size_t n_epoch, size_t n_outputs) {
    for (size_t e = 0; e < n_epoch; e++) {
        float sum_error = 0;

        for (const auto& row : trainings_data) {
            std::vector<float> outputs = this->forward_propagate(row);
            std::vector<float> expected(n_outputs, 0.0f);
            expected[static_cast<int>(row.back())] = 1.0f;
            for (size_t x = 0; x < n_outputs; x++) {
                sum_error += std::pow((expected[x] - outputs[x]), 2);
            }
            this->backward_propagate_error(expected);
            this->update_weights(row, l_rate);
        }
        std::cout << "[>] epoch=" << e << ", l_rate=" << l_rate << ", error=" << sum_error << std::endl;
    }
}

/*
* Make a prediction
*/
int Network::predict(std::vector<float> input) {
    std::vector<float> outputs = this->forward_propagate(input);
    return std::distance(outputs.begin(), std::max_element(outputs.begin(), outputs.end()));
}

/*
* Display the network
*/
void Network::display_human() {
    std::cout << "[Network] (Layers: " << m_nLayers << ")" << std::endl;

    std::cout << "{" << std::endl;
    for (size_t l = 0; l < m_layers.size(); l++) {
        Layer layer = m_layers[l];
        std::cout << "\t (Layer " << l << "): {";
        for (size_t i = 0; i < layer.get_neurons().size(); i++) {
            Neuron neuron = layer.get_neurons()[i];
            std::cout << "<(Neuron " << i << "): [ weights={";
            std::vector<float> weights = neuron.get_weights();
            for (size_t w = 0; w < weights.size(); ++w) {
                std::cout << weights[w];
                if (w < weights.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "}, output=" << neuron.get_output() << ", activation=" << neuron.get_activation() << ", delta=" << neuron.get_delta();
            std::cout << "]>";
            if (i < layer.get_neurons().size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}";
        if (l < m_layers.size() - 1) {
            std::cout << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "}" << std::endl;
}

/*
* Save the network to a file
*/
bool Network::save(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for saving the network." << std::endl;
        return false;
    }

    // Save the number of layers
    file << m_nLayers << std::endl;

    // Save each layer
    for (const auto& layer : m_layers) {
        save_layer(layer, file);
    }

    file.close();
    return true;
}

/*
* Load the network from a file
*/
bool Network::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "' for loading the network." << std::endl;
        return false;
    }

    // Load the number of layers
    size_t n_layers = 0;
    file >> n_layers;
    m_nLayers = n_layers;

    // Clear existing layers
    m_layers.clear();

    // Load each layer
    for (size_t i = 0; i < m_nLayers; ++i) {
        Layer layer;
        load_layer(layer, file);
        m_layers.push_back(layer);
    }

    file.close();
    return true;
}

/*
* Save a layer to a file
*/
void Network::save_layer(const Layer& layer, std::ofstream& file) {
    // Save the number of neurons
    file << layer.get_neurons().size() << std::endl;

    // Save each neuron
    for (const auto& neuron : layer.get_neurons()) {
        const auto& weights = neuron.get_weights();

        // Save the number of weights
        file << weights.size() << std::endl;

        // Save each weight
        for (const float& weight : weights) {
            file << weight << " ";
        }
        file << std::endl;
    }
}

/*
* Load a layer from a file
*/
void Network::load_layer(Layer& layer, std::ifstream& file) {
    // Load the number of neurons
    size_t n_neurons = 0;
    file >> n_neurons;

    // Initialize the neurons
    std::vector<Neuron> neurons;
    for (size_t i = 0; i < n_neurons; ++i) {
        Neuron neuron;
        load_weights(neuron, file);
        neurons.push_back(neuron);
    }
    layer.set_neurons(neurons);
}

/*
* Load weights for a neuron from a file
*/
void Network::load_weights(Neuron& neuron, std::ifstream& file) {
    // Load the number of weights
    size_t n_weights = 0;
    file >> n_weights;

    // Load each weight
    std::vector<float> weights(n_weights);
    for (size_t i = 0; i < n_weights; ++i) {
        file >> weights[i];
    }

    // Set the weights of the neuron
    neuron.set_weights(weights);
}