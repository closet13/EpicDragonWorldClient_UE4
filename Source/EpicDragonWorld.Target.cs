

using UnrealBuildTool;
using System.Collections.Generic;

public class EpicDragonWorldTarget : TargetRules
{
	public EpicDragonWorldTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "EpicDragonWorld" } );
	}
}
