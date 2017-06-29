#include "cb.hh"

Cb::Cb() : 	_help(false), _all(false), _xor(false), _memory(false), _switchfptr(false), 
			_jump(false), _function(false), _math(false), _compare(false),
			_loop(100 * 1000 * 1000), _repeat(1), _vec(10 * 1000 * 1000), _core(0),
			_name(""){}


// inline const bool help(){ return _help; }
// inline void help(const bool& x) { _help = x; }

// inline const bool all(){ return _all; }
// inline void all(const bool& x) { _all = x; }

// inline const bool fxor(){ return _xor;}
// inline void fxor(const bool& x){ _xor = x;}

// inline const bool memory(){ return _memory;}
// inline void memory(const bool& x){ _memory = x;}

// inline const bool math(){ return _functions;}
// inline void math(const bool& x){ _functions = x;}

// inline const uint loop(){ return _loop;}
// inline void loop(const uint& x){ _loop = x;}

// inline const uint repeat(){ return _repeat;}
// inline void repeat(const uint& x){ _repeat = x;}

// inline const uint vec(){ return _vec;}
// inline void vec(const uint& x){ _vec = x;}