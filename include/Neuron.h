#pragma once

#include <iostream>
#include <vector>

class Neuron {
public:
    Neuron();
    Neuron(int n_weights);
    ~Neuron();

    void activate(std::vector<float> inputs);
    void transfer();
    float transfer_derivative() const { return static_cast<float>(m_output * (1.0f - m_output)); };

    // Return mutable reference to the neuron weights
    std::vector<float>& get_weights(void) { return m_weights; };

    // Return const reference to the neuron weights (const version)
    const std::vector<float>& get_weights(void) const { return m_weights; };

    float get_output(void) const { return m_output; };
    float get_activation(void) const { return m_activation; };
    float get_delta(void) const { return m_delta; };

    void set_delta(float delta) { m_delta = delta; };

    // Set the weights (used during loading)
    void set_weights(const std::vector<float>& weights) { m_weights = weights; m_nWeights = weights.size(); }

private:
    size_t m_nWeights;
    std::vector<float> m_weights;
    float m_activation;
    float m_output;
    float m_delta;

private:
    void initWeights(int n_weights);
};
