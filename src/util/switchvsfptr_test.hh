#ifndef SWITCHVSFPTR_TEST_HH
#define SWITCHVSFPTR_TEST_HH

#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <random>

#include "infra/measure.hh"
#include "format.hh"

class SwitchFPtr
{
	public:
		typedef uint (*fptrInt2)(const int x, const int y);

	private:
		const uint _loop;
		const uint _vector_length;

		measure_vt _measure;

		uint_vt _arg1;
		uint_vt _arg2;
		uint_vt _result;
		uint_vt _random;

	public:
		SwitchFPtr(const uint loop, const uint vector_length);

	public:
		void init();

		void fTestOperations();
		void fTestSwitch();

		static uint fAdd(const int x, const int y);
		static uint fSub(const int x, const int y);
		static uint fXor(const int x, const int y);
		static uint fAnd(const int x, const int y);
		static uint fOr(const int x, const int y);
		void fTestFunPtr();

		void fPrintResult(std::ostream& output, std::ostream& compare);

		void fRunTest(std::ostream& output, std::ostream& compare);
};

#endif