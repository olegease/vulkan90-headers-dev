#include <vulkan90/vulkan.h>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define APP_PHYSICAL_DEVICES_MAX 8u
#define APP_QUEUE_FAMILIES_MAX 16u

typedef struct AppDataVk {
    VkInstance instance;
    VkPhysicalDevice physDevices[APP_PHYSICAL_DEVICES_MAX];
    VkPhysicalDeviceProperties physDevicesProps[APP_PHYSICAL_DEVICES_MAX];
    VkPhysicalDeviceFeatures physDevicesFeatures[APP_PHYSICAL_DEVICES_MAX];
    VkPhysicalDevice physDevice;
    VkQueueFamilyProperties physDeviceFamilies[APP_QUEUE_FAMILIES_MAX];
} AppDataVk;

static AppDataVk Global_App = { 0u };

int main( void ) {
    AppDataVk *app = &Global_App;
    VkResult result;
    unsigned u32i, countDevices = APP_PHYSICAL_DEVICES_MAX, countFamilies = APP_QUEUE_FAMILIES_MAX;
    unsigned lastIntegratedDeviceIndex = 0, lastDiscreteDeviceIndex = 0, deviceChosenIndex = 0;

    app->instance = vk90_create_instance_default( );
    result = vkEnumeratePhysicalDevices( app->instance, &countDevices, app->physDevices );
    assert( countDevices );
    assert( VK_SUCCESS <= result );
    printf( "devices count: %u\n", countDevices );
    assert( countDevices <= APP_PHYSICAL_DEVICES_MAX );
    for ( u32i = 0u; u32i < countDevices; ++u32i ) {
        vkGetPhysicalDeviceProperties( app->physDevices[u32i], &app->physDevicesProps[u32i] );
        printf( "[%u] %s: ", u32i, app->physDevicesProps[u32i].deviceName );
        switch ( app->physDevicesProps[u32i].deviceType ) {
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: lastIntegratedDeviceIndex = u32i; puts( "integrated gpu" ); break;
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU: lastDiscreteDeviceIndex = u32i; puts( "discrete gpu" ); break;
            default: puts( "find better gpu!" ); break;
        }
        vkGetPhysicalDeviceFeatures(app->physDevices[u32i], &app->physDevicesFeatures[u32i] );
        if ( app->physDevicesFeatures[u32i].geometryShader ) puts( "-- feature geometry shader supported" );
    }

    if ( lastDiscreteDeviceIndex ) deviceChosenIndex = lastDiscreteDeviceIndex;
    else if ( lastIntegratedDeviceIndex ) deviceChosenIndex = lastIntegratedDeviceIndex;
    else deviceChosenIndex = 0;
    app->physDevice = app->physDevices[deviceChosenIndex];

    printf( "chosen device [%u]\n", deviceChosenIndex );

    vkGetPhysicalDeviceQueueFamilyProperties( app->physDevice, &countFamilies, app->physDeviceFamilies );
    assert( countFamilies );
    printf( "family queues count: %u\n", countFamilies );
    assert( countFamilies <= APP_QUEUE_FAMILIES_MAX );

    for ( u32i = 0u; u32i < countFamilies; ++u32i ) {
        printf( "queue family [%u]\n", u32i );
        if ( app->physDeviceFamilies[u32i].queueFlags & VK_QUEUE_GRAPHICS_BIT ) puts( "-- graphics supported" );
        if ( app->physDeviceFamilies[u32i].queueFlags & VK_QUEUE_COMPUTE_BIT ) puts( "-- compute supported" );
        if ( app->physDeviceFamilies[u32i].queueFlags & VK_QUEUE_TRANSFER_BIT ) puts( "-- transfer supported" );
        if ( app->physDeviceFamilies[u32i].queueFlags & VK_QUEUE_SPARSE_BINDING_BIT ) puts( "-- sparse binding supported" );
    }

    vk90_delete_instance( app->instance );

    return EXIT_SUCCESS;
}

/* Apache License 2.0 */
/* NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0> */
/* SPDX-License-Identifier: Apache-2.0 */
/* lib: `vulkan90-headers-dev` (research) C90 Conformant Vulkan Headers */
/* Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
