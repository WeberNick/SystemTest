#ifndef FORMAT_HH
#define FORMAT_HH

#include <string>
#include <vector>

#include "infra/measure.hh"

typedef unsigned int uint;
typedef std::vector<Measure> measure_vt;
typedef std::vector<measure_vt> measure_vvt;
typedef std::vector<uint> uint_vt;
typedef std::vector<double> double_vt;
typedef std::vector<double_vt> double_vvt;
typedef std::vector<std::string> string_vt;
typedef std::vector<string_vt> string_vvt;

const double NS = (1000.0L * 1000.0L * 1000.0L);


std::string fFormatNumber(int number);

#endif