#include "print_test_header.hh"


void print_test_header(std::ostream& os, const std::string aTestName, int aTot) 
{
  const int lLen = aTestName.size() + 4; // 2 blanks links/rechts
  const int lTot = aTot;
  const int lLeft = ((lTot - lLen) / 2);
  const int lRight = lTot - lLeft - lLen;

  os << std::string(lTot, '=') << std::endl
            << std::string(lLeft, '=') << "  " << aTestName << "  " << std::string(lRight, '=') << std::endl
            << std::string(lTot, '=') << std::endl
            << std::endl;
}

