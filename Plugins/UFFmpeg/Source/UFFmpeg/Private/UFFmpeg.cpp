// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UFFmpeg.h"
#include "Unix/UnixPlatformProcess.h"
#include "Interfaces/IPluginManager.h"
#include "Core.h"

extern  "C" {
#include "libavformat/avformat.h"
}

#define LOCTEXT_NAMESPACE "FUffmpegModule"

void FUFFmpegModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	AVUtilLibrary = LoadLibrary(TEXT("avutil"));
	SWResampleLibrary = LoadLibrary(TEXT("swresample"));
	AVCodecLibrary = LoadLibrary(TEXT("avcodec"));
	AVFormatLibrary = LoadLibrary(TEXT("avformat"));
	SWScaleLibrary = LoadLibrary(TEXT("swscale"));
	PostProcLibrary = LoadLibrary(TEXT("postproc"));
	AVFilterLibrary = LoadLibrary(TEXT("avfilter"));
	AVDeviceLibrary = LoadLibrary(TEXT("avdevice"));
	Initialized = true;
}

// TODO:
// Find equivalent of FreeDllHandle for Linux Platform
// Action: The class for it was different
void FUFFmpegModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (!Initialized)
	{
		return;
	}
	// TODO:
	// Change this to a relevant function
	// Action: The class was changed to be for Unix Platform, the function is the same
	if (AVDeviceLibrary) FUnixPlatformProcess::FreeDllHandle(AVDeviceLibrary);
	if (AVFilterLibrary) FUnixPlatformProcess::FreeDllHandle(AVFilterLibrary);
	if (PostProcLibrary) FUnixPlatformProcess::FreeDllHandle(PostProcLibrary);
	if (SWScaleLibrary) FUnixPlatformProcess::FreeDllHandle(SWScaleLibrary);
	if (AVFormatLibrary) FUnixPlatformProcess::FreeDllHandle(AVFormatLibrary);
	if (AVCodecLibrary) FUnixPlatformProcess::FreeDllHandle(AVCodecLibrary);
	if (SWResampleLibrary) FUnixPlatformProcess::FreeDllHandle(SWResampleLibrary);
	if (AVUtilLibrary) FUnixPlatformProcess::FreeDllHandle(AVUtilLibrary);

	Initialized = false;
}

void* FUFFmpegModule::LoadLibrary(const FString& name)
{
	FString BaseDir = IPluginManager::Get().FindPlugin("Uffmpeg")->GetBaseDir();
	FString LibDir;
	FString extension;
	// Action: Changing it to be platform specific
	#if PLATFORM_UNIX
		extension = TEXT(".so");
		LibDir = FPaths::Combine(*BaseDir, TEXT("ThirdParty/ffmpeg/linux/"));
	#else
		// TODO: Add an error message and return
		// Throw Error
		// Handle Library Directory empty
		return nullptr;
	#endif

	if (!LibDir.IsEmpty()) {
		FString LibraryPath = FPaths::Combine(*LibDir, name + extension);
		// TODO: Fix this
		return FUnixPlatformProcess::GetDllHandle(*LibraryPath);
	}
	return nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUFFmpegModule, UFFmpeg)