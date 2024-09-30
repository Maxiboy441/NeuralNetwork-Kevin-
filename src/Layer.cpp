#include "Layer.h"

#include <iostream>

/* LAYER */

/*
* Default Constructor
*/
Layer::Layer() {
    /*pass*/
}

/*
* Layer Constructor
*/
Layer::Layer(int n_neurons, int n_weights) {
    this->initNeurons(n_neurons, n_weights);
}

Layer::~Layer() {
    /*pass*/
}

void Layer::initNeurons(int n_neurons, int n_weights) {
    for (int n = 0; n < n_neurons; n++) {
        m_neurons.push_back(Neuron(n_weights));
    }
}
