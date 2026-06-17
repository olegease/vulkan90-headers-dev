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

void vkDestroyInstance( VkInstance instance, VkAllocationCallbacks const *refAlloc );

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

VkResult vkCreateInstance( VkInstanceCreateInfo const *refInfo, VkAllocationCallbacks const *refAlloc, VkInstance *out );

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

typedef struct VkPhysicalDeviceFeatures {
    VkBool32 robustBufferAccess;
    VkBool32 fullDrawIndexUint32;
    VkBool32 imageCubeArray;
    VkBool32 independentBlend;
    VkBool32 geometryShader;
    VkBool32 tessellationShader;
    VkBool32 sampleRateShading;
    VkBool32 dualSrcBlend;
    VkBool32 logicOp;
    VkBool32 multiDrawIndirect;
    VkBool32 drawIndirectFirstInstance;
    VkBool32 depthClamp;
    VkBool32 depthBiasClamp;
    VkBool32 fillModeNonSolid;
    VkBool32 depthBounds;
    VkBool32 wideLines;
    VkBool32 largePoints;
    VkBool32 alphaToOne;
    VkBool32 multiViewport;
    VkBool32 samplerAnisotropy;
    VkBool32 textureCompressionETC2;
    VkBool32 textureCompressionASTC_LDR;
    VkBool32 textureCompressionBC;
    VkBool32 occlusionQueryPrecise;
    VkBool32 pipelineStatisticsQuery;
    VkBool32 vertexPipelineStoresAndAtomics;
    VkBool32 fragmentStoresAndAtomics;
    VkBool32 shaderTessellationAndGeometryPointSize;
    VkBool32 shaderImageGatherExtended;
    VkBool32 shaderStorageImageExtendedFormats;
    VkBool32 shaderStorageImageMultisample;
    VkBool32 shaderStorageImageReadWithoutFormat;
    VkBool32 shaderStorageImageWriteWithoutFormat;
    VkBool32 shaderUniformBufferArrayDynamicIndexing;
    VkBool32 shaderSampledImageArrayDynamicIndexing;
    VkBool32 shaderStorageBufferArrayDynamicIndexing;
    VkBool32 shaderStorageImageArrayDynamicIndexing;
    VkBool32 shaderClipDistance;
    VkBool32 shaderCullDistance;
    VkBool32 shaderFloat64;
    VkBool32 shaderInt64;
    VkBool32 shaderInt16;
    VkBool32 shaderResourceResidency;
    VkBool32 shaderResourceMinLod;
    VkBool32 sparseBinding;
    VkBool32 sparseResidencyBuffer;
    VkBool32 sparseResidencyImage2D;
    VkBool32 sparseResidencyImage3D;
    VkBool32 sparseResidency2Samples;
    VkBool32 sparseResidency4Samples;
    VkBool32 sparseResidency8Samples;
    VkBool32 sparseResidency16Samples;
    VkBool32 sparseResidencyAliased;
    VkBool32 variableMultisampleRate;
    VkBool32 inheritedQueries;
} VkPhysicalDeviceFeatures;

void vkGetPhysicalDeviceFeatures( VkPhysicalDevice physDevice, VkPhysicalDeviceFeatures *outFeatures );

typedef struct VkQueueFamilyProperties {
    VkQueueFlags queueFlags;
    unsigned queueCount;
    unsigned timestampValidBits;
    VkExtent3D minImageTransferGranularity;
} VkQueueFamilyProperties;

void vkGetPhysicalDeviceQueueFamilyProperties( VkPhysicalDevice physDevice, unsigned *outCount, VkQueueFamilyProperties *pQueueFamilyProperties );

#endif/*VULKAN90_HIDE_V1_0_H_*/

/* Apache License 2.0 */
/* NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0> */
/* SPDX-License-Identifier: Apache-2.0 */
/* lib: `vulkan90-headers-dev` (research) C90 Conformant Vulkan Headers */
/* Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
