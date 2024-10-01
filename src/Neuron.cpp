#include "Neuron.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

/* NEURON */

/*
* Default Constructor
*/
Neuron::Neuron() : m_nWeights(0), m_activation(0.0f), m_output(0.0f), m_delta(0.0f) {
    /*pass*/
}

/*
* Neuron Constructor
*/
Neuron::Neuron(int n_weights) {
    this->initWeights(n_weights);
    m_nWeights = n_weights;
    m_activation = 0.0f;
    m_output = 0.0f;
    m_delta = 0.0f;
}

/*
* Neuron Destructor
*/
Neuron::~Neuron() {
    /*pass*/
}

/*
* Initialize weights
*/
void Neuron::initWeights(int n_weights) {
    // Add random small weights (between 0 and 1)
    for (int w = 0; w < n_weights; w++) {
        m_weights.push_back(static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX));
    }
}

/*
* Activate neuron
*/
void Neuron::activate(std::vector<float> inputs) {
    // The last weight is assumed to be the bias
    m_activation = m_weights[m_nWeights - 1];

    // Accumulate weighted inputs
    for (size_t i = 0; i < m_nWeights - 1; i++) {
        m_activation += m_weights[i] * inputs[i];
    }
}

/*
* Transfer activation
*/
void Neuron::transfer() {
    m_output = 1.0f / (1.0f + std::exp(-m_activation));
}
