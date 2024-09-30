#pragma once

#include <iostream>
#include <vector>
#include "Neuron.h"

class Layer {
public:
    Layer();
    Layer(int n_neurons, int n_weights);
    ~Layer();

    // Return mutable reference to the neurons
    std::vector<Neuron>& get_neurons(void) { return m_neurons; };

    // Return const reference to the neurons (const version)
    const std::vector<Neuron>& get_neurons(void) const { return m_neurons; };

    // Set the neurons (used during loading)
    void set_neurons(const std::vector<Neuron>& neurons) { m_neurons = neurons; }

private:
    void initNeurons(int n_neurons, int n_weights);

    std::vector<Neuron> m_neurons;
};
