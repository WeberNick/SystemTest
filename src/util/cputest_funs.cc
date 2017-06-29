#include "cputest_funs.hh"

double
run2uint(uint (*f)(uint,uint), const uint n) {
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
  Measure lMeasure;
  lMeasure.start();
  for(uint i = 0; i < n; ++i){
    la = (*f)(le , lf);
    lb = (*f)(lf , lg);
    lc = (*f)(lg , lh);
    ld = (*f)(lh , li);
    le = (*f)(li , lj);
    lf = (*f)(lj , lk);
    lg = (*f)(lk , ll);
    lh = (*f)(ll , la);
    li = (*f)(la , lb);
    lj = (*f)(lb , lc);
    lk = (*f)(lc , ld);
    ll = (*f)(ld , le);
  }
  lMeasure.stop();
  std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;

  return (lMeasure.mTotalTime() / (double) (12 * n)) * NS;
}

double
run3uint(uint (*f)(uint,uint,uint), const uint n) {
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
  Measure lMeasure;
  lMeasure.start();
  for(uint i = 0; i < n; ++i) {
    la = (*f)(le , lf, lg);
    lb = (*f)(lf , lg, lh);
    lc = (*f)(lg , lh, li);
    ld = (*f)(lh , li, lj);
    le = (*f)(li , lj, lk);
    lf = (*f)(lj , lk, ll);
    lg = (*f)(lk , ll, la);
    lh = (*f)(ll , la, lb);
    li = (*f)(la , lb, lc);
    lj = (*f)(lb , lc, ld);
    lk = (*f)(lc , ld, le);
    ll = (*f)(ld , le, lf);
  }
  lMeasure.stop();
  std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;
  return (lMeasure.mTotalTime() / (double) (n * 12)) * NS;
}

double
run4uint(uint (*f)(uint,uint,uint,uint), const uint n) {
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
  Measure lMeasure;
  lMeasure.start();
  for(uint i = 0; i < n; ++i) {
    la = (*f)(le , lf, lg, lh);
    lb = (*f)(lf , lg, lh, li);
    lc = (*f)(lg , lh, li, lj);
    ld = (*f)(lh , li, lj, lk);
    le = (*f)(li , lj, lk, ll);
    lf = (*f)(lj , lk, ll, la);
    lg = (*f)(lk , ll, la, lb);
    lh = (*f)(ll , la, lb, lc);
    li = (*f)(la , lb, lc, ld);
    lj = (*f)(lb , lc, ld, le);
    lk = (*f)(lc , ld, le, lf);
    ll = (*f)(ld , le, lf, lg);
  }
  lMeasure.stop();
  std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;
  return (lMeasure.mTotalTime() / (double) (n * 12)) * NS;
}

double
run5uint(uint (*f)(uint,uint,uint,uint,uint), const uint n) {
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
  Measure lMeasure;
  lMeasure.start();
  for(uint i = 0; i < n; ++i) {
    la = (*f)(le , lf, lg, lh, li);
    lb = (*f)(lf , lg, lh, li, lj);
    lc = (*f)(lg , lh, li, lj, lk);
    ld = (*f)(lh , li, lj, lk, ll);
    le = (*f)(li , lj, lk, ll, la);
    lf = (*f)(lj , lk, ll, la, lb);
    lg = (*f)(lk , ll, la, lb, lc);
    lh = (*f)(ll , la, lb, lc, ld);
    li = (*f)(la , lb, lc, ld, le);
    lj = (*f)(lb , lc, ld, le, lf);
    lk = (*f)(lc , ld, le, lf, lg);
    ll = (*f)(ld , le, lf, lg, lh);
  }
  lMeasure.stop();
  std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;
  return (lMeasure.mTotalTime() / (double) (n * 12)) * NS;
}

