LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := thrower
LOCAL_SRC_FILES := thrower.cpp
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := catcher
LOCAL_SRC_FILES := catcher.cpp
LOCAL_SHARED_LIBRARIES := thrower
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := runnerapp
LOCAL_SRC_FILES := runnerapp.cpp
include $(BUILD_EXECUTABLE)

