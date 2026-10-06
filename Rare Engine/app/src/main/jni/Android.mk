# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

# Recursively find source files
rwildcard = $(foreach d,$(wildcard $1/*),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))


# ============================================================
# RareEngine Core
# ============================================================

include $(CLEAR_VARS)

LOCAL_MODULE := rareengine-core

LOCAL_CPP_EXTENSION := .cpp .cc

LOCAL_SRC_FILES := \
    $(patsubst $(LOCAL_PATH)/%,%,$(call rwildcard,$(LOCAL_PATH)/rareengine/core,*.cpp)) \
    $(patsubst $(LOCAL_PATH)/%,%,$(call rwildcard,$(LOCAL_PATH)/rareengine/core,*.cc))

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/rareengine/headers

LOCAL_CPPFLAGS += -std=c++17

ifeq ($(TARGET_ARCH_ABI),x86)
    LOCAL_CFLAGS += -ffast-math -mtune=atom -mssse3 -mfpmath=sse
endif

LOCAL_LDLIBS += -lGLESv2 -lEGL

include $(BUILD_SHARED_LIBRARY)


# ============================================================
# Android Attachment
# ============================================================

include $(CLEAR_VARS)

LOCAL_MODULE := android-attachment

LOCAL_CPP_EXTENSION := .cpp .cc

LOCAL_SRC_FILES := Main.cpp

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/include \
    $(LOCAL_PATH)/rareengine/headers

# Link against RareEngine Core
LOCAL_SHARED_LIBRARIES := rareengine-core

LOCAL_CPPFLAGS += -std=c++17

ifeq ($(TARGET_ARCH_ABI),x86)
    LOCAL_CFLAGS += -ffast-math -mtune=atom -mssse3 -mfpmath=sse
endif

LOCAL_LDLIBS += -lEGL -lGLESv2 -landroid

include $(BUILD_SHARED_LIBRARY)

