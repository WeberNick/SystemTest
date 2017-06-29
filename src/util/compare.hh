#ifndef COMPARE_HH
#define COMPARE_HH

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#include "format.hh"

void fPrintMessage(const std::string message);
void fPrintHeader(std::ostream& os, const std::string message);
bool fHasSuffix(const std::string str, const std::string suffix);

string_vt fTxtFilesInDirectory(std::string dir);

int fGetNumber(const int maxFileNumber);

string_vt fGetFiles(const string_vt files);

string_vvt fGetComparisonData(const string_vt filesToCompare, const std::string directory);

void fPrint(const std::string directory, const string_vt filesToCompare, const string_vvt comparisonData);

void fCompare(const std::string name);

#endif