#include "xor_test.hh"

XorTest::XorTest(const uint loop, const uint repeat, const uint vector_length) : 
				_loop(loop), _repeat(repeat), _vector_length(vector_length),
				_measure(3), _avg(3), _min(3), _max(3), _avgTotal(3),
				_measureFn(6), _timeFnPtr(6), _measureVec(2),
				_minXor(0), _minFn(6), _minPtr(6){}

double XorTest::fAvg(measure_vt const &measurements, const uint &rep, const uint numb, const uint &loop)
{
	double avg_help = 0;
	for(uint i = 0; i < rep; ++i)
    {
      avg_help += (measurements[i].mTotalTime() / (double) (numb * loop)) * NS;
    }
    return (avg_help / rep);
}

double XorTest::fMin(measure_vt const &measurements, const uint &rep, const uint numb, const uint &loop)
{
	double min_help = (measurements[0].mTotalTime() / (double) (numb * loop)) * NS;
	for (uint i = 0; i < rep; ++i)
	{
		double current = (measurements[i].mTotalTime() / (double) (numb * loop)) * NS;
		if(current < min_help)
		{
			min_help = current;
		}
	}
	return min_help;
}

double XorTest::fMax(measure_vt const &measurements, const uint &rep, const uint numb, const uint &loop)
{
	double max_help = (measurements[0].mTotalTime() / (double) (numb * loop)) * NS;
	for (uint i = 0; i < rep; ++i)
	{
		double current = (measurements[i].mTotalTime() / (double) (numb * loop)) * NS;
		if(current > max_help)
		{
			max_help = current;
		}
	}
	return max_help;
}

double XorTest::fTotalAvg(measure_vt const &measurements, const uint &rep)
{
	double avgTotal_help = 0;
	for(uint i = 0; i < rep; ++i)
    {
      avgTotal_help += measurements[i].mTotalTime();
    }
    return (avgTotal_help / rep);
}

void XorTest::init(measure_vvt &measure, const uint &rep)
{
	for (uint i = 0; i < measure.size(); ++i)
	{
		measure[i].resize(rep);
	}
}

void XorTest::fMeasureXOR24()
{
	uint la =  3;
	uint lb =  5;
	uint lc =  7;
	uint ld = 11;
	uint le = 13;
	uint lf = 17;
	uint lg = 1717171717;
	uint lh = 2171717171;
	uint li = 19;
	uint lj = 33;
	uint lk = 33;
	uint ll = 44;
	uint lm = 23;
	uint ln = 29;
	uint lo = 31;
	uint lp = 37;
	uint lq = 41;
	uint lr = 43;
	uint ls = 47;
	uint lt = 53;
	uint lu = 59;
	uint lv = 61;
	uint lw = 67;
	uint lx = 71;

	for(uint i = 0; i < _repeat; ++i)
  	{
	    _measure[0][i].start();
	    for(uint j = 0; j < _loop; ++j) 
	    {
	        la = lo ^ lp;
	        lb = lp ^ lq;
	        lc = lq ^ lr;
	        ld = lr ^ ls;
	        le = ls ^ lt;
	        lf = lt ^ lu;
	        lg = lu ^ lv;
	        lh = lv ^ lw;
	        li = lw ^ lx;
	        lj = lx ^ la;
	        lk = la ^ lb;
	        ll = lb ^ lc;
	        lm = lc ^ ld;
	        ln = ld ^ le;
	        lo = le ^ lf;
	        lp = lf ^ lg;
	        lq = lg ^ lh;
	        lr = lh ^ li;
	        ls = li ^ lj;
	        lt = lj ^ lk;
	        lu = lk ^ ll;
	        lv = ll ^ lm;
	        lw = lm ^ ln;
	        lx = ln ^ lo;
	    }
	    _measure[0][i].stop();
	    std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll^lm^ln^lo^lp^lq^lr^ls^lt^lu^lv^lw^lx) << std::endl;
	}
	_avg[0] = XorTest::fAvg(_measure[0], _repeat, 24, _loop);
	_min[0] = XorTest::fMin(_measure[0], _repeat, 24, _loop);
	_max[0] = XorTest::fMax(_measure[0], _repeat, 24, _loop);
	_avgTotal[0] = XorTest::fTotalAvg(_measure[0], _repeat);
}

