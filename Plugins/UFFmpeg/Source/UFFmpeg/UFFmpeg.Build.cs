// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
public class UFFmpeg : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty")); }
    }
    private string ProjectPath
    {
        get { return Directory.GetParent(ModulePath).Parent.FullName; }
    }

    public UFFmpeg(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        bIgnoreUnresolvedSymbols = true;

        if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            // PublicIncludePaths.AddRange(new string[] { Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/include")});
            PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libavcodec.a"));
            PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libavdevice.a"));
            PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libavfilter.a"));
            PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libavformat.a"));
            PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libavutil.a"));
            PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libswscale.a"));
            PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libswresample.a"));

            RuntimeDependencies.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libavcodec.so"));
            RuntimeDependencies.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libavdevice.so"));
            RuntimeDependencies.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libavfilter.so"));
            RuntimeDependencies.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libavformat.so"));
            RuntimeDependencies.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libavutil.so"));
            RuntimeDependencies.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libswscale.so"));
            RuntimeDependencies.Add(Path.Combine(ModulePath, "../../ThirdParty/ffmpeg/linux/libswresample.so"));
        }      

        PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "ffmpeg", "include"));
        PublicIncludePaths.Add(Path.Combine(Directory.GetCurrentDirectory(), "Runtime","AudioMixer","Private"));

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "AudioMixer",
				// ... add other public dependencies that you statically link with here ...
			}
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "Projects",
                "Engine",
                "RHI",
                "UnrealEd",
                "RenderCore"
				// ... add private dependencies that you statically link with here ...	
			}
            );


        OptimizeCode = CodeOptimization.InShippingBuildsOnly;
        //bEnableUndefinedIdentifierWarnings = false;

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );

    }
}
