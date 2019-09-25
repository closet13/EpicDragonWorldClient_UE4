// Copyright (c) 2018-current Pantelis Andrianakis

using UnrealBuildTool;
using System.Collections.Generic;

public class EpicDragonWorldTarget : TargetRules
{
	public EpicDragonWorldTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("EpicDragonWorld");
	}
}
