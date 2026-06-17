#ifndef VULKAN90_VULKAN_H
#define VULKAN90_VULKAN_H

#include "hide/v1_0_.h"

typedef void (*Vk90ErrorHandler)( VkResult result, char const *message );
/* error handling */
void vk90_set_error_handler_positive( Vk90ErrorHandler handler );
void vk90_set_error_handler_negative( Vk90ErrorHandler handler );
/* instance */
void vk90_delete_instance( VkInstance instance );
VkInstance vk90_create_instance( VkInstanceCreateInfo const *refInfo );
VkInstance vk90_create_instance_alloc( VkInstanceCreateInfo const *refInfo, VkAllocationCallbacks const *refAlloc );
VkInstance vk90_create_instance_default( void );
/* -- create info */
VkInstanceCreateInfo const *vk90_instance_info_static( void );
VkInstanceCreateInfo vk90_instance_info_default( void );

#endif/*VULKAN90_VULKAN_H*/

/* Apache License 2.0 */
/* NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0> */
/* SPDX-License-Identifier: Apache-2.0 */
/* lib: `vulkan90-headers-dev` (research) C90 Conformant Vulkan Headers */
/* Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
