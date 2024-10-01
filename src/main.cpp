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

// function declaration
std::vector<std::vector<float>> load_csv_data(std::string filename);
float evaluate_network(Network* network, std::vector<std::vector<float>> dataset);

int main(int argc, char* argv[]) {
    std::cout << "Neural Network from scratch" << std::endl;

    std::vector<std::vector<float>> csv_data;
    csv_data = load_csv_data("../data/seeds_dataset.csv");

    // normalize the last Column values
    std::map<int, int> lookup = {};
    int index = 0;
    for (auto& vec : csv_data) {
        std::pair<std::map<int, int>::iterator, bool> ret;
        ret = lookup.insert(std::pair<int, int>(static_cast<int>(vec.back()), index));
        vec.back() = static_cast<float>(ret.first->second);
        if (ret.second) {
            index++;
        }
    }

    int n_hidden = 5;
    float l_rate = 0.2f;
    int n_epoch = 500;

    // set return amount
    std::set<float> results;
    for (const auto& r : csv_data) {
        results.insert(r.back());
    }
    int n_outputs = results.size();

    // initialize Netzwerk
    Network* network = new Network();

    // network save path
    std::string network_filename = "saved_network.txt";

    // Alternative method to check if the file exists
    std::ifstream infile(network_filename);
    if (infile.good()) {
        infile.close();
        std::cout << "Network found. Loading..." << std::endl;
        if (network->load(network_filename)) {
            std::cout << "Success." << std::endl;
        } else {
            std::cerr << "Failed. Initializing new Network." << std::endl;
            network->initialize_network(csv_data[0].size() - 1, n_hidden, n_outputs);
        }
    } else {
        std::cout << "Network not found. Initializing new Network." << std::endl;
        network->initialize_network(csv_data[0].size() - 1, n_hidden, n_outputs);
    }

    // Measure performance before training
    float accuracy_before = evaluate_network(network, csv_data);

    // Train network
    network->train(csv_data, l_rate, n_epoch, n_outputs);

    // Measure performance after training
    float accuracy_after = evaluate_network(network, csv_data);

    // View improvement report
    std::cout << "Previous accuracy: " << accuracy_before << "%" << std::endl;
    std::cout << "Current accuracy: " << accuracy_after << "%" << std::endl;

    if (accuracy_after > accuracy_before) {
        std::cout << "Network improved." << std::endl;
    } else if (accuracy_after < accuracy_before) {
        std::cout << "Network worsened." << std::endl;
    } else {
        std::cout << "Nothing changed." << std::endl;
    }

    // ask to save network
    std::cout << "Save Network? (j/n): ";
    char save_response;
    std::cin >> save_response;

    if (save_response == 'j' || save_response == 'J') {
        if (network->save(network_filename)) {
            std::cout << "Saved successfully." << std::endl;
        } else {
            std::cerr << "Error. Network could not be saved." << std::endl;
        }
    } else {
        std::cout << "Changes discarded." << std::endl;
    }

    delete network;

    return 0;
}

// Definition of CSV data loading and normalization function
std::vector<std::vector<float>> load_csv_data(std::string filename) {
    const std::regex comma(",");
    std::ifstream csv_file(filename);
    std::vector<std::vector<float>> data;
    std::string line;
    std::vector<float> mins;
    std::vector<float> maxs;
    bool first = true;

    while (csv_file && std::getline(csv_file, line)) {
        // Split line by comma
        std::vector<std::string> srow{ std::sregex_token_iterator(line.begin(), line.end(), comma, -1), std::sregex_token_iterator() };
        // Convert string vector to float vector
        std::vector<float> row(srow.size());
        std::transform(srow.begin(), srow.end(), row.begin(), [](std::string const& val) { return std::stof(val); });

        // Capture min and max values ​​for normalization
        if (first) {
            mins = row;
            maxs = row;
            first = false;
        } else {
            for (size_t t = 0; t < row.size(); t++) {
                if (row[t] > maxs[t]) {
                    maxs[t] = row[t];
                } else if (row[t] < mins[t]) {
                    mins[t] = row[t];
                }
            }
        }

        data.push_back(row);
    }

    // Normalize values
    for (auto& vec : data) {
        // Ignore last column (output).
        for (size_t i = 0; i < vec.size() - 1; i++) {
            vec[i] = (vec[i] - mins[i]) / (maxs[i] - mins[i]);
        }
    }

    return data;
}

// Definition of the function for evaluating the network
float evaluate_network(Network* network, std::vector<std::vector<float>> dataset) {
    int correct = 0;
    int total = dataset.size();

    for (const auto& row : dataset) {
        std::vector<float> input = row;
        int expected = static_cast<int>(input.back());
        input.pop_back(); // Removes the expected output from the inputs

        int predicted = network->predict(input);

        if (predicted == expected) {
            correct++;
        }
    }

    float accuracy = static_cast<float>(correct) / total * 100.0f;
    return accuracy;
}