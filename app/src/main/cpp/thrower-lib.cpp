#include "thrower-lib.h"

void lib_throwRuntimeError() {
  throw std::runtime_error("throwing lib::std::runtime_error 2");
}

bool lib_throwAndCatchRuntimeError() {
  try {
    throw std::runtime_error("throwing and trying to catch lib::std::runtime_error 3");
  } catch (const std::runtime_error &e) {
    return true;
  }
  return false;
}

void lib_throwExtended() {
  throw ExtendedException("throwing lib::ExtendedException 5");
}

bool lib_throwAndCatchExtended() {
  try {
    throw ExtendedException("throwing and trying to catch lib::ExtendedException 6");
  } catch (const ExtendedException &e) {
    return true;
  }
  return false;
}
