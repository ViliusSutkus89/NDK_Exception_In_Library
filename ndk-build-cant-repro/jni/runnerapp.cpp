#include <cstdlib>
#include <iostream>
#include <dlfcn.h>

typedef bool (*run_test_func)();

void *load_library(const char *name) {
  void * lib = dlopen(name, RTLD_NOW);
  if (nullptr == lib) {
    std::cerr << dlerror() << std::endl;
    abort();
  }
  return lib;
}

run_test_func load_func(void *lib, const char *name) {
  run_test_func sym = reinterpret_cast<run_test_func>(dlsym(lib, name));
  if (nullptr == sym) {
    std::cerr << dlerror() << std::endl;
    abort();
  }
  return sym;
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) const char * argv[]) {
  load_library("libc++_shared.so");
  load_library("libthrower.so");
  void * lib_catcher = load_library("libcatcher.so");

  run_test_func run_test = load_func(lib_catcher, "run_test");
  return run_test() ? 0 : 1;
}

