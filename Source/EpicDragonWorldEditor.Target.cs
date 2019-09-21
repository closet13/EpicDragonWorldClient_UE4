// Epic Dragon World 2018-2019

using UnrealBuildTool;
using System.Collections.Generic;

public class EpicDragonWorldEditorTarget : TargetRules
{
	public EpicDragonWorldEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("EpicDragonWorld");
	}
}
