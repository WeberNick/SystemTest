#include <limits>
#include "system.hh"

namespace GM {

typedef unsigned int uint;

System::System() : _hwthreadno(0), _ok(true), _hostname(), _osname(), _osversion(), _osrelease(), _machine(), _domainname(),
                   _cpus(), _vendor(kNoVendor), _clockticks(0),
                   _totalram(0), _pagesize(0), _cachelinesize(0), _cachesize() {
  _cachesize[0] = 0;
  _cachesize[1] = 0;
  _cachesize[2] = 0;
  _cachesize[3] = 0;
  utsname x;
  const int lRetCode = uname(&x);
  if(0 == lRetCode) {
    _osname = std::string(x.sysname);
    _osversion = std::string(x.version);
    _osrelease = std::string(x.release);
    _machine = std::string(x.machine);
    _hostname = std::string(x.nodename);
    #ifdef _GNU_SOURCE
    _domainname = std::string(x.domainname);
    #endif
  } else {
    _ok = false;
  }

  get_sysinfo();
  get_sysconf();
  get_sys_devices_info();
  #ifdef __x86
  get_cpuid_info();
  #elif __x86_64
  get_cpuid_info();
  #elif __ARM_ARCH
  _vendor = kArm;
  #elif __ARM_ARCH_6
  _vendor = kArm;
  #endif

  get_clockticks(0);
}

System::System(const int aHwThreadNo)
       : _hwthreadno(aHwThreadNo), _ok(true), _hostname(),
         _osname(), _osversion(), _osrelease(), _machine(), _domainname(),
         _cpus(), _vendor(kNoVendor), _clockticks(0),
         _totalram(0), _pagesize(0), _cachelinesize(0), _cachesize() {
  _cachesize[0] = 0;
  _cachesize[1] = 0;
  _cachesize[2] = 0;
  _cachesize[3] = 0;
  utsname x;
  const int lRetCode = uname(&x);
  if(0 == lRetCode) {
    _osname = std::string(x.sysname);
    _osversion = std::string(x.version);
    _osrelease = std::string(x.release);
    _machine = std::string(x.machine);
    _hostname = std::string(x.nodename);
    #ifdef _GNU_SOURCE
    _domainname = std::string(x.domainname);
    #endif
  } else {
    _ok = false;
  }

  get_sysinfo();
  get_sysconf();
  get_sys_devices_info();
  #ifdef __x86
  get_cpuid_info();
  #elif __x86_64
  get_cpuid_info();
  #elif __ARM_ARCH
  _vendor = kArm;
  #elif __ARM_ARCH_6
  _vendor = kArm;
  #endif

  get_clockticks(hwthreadno());
}


void
System::get_sysinfo() {
  struct sysinfo lSysinfo;
  sysinfo(&lSysinfo);
  _totalram = lSysinfo.totalram;
}

void
System::get_sysconf() {
  // _no_cpus    = sysconf( _SC_NPROCESSORS_ONLN );
  _pagesize   = sysconf(_SC_PAGESIZE);
}


void
System::get_clockticks(uint aHwThreadNo) {
  char lBuffer[128];
  snprintf(lBuffer, 127, "/sys/devices/system/cpu/cpu%d/cpufreq/scaling_cur_freq", aHwThreadNo);
  std::ifstream lIs(lBuffer);
  // std::ifstream lIs("/sys/devices/system/cpu/cpu%d/cpufreq/scaling_cur_freq");
  size_t lClockTicks = 0;
  if(lIs) {
    lIs >> lClockTicks;
  }
  _clockticks = 1000 * lClockTicks;
}

void
System::get_sys_devices_info() {
  // std::cout << "get_sys_devices_info:" << std::endl;

  {
    std::ifstream lIs("/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size");
    if(lIs) {
      lIs >> _cachelinesize;
    }
  }

/*
  bool lIsOk = true;
  for(uint i = 0; lIsOk; ++i) {
    unsigned int lLevel = 0;
    unsigned int lSize  = 0;
    std::string  lType;
    char lSizeChar;
    char lNameLevel[100];
    char lNameSize[100];
    char lNameType[100];
    unsigned int lThreadNo = 0;
    snprintf(lNameLevel, 99, "/sys/devices/system/cpu/cpu%d/cache/index%d/level", lThreadNo, i);
    snprintf(lNameSize,  99, "/sys/devices/system/cpu/cpu%d/cache/index%d/size", lThreadNo, i);
    snprintf(lNameType,  99, "/sys/devices/system/cpu/cpu%d/cache/index%d/type", lThreadNo, i);
    std::ifstream lIsLevel(lNameLevel);
    std::ifstream lIsSize(lNameSize);
    std::ifstream lIsType(lNameType);
    if(lIsLevel && lIsSize && lIsType) {
      lIsLevel >> lLevel;
      lIsSize  >> lSize >> lSizeChar;
      lIsType  >> lType;
      std::cout << "cache " << i << ": " << 'L' << lLevel  << " of size " << lSize 
                << " with size char " << lSizeChar << " of type " << lType << std::endl;
      if('K' == lSizeChar || 'k' == lSizeChar) {
        lSize *= 1024;
      }
    } else {
      lIsOk = false;
      // if(!lIsLevel) { std::cout << "cache: level unreadable." << std::endl; }
      // if(!lIsSize) { std::cout << "cache: size unreadable." << std::endl; }
      // if(!lIsType) { std::cout << "cache: type unreadable." << std::endl; }
    }
  }
*/


  // determine number of CPU's = number of physical packages

  bool lIsOk = true;
  char lNameCpuNo[200];
  char lNameCoreNo[200];

/*
  uint lMaxCpuNo = 0;
  for(lThreadNo = 0; lIsOk; ++lThreadNo) {
    unsigned int lCpuNo    = 0;
    snprintf(lNameCpuNo, 199,    "/sys/devices/system/cpu/cpu%d/topology/physical_package_id", i);
    std::ifstream lIsCpuNo(lNameCpuNo);
    if(!lIsCpuNo) {
      break;
    }
  }
*/    
    

  for(uint i = 0; lIsOk; ++i) {
             int lCpuNo    = 0;
             int lCoreNo   = 0;
             int lThreadNo = i;
    snprintf(lNameCpuNo, 199,    "/sys/devices/system/cpu/cpu%d/topology/physical_package_id", i);
    snprintf(lNameCoreNo, 199,   "/sys/devices/system/cpu/cpu%d/topology/core_id"            , i);
    std::ifstream lIsCpuNo(lNameCpuNo);
    std::ifstream lIsCoreNo(lNameCoreNo);
    if(lIsCpuNo && lIsCoreNo) {
      lIsCpuNo  >> lCpuNo;
      lIsCoreNo >> lCoreNo;
      // fuer raspi:
      if(0 > lCpuNo) {
        lCpuNo = 0;
      }
      // std::cout << "read: " << i << ' ' << lCpuNo << ' ' << lCoreNo << std::endl;
      if((int) _cpus.size() <= lCpuNo) {
         // std::cout << "push: " << lCpuNo << std::endl;
         // _cpus.push_back(cpu_t(lCpuNo)); // must be sorted, idx=lCpuNo
         _cpus.resize(lCpuNo + 1);
         _cpus[lCpuNo]._cpuid = lCpuNo;
         // read cache info

         bool lIsOk2 = true;
         for(unsigned int lCacheNo = 0; lIsOk2; ++lCacheNo) {
           char lNameLevel[200];
           char lNameSize[200];
           char lNameType[200];
           snprintf(lNameLevel, 199, "/sys/devices/system/cpu/cpu%d/cache/index%d/level", lThreadNo, lCacheNo);
           snprintf(lNameSize,  199, "/sys/devices/system/cpu/cpu%d/cache/index%d/size", lThreadNo, lCacheNo);
           snprintf(lNameType,  199, "/sys/devices/system/cpu/cpu%d/cache/index%d/type", lThreadNo, lCacheNo);
           unsigned int lLevel = 0;
           unsigned int lSize  = 0;
           char         lSizeChar = 'K';
           std::string  lTypeName;
           std::ifstream lIsLevel(lNameLevel);
           std::ifstream lIsSize(lNameSize);
           std::ifstream lIsType(lNameType);
           if(lIsLevel && lIsSize && lIsType) {
             lIsLevel >> lLevel;
             lIsSize  >> lSize >> lSizeChar;
             lIsType  >> lTypeName;
             // std::cout << "cache " << lCpuNo << ' ' << lCoreNo << ' ' << lThreadNo << " : " << lCacheNo
             //           << ": " << 'L' << lLevel  << " of size " << lSize << lSizeChar << " of type " << lTypeName << std::endl;
             if('K' != lSizeChar && 'k' != lSizeChar) {
               std::cerr << "BAD size char: " << lSizeChar << std::endl;
             }
             CacheType lType = kNoCacheType;
             if("Data" == lTypeName) {
               lType = kData;
             } else
             if("Instruction" == lTypeName) {
               lType = kInstruction;
             } else
             if("Unified" == lTypeName) {
               lType = kUnified;
             }
             if((int) _cpus.size() <= lCpuNo) {
               _cpus.resize(lCpuNo + 1);
             }
             if(_cpus[lCpuNo]._caches.size() <= lCacheNo) {
                _cpus[lCpuNo]._caches.resize(lCacheNo + 1);
             }
             if(0 != cpu(lCpuNo).cache(lCacheNo).size()) {
               std::cout << "WARNING:  cache duplicate?" << std::endl;
               if((cpu(lCpuNo).cache(lCacheNo).id()    != lCacheNo) ||
                  (cpu(lCpuNo).cache(lCacheNo).level() != lLevel) ||
                  (cpu(lCpuNo).cache(lCacheNo).size()  != lSize) ||
                  (cpu(lCpuNo).cache(lCacheNo).type()  != lType)) {
                 std::cout << "WARNING: cache duplicate: something differs." << std::endl;
                 std:: cout << "   id: " << std::setw(10) << cpu(lCpuNo).cache(lCacheNo).id()    << ' ' <<  lCacheNo << std::endl
                            << "level: " << std::setw(10) << cpu(lCpuNo).cache(lCacheNo).level() << ' ' <<  lLevel   << std::endl
                            << " size: " << std::setw(10) << cpu(lCpuNo).cache(lCacheNo).size()  << ' ' <<  lSize    << std::endl
                            << " type: " << std::setw(10) << cpu(lCpuNo).cache(lCacheNo).type()  << ' ' <<  lType    << std::endl
                            ;
               }
             }
             _cpus[lCpuNo]._caches[lCacheNo] = cache_t(lCacheNo, lLevel, lSize, lType);
           } else {
             lIsOk2 = false;
           }
        }
      }
      if((int) _cpus[lCpuNo].cores().size() <= lCoreNo) {
         _cpus[lCpuNo]._cores.resize(lCoreNo + 1);
      }
      _cpus[lCpuNo]._cores[lCoreNo]._coreid = lCoreNo;
      _cpus[lCpuNo]._cores[lCoreNo].threads().push_back(lThreadNo);
      // std::cout << lCpuNo << ' ' << lCoreNo << ' ' << lThreadNo << std::endl;
    } else {
      lIsOk = false;
    }
  }

  { 
    std::ifstream lIs("/proc/cpuinfo");
    std::string   lLine;
    unsigned int  lCpuNo = 0;
    std::string   lCpuName;
    char*         lCharPtr = 0;
    double        lTaktrate = 0;
    while(lIs && !lIs.eof()) {
      getline(lIs, lLine);
      // std::cout << lLine << std::endl;
      if(0 == lLine.compare(0, 10, "model name")) {
        for(size_t i = 0; i < lLine.size(); ++i) {
          if(':' == lLine[i]) {
            ++i;
            while(' ' == lLine[i]) { ++i; }
            lCpuName = lLine.substr(i);
            for(int j = lLine.size() - 5; 0 < j; --j) {
              if(' ' == lLine[j]) {
                 // std::cout << "yak = " << (lLine.c_str() + j) << "  " << j << ' ' << lLine.size() << std::endl;
                 lTaktrate = strtod(lLine.c_str() + j, &lCharPtr);
                 break;
              }
            }
            // std::cout << "cpu name = " << lCpuName << std::endl;
            break;
          }
        }
      } else
      if(0 == lLine.compare(0, 11, "physical id")) {
        for(size_t i = 0; i < lLine.size(); ++i) {
          if(':' == lLine[i]) {
            ++i;
            while(' ' == lLine[i]) { ++i; }
            unsigned int lNum = strtol(lLine.c_str() + i, &lCharPtr, 10);
            // std::cout << "cpu id " << lNum << " :" << lLine[i-1] << lLine[i] << ':' 
            //           << *(lLine.c_str() + i) << ':'
            //           << std::endl;
            if(lCpuNo == lNum) {
              // std::cout << "CPU " << lCpuNo << ' ' << lCpuName << ' ' << lTaktrate << std::endl;
              _cpus[lCpuNo]._taktrate = lTaktrate;
              _cpus[lCpuNo]._name = lCpuName;
              ++lCpuNo;
            }
          }
        }
      }
    }
  }
}


void
System::get_cpuid_info() {
  #ifdef __x86_64
  // std::cout << "cpuid: " << std::endl;
  const unsigned int SIG_INTEL =  0x756E6547; // EBX, ECX, EDS: vendor name: "GenuineIntel"
  const unsigned int SIG_AMD   =  0x68747541; // EBX, ECX, EDX: vendor name: "AuthenticAMD"

  // unsigned int lSig[4];
  // unsigned int lMaxInstrLevel    = __get_cpuid_max(0x0, lSig);       // basic    cpuid information
  // unsigned int lMaxExtInstrLevel = __get_cpuid_max(0x8000000, lSig); // extended cpuid information


  // os << "cpuid     max: " << lMaxInstrLevel << std::endl;
  // os << "cpuid ext max: " << lMaxExtInstrLevel << std::endl;
  // os << "      sig: " << lSig[0] << '.' << lSig[1] << '.' << lSig[2] << '.' << lSig[3] << std::endl;

  unsigned int a = 0, b = 0, c = 0, d = 0;
  Vendor lVendor = kNoVendor;
  // unsigned int lNoCores   = 1;
  // unsigned int lNoThreads = 1;

  a = 0x80000000;
  b = c = d = 0;
  __cpuid(0, a, b, c, d);
  if(SIG_INTEL == b) {
    lVendor = kIntel;
  } else
  if(SIG_AMD == b) {
    lVendor = kAmd;
  } else {
    lVendor = kNoVendor;
  }
  _vendor = lVendor;
  // std::cout << " vendor: " << vendor() << std::endl;
  #endif
}

size_t
System::no_cores() const {
  size_t lRes = 0;
  for(size_t i = 0; i < cpus().size(); ++i) {
    for(size_t j = 0; j < cpu(i).cores().size(); ++j) {
      if(0 < cpu(i).core(j).threads().size()) {
        ++lRes;
      }
    }
  }
  return lRes;
}

size_t
System::no_threads() const {
  size_t lRes = 0;
  for(size_t i = 0; i < cpus().size(); ++i) {
    const core_vt& lCores = cpus()[i].cores();
    for(size_t j = 0; j < lCores.size(); ++j) {
      lRes += lCores[j].threads().size();
    }
  }
  return lRes;
}

void
System::print(std::ostream& os) const {
  os << std::setw(15) <<   "hostname: " << hostname()   << std::endl
     << std::setw(15) <<    "machine: " << machine()    << std::endl
     << std::setw(15) <<     "osname: " << osname()     << std::endl
     << std::setw(15) <<  "osrelease: " << osrelease()  << std::endl
     << std::setw(15) <<  "osversion: " << osversion()  << std::endl
     << std::setw(15) << "domainname: " << domainname() << std::endl
     << std::setw(15) <<     "no cpu: " << no_cpus()    << std::endl
     << std::setw(15) <<   "no cores: " << no_cores()   << std::endl
     << std::setw(15) << "no threads: " << no_threads() << std::endl
     << std::setw(15) <<     "vendor: " << vendor()     << std::endl
     << std::setw(15) << "clockticks: " << clockticks() << std::endl
     << std::setw(15) << " cycle[ns]: " << cycleNS()    << std::endl
     << std::setw(15) <<  "total ram: " << totalram()   << std::endl
     << std::setw(15) <<   "pagesize: " << pagesize()   << std::endl
     ;

  os << "cpu info:" << std::endl;
  for(size_t lCpuNo = 0; lCpuNo < cpus().size(); ++lCpuNo) {
    os << "   " << lCpuNo << "  "
       << _cpus[lCpuNo].name() << "   "
       << _cpus[lCpuNo].taktrate()
       << std::endl;
  }

  os << "cpu/core/thread topology:" << std::endl;
  for(size_t lCpuNo = 0; lCpuNo < cpus().size(); ++lCpuNo) {
    os << "   " << _cpus[lCpuNo].cpuid() << ' ';
    const core_vt& lCores = _cpus[lCpuNo].cores();
    for(size_t lCoreNo = 0; lCoreNo < lCores.size(); ++lCoreNo) {
      os << '[' << lCores[lCoreNo].coreid() << " [ ";
      const thread_vt& lThreads = lCores[lCoreNo].threads();
      for(size_t lThreadNo = 0; lThreadNo < lThreads.size(); ++lThreadNo) {
        os << lThreads[lThreadNo] << ' ';
      }
      os << "]] ";
    }
    os << std::endl;
  }

  os << "cache info: " << std::endl;
  for(size_t i = 0; i < cpus().size(); ++i) {
    os << "   " << i << " : ";
    const cache_vt& lCaches = cpus()[i].caches();
    for(size_t j = 0; j < lCaches.size(); ++j) {
      os << lCaches[j] << "  ";
    }
    os << std::endl;
  }

  os << std::endl;
}

void
System::printCompare(std::ostream& os) const {
  os << "no cpu/" << no_cpus() << std::endl
     << "no cores/" << no_cores() << std::endl
     << "no threads/" << no_threads() << std::endl
     << "vendor/" << vendor()     << std::endl
     << "clockticks/" << clockticks() << std::endl
     << "cycle [ns]/" << cycleNS() << std::endl
     << "total ram/" << totalram() << std::endl
     << "pagesize/" << pagesize() << std::endl;
}

// in der shell sind die dinge einfach: use: lscpu

void
System::print_sysinfo(std::ostream& os) const {
  std::cout << "sysinfo: " << std::endl;
  struct sysinfo lSysinfo;
  sysinfo(&lSysinfo);
  os << "total  ram: " << lSysinfo.totalram << std::endl
     << "free   ram: " << lSysinfo.freeram  << std::endl
     // << "#processes: " << lSysinfo.procs    << std::endl
     ;
}

void
System::print_cpuid(std::ostream& os) const {
  #ifdef __x86_64
  std::cout << "cpuid: " << std::endl;
  const unsigned int SIG_INTEL = 0x756E6547; // EBX, ECX, EDS: vendor name: "GenuineIntel"
  const unsigned int SIG_AMD   = 0x68747541; // EBX, ECX, EDX: vendor name: "AuthenticAMD"

  unsigned int lSig[4];
  unsigned int lMaxInstrLevel    = __get_cpuid_max(0x0, lSig);       // basic    cpuid information
  unsigned int lMaxExtInstrLevel = __get_cpuid_max(0x8000000, lSig); // extended cpuid information
  

  os << "cpuid     max: " << lMaxInstrLevel << std::endl;
  os << "cpuid ext max: " << lMaxExtInstrLevel << std::endl;
  os << "      sig: " << lSig[0] << '.' << lSig[1] << '.' << lSig[2] << '.' << lSig[3] << std::endl;

  unsigned int lInstr = 0;

  unsigned int a = 0, b = 0, c = 0, d = 0;
  Vendor lVendor = kNoVendor;
  // unsigned int lNoCores   = 1;
  // unsigned int lNoThreads = 1;

  a = 0x80000000;
  b = c = d = 0;
  __cpuid(0, a, b, c, d);
  if(SIG_INTEL == b) {
    lVendor = kIntel;
  } else
  if(SIG_AMD == b) {
    lVendor = kAmd;
  } else {
    lVendor = kNoVendor;
  }

  os << " vendor: " << lVendor << std::endl;

/*
  // read number of threads, same for Intel and AMD
  if(1 <= lMaxInstrLevel) {
    b = c = d = 0;
    a = 0x1;
    __cpuid(a, a, b, c, d);
    lNoThreads = (b >> 16) & 0xFF; // read_val(&b, 16, 23);
    std::cout << "no threads: " << lNoThreads << std::endl;
  }

  // read number of cores
  if(kIntel == lVendor) {
    lInstr = 0x4;
    a = b = c = d = 0;
    a = lInstr;
    __cpuid(lInstr, a, b, c, d);
    lNoCores = ((a >> 26) & 0x3F) + 1;
    std::cout << "no cores: " << lNoCores << std::endl;
  } else
  if(kAmd == lVendor) {
  }
*/


/*

    3:0 – Stepping
    7:4 – Model
    11:8 – Family
    13:12 – Processor Type
    19:16 – Extended Model
    27:20 – Extended Family
  */

  if(kIntel == lVendor) {
    lInstr = 0x1;
    a = b = c = d = 0;
    a = lInstr;
    __cpuid(lInstr, a, b, c, d);
    std::cout << "Stepping: " << ((a >>  0) & 0xF)  << std::endl
              << "   Model: " << ((a >>  4) & 0xF)  << std::endl
              << "  Family: " << ((a >>  8) & 0xF)  << std::endl
              << "    Type: " << ((a >> 12) & 0x3)  << std::endl
              << "  XModel: " << ((a >> 16) & 0xF)  << std::endl
              << " XFamily: " << ((a >> 20) & 0xFF) << std::endl
              ;
  }

  // more fun
/*
  for(unsigned int i = 0; i < lMaxInstrLevel; ++i) {
    a = b = c = d = 0;
    __cpuid(i, a, b, c, d);
    os << std::setw(2)  << i << ' '
       << std::setw(12) << a << ' ' 
       << std::setw(12) << b << ' ' 
       << std::setw(12) << c << ' ' 
       << std::setw(12) << d << std::endl;
  }
*/
/*
   from libcpuinfo.h

    if (!cpuid_present()) {
        std::cout << "Sorry, your CPU doesn't support CPUID!" << std::endl;
        return;
    }

    struct cpu_raw_data_t raw; 
    struct cpu_id_t data;     

    if (cpuid_get_raw_data(&raw) < 0) { 
        printf("Sorry, cannot get the CPUID raw data.\n");
        printf("Error: %s\n", cpuid_error());
        return;
    }

    if (cpu_identify(&raw, &data) < 0) {    
        printf("Sorrry, CPU identification failed.\n");
        printf("Error: %s\n", cpuid_error());
        return;
    }

    printf("Processor has %d physical cores\n", data.num_cores);
*/

 #endif
}


std::ostream&
System::cache_t::print(std::ostream& os) const {
  os << 'L' << level() << ' ' << size() << 'K' <<  ' ' << type();
  return os;
}

std::ostream&
operator<<(std::ostream& os, const System::Vendor x) {
  switch(x) {
    case System::kIntel: os << "Intel";  break;
    case System::kAmd:   os << "AMD";  break;
    case System::kArm:   os << "ARM"; break;
    default:
    case System::kNoVendor: os << "<no vendor>"; break;
  }
  return os;
}


std::ostream&
operator<<(std::ostream& os, const System::CacheType x) {
  switch(x) {
    case System::kInstruction: os << "Instruction";  break;
    case System::kData:        os << "Data";  break;
    case System::kUnified:     os << "Unified";  break;
    case System::kNoCacheType:
    default: os << "<no cache type>"; break;
  }
  return os;
}

  

} // end namespace



