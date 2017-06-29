#include "jump_test.hh"

#include <fstream>

JumpTest::JumpTest(const uint vector_length) : 
				_vector_length(vector_length),
				_measureJump(101), _measurePred(101), _input(vector_length), _output(vector_length){}


void JumpTest::init()
{
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	auto real_rand = std::bind(std::uniform_int_distribution<int>(0,99), std::mt19937(seed));
	for(uint i = 0; i < _vector_length; ++i)
	{
		_input[i] = real_rand();
	}
}

void JumpTest::fTestJump()
{
	for (uint theta = 0; theta <= 100; ++theta)
	{
		Measure measure;
		measure.start();
		for (uint j = 0, k = 0; j < _vector_length; ++j)
		{
			if(_input[j] < theta) 
			{
				_output[k++] = j;
			}
		}
		measure.stop();
		_measureJump[theta] = measure.mTotalTime();
	}
}

void JumpTest::fTestPredicated()
{
	for (uint theta = 0; theta <= 100; ++theta)
	{
		Measure measure;
		measure.start();
		for (uint j = 0, k = 0; j < _vector_length; ++j)
		{
			const bool b = (_input[j] < theta);
			_output[k] = j;
			k += b;
		}
		measure.stop();
		_measurePred[theta] = measure.mTotalTime();
	}
}

double JumpTest::fBranchMispredictionCost(const double aSelectivity) 
{
	const double x = aSelectivity;
	if(aSelectivity < 0.4) 
	{
		return 6.26365 * x +  0.00309905; //  (6.26365, 0.00309905)
	} 
	else if(aSelectivity <= 0.6) 
	{
		return  (-3.96349 + 26.8831 * x - 27.1705 * x * x);  // max qerror: 1.00888
	} 
	else 
	{
		return -6.06495 * x + 6.06495;  // (-6.06495, 5.97489)
	}
}

void JumpTest::fPrintResult(std::ostream& output, const std::string setting)
{
	output << std::setw(23) << "vector.size(): " << fFormatNumber(_vector_length) << "\n" << std::endl;
	
	const double nd = (double) _vector_length;
	double_vt lCpu1(101);
	double_vt lCpu2(101);

	output << "jump version of selection:" << std::endl;
	output << "  v" << std::setw(7) << "jump" << std::setw(17) << "predicated" << std::endl;
	for(int v = 0; v <= 100; v+=10) 
	{
		const double vd = (double) v;
		const double x1 = _measureJump[v];
		const double x2 = _measurePred[v];
		lCpu1[v] = x1;
		lCpu2[v] = x2;
		output << std::setw(3)  << v  << ' '
			<< std::setw(10) << x1 << ' '
			<< std::setw(10) << x2 << ' '
			<< std::setw(10) << (x1 / _vector_length) * NS << ' '
			<< std::setw(10) << (x2 / _vector_length) * NS << ' ';
    
		if(v <= 50) 
		{ 
			output << std::setw(10) 
				<< ((_measureJump[v] - _measureJump[0]) / (vd * nd / 100.0)) * NS 
				<< ' ';
		} 
		else if(v > 50 && v < 100) 
		{
			output << std::setw(10) 
				<< ((_measureJump[v] - _measureJump[100]) / ((100 - vd) * nd / 100.0)) * NS 
				<< ' ';
		} 
		else 
		{
			output << std::setw(10) << 0 << ' ';
		}
		output << std::endl;
	}

	output << std::endl;

	const double lCostLo  = lCpu1[0];
	const double lCostHi  = lCpu1[100];
	const double lCountHi = _vector_length;

	const double lCostPerInputTuple  = lCostLo / _vector_length;
	const double lCostPerOutputTuple = (lCostHi - lCostLo) / lCountHi;


	output << "# " 
		<< lCostLo << '/' << lCostHi << ", "
		<< "CostPerTupleIn = " << lCostPerInputTuple << ", "
		<< "CostPerTupleOut = " << lCostPerOutputTuple << ",\n"
		<< std::endl;


	std::ofstream os(("/home/nickwebe/Results/" + setting + "_bmp.dat"));

	os << "# " 
		<< lCostLo << '/' << lCostHi << ", "
		<< "CostPerTupleIn = " << lCostPerInputTuple << ", "
		<< "CostPerTupleOut = " << lCostPerOutputTuple << ", "
		<< std::endl;

	for(uint v = 0; v <= 100; ++v) 
	{
		const double lSel = (double) v / 100;
		const double lTimeBmp = lCpu1[v] - (lCostPerInputTuple * _vector_length + lCostPerOutputTuple * _vector_length * lSel);
		os << v << ' '
			<< lSel << ' '
			<< lCpu1[v] << ' '
			<< lCpu2[v] << ' '
			<< lTimeBmp << ' '
			<< ((lTimeBmp / _vector_length) * 1000 * 1000 * 1000) << ' '
			<< fBranchMispredictionCost(lSel) << ' '
			<< std::endl;
	}
}


void JumpTest::fRunTest(std::ostream& output, const std::string setting)
{
	init();
	fTestJump();
	fTestPredicated();

	fPrintResult(output, setting);
}