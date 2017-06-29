#include "types.hh"


void fd_empty(double* aRes, double* aArg);
void fd_move (double* aRes, double* aArg);
void fd_sqrt (double* aRes, double* aArg);
void fd_log  (double* aRes, double* aArg);
void fd_exp  (double* aRes, double* aArg);
void fd_sin  (double* aRes, double* aArg);
void fd_cos  (double* aRes, double* aArg);
void fd_gamma(double* aRes, double* aArg);

void fd_empty(double* aRes, double* aArg1, double* aArg2);
void fd_add(double* aRes, double* aArg1, double* aArg2);
void fd_mul(double* aRes, double* aArg1, double* aArg2);
void fd_div(double* aRes, double* aArg1, double* aArg2);
void fd_pow(double* aRes, double* aArg1, double* aArg2);

void fi_empty(int* aRes, int* aArg1, int* aArg2);
void fi_add(int* aRes, int* aArg1, int* aArg2);
void fi_mul(int* aRes, int* aArg1, int* aArg2);
void fi_div(int* aRes, int* aArg1, int* aArg2);
void fi_mod(int* aRes, int* aArg1, int* aArg2);

