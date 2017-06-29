#ifndef XOR_TEST_HH
#define XOR_TEST_HH

#include <iostream>
#include <vector>

#include "infra/measure.hh"
#include "cputest_funs.hh"
#include "format.hh"

class XorTest
{
	private:
		const uint _loop;
		const uint _repeat;
		const uint _vector_length;
		
		measure_vvt _measure;

  		double_vt _avg;
		double_vt _min;
		double_vt _max;
		double_vt _avgTotal;

  		measure_vvt _measureFn;
  		double_vvt _timeFnPtr;

  		measure_vt _measureVec;

  		double _minXor;
  		double_vt _minFn;
		double_vt _minPtr;

  	public:
		XorTest(const uint loop, const uint repeat, const uint vector_length);

	public:
		static double fAvg(measure_vt const &measurements, const uint &rep, const uint numb, const uint &loop);
		static double fMin(measure_vt const &measurements, const uint &rep, const uint numb, const uint &loop);
		static double fMax(measure_vt const &measurements, const uint &rep, const uint numb, const uint &loop);
		static double fTotalAvg(measure_vt const &measurements, const uint &rep);

		static void init(measure_vvt &measure, const uint &rep);

		void fMeasureXOR24();
		void fMeasureXOR12();
		void fMeasureXOR6();
		
		void fMeasureFnXOR();
		void fMeasureFnPtrXOR();

		void fMeasureVectorXOR();

		void fMinXOR();
		void fMinFn();
		void fMinPtr();

		void fPrintResult(std::ostream& output, std::ostream& compare);

		void fRunTest(std::ostream& output, std::ostream& compare);
};

#endif