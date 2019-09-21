// Epic Dragon World 2018-2019

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
