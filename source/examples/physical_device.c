#include <vulkan90/vulkan.h>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define APP_PHYSICAL_DEVICES_MAX 8u

typedef struct AppDataVk {
    VkInstance instance;
    VkPhysicalDevice physDevices[APP_PHYSICAL_DEVICES_MAX];
    VkPhysicalDeviceProperties physDeviceProps[APP_PHYSICAL_DEVICES_MAX];
} AppDataVk;

static AppDataVk Global_App = { 0u };

int main( void ) {
    AppDataVk *app = &Global_App;
    VkResult result;
    unsigned i;
    unsigned countDevices = APP_PHYSICAL_DEVICES_MAX;


    app->instance = vk90_create_instance( vk90_instance_info_static( ) );
    result = vkEnumeratePhysicalDevices( app->instance, &countDevices, app->physDevices );
    assert( countDevices && VK_SUCCESS <= result && countDevices <= APP_PHYSICAL_DEVICES_MAX );
    printf( "devices count: %u\n", countDevices );
    for ( i = 0u; i < countDevices; ++i ) {
        vkGetPhysicalDeviceProperties( app->physDevices[i], &app->physDeviceProps[i] );
        switch ( app->physDeviceProps[i].deviceType ) {
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: puts( "integrated gpu" ); break;
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU: puts( "discrete gpu" ); break;
            default: puts( "find better gpu!" ); break;
        }
    }

    vk90_delete_instance( app->instance );

    return EXIT_SUCCESS;
}

/* Apache License 2.0 */
/* NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0> */
/* SPDX-License-Identifier: Apache-2.0 */
/* lib: `vulkan90-headers-dev` (research) C90 Conformant Vulkan Headers */
/* Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
