// Epic Dragon World 2018-2019

using UnrealBuildTool;

public class EpicDragonWorld : ModuleRules
{
	public EpicDragonWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "Sockets", "Networking" });
	}
}
