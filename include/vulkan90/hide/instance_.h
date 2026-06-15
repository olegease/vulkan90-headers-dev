#ifndef VULKAN90_HIDE_INSTANCE_H_
#define VULKAN90_HIDE_INSTANCE_H_

#include "core_.h"

typedef struct VkInstance_T *VkInstance;

typedef VkFlags VkInstanceCreateFlags;

typedef struct VkApplicationInfo {
    VkStructureType sType;
    void const *pNext;
    char const *pApplicationName;
    unsigned applicationVersion;
    char const *pEngineName;
    unsigned engineVersion;
    unsigned apiVersion;
} VkApplicationInfo;

typedef struct VkInstanceCreateInfo {
    VkStructureType sType;
    void const *pNext;
    VkInstanceCreateFlags flags;
    VkApplicationInfo const *pApplicationInfo;
    unsigned enabledLayerCount;
    char const *const *ppEnabledLayerNames;
    unsigned enabledExtensionCount;
    char const *const *ppEnabledExtensionNames;
} VkInstanceCreateInfo;

#endif/*VULKAN90_HIDE_INSTANCE_H_*/
