#include "switchvsfptr_test.hh"

SwitchFPtr::SwitchFPtr(const uint loop, const uint vector_length) : 
				_loop(loop), _vector_length(vector_length),
				_measure(7),
				_arg1(vector_length), _arg2(vector_length), _result(vector_length), _random(vector_length){}

void SwitchFPtr::init()
{
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	auto real_rand = std::bind(std::uniform_int_distribution<int>(0,4), std::mt19937(seed));
	uint x = 77777777;
	for(uint i = 0; i < _vector_length; ++i) 
	{
		_arg1[i] = x^i;
		_arg2[i] = x^i;
		_random[i] = real_rand();
	}
}

void SwitchFPtr::fTestOperations()
{
	_measure[0].start();
	for (uint k = 0; k < 100; ++k)
	{
		for (uint i = 0; i < _vector_length; ++i)
		{
			_result[i] = _arg1[i] + _arg2[i];
		}
	}
	_measure[0].stop();


	_measure[1].start();
	for (uint k = 0; k < 100; ++k)
	{
		for (uint i = 0; i < _vector_length; ++i)
		{
			_result[i] = _arg1[i] - _arg2[i];
		}
	}
	_measure[1].stop();


	_measure[2].start();
	for (uint k = 0; k < 100; ++k)
	{
		for (uint i = 0; i < _vector_length; ++i)
		{
			_result[i] = _arg1[i] ^ _arg2[i];
		}
	}
	_measure[2].stop();


	_measure[3].start();
	for (uint k = 0; k < 100; ++k)
	{
		for (uint i = 0; i < _vector_length; ++i)
		{
			_result[i] = _arg1[i] & _arg2[i];
		}
	}
	_measure[3].stop();


	_measure[4].start();
	for (uint k = 0; k < 100; ++k)
	{
		for (uint i = 0; i < _vector_length; ++i)
		{
			_result[i] = _arg1[i] | _arg2[i];
		}
	}
	_measure[4].stop();
}

void SwitchFPtr::fTestSwitch()
{
	_measure[5].start();
	for(uint k = 0; k < 100; ++k)
	{
		for(uint i = 0; i < _vector_length; ++i) 
		{
			switch(_random[i]) 
			{
				case 0: _result[i] = _arg1[i] + _arg2[i];
					break;
				case 1: _result[i] = _arg1[i] - _arg2[i];
					break;
				case 2: _result[i] = _arg1[i] ^ _arg2[i];
					break;
				case 3: _result[i] = _arg1[i] & _arg2[i];
					break;
				case 4: _result[i] = _arg1[i] | _arg2[i];
					break;
				default: break;
			}
		}
	}
	_measure[5].stop();
}

uint SwitchFPtr::fAdd(const int x, const int y) { return x + y; }
uint SwitchFPtr::fSub(const int x, const int y) { return x - y; }
uint SwitchFPtr::fXor(const int x, const int y) { return x ^ y; }
uint SwitchFPtr::fAnd(const int x, const int y) { return x & y; }
uint SwitchFPtr::fOr (const int x, const int y) { return x | y; }

void SwitchFPtr::fTestFunPtr() 
{
	fptrInt2 lFPtr[5] = {&fAdd, &fSub, &fXor, &fAnd, &fOr};
	_measure[6].start();
	for(uint k = 0; k < 100; ++k) 
	{
		for(uint i = 0; i < _vector_length; ++i) 
		{
			_result[i] = (*(lFPtr[_random[i]]))(_arg1[i], _arg2[i]);
		}
	}
	_measure[6].stop();
}

void SwitchFPtr::fPrintResult(std::ostream& output, std::ostream& compare)
{
	output << std::setw(23) << "vector.size(): " << fFormatNumber(_vector_length) << "\n" << std::endl;
	output.precision(4);
	output << "A[i] + B[i] : ~" << ((_measure[0].mTotalTime() / (double) (100 * _vector_length)) * NS) << " [ns]" << std::endl;
	output << "A[i] - B[i] : ~" << ((_measure[1].mTotalTime() / (double) (100 * _vector_length)) * NS) << " [ns]" << std::endl;
	output << "A[i] ^ B[i] : ~" << ((_measure[2].mTotalTime() / (double) (100 * _vector_length)) * NS) << " [ns]" << std::endl;
	output << "A[i] & B[i] : ~" << ((_measure[3].mTotalTime() / (double) (100 * _vector_length)) * NS) << " [ns]" << std::endl;
	output << "A[i] | B[i] : ~" << ((_measure[4].mTotalTime() / (double) (100 * _vector_length)) * NS) << " [ns]" << std::endl;
	output << std::string(80, '-') << "\n" << std::endl;

	double avg = 0;
	for (int i = 0; i < 5; ++i)
	{
		avg += _measure[i].mTotalTime();
	}
	avg /= 5;
	output << "Time for a case jump: " << (((_measure[5].mTotalTime() - avg) / (double) (100 * _vector_length)) * NS) << " [ns]" << ' ' 
		<<  " (total test duration: " << _measure[5].mTotalTime() << " [s])" << std::endl;
	output << "Time for a fptr jump: " << (((_measure[6].mTotalTime() - avg) / (double) (100 * _vector_length)) * NS) << " [ns]" << ' ' 
		<<  " (total test duration: " << _measure[6].mTotalTime() << " [s])\n" << std::endl;

	compare << "case jump [ns]/" <<  (((_measure[5].mTotalTime() - avg) / (double) (100 * _vector_length)) * NS) << std::endl
		<< "fptr jump [ns]/" << (((_measure[6].mTotalTime() - avg) / (double) (100 * _vector_length)) * NS) << std::endl;
}

void SwitchFPtr::fRunTest(std::ostream& output, std::ostream& compare)
{
	init();
	fTestOperations();
	fTestSwitch();
	fTestFunPtr();

	fPrintResult(output, compare);
}
