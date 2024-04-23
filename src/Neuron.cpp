#include "Neuron.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <iosfwd> // For forward declaration of iostream objects


/* NEURON */

/*
* Neuron Constructor
*/
Neuron::Neuron(int n_weights) {
	this->initWeights(n_weights);
	m_nWeights = n_weights;
	m_activation = 0;
	m_output = 0;
	m_delta = 0;
}

/*
* Neuron Destructor
*/
Neuron::~Neuron(){
	/*pass*/
}

/*
* Initialize weights
*/
void Neuron::initWeights(int n_weights) {
    // add random small weights (between 0 and 1)
    for (int w = 0; w < n_weights; w++) {
        m_weights.push_back(static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX));
    }
}

/* 
* Calculate the activation of a neuron for a given input
*/
void Neuron::activate(std::vector<float> inputs) {
    // the last weight is assumed to be the bias
    m_activation = m_weights[m_nWeights-1];

    // accumulate all weighted inputs
    for (size_t i = 0; i < m_nWeights-1; i++)
    {
        m_activation += m_weights[i] * inputs[i];
    }
}

/* 
* Transfer the activation of the neuron to an actual output
*/
void Neuron::transfer() {
	m_output = 1.0f / (1.0f + std::exp(-m_activation));
}