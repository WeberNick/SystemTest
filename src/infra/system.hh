#ifndef INFRA_SYSTEM_HH
#define INFRA_SYSTEM_HH

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <stdlib.h>


#ifdef __x86_64
#include <cpuid.h>
#endif

// #include <libcpuid.h>


namespace GM {

class System {
  public:
    enum Vendor {
       kIntel = 0,
       kAmd   = 1,
       kArm   = 2,
       kNoVendor = 3
    };

    enum CacheType {
      kInstruction = 0,
      kData = 1,
      kUnified = 2,
      kNoCacheType = 3
    };

    struct cache_t {
      unsigned int _id;
      unsigned int _level;
      size_t       _size; // in kA
      CacheType    _type;

      cache_t() : _id(0), _level(0), _size(0), _type(kNoCacheType) {}
      cache_t(const unsigned int aId, const unsigned int aLevel, const size_t aSize, const CacheType aType)
             : _id(aId), _level(aLevel), _size(aSize), _type(aType) {}

      inline unsigned int id() const { return _id; }
      inline unsigned int level() const { return _level; }
      inline unsigned int size() const { return _size; }
      inline CacheType    type() const { return _type; }

      std::ostream& print(std::ostream& os) const;
    };
    typedef std::vector<cache_t> cache_vt;

    typedef std::vector<unsigned int> thread_vt;
    struct core_t {
      unsigned int _coreid;
      thread_vt    _threads;
      core_t() : _coreid(0), _threads() {}
      core_t(unsigned int aCoreId) : _coreid(aCoreId), _threads() {}

      inline unsigned int coreid() const { return _coreid; }
      inline const thread_vt& threads() const { return _threads; }
      inline       thread_vt& threads() { return _threads; }

      std::ostream& print(std::ostream&);
    };
    typedef std::vector<core_t> core_vt;

    struct cpu_t {
      unsigned int _cpuid; // physical cpu
      double       _taktrate;
      std::string  _name;
      core_vt      _cores;
      cache_vt     _caches;

      cpu_t() : _cpuid(0), _taktrate(0), _name(), _cores(), _caches() {}
      cpu_t(unsigned int aCpuid) : _cpuid(aCpuid), _taktrate(0), _name(), _cores(), _caches() {}

      inline unsigned int cpuid() const { return _cpuid; }
      inline double       taktrate() const { return _taktrate; }
      inline const std::string& name() const { return _name; }
      inline const core_vt&  cores() const { return _cores; }
      inline       core_vt&  cores()       { return _cores; }
      inline const cache_vt& caches() const { return _caches; }
      inline       cache_vt& caches()       { return _caches; }

      inline const cache_t& cache(const size_t i) const { return _caches[i]; }
      inline const core_t&  core(const size_t i) const { return _cores[i]; }
    };

    typedef std::vector<cpu_t> cpu_vt;

  public:
    System();
    System(const int aHwThreadNo);
  public:
    inline int   hwthreadno() const { return _hwthreadno; }
    inline bool  ok() const { return _ok; }
    inline const std::string& hostname() const { return _hostname; }
    inline const std::string& machine() const { return _machine; }
    inline const std::string& osname() const { return _osname; }
    inline const std::string& osrelease() const { return _osrelease; }
    inline const std::string& osversion() const { return _osversion; }
    inline const std::string& domainname() const { return _domainname; }

    inline Vendor vendor() const { return _vendor; }
    inline size_t no_cpus() const { return _cpus.size(); }
           size_t no_cores() const;
           size_t no_threads() const;
    inline const cpu_vt& cpus() const { return _cpus; }
    inline size_t clockticks() const { return _clockticks; }
    inline double cycleNS() const { return (((double) 1000L*1000L*1000L) / ((double) clockticks())); }
    inline size_t totalram() const { return _totalram; }
    inline size_t pagesize() const { return _pagesize; }

    inline size_t cachelinesize() const { return _cachelinesize; }
    inline size_t cachesize(const unsigned int aLevel) const { return _cachesize[aLevel]; }

    inline const cpu_t& cpu(const size_t i) const { return _cpus[i]; }
  public:
    void get_clockticks(const uint aHwThreadNo); // get/aktualisiere read form cpufreq/scaling_cur_freq
  public:
    void print(std::ostream& os) const;
    void printCompare(std::ostream& os) const;
    void print_sysinfo(std::ostream& os) const;
    void print_cpuid(std::ostream& os) const; // only for intel
  private:
    void get_sysconf();
    void get_cpuid_info(); // only for intel
    void get_sys_devices_info();
    void get_sysinfo();    // read RAM
  private:
    int         _hwthreadno;
    bool        _ok;
    std::string _hostname;
    std::string _osname;
    std::string _osversion;
    std::string _osrelease;
    std::string _machine;
    std::string _domainname;
    cpu_vt      _cpus;
    Vendor      _vendor;
    size_t      _clockticks; // as current
    size_t      _totalram;
    size_t      _pagesize;
    size_t      _cachelinesize;
    size_t      _cachesize[4];
};


std::ostream&  operator<<(std::ostream&, const System::Vendor);
std::ostream&  operator<<(std::ostream&, const System::CacheType);

inline std::ostream& operator<<(std::ostream& os, const System::cache_t& x) { return x.print(os); }

} // end namespace


#endif