double
run6uint(uint (*f)(uint,uint,uint,uint,uint,uint), const uint n) {
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
  Measure lMeasure;
  lMeasure.start();
  for(uint i = 0; i < n; ++i) {
    la = (*f)(le , lf, lg, lh, li, lj);
    lb = (*f)(lf , lg, lh, li, lj, lk);
    lc = (*f)(lg , lh, li, lj, lk, ll);
    ld = (*f)(lh , li, lj, lk, ll, la);
    le = (*f)(li , lj, lk, ll, la, lb);
    lf = (*f)(lj , lk, ll, la, lb, lc);
    lg = (*f)(lk , ll, la, lb, lc, ld);
    lh = (*f)(ll , la, lb, lc, ld, le);
    li = (*f)(la , lb, lc, ld, le, lf);
    lj = (*f)(lb , lc, ld, le, lf, lg);
    lk = (*f)(lc , ld, le, lf, lg, lh);
    ll = (*f)(ld , le, lf, lg, lh, li);
  }
  lMeasure.stop();
  std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;
  return (lMeasure.mTotalTime() / (double) (n * 12)) * NS;
}

double
run7uint(uint (*f)(uint,uint,uint,uint,uint,uint,uint), const uint n) {
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
  Measure lMeasure;
  lMeasure.start();
  for(uint i = 0; i < n; ++i) {
    la = (*f)(le , lf, lg, lh, li, lj, lk);
    lb = (*f)(lf , lg, lh, li, lj, lk, ll);
    lc = (*f)(lg , lh, li, lj, lk, ll, la);
    ld = (*f)(lh , li, lj, lk, ll, la, lb);
    le = (*f)(li , lj, lk, ll, la, lb, lc);
    lf = (*f)(lj , lk, ll, la, lb, lc, ld);
    lg = (*f)(lk , ll, la, lb, lc, ld, le);
    lh = (*f)(ll , la, lb, lc, ld, le, lf);
    li = (*f)(la , lb, lc, ld, le, lf, lg);
    lj = (*f)(lb , lc, ld, le, lf, lg, lh);
    lk = (*f)(lc , ld, le, lf, lg, lh, li);
    ll = (*f)(ld , le, lf, lg, lh, li, lj);
  }
  lMeasure.stop();
  std::cout << "// " << (la^lb^lc^ld^le^lf^lg^lh^li^lj^lk^ll) << std::endl;
  return (lMeasure.mTotalTime() / (double) (n * 12)) * NS;
}




uint fId2(uint x1, uint x2) { return x1; }
uint fId3(uint x1, uint x2, uint x3) { return x1; }
uint fId4(uint x1, uint x2, uint x3, uint x4) { return x1; }
uint fId5(uint x1, uint x2, uint x3, uint x4, uint x5) { return x1; }
uint fId6(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6) { return x1; }
uint fId7(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6, uint x7) { return x1; }


void foCsiVoid(int a, int b, int& c) {}
void foCsiCopya(int a, int b, int& c) { c = a; }
void foCsiCopyb(int a, int b, int& c) { c = b; }

int  foRsiPlusC(int a, int b) { return (a + b); }
void foCsiPlusC(const int a, const int b, int& c) { c = a + b; }


int foRsiPlus(int a, int b)  { return (a + b); }
int foRsiMinus(int a, int b) { return (a - b); }
int foRsiMal(int a, int b)   { return (a * b); }
int foRsiDiv(int a, int b)   { return (a / b); }

void foCsiPlus(int a, int b, int& c)  { c = (a + b); }
void foCsiMinus(int a, int b, int& c) { c = (a - b); }
void foCsiMal(int a, int b, int& c)   { c = (a * b); }
void foCsiDiv(int a, int b, int& c)   { c = (a / b); }


double foRdbExp(double a, double b)    { return exp(a); }
double foRdbLog(double a, double b)    { return log(a); }
double foRdbPow(double a, double b)    { return pow(a,b); }
double foRdbLGamma(double a, double b) { return lgamma(a); }
double foRdbSqrt(double a, double b) { return sqrt(a); }

void foCdbExp(double a, double b, double& c)    { c = exp(a); }
void foCdbLog(double a, double b, double& c)    { c = log(a); }
void foCdbPow(double a, double b, double& c)    { c = pow(a,b); }
void foCdbLGamma(double a, double b, double& c) { c = lgamma(a); }


float foRftExp(float a, float b) { return expf(a); }
float foRftLog(float a, float b) { return logf(a); }
float foRftPow(float a, float b) { return powf(a,b); }
float foRftLGamma(float a, float b) { return lgammaf(a); }
float foRftSqrt(float a, float b) { return sqrtf(a); }

