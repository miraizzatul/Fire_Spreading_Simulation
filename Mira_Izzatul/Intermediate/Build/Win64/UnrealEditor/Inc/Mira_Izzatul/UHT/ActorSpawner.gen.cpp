// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mira_Izzatul/Public/ActorSpawner.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorSpawner() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
MIRA_IZZATUL_API UClass* Z_Construct_UClass_AActorSpawner();
MIRA_IZZATUL_API UClass* Z_Construct_UClass_AActorSpawner_NoRegister();
MIRA_IZZATUL_API UClass* Z_Construct_UClass_AFireManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_Mira_Izzatul();
// End Cross Module References

// Begin Class AActorSpawner Function GenerateScene
struct Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics
{
	struct ActorSpawner_eventGenerateScene_Parms
	{
		int32 NumActors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spawning" },
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumActors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::NewProp_NumActors = { "NumActors", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ActorSpawner_eventGenerateScene_Parms, NumActors), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::NewProp_NumActors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorSpawner, nullptr, "GenerateScene", nullptr, nullptr, Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::PropPointers), sizeof(Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::ActorSpawner_eventGenerateScene_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::Function_MetaDataParams), Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::ActorSpawner_eventGenerateScene_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AActorSpawner_GenerateScene()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActorSpawner_GenerateScene_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AActorSpawner::execGenerateScene)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NumActors);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GenerateScene(Z_Param_NumActors);
	P_NATIVE_END;
}
// End Class AActorSpawner Function GenerateScene

// Begin Class AActorSpawner
void AActorSpawner::StaticRegisterNativesAActorSpawner()
{
	UClass* Class = AActorSpawner::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GenerateScene", &AActorSpawner::execGenerateScene },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AActorSpawner);
UClass* Z_Construct_UClass_AActorSpawner_NoRegister()
{
	return AActorSpawner::StaticClass();
}
struct Z_Construct_UClass_AActorSpawner_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ActorSpawner.h" },
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_objMesh_MetaData[] = {
		{ "Category", "Spawning" },
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fireManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HISM_MetaData[] = {
		{ "Category", "Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** HISM component for instancing */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HISM component for instancing" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_objMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_fireManager;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HISM;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AActorSpawner_GenerateScene, "GenerateScene" }, // 3042212074
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AActorSpawner>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_objMesh = { "objMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, objMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_objMesh_MetaData), NewProp_objMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_fireManager = { "fireManager", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, fireManager), Z_Construct_UClass_AFireManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fireManager_MetaData), NewProp_fireManager_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_HISM = { "HISM", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, HISM), Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HISM_MetaData), NewProp_HISM_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AActorSpawner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_objMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_fireManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_HISM,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActorSpawner_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AActorSpawner_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Mira_Izzatul,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActorSpawner_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AActorSpawner_Statics::ClassParams = {
	&AActorSpawner::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AActorSpawner_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AActorSpawner_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AActorSpawner_Statics::Class_MetaDataParams), Z_Construct_UClass_AActorSpawner_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AActorSpawner()
{
	if (!Z_Registration_Info_UClass_AActorSpawner.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AActorSpawner.OuterSingleton, Z_Construct_UClass_AActorSpawner_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AActorSpawner.OuterSingleton;
}
template<> MIRA_IZZATUL_API UClass* StaticClass<AActorSpawner>()
{
	return AActorSpawner::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AActorSpawner);
AActorSpawner::~AActorSpawner() {}
// End Class AActorSpawner

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AActorSpawner, AActorSpawner::StaticClass, TEXT("AActorSpawner"), &Z_Registration_Info_UClass_AActorSpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AActorSpawner), 130928974U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_3046115314(TEXT("/Script/Mira_Izzatul"),
	Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
