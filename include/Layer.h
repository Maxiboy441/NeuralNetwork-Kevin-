#include <iostream>
#include <vector>
#include "Neuron.h"

class Layer {
public:
	Layer(int n_neurons, int n_weights);
	~Layer();

	// return mutable reference to the neurons
	std::vector<Neuron>& get_neurons(void) { return m_neurons; };


private:
	void initNeurons(int n_neurons, int n_weights);

	std::vector<Neuron> m_neurons;
};