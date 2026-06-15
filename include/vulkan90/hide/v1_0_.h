#ifndef VULKAN90_HIDE_V1_0_H_
#define VULKAN90_HIDE_V1_0_H_

#include "core_.h"
#include "instance_.h"

typedef struct VkLayerProperties {
    char layerName[VK_MAX_EXTENSION_NAME_SIZE];
    unsigned specVersion;
    unsigned implementationVersion;
    char description[VK_MAX_DESCRIPTION_SIZE];
} VkLayerProperties;

VkResult vkEnumerateInstanceLayerProperties( unsigned *outCount, VkLayerProperties *outProps );

typedef struct VkExtensionProperties {
    char extensionName[VK_MAX_EXTENSION_NAME_SIZE];
    unsigned specVersion;
} VkExtensionProperties;

VkResult vkEnumerateInstanceExtensionProperties( char const *refLayerName, unsigned *outCount, VkExtensionProperties *outProps );
VkResult vkCreateInstance( VkInstanceCreateInfo const *refInfo, VkAllocationCallbacks const *refAlloc, VkInstance *out );
void vkDestroyInstance( VkInstance in, VkAllocationCallbacks const *refAlloc );

#endif/*VULKAN90_HIDE_V1_0_H_*/
