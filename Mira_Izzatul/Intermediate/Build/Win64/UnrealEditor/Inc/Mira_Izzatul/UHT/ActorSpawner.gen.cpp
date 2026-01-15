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
MIRA_IZZATUL_API UFunction* Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature();
MIRA_IZZATUL_API UScriptStruct* Z_Construct_UScriptStruct_FCandidate();
UPackage* Z_Construct_UPackage__Script_Mira_Izzatul();
// End Cross Module References

// Begin ScriptStruct FCandidate
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Candidate;
class UScriptStruct* FCandidate::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Candidate.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Candidate.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCandidate, (UObject*)Z_Construct_UPackage__Script_Mira_Izzatul(), TEXT("Candidate"));
	}
	return Z_Registration_Info_UScriptStruct_Candidate.OuterSingleton;
}
template<> MIRA_IZZATUL_API UScriptStruct* StaticStruct<FCandidate>()
{
	return FCandidate::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCandidate_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Candidate struct with per-candidate bounds\n" },
#endif
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Candidate struct with per-candidate bounds" },
#endif
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCandidate>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCandidate_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Mira_Izzatul,
	nullptr,
	&NewStructOps,
	"Candidate",
	nullptr,
	0,
	sizeof(FCandidate),
	alignof(FCandidate),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCandidate_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCandidate_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCandidate()
{
	if (!Z_Registration_Info_UScriptStruct_Candidate.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Candidate.InnerSingleton, Z_Construct_UScriptStruct_FCandidate_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_Candidate.InnerSingleton;
}
// End ScriptStruct FCandidate

// Begin Delegate FOnMaxSpawnableChanged
struct Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics
{
	struct ActorSpawner_eventOnMaxSpawnableChanged_Parms
	{
		int32 MaxSpawnable;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delegate broadcast when MaxSpawnable is (re)computed\n" },
#endif
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate broadcast when MaxSpawnable is (re)computed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxSpawnable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::NewProp_MaxSpawnable = { "MaxSpawnable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ActorSpawner_eventOnMaxSpawnableChanged_Parms, MaxSpawnable), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::NewProp_MaxSpawnable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorSpawner, nullptr, "OnMaxSpawnableChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::ActorSpawner_eventOnMaxSpawnableChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::ActorSpawner_eventOnMaxSpawnableChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void AActorSpawner::FOnMaxSpawnableChanged_DelegateWrapper(const FMulticastScriptDelegate& OnMaxSpawnableChanged, int32 MaxSpawnable)
{
	struct ActorSpawner_eventOnMaxSpawnableChanged_Parms
	{
		int32 MaxSpawnable;
	};
	ActorSpawner_eventOnMaxSpawnableChanged_Parms Parms;
	Parms.MaxSpawnable=MaxSpawnable;
	OnMaxSpawnableChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnMaxSpawnableChanged

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

// Begin Class AActorSpawner Function GetMaxSpawnable
struct Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics
{
	struct ActorSpawner_eventGetMaxSpawnable_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Expose MaxSpawnable to Blueprints via a getter\n" },
#endif
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Expose MaxSpawnable to Blueprints via a getter" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ActorSpawner_eventGetMaxSpawnable_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorSpawner, nullptr, "GetMaxSpawnable", nullptr, nullptr, Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::PropPointers), sizeof(Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::ActorSpawner_eventGetMaxSpawnable_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::Function_MetaDataParams), Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::ActorSpawner_eventGetMaxSpawnable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AActorSpawner::execGetMaxSpawnable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetMaxSpawnable();
	P_NATIVE_END;
}
// End Class AActorSpawner Function GetMaxSpawnable

// Begin Class AActorSpawner Function RecomputeCachedCandidates
struct Z_Construct_UFunction_AActorSpawner_RecomputeCachedCandidates_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Recompute cached candidate positions and update MaxSpawnable. Call when level streaming finishes.\n" },
#endif
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Recompute cached candidate positions and update MaxSpawnable. Call when level streaming finishes." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActorSpawner_RecomputeCachedCandidates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorSpawner, nullptr, "RecomputeCachedCandidates", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AActorSpawner_RecomputeCachedCandidates_Statics::Function_MetaDataParams), Z_Construct_UFunction_AActorSpawner_RecomputeCachedCandidates_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AActorSpawner_RecomputeCachedCandidates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActorSpawner_RecomputeCachedCandidates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AActorSpawner::execRecomputeCachedCandidates)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RecomputeCachedCandidates();
	P_NATIVE_END;
}
// End Class AActorSpawner Function RecomputeCachedCandidates

// Begin Class AActorSpawner
void AActorSpawner::StaticRegisterNativesAActorSpawner()
{
	UClass* Class = AActorSpawner::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GenerateScene", &AActorSpawner::execGenerateScene },
		{ "GetMaxSpawnable", &AActorSpawner::execGetMaxSpawnable },
		{ "RecomputeCachedCandidates", &AActorSpawner::execRecomputeCachedCandidates },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMaxSpawnableChanged_MetaData[] = {
		{ "Category", "Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Blueprint event to receive MaxSpawnable updates\n" },
#endif
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event to receive MaxSpawnable updates" },
#endif
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedCandidates_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Cached candidate positions computed on BeginPlay using the minimum allowed gap\n" },
#endif
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached candidate positions computed on BeginPlay using the minimum allowed gap" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxSpawnable_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Maximum spawnable count computed at BeginPlay\n" },
#endif
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum spawnable count computed at BeginPlay" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialMinGap_MetaData[] = {
		{ "Category", "Spawning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Adaptive spawning parameters (exposed so designers can tweak)\n" },
#endif
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adaptive spawning parameters (exposed so designers can tweak)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinAllowedGap_MetaData[] = {
		{ "Category", "Spawning" },
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAttempts_MetaData[] = {
		{ "Category", "Spawning" },
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RelaxationFactor_MetaData[] = {
		{ "Category", "Spawning" },
		{ "ModuleRelativePath", "Public/ActorSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMaxSpawnableChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_objMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_fireManager;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HISM;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedCandidates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CachedCandidates;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxSpawnable;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InitialMinGap;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinAllowedGap;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAttempts;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RelaxationFactor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AActorSpawner_GenerateScene, "GenerateScene" }, // 3042212074
		{ &Z_Construct_UFunction_AActorSpawner_GetMaxSpawnable, "GetMaxSpawnable" }, // 2533620729
		{ &Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature, "OnMaxSpawnableChanged__DelegateSignature" }, // 32247395
		{ &Z_Construct_UFunction_AActorSpawner_RecomputeCachedCandidates, "RecomputeCachedCandidates" }, // 3360390743
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AActorSpawner>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_OnMaxSpawnableChanged = { "OnMaxSpawnableChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, OnMaxSpawnableChanged), Z_Construct_UDelegateFunction_AActorSpawner_OnMaxSpawnableChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMaxSpawnableChanged_MetaData), NewProp_OnMaxSpawnableChanged_MetaData) }; // 32247395
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_objMesh = { "objMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, objMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_objMesh_MetaData), NewProp_objMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_fireManager = { "fireManager", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, fireManager), Z_Construct_UClass_AFireManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fireManager_MetaData), NewProp_fireManager_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_HISM = { "HISM", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, HISM), Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HISM_MetaData), NewProp_HISM_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_CachedCandidates_Inner = { "CachedCandidates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCandidate, METADATA_PARAMS(0, nullptr) }; // 925215059
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_CachedCandidates = { "CachedCandidates", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, CachedCandidates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedCandidates_MetaData), NewProp_CachedCandidates_MetaData) }; // 925215059
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_MaxSpawnable = { "MaxSpawnable", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, MaxSpawnable), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxSpawnable_MetaData), NewProp_MaxSpawnable_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_InitialMinGap = { "InitialMinGap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, InitialMinGap), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialMinGap_MetaData), NewProp_InitialMinGap_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_MinAllowedGap = { "MinAllowedGap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, MinAllowedGap), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinAllowedGap_MetaData), NewProp_MinAllowedGap_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_MaxAttempts = { "MaxAttempts", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, MaxAttempts), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAttempts_MetaData), NewProp_MaxAttempts_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActorSpawner_Statics::NewProp_RelaxationFactor = { "RelaxationFactor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActorSpawner, RelaxationFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RelaxationFactor_MetaData), NewProp_RelaxationFactor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AActorSpawner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_OnMaxSpawnableChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_objMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_fireManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_HISM,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_CachedCandidates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_CachedCandidates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_MaxSpawnable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_InitialMinGap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_MinAllowedGap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_MaxAttempts,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorSpawner_Statics::NewProp_RelaxationFactor,
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
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCandidate::StaticStruct, Z_Construct_UScriptStruct_FCandidate_Statics::NewStructOps, TEXT("Candidate"), &Z_Registration_Info_UScriptStruct_Candidate, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCandidate), 925215059U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AActorSpawner, AActorSpawner::StaticClass, TEXT("AActorSpawner"), &Z_Registration_Info_UClass_AActorSpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AActorSpawner), 1577160262U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_4078847962(TEXT("/Script/Mira_Izzatul"),
	Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
