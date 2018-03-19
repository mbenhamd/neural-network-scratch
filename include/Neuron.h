//
// Created by mbenhamd on 3/18/18.
//

#ifndef NEURAL_NETWORK_SCRATCH_NEURON_H
#define NEURAL_NETWORK_SCRATCH_NEURON_H


#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>
#include "Layer.h"
#include "Connection.h"

using namespace std;


class Neuron
{
public:
	Neuron(unsigned numOutputs, unsigned myIndex);
	void setOutputVal(double val) { m_outputVal = val; }
	double getOutputVal(void) const { return m_outputVal; }
	void feedForward(const vector<Neuron> &prevLayer);
	void calcOutputGradients(double targetVals);
	void calcHiddenGradients(const vector<Neuron> &nextLayer);
	void updateInputWeights(vector<Neuron> &prevLayer);
private:
	static double eta; // [0.0...1.0] overall net training rate
	static double alpha; // [0.0...n] multiplier of last weight change [momentum]
	static double transferFunction(double x);
	static double transferFunctionDerivative(double x);
	// randomWeight: 0 - 1
	static double randomWeight(void) { return rand() / double(RAND_MAX); }
	double sumDOW(const vector<Neuron> &nextLayer) const;
	double m_outputVal;
	vector<Connection> m_outputWeights;
	unsigned m_myIndex;
	double m_gradient;
};

#endif //NEURAL_NETWORK_SCRATCH_NEURON_H