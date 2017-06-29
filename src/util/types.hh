#ifndef SYSTEMTEST_TYPES_HH
#define SYSTEMTEST_TYPES_HH

#include <iostream>
#include <iomanip>
#include <inttypes.h>
#include <vector>
#include <cmath>

#include "infra/measure.hh"
#include "infra/print_test_header.hh"
#include "infra/random_permutation.hh"

#include "format.hh"

#ifdef __x86_64__
const uint   Nexp = ( 100*1000*1000); // number of times 'expensive' things are repeated
const uint   Nchp = (1000*1000*1000); // number of times 'cheap' things are repeated
const uint   Narr = ( 100*1000*1000); // array size used
#elif __arm__
const uint   Nexp = (  10*1000*1000); // number of times 'expensive' things are repeated
const uint   Nchp = ( 100*1000*1000); // number of times 'cheap' things are repeated
const uint   Narr = (  10*1000*1000); // array size used
#endif

// const double NS = (1000.0L * 1000.0L * 1000.0L);
extern const char* uNS; // "[ns]"

inline double
nstime(const double t, const double n) {
  return (t / n) * NS;
}

typedef unsigned int uint;
typedef std::vector<uint> uint_vt;


typedef void   (*int1_ft   )(int*   , int    *);
typedef void   (*int2_ft   )(int*   , int    *, int   *);
typedef void   (*uint1_ft  )(uint*  , uint   *);
typedef void   (*uint2_ft  )(uint*  , uint   *, uint  *);
typedef void   (*float1_ft )(float* , float  *);
typedef void   (*float2_ft )(float* , float  *, float *);
typedef void   (*double1_ft)(double*, double *);
typedef void   (*double2_ft)(double*, double *, double*);


template<typename T>
double
run1(T* aRes, T* aArg, void (*aFun)(T*,T*), const uint aN) {
  Measure lMeasure;
  lMeasure.start();
  for(uint i = 0; i < aN; ++i) {
    (*aFun)(aRes, aArg);
  }
  lMeasure.stop();
  // std::cout << "tot cpu: " << lMeasure.mCpuTime() << std::endl;
  return nstime(lMeasure.mCpuTime(), aN);
}


template<typename T>
double
run2(T* aRes, T* aArg1, T* aArg2, void (*aFun)(T*,T*,T*), const uint aN) {
  Measure lMeasure;
  lMeasure.start();
  for(uint i = 0; i < aN; ++i) {
    (*aFun)(aRes, aArg1, aArg2);
  }
  lMeasure.stop();
  // std::cout << "tot cpu: " << lMeasure.mCpuTime() << std::endl;
  return nstime(lMeasure.mCpuTime(), aN);
}


#endif
