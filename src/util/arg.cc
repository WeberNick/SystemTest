#include "arg.hh"

void
construct_arg_desc(argdesc_vt& x) {
  // typedef argdesc_t<Cb, int>         iarg_t;
  typedef argdesc_t<Cb, uint>        uarg_t;
  // typedef argdesc_t<Cb, float>       farg_t;
  // typedef argdesc_t<Cb, double>      darg_t;
  typedef argdesc_t<Cb, bool>        barg_t;
  typedef argdesc_t<Cb, std::string> sarg_t;

  x.push_back( new barg_t("--help", false, &Cb::help, "print this message" ));
  x.push_back( new barg_t("--all", false, &Cb::all, "test all"));
  x.push_back( new barg_t("--memory", false, &Cb::memory, "memory test"));
  x.push_back( new barg_t("--xor", false, &Cb::fxor, "xor test"));
  x.push_back( new barg_t("--switchfptr", false, &Cb::switchFPtr, "switch vs function pointer test"));
  x.push_back( new barg_t("--jump", false, &Cb::jump, "if vs. predicated code (branch time) test"));
  x.push_back( new barg_t("--function", false, &Cb::function, "function call test"));
  x.push_back( new barg_t("--math", false, &Cb::math, "math functions test"));
  x.push_back( new barg_t("--compare", false, &Cb::compare, "compare 2 or more test results"));

  x.push_back( new uarg_t("--loop", 100, &Cb::loop, "number of loop iterations in millions"));
  x.push_back( new uarg_t("--repeat", 1, &Cb::repeat, "number of repeats"));
  x.push_back( new uarg_t("--vector", 10, &Cb::vec, "vector size in millions"));
  x.push_back( new uarg_t("--core", 0, &Cb::core, "core number to run the test on"));


  x.push_back( new sarg_t("--name", "hostname_machine", &Cb::name, "assign a name for this test" ));
}