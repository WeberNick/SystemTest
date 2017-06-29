#include "functions.hh"

void
fd_empty(double* aRes, double* aArg) {
}

void
fd_move(double* aRes, double* aArg) {
  *aRes = *aArg;
}

void
fd_sqrt(double* aRes, double* aArg) {
  *aRes = std::sqrt(*aArg);
}

void
fd_log(double* aRes, double* aArg) {
  *aRes = std::log(*aArg);
}

void
fd_exp(double* aRes, double* aArg) {
  *aRes = std::exp(*aArg);
}

void
fd_sin(double* a, double* b) {
  *a = std::sin(*b);
}

void
fd_cos(double* a, double* b) {
  *a = std::cos(*b);
}

void
fd_gamma(double* a, double* b) {
  *a = gamma(*b);
}

void
fd_empty(double* a, double* b, double* c) {
}

void
fd_add(double* a, double* b, double* c) {
 *a = *b + *c;
}

void
fd_mul(double* a, double* b, double* c) {
 *a = *b * *c;
}

void
fd_div(double* a, double* b, double* c) {
 *a = *b / *c;
}

void
fd_pow(double* a, double* b, double* c) {
  *a = std::pow(*b, *c);
}

void
fi_empty(int* a, int* b, int* c) {
}

void
fi_add(int* a, int* b, int* c) {
 *a = *b + *c;
}

void
fi_mul(int* a, int* b, int* c) {
 *a = *b * *c;
}

void
fi_div(int* a, int* b, int* c) {
 *a = *b / *c;
}

void
fi_mod(int* a, int* b, int* c) {
 *a = *b % *c;
}

