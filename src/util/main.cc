#include <stdlib.h>
#include <sched.h>        // sched_setaffinity
#include <unistd.h>       // getpid, sysconf

#include "infra/system.hh"
#include "infra/argbase.hh"

#include "arg.hh"
#include "cb.hh"
#include "format.hh"
#include "compare.hh"
#include "memory_access.hh"
#include "xor_test.hh"
#include "switchvsfptr_test.hh"
#include "jump_test.hh"
#include "functions.hh"

using namespace GM;

void fCompareResults(const std::string name)
{
  fCompare(name);
}

std::string fSetting()
{
  System lSystem;
  return lSystem.hostname() + "_" + lSystem.machine();
}

void fSystem(std::ostream& output, std::ostream& output_compare, const int aHwThreadNo)
{
	print_test_header(output, "System");
	System lSystem(aHwThreadNo);
  lSystem.print(output);
  lSystem.printCompare(output_compare);
}

void fMeasureMemoryAccess(std::ostream& output, const uint vector_length, std::ostream& output_compare)
{ 
  print_test_header(output, "RANDOM vs. SEQUENTIAL MEMORY ACCESS");
  MemoryAccess memoryAccess(vector_length);
  memoryAccess.fRunTest(output, output_compare);
}

void fMeasureXOR(std::ostream& output, const uint loop, const uint repeat, const uint vector_length, std::ostream& output_compare)
{
	print_test_header(output, "TEST xor");
  XorTest xorTest(loop, repeat, vector_length);
  xorTest.fRunTest(output, output_compare);
}

void fMeasureSwitchVsFPtr(std::ostream& output, const uint loop, const uint vector_length, std::ostream& output_compare) 
{
  print_test_header(output, "TEST switch vs. function pointer");
  SwitchFPtr switchFPtr(loop, vector_length);
  switchFPtr.fRunTest(output, output_compare);
}

void fMeasureJump(std::ostream& output, const uint vector_length, const std::string setting, std::ostream& output_compare) 
{
  print_test_header(output, "TEST BRANCH TIME: IF VS. PREDICATED CODE");
  JumpTest jumpTest(vector_length);
  jumpTest.fRunTest(output, setting);
}

void fMeasureFunctionCall(std::ostream& output, std::ostream& output_compare) 
{
  print_test_header(output, "Function Calls (simple/member/virtual)");
}

void fMeasureMathFunctions(std::ostream& output, std::ostream& output_compare)
{
    print_test_header(output, "Math Functions");

  double a = 0.0, b = 0.7, c = 7.0;
  double m;
  std::cout.setf(std::ios_base::fixed);
    std::cout.precision(4);
    m = run1(&a, &b, &fd_empty, Nchp);
    output << "double empty: " << std::setw(8) << m << ' ' << uNS << std::endl;
    m = run1(&a, &b, &fd_move, Nchp);
    output << "double move : " << std::setw(8) << m << ' ' << uNS << std::endl;
  m = run1(&a, &b, &fd_sqrt, Nexp);
  output << "double sqrt : " << std::setw(8) << m << ' ' << uNS << std::endl;
  m = run1(&a, &b, &fd_log, Nexp);
  output << "double log  : " << std::setw(8) << m << ' ' << uNS << std::endl;
  m = run1(&a, &b, &fd_exp, Nexp);
  output << "double exp  : " << std::setw(8) << m << ' ' << uNS << std::endl;
    m = run1(&a, &b, &fd_sin, Nexp);
    output << "double sin  : " << std::setw(8) << m << ' ' << uNS << std::endl;
    m = run1(&a, &b, &fd_cos, Nexp);
    output << "double cos  : " << std::setw(8) << m << ' ' << uNS << std::endl;
    b = 77.3;
    m = run1(&a, &b, &fd_gamma, Nexp);
    output << "double gamma: " << std::setw(8) << m << ' ' << uNS << std::endl;

    m = run2(&a, &b, &c, &fd_empty, Nchp);
    output << "double empty: " << std::setw(8) << m << ' ' << uNS << std::endl;
    m = run2(&a, &b, &c, &fd_add, Nchp);
    output << "double add  : " << std::setw(8) << m << ' ' << uNS << std::endl;
   m = run2(&a, &b, &c, &fd_mul, Nchp);
    output << "double mul  : " << std::setw(8) << m << ' ' << uNS << std::endl;
    m = run2(&a, &b, &c, &fd_div, Nchp);
    output << "double div  : " << std::setw(8) << m << ' ' << uNS << std::endl;
    m = run2(&a, &b, &c, &fd_pow, Nexp);
    output << "double pow  : " << std::setw(8) << m << ' ' << uNS << std::endl;

    int i = 0;
    int j = 77372;
    int k = 3994;
    m = run2(&i, &j, &k, &fi_empty, Nchp);
    output << "int    empty: " << std::setw(8) << m << ' ' << uNS << std::endl;
    m = run2(&i, &j, &k, &fi_add, Nchp);
    output << "int    add  : " << std::setw(8) << m << ' ' << uNS << std::endl;
    m = run2(&i, &j, &k, &fi_mul, Nchp);
    output << "int    mul  : " << std::setw(8) << m << ' ' << uNS << std::endl;
    m = run2(&i, &j, &k, &fi_div, Nchp);
    output << "int    div  : " << std::setw(8) << m << ' ' << uNS << std::endl;
    m = run2(&i, &j, &k, &fi_mod, Nchp);
    output << "int    mod  : " << std::setw(8) << m << ' ' << uNS << std::endl;
}

