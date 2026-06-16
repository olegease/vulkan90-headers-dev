#ifndef VK90_HIDE_PHYSICAL_DEVICE_H_
#define VK90_HIDE_PHYSICAL_DEVICE_H_

#include "core_.h"
#include <stddef.h>

typedef struct VkPhysicalDevice_T *VkPhysicalDevice;
typedef unsigned long VkDeviceSize;
typedef VkFlags VkSampleCountFlags;

typedef enum VkPhysicalDeviceType {
    VK_PHYSICAL_DEVICE_TYPE_OTHER = 0,
    VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU = 1,
    VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU = 2,
    VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU = 3,
    VK_PHYSICAL_DEVICE_TYPE_CPU = 4,
    VK_PHYSICAL_DEVICE_TYPE_BEGIN_RANGE = VK_PHYSICAL_DEVICE_TYPE_OTHER,
    VK_PHYSICAL_DEVICE_TYPE_END_RANGE = VK_PHYSICAL_DEVICE_TYPE_CPU,
    VK_PHYSICAL_DEVICE_TYPE_RANGE_SIZE = (VK_PHYSICAL_DEVICE_TYPE_CPU - VK_PHYSICAL_DEVICE_TYPE_OTHER + 1),
    VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM = 0x7FFFFFFF
} VkPhysicalDeviceType;

typedef struct VkPhysicalDeviceLimits {
    unsigned maxImageDimension1D;
    unsigned maxImageDimension2D;
    unsigned maxImageDimension3D;
    unsigned maxImageDimensionCube;
    unsigned maxImageArrayLayers;
    unsigned maxTexelBufferElements;
    unsigned maxUniformBufferRange;
    unsigned maxStorageBufferRange;
    unsigned maxPushConstantsSize;
    unsigned maxMemoryAllocationCount;
    unsigned maxSamplerAllocationCount;
    VkDeviceSize bufferImageGranularity;
    VkDeviceSize sparseAddressSpaceSize;
    unsigned maxBoundDescriptorSets;
    unsigned maxPerStageDescriptorSamplers;
    unsigned maxPerStageDescriptorUniformBuffers;
    unsigned maxPerStageDescriptorStorageBuffers;
    unsigned maxPerStageDescriptorSampledImages;
    unsigned maxPerStageDescriptorStorageImages;
    unsigned maxPerStageDescriptorInputAttachments;
    unsigned maxPerStageResources;
    unsigned maxDescriptorSetSamplers;
    unsigned maxDescriptorSetUniformBuffers;
    unsigned maxDescriptorSetUniformBuffersDynamic;
    unsigned maxDescriptorSetStorageBuffers;
    unsigned maxDescriptorSetStorageBuffersDynamic;
    unsigned maxDescriptorSetSampledImages;
    unsigned maxDescriptorSetStorageImages;
    unsigned maxDescriptorSetInputAttachments;
    unsigned maxVertexInputAttributes;
    unsigned maxVertexInputBindings;
    unsigned maxVertexInputAttributeOffset;
    unsigned maxVertexInputBindingStride;
    unsigned maxVertexOutputComponents;
    unsigned maxTessellationGenerationLevel;
    unsigned maxTessellationPatchSize;
    unsigned maxTessellationControlPerVertexInputComponents;
    unsigned maxTessellationControlPerVertexOutputComponents;
    unsigned maxTessellationControlPerPatchOutputComponents;
    unsigned maxTessellationControlTotalOutputComponents;
    unsigned maxTessellationEvaluationInputComponents;
    unsigned maxTessellationEvaluationOutputComponents;
    unsigned maxGeometryShaderInvocations;
    unsigned maxGeometryInputComponents;
    unsigned maxGeometryOutputComponents;
    unsigned maxGeometryOutputVertices;
    unsigned maxGeometryTotalOutputComponents;
    unsigned maxFragmentInputComponents;
    unsigned maxFragmentOutputAttachments;
    unsigned maxFragmentDualSrcAttachments;
    unsigned maxFragmentCombinedOutputResources;
    unsigned maxComputeSharedMemorySize;
    unsigned maxComputeWorkGroupCount[3];
    unsigned maxComputeWorkGroupInvocations;
    unsigned maxComputeWorkGroupSize[3];
    unsigned subPixelPrecisionBits;
    unsigned subTexelPrecisionBits;
    unsigned mipmapPrecisionBits;
    unsigned maxDrawIndexedIndexValue;
    unsigned maxDrawIndirectCount;
    float maxSamplerLodBias;
    float maxSamplerAnisotropy;
    unsigned maxViewports;
    unsigned maxViewportDimensions[2];
    float viewportBoundsRange[2];
    unsigned  viewportSubPixelBits;
    size_t minMemoryMapAlignment;
    VkDeviceSize minTexelBufferOffsetAlignment;
    VkDeviceSize minUniformBufferOffsetAlignment;
    VkDeviceSize minStorageBufferOffsetAlignment;
    int minTexelOffset;
    unsigned maxTexelOffset;
    int minTexelGatherOffset;
    unsigned maxTexelGatherOffset;
    float minInterpolationOffset;
    float maxInterpolationOffset;
    unsigned subPixelInterpolationOffsetBits;
    unsigned maxFramebufferWidth;
    unsigned maxFramebufferHeight;
    unsigned maxFramebufferLayers;
    VkSampleCountFlags framebufferColorSampleCounts;
    VkSampleCountFlags framebufferDepthSampleCounts;
    VkSampleCountFlags framebufferStencilSampleCounts;
    VkSampleCountFlags framebufferNoAttachmentsSampleCounts;
    unsigned maxColorAttachments;
    VkSampleCountFlags sampledImageColorSampleCounts;
    VkSampleCountFlags sampledImageIntegerSampleCounts;
    VkSampleCountFlags sampledImageDepthSampleCounts;
    VkSampleCountFlags sampledImageStencilSampleCounts;
    VkSampleCountFlags storageImageSampleCounts;
    unsigned maxSampleMaskWords;
    VkBool32 timestampComputeAndGraphics;
    float timestampPeriod;
    unsigned maxClipDistances;
    unsigned maxCullDistances;
    unsigned maxCombinedClipAndCullDistances;
    unsigned discreteQueuePriorities;
    float pointSizeRange[2];
    float lineWidthRange[2];
    float pointSizeGranularity;
    float lineWidthGranularity;
    VkBool32 strictLines;
    VkBool32 standardSampleLocations;
    VkDeviceSize optimalBufferCopyOffsetAlignment;
    VkDeviceSize optimalBufferCopyRowPitchAlignment;
    VkDeviceSize nonCoherentAtomSize;
} VkPhysicalDeviceLimits;

typedef struct VkPhysicalDeviceSparseProperties {
    VkBool32 residencyStandard2DBlockShape;
    VkBool32 residencyStandard2DMultisampleBlockShape;
    VkBool32 residencyStandard3DBlockShape;
    VkBool32 residencyAlignedMipSize;
    VkBool32 residencyNonResidentStrict;
} VkPhysicalDeviceSparseProperties;

#endif/*VK90_HIDE_PHYSICAL_DEVICE_H_*/
