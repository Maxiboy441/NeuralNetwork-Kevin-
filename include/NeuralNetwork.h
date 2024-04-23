#pragma once

#include <iostream>
#include <vector>
#include "Layer.h"

class Network {
public:
	Network();
	~Network();

	void initialize_network(int n_inputs, int n_hidden, int n_outputs);

	void add_layer(int n_neurons, int n_weights);
	std::vector<float> forward_propagate(std::vector<float> inputs);
	void backward_propagate_error(std::vector<float> expected);
	void update_weights(std::vector<float> inputs, float l_rate);

	void train(std::vector<std::vector<float>>trainings_data, float l_rate, size_t n_epoch, size_t n_outputs);
	int predict(std::vector<float> input);

	void display_human();

	bool save(const std::string& filename);
	bool load(const std::string& filename);

	private:
		size_t m_nLayers;
		std::vector<Layer> m_layers;

		void save_layer(const Layer& layer, std::ofstream& file);
		void load_layer(Layer& layer, std::ifstream& file);
		void load_weights(std::vector<float>& weights, std::ifstream& file);
};