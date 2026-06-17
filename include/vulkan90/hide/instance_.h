#ifndef VULKAN90_HIDE_INSTANCE_H_
#define VULKAN90_HIDE_INSTANCE_H_

#include "core_.h"

typedef struct VkInstance_T *VkInstance;

typedef VkFlags VkInstanceCreateFlags;

typedef struct VkApplicationInfo {
    VkStructureType sType;
    void const *pNext;
    char const *pApplicationName;
    unsigned applicationVersion;
    char const *pEngineName;
    unsigned engineVersion;
    unsigned apiVersion;
} VkApplicationInfo;

#endif/*VULKAN90_HIDE_INSTANCE_H_*/

/* Apache License 2.0 */
/* NO WARRANTY OF ANY KIND see <http://www.apache.org/licenses/LICENSE-2.0> */
/* SPDX-License-Identifier: Apache-2.0 */
/* lib: `vulkan90-headers-dev` (research) C90 Conformant Vulkan Headers */
/* Ⓒ Copyright (c) 2026 Oleg'Ease'Kharchuk ᦒ */
