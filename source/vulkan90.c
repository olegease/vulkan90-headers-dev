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
    if ( handler == NULL ) Error_Handler_Positive = handle_error_positive_default;
    else Error_Handler_Positive = handler;
}
void vk90_set_error_handler_negative( Vk90ErrorHandler handler ) {
    if ( handler == NULL ) Error_Handler_Positive = handle_error_negative_default;
    else Error_Handler_Negative = handler;
}

void vk90_delete_instance( VkInstance instance ) {
    vkDestroyInstance( instance, NULL );
}
/* NOTE: no need for file as it will be only single file */
#define VK90_HANDLE_ERROR( result, success, failed, line ) \
    do { \
        if ( result == VK_SUCCESS ) return success; \
        fprintf( stderr, "%s:%d\n", __FILE__, line ); \
        if ( result < VK_SUCCESS ) Error_Handler_Negative( result, "" ); \
        else Error_Handler_Positive( result, "" ); \
        return failed; \
    } while ( 0u )

VkInstance vk90_create_instance( VkInstanceCreateInfo const *refInfo ) {
    VkInstance instance;
    VkResult result = vkCreateInstance( refInfo, NULL, &instance );
    VK90_HANDLE_ERROR( result, instance, NULL, __LINE__ );
}
