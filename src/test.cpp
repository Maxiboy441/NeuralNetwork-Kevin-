#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <regex>
#include <iterator>
#include <map>
#include <numeric>
#include <cmath>
#include "NeuralNetwork.h"



int main(int argc, char* argv[]) {
	std::cout << "Neural Network with Backpropagation in C++ from scratch (development-phase)" << std::endl;

	// define a set of trainings data
	// each row has two inputs and one result
	// the result is either one or zero (binary classfication)
	std::vector<std::vector<float>> traindata {
		{2.7810836,		2.550537003,	0},
		{1.465489372,	2.362125076,	0},
		{3.396561688,	4.400293529,	0},
		{1.38807019,	1.850220317,	0},
		{3.06407232,	3.005305973,	0},
		{7.627531214,	2.759262235,	1},
		{5.332441248,	2.088626775,	1},
		{6.922596716,	1.77106367,		1},
		{8.675418651,	-0.242068655,	1},
		{7.673756466,	3.508563011,	1}
	};

	// get the amount of possible outputs (binary classification => 2 possible outputs in this case)
	std::set<float> results;
	for (const auto& r : traindata) {
		results.insert(r[r.size() - 1]);
	}
	int n_outputs = results.size();
	int n_inputs = traindata[0].size() - 1;

	// we can experiment with these values
	float learn_rate = 0.4; // the learn rate specifies how much the error will influence a weight
	int epochs = 500; // the epochs specify how often an error will be back propagated through the network

	// initialize a network with 2 neurons in the first hidden layer
	Network* network = new Network();
	network->initialize_network(n_inputs, 2, n_outputs);

	// train the network (forward propagation, backward propagation and weight updating)
	network->train(traindata, learn_rate, epochs, n_outputs);

	// display the created network (in an understandable format) for visualization purposes
	network->display_human();
	
	// make a prediction on the same data we trained with
	std::cout << "[Prediction]" << std::endl;

	for (const auto& data : traindata) {
		int prediction = network->predict(data);
		std::cout << "\t[>] Expected=" << data.back() << ", Got=" << prediction << std::endl;
	}

	return 0;
}