void XorTest::fMeasureXOR12()
{
	uint la =  3;
	uint lb =  5;
	uint lc =  7;
	uint ld = 11;
	uint le = 13;
	uint lf = 17;
	uint lg = 1717171717;
	uint lh = 2171717171;
	uint li = 19;
	uint lj = 33;
	uint lk = 33;
	uint ll = 44;

	for(uint i = 0; i < _repeat; ++i)
  	{
	    _measure[1][i].start();
	    for(uint j = 0; j < _loop; ++j) 
	    {
	        la = le ^ lf;
	        lb = lf ^ lg;
	        lc = lg ^ lh;
	        ld = lh ^ li;
	        le = li ^ lj;
	        lf = lj ^ lk;
	        lg = lk ^ ll;
	        lh = ll ^ la;
	        li = la ^ lb;
	        lj = lb ^ lc;
	        lk = lc ^ ld;
	        ll = ld ^ le;
	    }
	    _measure[1][i].stop();
		std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;
	}
	_avg[1] = XorTest::fAvg(_measure[1], _repeat, 12, _loop);
	_min[1] = XorTest::fMin(_measure[1], _repeat, 12, _loop);
	_max[1] = XorTest::fMax(_measure[1], _repeat, 12, _loop);
	_avgTotal[1] = XorTest::fTotalAvg(_measure[1], _repeat);
}

void XorTest::fMeasureXOR6()
{
	uint la =  3;
	uint lb =  5;
	uint lc =  7;
	uint ld = 11;
	uint le = 13;
	uint lf = 17;

	for(uint i = 0; i < _repeat; ++i)
  	{
	    _measure[2][i].start();
	    for(uint j = 0; j < _loop; ++j) 
	    {
	        la = lc ^ ld;
	        lb = ld ^ le;
	        lc = le ^ lf;
	        ld = lf ^ la;
	        le = la ^ lb;
	        lf = lb ^ lc;
	    }
	    _measure[2][i].stop();
		std::cout << "// " << (la^lb^lc^ld^le^lf) << std::endl;
	}
	_avg[2] = XorTest::fAvg(_measure[2], _repeat, 6, _loop);
	_min[2] = XorTest::fMin(_measure[2], _repeat, 6, _loop);
	_max[2] = XorTest::fMax(_measure[2], _repeat, 6, _loop);
	_avgTotal[2] = XorTest::fTotalAvg(_measure[2], _repeat);
}

