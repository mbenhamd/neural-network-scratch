//
// Created by mbenhamd on 3/18/18.
//

#ifndef NEURAL_NETWORK_SCRATCH_TRAININGDATA_H
#define NEURAL_NETWORK_SCRATCH_TRAININGDATA_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;


class TrainingData
{
public:
	TrainingData(const string filename);
	bool isEof(void)
	{
		return m_trainingDataFile.eof();
	}
	void getTopology(vector<unsigned> &topology);

	// Returns the number of input values read from the file:
	unsigned getNextInputs(vector<double> &inputVals);
	unsigned getTargetOutputs(vector<double> &targetOutputVals);

private:
	ifstream m_trainingDataFile;
};

#endif //NEURAL_NETWORK_SCRATCH_TRAININGDATA_H