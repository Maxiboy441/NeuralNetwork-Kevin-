#include "Layer.h"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <iosfwd> // For forward declaration of iostream objects


/* LAYER */

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