void XorTest::fMeasureFnXOR()
{
	uint la =  3;
	uint lb =  5;
	uint lc =  7;
	uint ld = 11;
	uint le = 13;
	uint lf = 17;
	uint lg = 1717171717;
	uint lh = 2171717171;
	uint li = 19;
	uint lj = 33;
	uint lk = 33;
	uint ll = 44;

	for (uint i = 0; i < _repeat; ++i)
	{
		_measureFn[0][i].start();
		for(uint j = 0; j < _loop; ++j) 
		{
			la = xor2(le , lf);
			lb = xor2(lf , lg);
			lc = xor2(lg , lh);
			ld = xor2(lh , li);
			le = xor2(li , lj);
			lf = xor2(lj , lk);
			lg = xor2(lk , ll);
			lh = xor2(ll , la);
			li = xor2(la , lb);
			lj = xor2(lb , lc);
			lk = xor2(lc , ld);
			ll = xor2(ld , le);
		}
		_measureFn[0][i].stop();
		std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;

		_measureFn[1][i].start();
		for(uint j = 0; j < _loop; ++j) 
		{
			la = xor3(le , lf, lg);
			lb = xor3(lf , lg, lh);
			lc = xor3(lg , lh, li);
			ld = xor3(lh , li, lj);
			le = xor3(li , lj, lk);
			lf = xor3(lj , lk, ll);
			lg = xor3(lk , ll, la);
			lh = xor3(ll , la, lb);
			li = xor3(la , lb, lc);
			lj = xor3(lb , lc, ld);
			lk = xor3(lc , ld, le);
			ll = xor3(ld , le, lf);
		}
		_measureFn[1][i].stop();
		std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;

		_measureFn[2][i].start();
		for(uint j = 0; j < _loop; ++j)
		{
	      	la = xor4(le , lf, lg, lh);
	      	lb = xor4(lf , lg, lh, li);
	      	lc = xor4(lg , lh, li, lj);
	      	ld = xor4(lh , li, lj, lk);
	      	le = xor4(li , lj, lk, ll);
	      	lf = xor4(lj , lk, ll, la);
	      	lg = xor4(lk , ll, la, lb);
	      	lh = xor4(ll , la, lb, lc);
	      	li = xor4(la , lb, lc, ld);
	      	lj = xor4(lb , lc, ld, le);
	      	lk = xor4(lc , ld, le, lf);
	      	ll = xor4(ld , le, lf, lg);
		}
		_measureFn[2][i].stop();
		std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;

		_measureFn[3][i].start();
    	for(uint j = 0; j < _loop; ++j)
    	{
	      	la = xor5(le , lf, lg, lh, li);
	      	lb = xor5(lf , lg, lh, li, lj);
	      	lc = xor5(lg , lh, li, lj, lk);
	      	ld = xor5(lh , li, lj, lk, ll);
	      	le = xor5(li , lj, lk, ll, la);
	      	lf = xor5(lj , lk, ll, la, lb);
	      	lg = xor5(lk , ll, la, lb, lc);
	      	lh = xor5(ll , la, lb, lc, ld);
	      	li = xor5(la , lb, lc, ld, le);
	      	lj = xor5(lb , lc, ld, le, lf);
	      	lk = xor5(lc , ld, le, lf, lg);
	      	ll = xor5(ld , le, lf, lg, lh);
    	}
    	_measureFn[3][i].stop();
    	std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;

    	_measureFn[4][i].start();
    	for(uint j = 0; j < _loop; ++j)
    	{
	      	la = xor6(le , lf, lg, lh, li, lj);
	      	lb = xor6(lf , lg, lh, li, lj, lk);
	      	lc = xor6(lg , lh, li, lj, lk, ll);
	      	ld = xor6(lh , li, lj, lk, ll, la);
	      	le = xor6(li , lj, lk, ll, la, lb);
	      	lf = xor6(lj , lk, ll, la, lb, lc);
	      	lg = xor6(lk , ll, la, lb, lc, ld);
	      	lh = xor6(ll , la, lb, lc, ld, le);
	      	li = xor6(la , lb, lc, ld, le, lf);
	      	lj = xor6(lb , lc, ld, le, lf, lg);
	      	lk = xor6(lc , ld, le, lf, lg, lh);
	      	ll = xor6(ld , le, lf, lg, lh, li);
    	}
    	_measureFn[4][i].stop();
    	std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;

    	_measureFn[5][i].start();
    	for(uint j = 0; j < _loop; ++j)
    	{
	      	la = xor7(le , lf, lg, lh, li, lj, lk);
	      	lb = xor7(lf , lg, lh, li, lj, lk, ll);
	      	lc = xor7(lg , lh, li, lj, lk, ll, la);
	      	ld = xor7(lh , li, lj, lk, ll, la, lb);
	      	le = xor7(li , lj, lk, ll, la, lb, lc);
	      	lf = xor7(lj , lk, ll, la, lb, lc, ld);
	      	lg = xor7(lk , ll, la, lb, lc, ld, le);
	      	lh = xor7(ll , la, lb, lc, ld, le, lf);
	      	li = xor7(la , lb, lc, ld, le, lf, lg);
	      	lj = xor7(lb , lc, ld, le, lf, lg, lh);
	      	lk = xor7(lc , ld, le, lf, lg, lh, li);
	      	ll = xor7(ld , le, lf, lg, lh, li, lj);
    	}
		_measureFn[5][i].stop();
		std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;
	}
}

