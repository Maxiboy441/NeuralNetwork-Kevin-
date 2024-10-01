# Neural Network from Scratch in C++
This project implements a simple neural network in C++ without using external machine learning libraries. It provides functions for training, saving, and loading the network, as well as evaluating its performance on a given dataset.

## Inhaltsverzeichnis
About the Project
Features
Prerequisites
Installation
Usage
Example Output
Project Structure
Contributors
License

## About the Project
The goal of this project is to understand the basics of neural networks by implementing a network from scratch in C++. It serves as a learning resource and offers insights into the implementation of forward and backpropagation, weight adjustments, and saving and loading models.

## Features
* Standalone Neural Network: No external libraries required.
* Save and Load Functions: Save trained models and load them for future predictions.
* Performance Evaluation: Compare the accuracy of the network before and after training.
* User Interaction: The program informs the user about performance changes and asks if the model should be saved.

## Prerequisites
C++ Compiler: Supports at least C++11.
CMake: For building the project.
Standard Libraries: No additional libraries required.

## Installation
Clone the repository

```
git clone https://github.com/IhrBenutzername/NeuralNetwork.git
cd NeuralNetwork
```
Create a build directory and navigate to it

```
mkdir build
cd build
```
Configure the project with CMake

```
cmake ..
```
Build the project

```
make
```

## Usage
After a successful build, you can run the program:

```
./NN
```
The program performs the following steps:

- Load Dataset: The Seeds dataset is loaded from the data/ directory and normalized.
- Initialize or Load Network: Checks if a saved network exists. If so, it is loaded; otherwise, a new network is initialized.
- Performance Evaluation Before Training: The accuracy of the network is measured on the dataset.
- Training the Network: The network is trained with the specified hyperparameters.
- Performance Evaluation After Training: The accuracy is measured again and compared with the previous one.
- Save Option: The user is asked whether to save the trained network.


## Project Structure
- src/: 
    - Source code of the project.
- include/:
    - Header files for the project.
- data/:
    - Dataset files (e.g., seeds_dataset.csv).
- build/:
    - Build directory (after creation).

## Adjusting Hyperparameters
You can adjust the hyperparameters of the network directly in main.cpp:
- n_hidden: Number of neurons in the hidden layer.
- l_rate: Learning rate for weight adjustment.
- n_epoch: Number of epochs for training.
```
int n_hidden = 5;   
float l_rate = 0.2f;
int n_epoch = 500;  
```
## Preparing Data
Ensure that the Seeds dataset is present in the data/ directory and named seeds_dataset.csv. The path to the dataset is set in main.cpp:

```
csv_data = load_csv_data("data/seeds_dataset.csv");
```
If the dataset is located elsewhere, adjust the path accordingly.

# TODO
- [ ] auto set learn rate