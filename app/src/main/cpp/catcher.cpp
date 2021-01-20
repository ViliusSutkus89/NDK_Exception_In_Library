#include <jni.h>
#include "thrower.h"

extern "C" JNIEXPORT jboolean JNICALL
Java_com_viliussutkus89_exceptioner_ExceptionInstrumentedTest_throwRuntimeError(__attribute__((unused)) JNIEnv *env,
                                                                                __attribute__((unused)) jclass clazz) {
  try {
    throw std::runtime_error("this is std::runtime_error 1");
  } catch (const std::runtime_error &e) {
    return JNI_TRUE;
  }
  return JNI_FALSE;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_viliussutkus89_exceptioner_ExceptionInstrumentedTest_throwRuntimeErrorInLib(__attribute__((unused)) JNIEnv *env,
                                                                                     __attribute__((unused)) jclass clazz) {
  try {
    lib_throwRuntimeError();
  } catch (const std::runtime_error &e) {
    return JNI_TRUE;
  }
  return JNI_FALSE;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_viliussutkus89_exceptioner_ExceptionInstrumentedTest_throwAndCatchRuntimeErrorInLib(__attribute__((unused)) JNIEnv *env,
                                                                                             __attribute__((unused)) jclass clazz) {
  return lib_throwAndCatchRuntimeError() ? JNI_TRUE : JNI_FALSE;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_viliussutkus89_exceptioner_ExceptionInstrumentedTest_throwExtended(__attribute__((unused)) JNIEnv *env,
                                                                            __attribute__((unused)) jclass clazz) {
  try {
    throw ExtendedException("this is ExtendedException 4");
  } catch (const ExtendedException &e) {
    return JNI_TRUE;
  }
  return JNI_FALSE;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_viliussutkus89_exceptioner_ExceptionInstrumentedTest_throwExtendedInLib(__attribute__((unused)) JNIEnv *env,
                                                                                 __attribute__((unused)) jclass clazz) {
  try {
    lib_throwExtended();
  } catch (const ExtendedException &e) {
    return JNI_TRUE;
  }
  return JNI_FALSE;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_viliussutkus89_exceptioner_ExceptionInstrumentedTest_throwAndCatchExtendedInLib(__attribute__((unused)) JNIEnv *env,
                                                                                         __attribute__((unused)) jclass clazz) {
  return lib_throwAndCatchExtended() ? JNI_TRUE : JNI_FALSE;
}