void fileError()
{
  std::cerr << "Error: Can not write to file (file not open)!" << std::endl;
}

int main(const int argc, const char* argv[])
{
  Cb lCb;
  argdesc_vt lArgDesc;
  construct_arg_desc(lArgDesc);

  if(!parse_args<Cb>(1, argc, argv, lArgDesc, lCb)) {
    std::cerr << "error while parsing arguments." << std::endl;
    return -1;
  }
  if(lCb.help()) {
    print_usage(std::cout, argv[0], lArgDesc);
    return 0;
  }

  if(lCb.compare())
  {
    fCompareResults(lCb.name());
    return 0;
  }

  const std::string setting = fSetting();
  const std::string fileNameResult = "/home/nickwebe/Results/" + setting + lCb.name();
  const std::string fileNameCompare = "/home/nickwebe/test/src/util/SystemTest/Compare/" + setting + lCb.name() + ".txt";
  const std::ios::openmode out = std::ofstream::out;
  
  std::ofstream output_result(fileNameResult.c_str(), out);
  std::ofstream output_compare(fileNameCompare.c_str(), out);

  uint lHwThreadNo = lCb.core();
  cpu_set_t lMask;
  CPU_ZERO(&lMask);
  CPU_SET(lHwThreadNo, &lMask);
  int lRc = sched_setaffinity(0, sizeof(cpu_set_t), &lMask);
  if(0 != lRc) 
  {
    std::cerr << "binding thread to " << lHwThreadNo << " failed: return code: " << lRc << std::endl;
  } 
  else 
  {
    std::cerr << "binding thread to " << lHwThreadNo << " succeeded." << std::endl;
  }

  fSystem(output_result, output_compare, lHwThreadNo);

  const uint loop = lCb.loop();
  const uint repeat = lCb.repeat();
  const uint vector_length = lCb.vec();

  if(lCb.all())
  {
    if(output_result.is_open() && output_compare.is_open())
    {
      fMeasureMemoryAccess(output_result, vector_length, output_compare);
      fMeasureXOR(output_result, loop, repeat, vector_length, output_compare);
      fMeasureSwitchVsFPtr(output_result, loop, vector_length, output_compare);
      fMeasureJump(output_result, vector_length, setting, output_compare);
      fMeasureFunctionCall(output_result, output_compare);
      fMeasureMathFunctions(output_result, output_compare);
      output_result.close();
      output_compare.close();
    }
    else fileError();
    return 0;
  }

  if(lCb.memory())
  {
    if(output_result.is_open() && output_compare.is_open())
    {
      fMeasureMemoryAccess(output_result, vector_length, output_compare);
    }
    else fileError();
  }

  if(lCb.fxor())
  {
    if(output_result.is_open() && output_compare.is_open())
    {
      fMeasureXOR(output_result, loop, repeat, vector_length, output_compare);
    }
    else fileError(); 
  }

  if(lCb.switchFPtr())
  {
    if(output_result.is_open() && output_compare.is_open())
    {
      fMeasureSwitchVsFPtr(output_result, loop, vector_length, output_compare);
    }
    else fileError();
  }

  if(lCb.jump())
  {
    if(output_result.is_open() && output_compare.is_open())
    {
      fMeasureJump(output_result, vector_length, setting, output_compare);
    }
    else fileError();
  }

  if(lCb.function())
  {
    if(output_result.is_open() && output_compare.is_open())
    {
      fMeasureFunctionCall(output_result, output_compare);
    }
    else fileError();
  }

  if(lCb.math())
  {
    if(output_result.is_open() && output_compare.is_open())
    {
      fMeasureMathFunctions(output_result, output_compare);
    }
    else fileError();
  }
  output_result.close();
  output_compare.close();
	return 0;
}