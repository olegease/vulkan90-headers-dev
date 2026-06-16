#ifndef VULKAN90_HIDE_CORE_H_
#define VULKAN90_HIDE_CORE_H_

#include <limits.h>

#   if 0u \
    || UCHAR_MAX != 0xFFu \
    || USHRT_MAX != 0xFFFFu \
    || UINT_MAX  != 0xFFFFFFFFu \
    || ULONG_MAX <= 0xFFFFFFFFul
#error "operational system platform are not supported because of C90 standard conformance, sorry!"
#   endif

typedef unsigned VkBool32;
typedef unsigned VkFlags;

typedef enum VkResult {
    VK_SUCCESS = 0,
    VK_TODO = -1,
    VK_RESULT_MAX_ENUM = 0x7FFFFFFF
} VkResult;

typedef enum VkStructureType {
    VK_STRUCTURE_TYPE_APPLICATION_INFO = 0,
    VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO = 1
} VkStructureType;

typedef struct VkAllocationCallbacks {
    char todo;
} VkAllocationCallbacks;

#endif/*VULKAN90_HIDE_CORE_H_*/
