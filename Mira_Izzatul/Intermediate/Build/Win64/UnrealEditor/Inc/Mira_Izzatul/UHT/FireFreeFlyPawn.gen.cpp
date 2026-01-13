// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mira_Izzatul/Public/FireFreeFlyPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFireFreeFlyPawn() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UFloatingPawnMovement_NoRegister();
MIRA_IZZATUL_API UClass* Z_Construct_UClass_AFireFreeFlyPawn();
MIRA_IZZATUL_API UClass* Z_Construct_UClass_AFireFreeFlyPawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Mira_Izzatul();
// End Cross Module References

// Begin Class AFireFreeFlyPawn
void AFireFreeFlyPawn::StaticRegisterNativesAFireFreeFlyPawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFireFreeFlyPawn);
UClass* Z_Construct_UClass_AFireFreeFlyPawn_NoRegister()
{
	return AFireFreeFlyPawn::StaticClass();
}
struct Z_Construct_UClass_AFireFreeFlyPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "FireFreeFlyPawn.h" },
		{ "ModuleRelativePath", "Public/FireFreeFlyPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "FireFreeFlyPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/FireFreeFlyPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Movement_MetaData[] = {
		{ "Category", "FireFreeFlyPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/FireFreeFlyPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinBounds_MetaData[] = {
		{ "Category", "Bounds" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Movement bounds\n" },
#endif
		{ "ModuleRelativePath", "Public/FireFreeFlyPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Movement bounds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxBounds_MetaData[] = {
		{ "Category", "Bounds" },
		{ "ModuleRelativePath", "Public/FireFreeFlyPawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Movement;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MinBounds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MaxBounds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFireFreeFlyPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFireFreeFlyPawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireFreeFlyPawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFireFreeFlyPawn_Statics::NewProp_Movement = { "Movement", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireFreeFlyPawn, Movement), Z_Construct_UClass_UFloatingPawnMovement_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Movement_MetaData), NewProp_Movement_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFireFreeFlyPawn_Statics::NewProp_MinBounds = { "MinBounds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireFreeFlyPawn, MinBounds), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinBounds_MetaData), NewProp_MinBounds_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFireFreeFlyPawn_Statics::NewProp_MaxBounds = { "MaxBounds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireFreeFlyPawn, MaxBounds), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxBounds_MetaData), NewProp_MaxBounds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFireFreeFlyPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireFreeFlyPawn_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireFreeFlyPawn_Statics::NewProp_Movement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireFreeFlyPawn_Statics::NewProp_MinBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireFreeFlyPawn_Statics::NewProp_MaxBounds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFireFreeFlyPawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFireFreeFlyPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_Mira_Izzatul,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFireFreeFlyPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFireFreeFlyPawn_Statics::ClassParams = {
	&AFireFreeFlyPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFireFreeFlyPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFireFreeFlyPawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFireFreeFlyPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AFireFreeFlyPawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFireFreeFlyPawn()
{
	if (!Z_Registration_Info_UClass_AFireFreeFlyPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFireFreeFlyPawn.OuterSingleton, Z_Construct_UClass_AFireFreeFlyPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFireFreeFlyPawn.OuterSingleton;
}
template<> MIRA_IZZATUL_API UClass* StaticClass<AFireFreeFlyPawn>()
{
	return AFireFreeFlyPawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFireFreeFlyPawn);
AFireFreeFlyPawn::~AFireFreeFlyPawn() {}
// End Class AFireFreeFlyPawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireFreeFlyPawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFireFreeFlyPawn, AFireFreeFlyPawn::StaticClass, TEXT("AFireFreeFlyPawn"), &Z_Registration_Info_UClass_AFireFreeFlyPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFireFreeFlyPawn), 1572747764U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireFreeFlyPawn_h_2034464240(TEXT("/Script/Mira_Izzatul"),
	Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireFreeFlyPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireFreeFlyPawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
