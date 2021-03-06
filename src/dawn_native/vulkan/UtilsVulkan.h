// Copyright 2019 The Dawn Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DAWNNATIVE_VULKAN_UTILSVULKAN_H_
#define DAWNNATIVE_VULKAN_UTILSVULKAN_H_

#include "common/vulkan_platform.h"
#include "dawn_native/Commands.h"
#include "dawn_native/dawn_platform.h"

#include "dawn_native/vulkan/BufferVk.h"
#include "dawn_native/vulkan/VulkanError.h"

namespace dawn_native { namespace vulkan {

    VkCompareOp ToVulkanCompareOp(wgpu::CompareFunction op);
    VkShaderStageFlags ToVulkanShaderStageFlags(wgpu::ShaderStage stages);
    VkGeometryTypeNV ToVulkanGeometryType(wgpu::RayTracingAccelerationGeometryType geometryType);
    VkIndexType ToVulkanIndexFormat(wgpu::IndexFormat format);
    VkFormat ToVulkanVertexFormat(wgpu::VertexFormat format);
    VkAccelerationStructureTypeNV ToVulkanAccelerationContainerLevel(
        wgpu::RayTracingAccelerationContainerLevel level);
    VkBuildAccelerationStructureFlagBitsNV ToVulkanBuildAccelerationContainerFlags(
        wgpu::RayTracingAccelerationContainerFlag buildFlags);
    VkGeometryInstanceFlagBitsNV ToVulkanAccelerationContainerInstanceFlags(
        wgpu::RayTracingAccelerationInstanceFlag instanceFlags);
    VkGeometryFlagBitsNV ToVulkanAccelerationContainerGeometryFlags(
        wgpu::RayTracingAccelerationGeometryFlag geometryFlags);
    VkRayTracingShaderGroupTypeNV ToVulkanShaderBindingTableGroupType(
        wgpu::RayTracingShaderBindingTableGroupType type);

    Extent3D ComputeTextureCopyExtent(const TextureCopy& textureCopy, const Extent3D& copySize);
    VkBufferImageCopy ComputeBufferImageCopyRegion(const BufferCopy& bufferCopy,
                                                   const TextureCopy& textureCopy,
                                                   const Extent3D& copySize);

    MaybeError CreateBufferFromResourceMemoryAllocation(Device* device,
                                                        VkBuffer* buffer,
                                                        uint32_t size,
                                                        VkBufferUsageFlags usage,
                                                        ResourceMemoryAllocation resource);

}}  // namespace dawn_native::vulkan

#endif  // DAWNNATIVE_VULKAN_UTILSVULKAN_H_
