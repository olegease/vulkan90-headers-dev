#include <vulkan90/vulkan.h>

#include <assert.h>
#include <stddef.h>
#include <stdio.h>

static void handle_error_positive_default( VkResult result, char const *message ) {
    fprintf( stderr, "Vulkan warning: %d, %s\n", result, message );
}

static void handle_error_negative_default( VkResult result, char const *message ) {
    fprintf( stderr, "Vulkan error: %d, %s\n", result, message );
    assert( VK_SUCCESS <= result );
}

static Vk90ErrorHandler Error_Handler_Positive = handle_error_positive_default;
static Vk90ErrorHandler Error_Handler_Negative = handle_error_negative_default;

void vk90_set_error_handler_positive( Vk90ErrorHandler handler ) {
    Error_Handler_Positive = ( handler ) ? handler : handle_error_positive_default;
}

void vk90_set_error_handler_negative( Vk90ErrorHandler handler ) {
    Error_Handler_Negative = ( handler ) ? handler : handle_error_negative_default;
}

void vk90_delete_instance( VkInstance instance ) {
    vkDestroyInstance( instance, NULL );
}
/* NOTE: no need for file argument as it will be only single file */
#define HANDLE_ERROR( result, success, failed, line, message ) \
    do { \
        if ( result == VK_SUCCESS ) return success; \
        fprintf( stderr, "%s:%d\n", __FILE__, line ); \
        if ( result < VK_SUCCESS ) Error_Handler_Negative( result, message ); \
        else Error_Handler_Positive( result, message ); \
        return failed; \
    } while ( 0u )

VkInstance vk90_create_instance( VkInstanceCreateInfo const *refInfo ) {
    VkInstance instance;
    VkResult result = vkCreateInstance( refInfo, NULL, &instance );
    HANDLE_ERROR( result, instance, NULL, __LINE__ - 1, "vkCreateInstance" );
}

VkInstance vk90_create_instance_default( void ) {
    return vk90_create_instance( vk90_instance_info_static( ) );
}

VkInstanceCreateInfo const *vk90_instance_info_static( void ) {
    static VkApplicationInfo const appInfo = {
        VK_STRUCTURE_TYPE_APPLICATION_INFO,
        NULL,
        "",
        0,
        "",
        0,
        0
    };

    static VkInstanceCreateInfo const info = {
        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        NULL,
        0,
        &appInfo,
        0, NULL, /* layers */
        0, NULL /* extensions */
    };

    return &info;
}

VkInstanceCreateInfo vk90_instance_info_default( void ) {
    return *vk90_instance_info_static( );
}

/* Apache License 2.0 */
/* NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0> */
/* SPDX-License-Identifier: Apache-2.0 */
/* lib: `vulkan90-headers-dev` (research) C90 Conformant Vulkan Headers */
/* Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
