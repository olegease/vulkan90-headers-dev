#ifndef VULKAN90_H
#define VULKAN90_H

#include "hide/v1_0_.h"

typedef void (*Vk90ErrorHandler)( VkResult result, char const *message );

void vk90_set_error_handler_positive( Vk90ErrorHandler handler );
void vk90_set_error_handler_negative( Vk90ErrorHandler handler );

VkInstance vk90_create_instance( VkInstanceCreateInfo const *refInfo );
void vk90_delete_instance( VkInstance instance );

#endif/*VULKAN90_H*/
