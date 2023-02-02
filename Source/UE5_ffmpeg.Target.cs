// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE5_ffmpegTarget : TargetRules
{
	public UE5_ffmpegTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;		
		ExtraModuleNames.AddRange( new string[] { "UE5_ffmpeg" } );
	}
}
