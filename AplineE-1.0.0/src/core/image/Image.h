#pragma once
#include <core/core.h>

#pragma region ImageStack & ImagePool

typedef struct ImageReference_T {
	uint32_t imageIndex;
	VkImage* image;
	VkImageView* imageView;
	VkFormat* format;
	VkExtent2D* extent;
	VkImageAspectFlags* aspectFlags;
	VkImageUsageFlags* usage;
	ImageStack stack;
}ImageReference_T;


typedef struct ImageStack_T {
	uint32_t imageCount;
	
	VkImage* images;
	VkImageView* imageViews;
	VkFormat* formats;
	VkImageUsageFlags* usage;
	VkImageAspectFlags* aspectFlags;
	ImageReference_T* imageReferences;

	VkExtent2D extent;

	VkSampleCountFlags sampleCount;
	
	ImagePool pool;
	
}ImageStack_T;

typedef struct ImagePool_T {
	EngineHandle handle;
	
	uint32_t imageStackCount;
	ImageStack_T* imageStacks;
	
	VkDeviceMemory memory;
}ImagePool_T;

#pragma endregion

typedef struct RenderModule_T {
	EngineHandle handle;
	RenderModuleType type;



}RenderModule_T;

typedef struct ComputeModule_T {
	EngineHandle handle;
	ComputeModuleType type;



}ComputeModule_T;

typedef struct Renderer_T {
	EngineHandle handle;

	uint32_t renderModuleCount;
	RenderModule_T* renderModules;

	uint32_t renderModuleImageCount;
	ImageReference* renderModuleImages;



	VkRenderPass renderPass;
	VkFramebuffer buffer;
}Renderer_T;

typedef struct RenderChain_T {

}RenderChain_T;