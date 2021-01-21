#include <iostream>
#include "thrower.h"

extern "C"
bool run_test() {
  std::cout << "Trying to throw and catch std::runtime_error" << std::endl;
  try {
    throw std::runtime_error("this is std::runtime_error 1");
  } catch (const std::runtime_error &e) {
  } catch (...) {
    return false;
  }

  std::cout << "Trying to throw std::runtime_error in thrower library and catch it in the same library" << std::endl;
  if (!lib_throwAndCatchRuntimeError()) {
    return false;
  }

  std::cout << "Trying to throw std::runtime_error in thrower library and catch it here, across the library border" << std::endl;
  try {
    lib_throwRuntimeError();
  } catch (const std::runtime_error &e) {
  } catch (...) {
    return false;
  }

  std::cout << "Trying to throw and catch ExtendedException" << std::endl;
  try {
    throw ExtendedException("this is ExtendedException 4");
  } catch (const ExtendedException &e) {
  } catch (...) {
    return false;
  }

  std::cout << "Trying to throw ExtendedException in thrower library and catch it in the same library" << std::endl;
  if (!lib_throwAndCatchExtended()) {
    return false;
  }

  std::cout << "Trying to throw ExtendedException in thrower library and catch it here, across the library border" << std::endl;
  try {
    lib_throwExtended();
  } catch (const std::runtime_error &e) {
  } catch (...) {
      return false;
  }

  return true;
}

