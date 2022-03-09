// todo(kazuki):: fix workaround
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"

#ifndef EXPORTED_VULKAN_FUNCTION
#define EXPORTED_VULKAN_FUNCTION( function )
#endif

EXPORTED_VULKAN_FUNCTION(vkGetInstanceProcAddr)

#undef EXPORTED_VULKAN_FUNCTION


#ifndef GLOBAL_VULKAN_FUNCTION
#define GLOBAL_VULKAN_FUNCTION(func)
#endif

GLOBAL_VULKAN_FUNCTION(vkCreateInstance)

#undef GLOBAL_VULKAN_FUNCTION

#ifndef INSTANCE_VULKAN_FUNCTION
#define INSTANCE_VULKAN_FUNCTION(func)
#endif

INSTANCE_VULKAN_FUNCTION(vkEnumeratePhysicalDevices)
INSTANCE_VULKAN_FUNCTION(vkEnumerateDeviceExtensionProperties)
INSTANCE_VULKAN_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties)
INSTANCE_VULKAN_FUNCTION(vkGetPhysicalDeviceMemoryProperties)
INSTANCE_VULKAN_FUNCTION(vkGetPhysicalDeviceFormatProperties)
INSTANCE_VULKAN_FUNCTION(vkCreateDevice)
INSTANCE_VULKAN_FUNCTION(vkGetDeviceProcAddr)
INSTANCE_VULKAN_FUNCTION(vkDestroyInstance)

#undef INSTANCE_VULKAN_FUNCTION

#ifndef DEVICE_VULKAN_FUNCTION
#define DEVICE_VULKAN_FUNCTION( function )
#endif

DEVICE_VULKAN_FUNCTION(vkDestroyDevice)
DEVICE_VULKAN_FUNCTION(vkCreateImage)
DEVICE_VULKAN_FUNCTION(vkCmdBeginRenderPass)
DEVICE_VULKAN_FUNCTION(vkCreateBuffer)
DEVICE_VULKAN_FUNCTION(vkGetBufferMemoryRequirements)
DEVICE_VULKAN_FUNCTION(vkGetImageSubresourceLayout)
DEVICE_VULKAN_FUNCTION(vkMapMemory)
DEVICE_VULKAN_FUNCTION(vkBindBufferMemory)
DEVICE_VULKAN_FUNCTION(vkAllocateMemory)
DEVICE_VULKAN_FUNCTION(vkAllocateCommandBuffers)
DEVICE_VULKAN_FUNCTION(vkCreateCommandPool)
DEVICE_VULKAN_FUNCTION(vkDestroyCommandPool)
DEVICE_VULKAN_FUNCTION(vkDestroyBuffer)
DEVICE_VULKAN_FUNCTION(vkDestroyImage)
DEVICE_VULKAN_FUNCTION(vkGetDeviceQueue)
DEVICE_VULKAN_FUNCTION(vkFreeMemory)
DEVICE_VULKAN_FUNCTION(vkUnmapMemory)
DEVICE_VULKAN_FUNCTION(vkQueueWaitIdle)
DEVICE_VULKAN_FUNCTION(vkDeviceWaitIdle)
DEVICE_VULKAN_FUNCTION(vkCmdCopyBufferToImage)
DEVICE_VULKAN_FUNCTION(vkFlushMappedMemoryRanges)
DEVICE_VULKAN_FUNCTION(vkCreatePipelineLayout)
DEVICE_VULKAN_FUNCTION(vkCreateShaderModule)
DEVICE_VULKAN_FUNCTION(vkDestroyShaderModule)
DEVICE_VULKAN_FUNCTION(vkCreateGraphicsPipelines)
DEVICE_VULKAN_FUNCTION(vkCmdBindPipeline)
DEVICE_VULKAN_FUNCTION(vkCmdDraw)
DEVICE_VULKAN_FUNCTION(vkCmdPushConstants)
DEVICE_VULKAN_FUNCTION(vkCmdBindVertexBuffers)
DEVICE_VULKAN_FUNCTION(vkDestroyPipeline)
DEVICE_VULKAN_FUNCTION(vkBeginCommandBuffer)
DEVICE_VULKAN_FUNCTION(vkBindImageMemory)
DEVICE_VULKAN_FUNCTION(vkCmdCopyImage)
DEVICE_VULKAN_FUNCTION(vkCmdPipelineBarrier)
DEVICE_VULKAN_FUNCTION(vkCreateImageView)
DEVICE_VULKAN_FUNCTION(vkEndCommandBuffer)
DEVICE_VULKAN_FUNCTION(vkFreeCommandBuffers)
DEVICE_VULKAN_FUNCTION(vkGetImageMemoryRequirements)
DEVICE_VULKAN_FUNCTION(vkQueueSubmit)
DEVICE_VULKAN_FUNCTION(vkDestroyPipelineLayout)

#undef DEVICE_LEVEL_VULKAN_FUNCTION

#pragma clang diagnostic pop