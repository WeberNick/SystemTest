#ifndef CPUTEST_FUNS_HH
#define CPUTEST_FUNS_HH

#include "types.hh"


double run2uint(uint (*f)(uint,uint), const uint n);
double run3uint(uint (*f)(uint,uint,uint), const uint n);
double run4uint(uint (*f)(uint,uint,uint,uint), const uint n);
double run5uint(uint (*f)(uint,uint,uint,uint,uint), const uint n);
double run6uint(uint (*f)(uint,uint,uint,uint,uint,uint), const uint n);
double run7uint(uint (*f)(uint,uint,uint,uint,uint,uint,uint), const uint n);

// inlined functions

inline void fiCsiVoid(int a, int b, int& c)  {}
inline void fiCsiCopya(int a, int b, int& c) { c = a; }
inline void fiCsiCopyb(int a, int b, int& c) { c = b; }

inline int  fiRsiPlusC(const int a, const int b)  { return (a + b); }
inline void fiCsiPlusC(const int a, const int b, int& c)  { c = (a + b); }

inline int fiRsiPlus(int a, int b)  { return (a + b); }
inline int fiRsiMinus(int a, int b) { return (a - b); }
inline int fiRsiMal(int a, int b)   { return (a * b); }
inline int fiRsiDiv(int a, int b)   { return (a / b); }

inline void fiCsiPlus(int a, int b, int& c)  { c = (a + b); }
inline void fiCsiMinus(int a, int b, int& c) { c = (a - b); }
inline void fiCsiMal(int a, int b, int& c)   { c = (a * b); }
inline void fiCsiDiv(int a, int b, int& c)   { c = (a / b); }

inline double fiRdbExp(double a, double b)    { return exp(a); }
inline double fiRdbLog(double a, double b)    { return log(a); }
inline double fiRdbPow(double a, double b)    { return pow(a,b); }
inline double fiRdbLGamma(double a, double b) { return lgamma(a); }
inline double fiRdbSqrt(double a, double b)   { return sqrt(a); }

inline void fiCdbExp(double a, double b, double& c)    { c = exp(a); }
inline void fiCdbLog(double a, double b, double& c)    { c = log(a); }
inline void fiCdbPow(double a, double b, double& c)    { c = pow(a,b); }
inline void fiCdbLGamma(double a, double b, double& c) { c = lgamma(a); }

inline float fiRftExp(float a, float b) { return expf(a); }
inline float fiRftLog(float a, float b) { return logf(a); }
inline float fiRftPow(float a, float b) { return powf(a,b); }
inline float fiRftLGamma(float a, float b) { return lgammaf(a); }

inline void fiCftExp(float a, float b, float& c)    { c =  expf(a); }
inline void fiCftLog(float a, float b, float& c)    { c =  logf(a); }
inline void fiCftPow(float a, float b, float& c)    { c =  powf(a,b); }
inline void fiCftLGamma(float a, float b, float& c) { c =  lgammaf(a); }

// outlined functions (real calls necessary)

uint fId2(uint x1, uint x2);
uint fId3(uint x1, uint x2, uint x3);
uint fId4(uint x1, uint x2, uint x3, uint x4);
uint fId5(uint x1, uint x2, uint x3, uint x4, uint x5);
uint fId6(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6);
uint fId7(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6, uint x7);


void foCsiVoid(int a, int b, int& c);
void foCsiCopya(int a, int b, int& c);
void foCsiCopyb(int a, int b, int& c);

int  foRsiPlusC(int a, int b);
void foCsiPlusC(const int a, const int b, int& c);

int foRsiPlus(int a, int b);
int foRsiMinus(int a, int b);
int foRsiMal(int a, int b);
int foRsiDiv(int a, int b);

void foCsiPlus(int a, int b, int& c);
void foCsiMinus(int a, int b, int& c);
void foCsiMal(int a, int b, int& c);
void foCsiDiv(int a, int b, int& c);


double foRdbExp(double a, double b);
double foRdbLog(double a, double b);
double foRdbPow(double a, double b);
double foRdbLGamma(double a, double b);
double foRdbSqrt(double a, double b);

void foCdbExp(double a, double b, double& c);
void foCdbLog(double a, double b, double& c);
void foCdbPow(double a, double b, double& c);
void foCdbLGamma(double a, double b, double& c);


float foRftExp(float a, float b);
float foRftLog(float a, float b);
float foRftPow(float a, float b);
float foRftLGamma(float a, float b);
float foRftSqrt(float a, float b);

void foCftExp(float a, float b, float& c);
void foCftLog(float a, float b, float& c);
void foCftPow(float a, float b, float& c);
void foCftLGamma(float a, float b, float& c);




uint xor2(uint x1, uint x2);
uint xor3(uint x1, uint x2, uint x3);
uint xor4(uint x1, uint x2, uint x3, uint x4);
uint xor5(uint x1, uint x2, uint x3, uint x4, uint x5);
uint xor6(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6);
uint xor7(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6, uint x7);

uint fId2(uint x1, uint x2);
uint fId3(uint x1, uint x2, uint x3);
uint fId4(uint x1, uint x2, uint x3, uint x4);
uint fId5(uint x1, uint x2, uint x3, uint x4, uint x5);
uint fId6(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6);
uint fId7(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6, uint x7);

uint fIdXor2(uint x1, uint x2);
uint fIdXor3(uint x1, uint x2, uint x3);
uint fIdXor4(uint x1, uint x2, uint x3, uint x4);
uint fIdXor5(uint x1, uint x2, uint x3, uint x4, uint x5);
uint fIdXor6(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6);
uint fIdXor7(uint x1, uint x2, uint x3, uint x4, uint x5, uint x6, uint x7);


void copyPtr(int** y, int** x, const int n);

void copyPtr1(int** y, int** x);
void copyPtr2(int** y, int** x);
void copyPtr3(int** y, int** x);
void copyPtr4(int** y, int** x);
void copyPtr5(int** y, int** x);
void copyPtr6(int** y, int** x);
void copyPtr7(int** y, int** x);
void copyPtr8(int** y, int** x);
void copyPtr9(int** y, int** x);
void copyPtr10(int** y, int** x);
void copyPtr11(int** y, int** x);
void copyPtr12(int** y, int** x);
void copyPtr13(int** y, int** x);
void copyPtr14(int** y, int** x);
void copyPtr15(int** y, int** x);
void copyPtr16(int** y, int** x);

void copyPtr1L(int** y, int** x);
void copyPtr2L(int** y, int** x);
void copyPtr3L(int** y, int** x);
void copyPtr4L(int** y, int** x);
void copyPtr5L(int** y, int** x);
void copyPtr6L(int** y, int** x);
void copyPtr7L(int** y, int** x);
void copyPtr8L(int** y, int** x);
void copyPtr9L(int** y, int** x);
void copyPtr10L(int** y, int** x);
void copyPtr11L(int** y, int** x);
void copyPtr12L(int** y, int** x);
void copyPtr13L(int** y, int** x);
void copyPtr14L(int** y, int** x);
void copyPtr15L(int** y, int** x);
void copyPtr16L(int** y, int** x);

#endif





