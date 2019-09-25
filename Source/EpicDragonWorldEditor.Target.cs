// Copyright (c) 2018-current Pantelis Andrianakis

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
