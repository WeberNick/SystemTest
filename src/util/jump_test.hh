#ifndef JUMP_TEST_HH
#define JUMP_TEST_HH

#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <random>

#include "infra/measure.hh"
#include "format.hh"

class JumpTest
{
	private:
		const uint _vector_length;
		double_vt _measureJump;
		double_vt _measurePred;

		uint_vt _input;
		uint_vt _output;

  	public:
		JumpTest(const uint vector_length);

	public:
		
		void init();

		void fTestJump();
		void fTestPredicated();

		double fBranchMispredictionCost(const double aSelectivity);

		void fPrintResult(std::ostream& output, const std::string setting);

		void fRunTest(std::ostream& output, const std::string setting);
};


#endif