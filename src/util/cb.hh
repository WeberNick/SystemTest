#ifndef HIST_K_DIM_CB_HH
#define HIST_K_DIM_CB_HH

#include <string>


class Cb {
	public:
		typedef unsigned int uint;
	public:
    	Cb();
  
	private:
    	bool _help;
    	bool _all;
    	bool _xor;
    	bool _memory;
      bool _switchfptr;
      bool _jump;
      bool _function;
    	bool _math;
      bool _compare;

    	uint _loop;
    	uint _repeat;
    	uint _vec;
      uint _core;

      std::string _name;

	public:
    inline const bool help(){ return _help; }
		inline void help(const bool& x) { _help = x; }

		inline const bool all(){ return _all; }
		inline void all(const bool& x) { _all = x; }

		inline const bool fxor(){ return _xor;}
		inline void fxor(const bool& x){ _xor = x;}

		inline const bool memory(){ return _memory;}
    inline void memory(const bool& x){ _memory = x;}

    inline const bool switchFPtr(){ return _switchfptr;}
    inline void switchFPtr(const bool& x){ _switchfptr = x;}

    inline const bool jump(){ return _jump;}
    inline void jump(const bool& x){ _jump = x;}

    inline const bool function(){ return _function;}
    inline void function(const bool& x){ _function = x;}

		inline const bool math(){ return _math;}
		inline void math(const bool& x){ _math = x;}

    inline const bool compare(){ return _compare;}
    inline void compare(const bool& x){ _compare = x;}

		inline const uint loop(){ return _loop;}
		inline void loop(const uint& x){ _loop = x * 1000 * 1000;}

		inline const uint repeat(){ return _repeat;}
		inline void repeat(const uint& x){ _repeat = x;}

		inline const uint vec(){ return _vec;}
		inline void vec(const uint& x){ _vec = x * 1000 * 1000;}

    inline const uint core(){ return _core;}
    inline void core(const uint& x){ _core = x;}

    inline const std::string name(){ return _name;}
    inline void name(const std::string& x){ _name = x;}

};
#endif