LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := DataProvider
LOCAL_SRC_FILES := DataProvider.c
#����log������Ӧ��log��
LOCAL_LDLIBS += -llog 

include $(BUILD_SHARED_LIBRARY)