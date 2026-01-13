// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mira_Izzatul/Public/FireSpreadSpecPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFireSpreadSpecPawn() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_ASpectatorPawn();
MIRA_IZZATUL_API UClass* Z_Construct_UClass_AFireSpreadSpecPawn();
MIRA_IZZATUL_API UClass* Z_Construct_UClass_AFireSpreadSpecPawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Mira_Izzatul();
// End Cross Module References

// Begin Class AFireSpreadSpecPawn
void AFireSpreadSpecPawn::StaticRegisterNativesAFireSpreadSpecPawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFireSpreadSpecPawn);
UClass* Z_Construct_UClass_AFireSpreadSpecPawn_NoRegister()
{
	return AFireSpreadSpecPawn::StaticClass();
}
struct Z_Construct_UClass_AFireSpreadSpecPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "FireSpreadSpecPawn.h" },
		{ "ModuleRelativePath", "Public/FireSpreadSpecPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinBounds_MetaData[] = {
		{ "Category", "Bounds" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Movement bounds\n" },
#endif
		{ "ModuleRelativePath", "Public/FireSpreadSpecPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Movement bounds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxBounds_MetaData[] = {
		{ "Category", "Bounds" },
		{ "ModuleRelativePath", "Public/FireSpreadSpecPawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MinBounds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxBounds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFireSpreadSpecPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFireSpreadSpecPawn_Statics::NewProp_MinBounds = { "MinBounds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireSpreadSpecPawn, MinBounds), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinBounds_MetaData), NewProp_MinBounds_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFireSpreadSpecPawn_Statics::NewProp_MaxBounds = { "MaxBounds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireSpreadSpecPawn, MaxBounds), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxBounds_MetaData), NewProp_MaxBounds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFireSpreadSpecPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireSpreadSpecPawn_Statics::NewProp_MinBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireSpreadSpecPawn_Statics::NewProp_MaxBounds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFireSpreadSpecPawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFireSpreadSpecPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ASpectatorPawn,
	(UObject* (*)())Z_Construct_UPackage__Script_Mira_Izzatul,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFireSpreadSpecPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFireSpreadSpecPawn_Statics::ClassParams = {
	&AFireSpreadSpecPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFireSpreadSpecPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFireSpreadSpecPawn_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFireSpreadSpecPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AFireSpreadSpecPawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFireSpreadSpecPawn()
{
	if (!Z_Registration_Info_UClass_AFireSpreadSpecPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFireSpreadSpecPawn.OuterSingleton, Z_Construct_UClass_AFireSpreadSpecPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFireSpreadSpecPawn.OuterSingleton;
}
template<> MIRA_IZZATUL_API UClass* StaticClass<AFireSpreadSpecPawn>()
{
	return AFireSpreadSpecPawn::StaticClass();
}
AFireSpreadSpecPawn::AFireSpreadSpecPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFireSpreadSpecPawn);
AFireSpreadSpecPawn::~AFireSpreadSpecPawn() {}
// End Class AFireSpreadSpecPawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireSpreadSpecPawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFireSpreadSpecPawn, AFireSpreadSpecPawn::StaticClass, TEXT("AFireSpreadSpecPawn"), &Z_Registration_Info_UClass_AFireSpreadSpecPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFireSpreadSpecPawn), 127591417U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireSpreadSpecPawn_h_2942936019(TEXT("/Script/Mira_Izzatul"),
	Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireSpreadSpecPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireSpreadSpecPawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
