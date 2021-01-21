#ifndef THROWER_H
#define THROWER_H

#include <stdexcept>

#define THROWER_API __attribute__((__visibility__("default")))

class THROWER_API ExtendedException : public std::runtime_error {
public:
  using std::runtime_error::runtime_error;
};

extern THROWER_API bool lib_throwAndCatchRuntimeError();
extern THROWER_API void lib_throwRuntimeError();

extern THROWER_API bool lib_throwAndCatchExtended();
extern THROWER_API void lib_throwExtended();

#endif // THROWER_H