void XorTest::fMeasureFnPtrXOR()
{
	for (uint i = 0; i < 6; ++i)
	{
		_timeFnPtr[i].resize(_repeat);
	}

	for(uint i = 0; i < _repeat; ++i)
	{
		_timeFnPtr[0][i] = run2uint(&xor2, _loop);
		_timeFnPtr[1][i] = run3uint(&xor3, _loop);
		_timeFnPtr[2][i] = run4uint(&xor4, _loop);
		_timeFnPtr[3][i] = run5uint(&xor5, _loop);
		_timeFnPtr[4][i] = run6uint(&xor6, _loop);
		_timeFnPtr[5][i] = run7uint(&xor7, _loop);
	}
}

void XorTest::fMeasureVectorXOR()
{
	uint la =  3;
	uint lb =  5;
	uint lc =  7;
	uint ld = 11;
	uint le = 13;
	uint lf = 17;
	uint lg = 1717171717;
	uint lh = 2171717171;
	uint li = 19;
	uint lj = 33;
	uint lk = 33;
	uint ll = 44;
	uint lm = 23;
	uint ln = 29;
	uint lo = 31;
	uint lp = 37;
	uint lq = 41;
	uint lr = 43;
	uint ls = 47;
	uint lt = 53;
	uint lu = 59;
	uint lv = 61;
	uint lw = 67;
	uint lx = 71;

	std::vector<uint> help = {la,lb,lc,ld,le,lf,lg,lh,li,lj,lk,ll,lm,ln,lo,lp,lq,lr,ls,lt,lu,lv,lw,lx};


	std::vector<uint> a(_vector_length);
	std::vector<uint> b(_vector_length);
	std::vector<uint> x(_vector_length);
    uint y = 97;

    for(uint i = 0; i < _vector_length; ++i)
    {
      a.push_back(help.at(i % 24));
      b.at(_vector_length-1-i) = help.at(i % 24);
    }

    _measureVec[0].start();
    for(uint i = 0; i < _vector_length; ++i)
    {
      y ^= a[i] ^ b[i];
    }
    _measureVec[0].stop();
    std::cout << "// " << y << std::endl;


    _measureVec[1].start();
    for(uint i = 0; i < _vector_length; ++i)
    {
       x[i] = a[i] ^ b[i];
    }
    _measureVec[1].stop();
    std::cout << "// " << x.at(_vector_length/2) << std::endl;
}

void XorTest::fMinXOR()
{
	double findMinXorTime = _min[0];
	for (int i = 1; i < 3; ++i)
	{
		if(_min[i] < findMinXorTime)
		{
			findMinXorTime = _min[i];
		}
	}
	_minXor = findMinXorTime;
}

void XorTest::fMinFn()
{
	for (uint i = 0; i < 6; ++i)
	{
		double min_f_help = (_measureFn[i][0].mTotalTime() / ((double) (12 * _loop))) * NS;
		for (uint j = 0; j < _repeat; ++j)
		{
			double current = (_measureFn[i][j].mTotalTime() / ((double) (12 * _loop))) * NS;
			if(current < min_f_help)
			{
				min_f_help = current;
			}
		}
		_minFn[i] = min_f_help;
	}
}

void XorTest::fMinPtr()
{
	for (uint i = 0; i < 6; ++i)
	{
		double min_p_help = _timeFnPtr[i][0];
		for (uint j = 0; j < _repeat; ++j)
		{
			if(_timeFnPtr[i][j] < min_p_help)
			{
				min_p_help = _timeFnPtr[i][j];
			}
		}
		_minPtr[i] = min_p_help;
	}
}

