#ifndef MEMORY_ACCESS_HH
#define MEMORY_ACCESS_HH

#include <iostream>
#include <vector>

#include "infra/measure.hh"
#include "types.hh"
#include "format.hh"

class MemoryAccess
{
	private:
		const int _n;
		double _x1;
		double _x2;
		int _r1;
		int _r2;

	private:

  	public:
		MemoryAccess(const uint vector_length);

	public:
		void fPrintResult(std::ostream& output, std::ostream& compare);
		void fRunTest(std::ostream& output, std::ostream& compare);
};

#endif