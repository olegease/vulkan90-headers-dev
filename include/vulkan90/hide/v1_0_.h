#ifndef VULKAN90_HIDE_V1_0_H_
#define VULKAN90_HIDE_V1_0_H_

#include "core_.h"

#define VK_MAX_EXTENSION_NAME_SIZE 256u
#define VK_MAX_DESCRIPTION_SIZE 256u

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

#include "instance_.h"

VkResult vkCreateInstance( VkInstanceCreateInfo const *refInfo, VkAllocationCallbacks const *refAlloc, VkInstance *out );
void vkDestroyInstance( VkInstance in, VkAllocationCallbacks const *refAlloc );

#include "physical_device_.h"

VkResult vkEnumeratePhysicalDevices( VkInstance instance, unsigned *outCount, VkPhysicalDevice *outPhysDevices );

#define VK_MAX_PHYSICAL_DEVICE_NAME_SIZE 256u
#define VK_UUID_SIZE 16u

typedef struct VkPhysicalDeviceProperties {
    unsigned apiVersion;
    unsigned driverVersion;
    unsigned vendorID;
    unsigned deviceID;
    VkPhysicalDeviceType deviceType;
    char deviceName[VK_MAX_PHYSICAL_DEVICE_NAME_SIZE];
    unsigned char pipelineCacheUUID[VK_UUID_SIZE];
    VkPhysicalDeviceLimits limits;
    VkPhysicalDeviceSparseProperties sparseProperties;
} VkPhysicalDeviceProperties;

void vkGetPhysicalDeviceProperties( VkPhysicalDevice physDevice, VkPhysicalDeviceProperties *outProps );

#endif/*VULKAN90_HIDE_V1_0_H_*/