void XorTest::fPrintResult(std::ostream& output, std::ostream& compare)
{
	output.precision(4);

	output << std::fixed;

	output << std::setw(27) << "Number of Repeats: " << std::setw(2) <<  _repeat << ' ' 
		<< std::setw(31) << "Loop Iterations: " << std::setw(2) << fFormatNumber(_loop) << "\n" <<std::endl;

	output << std::setw(3) << "<24xor> avg:" << ' ' 
		<< std::setw(5) << _avg[0] << " [ns]" << ' ' 
		<< std::setw(5) << "min:" << ' ' 
		<< std::setw(5) << _min[0] << " [ns]" << ' ' 
		<< std::setw(5) << "max:" << ' '
		<< std::setw(5) << _max[0] << " [ns]" << ' '
		<< std::setw(5) << "Total avg:" << ' '
		<< std::setw(5) << _avgTotal[0] << " [s]"
		<< std::endl;

	output << std::setw(3) << "<12xor> avg:" << ' ' 
		<< std::setw(5) << _avg[1] << " [ns]" << ' ' 
		<< std::setw(5) << "min:" << ' ' 
		<< std::setw(5) << _min[1] << " [ns]" << ' ' 
		<< std::setw(5) << "max:" << ' '
		<< std::setw(5) << _max[1] << " [ns]" << ' '
		<< std::setw(5) << "Total avg:" << ' '
		<< std::setw(5) << _avgTotal[1] << " [s]"
		<< std::endl;

	output << std::setw(3) << " <6xor> avg:" << ' ' 
		<< std::setw(5) << _avg[2] << " [ns]" << ' ' 
		<< std::setw(5) << "min:" << ' ' 
		<< std::setw(5) << _min[2] << " [ns]" << ' ' 
		<< std::setw(5) << "max:" << ' '
		<< std::setw(5) << _max[2] << " [ns]" << ' '
		<< std::setw(5) << "Total avg:" << ' '
		<< std::setw(5) << _avgTotal[2] << " [s]"
		<< std::endl;

	output << std::string(80, '-') << std::endl;
	output << "Time to Calculate xor: ~" << _minXor << " [ns]" <<std::endl;
	output << std::string(80, '-') << "\n" << std::endl;

	for(uint i = 0; i < 6; ++i)
	{
		const double functionCall = (_minFn[i] - _minXor);
		const double pointerCall = (_minPtr[i] /*- functionCall*/ - _minXor);
		output << std::setw(3) << "<xor" << (i+2) << ">  min:" << ' ' 
			<< std::setw(5) << functionCall << " [ns]" << ' '
			<< std::setw(5) << "<run" << (i+2) << "uint> min:" << ' ' 
			<< std::setw(5) << pointerCall << " [ns]" << ' '
			<< std::endl;
	}
	output << std::string(80, '-') << "\n" << std::endl;

	output << std::setw(23) << "vector.size(): " << fFormatNumber(_vector_length) << "\n" << std::endl;
	output << std::setw(3) << "X ^= A[i] ^ B[i] : " << ' ' 
		<< std::setw(5) << ((_measureVec[0].mTotalTime()/ (double) _vector_length) * NS) << " [ns]" << ' '
		<< std::setw(35) << "X[i] = A[i] ^ B[i] : " << ' ' 
		<< std::setw(5) << ((_measureVec[1].mTotalTime()/ (double) _vector_length) * NS) << " [ns]" << "\n"
		<< std::endl;

	compare << "XOR [ns]/" << _minXor << std::endl
		<< "X^=A[i]^B[i] [ns]/" << ((_measureVec[0].mTotalTime()/ (double) _vector_length) * NS) << std::endl
		<< "X[i]^=A[i]^B[i] [ns]/" << ((_measureVec[1].mTotalTime()/ (double) _vector_length) * NS) << std::endl;
}


void XorTest::fRunTest(std::ostream& output, std::ostream& compare)
{
	init(_measure, _repeat);
	fMeasureXOR24();
	fMeasureXOR12();
	fMeasureXOR6();

	init(_measureFn, _repeat);
	fMeasureFnXOR();
	fMeasureFnPtrXOR();

	fMeasureVectorXOR();

	fMinXOR();
	fMinFn();
	fMinPtr();

	fPrintResult(output, compare);
}