void foCftExp(float a, float b, float& c)    { c =  expf(a); }
void foCftLog(float a, float b, float& c)    { c =  logf(a); }
void foCftPow(float a, float b, float& c)    { c =  powf(a,c); }
void foCftLGamma(float a, float b, float& c) { c =  lgammaf(a); }

uint 
xor2(uint x1, uint x2) {
  return (x1 ^ x2);
}

uint 
xor3(uint x1, uint x2, uint x3) {
  return (x1 ^ x2);
}

uint 
xor4(uint x1, uint x2, uint x3, uint x4) {
  return (x1 ^ x2);
}

uint 
xor5(uint x1, uint x2, uint x3, uint x4, uint x5) {
  return (x1 ^ x2);
}

uint 
xor6(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6) {
  return (x1 ^ x2);
}

uint 
xor7(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6, uint x7) {
  return (x1 ^ x2);
}


uint
fIdXor2(uint x1, uint x2) {
  return (fId2(x1, x2) ^ x2);
}

uint
fIdXor3(uint x1, uint x2, uint x3) {
  return (fId3(x1, x2, x3) ^ x2);
}

uint
fIdXor4(uint x1, uint x2, uint x3, uint x4) {
  return (fId4(x1, x2, x3, x4) ^ x2);
}

uint
fIdXor5(uint x1, uint x2, uint x3, uint x4, uint x5) {
  return (fId5(x1, x2, x3, x4, x5) ^ x2);
}

uint
fIdXor6(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6) {
  return (fId6(x1, x2, x3, x4, x5, x6) ^ x2);
}

uint
fIdXor7(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6, uint x7) {
  return (fId7(x1, x2, x3, x4, x5, x6, x7) ^ x2);
}

void
copyPtr(int** y, int** x, const int n) {
  for(int i = 0; i < n; ++i) {
    y[i] = x[i];
  }
}


void 
copyPtr1(int** y, int** x) {
  *y = *x;
}

void 
copyPtr2(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
}

void 
copyPtr3(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}

void 
copyPtr4(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}

void 
copyPtr5(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}

void 
copyPtr6(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}

void 
copyPtr7(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}

void 
copyPtr8(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}

void 
copyPtr9(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}


void 
copyPtr10(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}


void 
copyPtr11(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}


void 
copyPtr12(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}


void 
copyPtr13(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}


void 
copyPtr14(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}


void 
copyPtr15(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}

void 
copyPtr16(int** y, int** x) {
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
  ++y; ++x;
  *y = *x;
}


template<int n>
void
copyPtrT(int** y, int** x) {
  for(int i = 0; i < n; ++i) {
    y[i] = x[i];
  }
}


void 
copyPtr1L(int** y, int** x) {
  copyPtrT<1>(y, x);
}

void 
copyPtr2L(int** y, int** x) {
  copyPtrT<2>(y, x);
}

void 
copyPtr3L(int** y, int** x) {
  copyPtrT<3>(y, x);
}

void 
copyPtr4L(int** y, int** x) {
  copyPtrT<4>(y, x);
}

void 
copyPtr5L(int** y, int** x) {
  copyPtrT<5>(y, x);
}

void 
copyPtr6L(int** y, int** x) {
  copyPtrT<6>(y, x);
}

void 
copyPtr7L(int** y, int** x) {
  copyPtrT<7>(y, x);
}

void 
copyPtr8L(int** y, int** x) {
  copyPtrT<8>(y, x);
}

void 
copyPtr9L(int** y, int** x) {
  copyPtrT<9>(y, x);
}

void 
copyPtr10L(int** y, int** x) {
  copyPtrT<10>(y, x);
}

void 
copyPtr11L(int** y, int** x) {
  copyPtrT<11>(y, x);
}

void 
copyPtr12L(int** y, int** x) {
  copyPtrT<12>(y, x);
}

void 
copyPtr13L(int** y, int** x) {
  copyPtrT<13>(y, x);
}

void 
copyPtr14L(int** y, int** x) {
  copyPtrT<14>(y, x);
}

void 
copyPtr15L(int** y, int** x) {
  copyPtrT<15>(y, x);
}

void 
copyPtr16L(int** y, int** x) {
  copyPtrT<16>(y, x);
}


