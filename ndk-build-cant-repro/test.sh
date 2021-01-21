#!/bin/bash
set -e

THIS_FILE=$(readlink -f "$0")
BASEDIR=$(dirname "$THIS_FILE")
function rm_folder_if_exists() {
  if test -d $BASEDIR/$1
  then
    rm -rf $BASEDIR/$1
  fi
}

rm_folder_if_exists libs
rm_folder_if_exists obj

TEST_PATH=/data/local/tmp/thrower

$NDK/ndk-build -B -j8

adb shell rm -rf $TEST_PATH
adb shell mkdir -p $TEST_PATH
adb push $BASEDIR/libs/x86_64/* $TEST_PATH
echo ""
adb shell "LD_LIBRARY_PATH=$TEST_PATH $TEST_PATH/runnerapp; echo retval: \$?"

