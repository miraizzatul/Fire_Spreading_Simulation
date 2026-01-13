// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Mira_Izzatul/Public/FireManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFireManager() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UDecalComponent_NoRegister();
MIRA_IZZATUL_API UClass* Z_Construct_UClass_AActorSpawner_NoRegister();
MIRA_IZZATUL_API UClass* Z_Construct_UClass_AFireManager();
MIRA_IZZATUL_API UClass* Z_Construct_UClass_AFireManager_NoRegister();
MIRA_IZZATUL_API UEnum* Z_Construct_UEnum_Mira_Izzatul_EFireState();
MIRA_IZZATUL_API UScriptStruct* Z_Construct_UScriptStruct_FFireInstanceData();
UPackage* Z_Construct_UPackage__Script_Mira_Izzatul();
// End Cross Module References

// Begin Enum EFireState
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFireState;
static UEnum* EFireState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFireState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFireState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Mira_Izzatul_EFireState, (UObject*)Z_Construct_UPackage__Script_Mira_Izzatul(), TEXT("EFireState"));
	}
	return Z_Registration_Info_UEnum_EFireState.OuterSingleton;
}
template<> MIRA_IZZATUL_API UEnum* StaticEnum<EFireState>()
{
	return EFireState_StaticEnum();
}
struct Z_Construct_UEnum_Mira_Izzatul_EFireState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Burning.Name", "EFireState::Burning" },
		{ "Burnt.Name", "EFireState::Burnt" },
		{ "Fresh.Name", "EFireState::Fresh" },
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFireState::Fresh", (int64)EFireState::Fresh },
		{ "EFireState::Burning", (int64)EFireState::Burning },
		{ "EFireState::Burnt", (int64)EFireState::Burnt },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Mira_Izzatul_EFireState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Mira_Izzatul,
	nullptr,
	"EFireState",
	"EFireState",
	Z_Construct_UEnum_Mira_Izzatul_EFireState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Mira_Izzatul_EFireState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Mira_Izzatul_EFireState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Mira_Izzatul_EFireState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Mira_Izzatul_EFireState()
{
	if (!Z_Registration_Info_UEnum_EFireState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFireState.InnerSingleton, Z_Construct_UEnum_Mira_Izzatul_EFireState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFireState.InnerSingleton;
}
// End Enum EFireState

// Begin ScriptStruct FFireInstanceData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FireInstanceData;
class UScriptStruct* FFireInstanceData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FireInstanceData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FireInstanceData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFireInstanceData, (UObject*)Z_Construct_UPackage__Script_Mira_Izzatul(), TEXT("FireInstanceData"));
	}
	return Z_Registration_Info_UScriptStruct_FireInstanceData.OuterSingleton;
}
template<> MIRA_IZZATUL_API UScriptStruct* StaticStruct<FFireInstanceData>()
{
	return FFireInstanceData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FFireInstanceData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Spawner_MetaData[] = {
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireState_MetaData[] = {
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ElapsedTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastUpdateTime_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// World time when this instance was last updated\n" },
#endif
		{ "ModuleRelativePath", "Public/FireManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World time when this instance was last updated" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceIndex_MetaData[] = {
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedLocation_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Cached world location (update if the instance moves)\n" },
#endif
		{ "ModuleRelativePath", "Public/FireManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached world location (update if the instance moves)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Spawner;
	static const UECodeGen_Private::FBytePropertyParams NewProp_FireState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FireState;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ElapsedTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LastUpdateTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InstanceIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFireInstanceData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_Spawner = { "Spawner", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFireInstanceData, Spawner), Z_Construct_UClass_AActorSpawner_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Spawner_MetaData), NewProp_Spawner_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_FireState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_FireState = { "FireState", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFireInstanceData, FireState), Z_Construct_UEnum_Mira_Izzatul_EFireState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireState_MetaData), NewProp_FireState_MetaData) }; // 2678549243
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_ElapsedTime = { "ElapsedTime", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFireInstanceData, ElapsedTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ElapsedTime_MetaData), NewProp_ElapsedTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_LastUpdateTime = { "LastUpdateTime", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFireInstanceData, LastUpdateTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastUpdateTime_MetaData), NewProp_LastUpdateTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_InstanceIndex = { "InstanceIndex", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFireInstanceData, InstanceIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceIndex_MetaData), NewProp_InstanceIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_CachedLocation = { "CachedLocation", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFireInstanceData, CachedLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedLocation_MetaData), NewProp_CachedLocation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFireInstanceData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_Spawner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_FireState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_FireState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_ElapsedTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_LastUpdateTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_InstanceIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewProp_CachedLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFireInstanceData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFireInstanceData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Mira_Izzatul,
	nullptr,
	&NewStructOps,
	"FireInstanceData",
	Z_Construct_UScriptStruct_FFireInstanceData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFireInstanceData_Statics::PropPointers),
	sizeof(FFireInstanceData),
	alignof(FFireInstanceData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFireInstanceData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFireInstanceData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFireInstanceData()
{
	if (!Z_Registration_Info_UScriptStruct_FireInstanceData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FireInstanceData.InnerSingleton, Z_Construct_UScriptStruct_FFireInstanceData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FireInstanceData.InnerSingleton;
}
// End ScriptStruct FFireInstanceData

// Begin Class AFireManager Function CalculateWindDirection
struct Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics
{
	struct FireManager_eventCalculateWindDirection_Parms
	{
		float WindAngleDegrees;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WindAngleDegrees;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::NewProp_WindAngleDegrees = { "WindAngleDegrees", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FireManager_eventCalculateWindDirection_Parms, WindAngleDegrees), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::NewProp_WindAngleDegrees,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFireManager, nullptr, "CalculateWindDirection", nullptr, nullptr, Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::FireManager_eventCalculateWindDirection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::FireManager_eventCalculateWindDirection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFireManager_CalculateWindDirection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFireManager_CalculateWindDirection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFireManager::execCalculateWindDirection)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_WindAngleDegrees);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CalculateWindDirection(Z_Param_WindAngleDegrees);
	P_NATIVE_END;
}
// End Class AFireManager Function CalculateWindDirection

// Begin Class AFireManager Function SetSimulationRunning
struct Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics
{
	struct FireManager_eventSetSimulationRunning_Parms
	{
		bool bRun;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bRun_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRun;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::NewProp_bRun_SetBit(void* Obj)
{
	((FireManager_eventSetSimulationRunning_Parms*)Obj)->bRun = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::NewProp_bRun = { "bRun", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FireManager_eventSetSimulationRunning_Parms), &Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::NewProp_bRun_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::NewProp_bRun,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFireManager, nullptr, "SetSimulationRunning", nullptr, nullptr, Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::FireManager_eventSetSimulationRunning_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::FireManager_eventSetSimulationRunning_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFireManager_SetSimulationRunning()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFireManager_SetSimulationRunning_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFireManager::execSetSimulationRunning)
{
	P_GET_UBOOL(Z_Param_bRun);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSimulationRunning(Z_Param_bRun);
	P_NATIVE_END;
}
// End Class AFireManager Function SetSimulationRunning

// Begin Class AFireManager Function ToggleWindVisual
struct Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics
{
	struct FireManager_eventToggleWindVisual_Parms
	{
		bool bOn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bOn_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::NewProp_bOn_SetBit(void* Obj)
{
	((FireManager_eventToggleWindVisual_Parms*)Obj)->bOn = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::NewProp_bOn = { "bOn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FireManager_eventToggleWindVisual_Parms), &Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::NewProp_bOn_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::NewProp_bOn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFireManager, nullptr, "ToggleWindVisual", nullptr, nullptr, Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::FireManager_eventToggleWindVisual_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::FireManager_eventToggleWindVisual_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFireManager_ToggleWindVisual()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFireManager_ToggleWindVisual_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFireManager::execToggleWindVisual)
{
	P_GET_UBOOL(Z_Param_bOn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleWindVisual(Z_Param_bOn);
	P_NATIVE_END;
}
// End Class AFireManager Function ToggleWindVisual

// Begin Class AFireManager Function UpdateNewWindSpeed
struct Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics
{
	struct FireManager_eventUpdateNewWindSpeed_Parms
	{
		float Speed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FireManager_eventUpdateNewWindSpeed_Parms, Speed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::NewProp_Speed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFireManager, nullptr, "UpdateNewWindSpeed", nullptr, nullptr, Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::FireManager_eventUpdateNewWindSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::FireManager_eventUpdateNewWindSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFireManager::execUpdateNewWindSpeed)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Speed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateNewWindSpeed(Z_Param_Speed);
	P_NATIVE_END;
}
// End Class AFireManager Function UpdateNewWindSpeed

// Begin Class AFireManager
void AFireManager::StaticRegisterNativesAFireManager()
{
	UClass* Class = AFireManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CalculateWindDirection", &AFireManager::execCalculateWindDirection },
		{ "SetSimulationRunning", &AFireManager::execSetSimulationRunning },
		{ "ToggleWindVisual", &AFireManager::execToggleWindVisual },
		{ "UpdateNewWindSpeed", &AFireManager::execUpdateNewWindSpeed },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFireManager);
UClass* Z_Construct_UClass_AFireManager_NoRegister()
{
	return AFireManager::StaticClass();
}
struct Z_Construct_UClass_AFireManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "FireManager.h" },
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSimulationRunning_MetaData[] = {
		{ "Category", "Fire Settings" },
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_spreadRadius_MetaData[] = {
		{ "Category", "Fire Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//in cm(2cm default)\n" },
#endif
		{ "ModuleRelativePath", "Public/FireManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "in cm(2cm default)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_spreadChance_MetaData[] = {
		{ "Category", "Fire Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//40% chance\n" },
#endif
		{ "ModuleRelativePath", "Public/FireManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "40% chance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_windDirection_MetaData[] = {
		{ "Category", "Fire Settings" },
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_windSpeed_MetaData[] = {
		{ "Category", "Fire Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// in m/s\n" },
#endif
		{ "ModuleRelativePath", "Public/FireManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "in m/s" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_burnDuration_MetaData[] = {
		{ "Category", "Fire Settings" },
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsWindFXVisible_MetaData[] = {
		{ "Category", "Fire Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// seconds\n" },
#endif
		{ "ModuleRelativePath", "Public/FireManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "seconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fireInstances_MetaData[] = {
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WindDecalComponent_MetaData[] = {
		{ "Category", "Decals" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/FireManager.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bIsSimulationRunning_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSimulationRunning;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_spreadRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_spreadChance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_windDirection;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_windSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_burnDuration;
	static void NewProp_bIsWindFXVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsWindFXVisible;
	static const UECodeGen_Private::FStructPropertyParams NewProp_fireInstances_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_fireInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WindDecalComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AFireManager_CalculateWindDirection, "CalculateWindDirection" }, // 2562062727
		{ &Z_Construct_UFunction_AFireManager_SetSimulationRunning, "SetSimulationRunning" }, // 282877059
		{ &Z_Construct_UFunction_AFireManager_ToggleWindVisual, "ToggleWindVisual" }, // 135747772
		{ &Z_Construct_UFunction_AFireManager_UpdateNewWindSpeed, "UpdateNewWindSpeed" }, // 3733839567
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFireManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_AFireManager_Statics::NewProp_bIsSimulationRunning_SetBit(void* Obj)
{
	((AFireManager*)Obj)->bIsSimulationRunning = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFireManager_Statics::NewProp_bIsSimulationRunning = { "bIsSimulationRunning", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFireManager), &Z_Construct_UClass_AFireManager_Statics::NewProp_bIsSimulationRunning_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSimulationRunning_MetaData), NewProp_bIsSimulationRunning_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFireManager_Statics::NewProp_spreadRadius = { "spreadRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireManager, spreadRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_spreadRadius_MetaData), NewProp_spreadRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFireManager_Statics::NewProp_spreadChance = { "spreadChance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireManager, spreadChance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_spreadChance_MetaData), NewProp_spreadChance_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFireManager_Statics::NewProp_windDirection = { "windDirection", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireManager, windDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_windDirection_MetaData), NewProp_windDirection_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFireManager_Statics::NewProp_windSpeed = { "windSpeed", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireManager, windSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_windSpeed_MetaData), NewProp_windSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFireManager_Statics::NewProp_burnDuration = { "burnDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireManager, burnDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_burnDuration_MetaData), NewProp_burnDuration_MetaData) };
void Z_Construct_UClass_AFireManager_Statics::NewProp_bIsWindFXVisible_SetBit(void* Obj)
{
	((AFireManager*)Obj)->bIsWindFXVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFireManager_Statics::NewProp_bIsWindFXVisible = { "bIsWindFXVisible", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFireManager), &Z_Construct_UClass_AFireManager_Statics::NewProp_bIsWindFXVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsWindFXVisible_MetaData), NewProp_bIsWindFXVisible_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFireManager_Statics::NewProp_fireInstances_Inner = { "fireInstances", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFireInstanceData, METADATA_PARAMS(0, nullptr) }; // 1962174022
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFireManager_Statics::NewProp_fireInstances = { "fireInstances", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireManager, fireInstances), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fireInstances_MetaData), NewProp_fireInstances_MetaData) }; // 1962174022
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFireManager_Statics::NewProp_WindDecalComponent = { "WindDecalComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFireManager, WindDecalComponent), Z_Construct_UClass_UDecalComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WindDecalComponent_MetaData), NewProp_WindDecalComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFireManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireManager_Statics::NewProp_bIsSimulationRunning,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireManager_Statics::NewProp_spreadRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireManager_Statics::NewProp_spreadChance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireManager_Statics::NewProp_windDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireManager_Statics::NewProp_windSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireManager_Statics::NewProp_burnDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireManager_Statics::NewProp_bIsWindFXVisible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireManager_Statics::NewProp_fireInstances_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireManager_Statics::NewProp_fireInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFireManager_Statics::NewProp_WindDecalComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFireManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFireManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Mira_Izzatul,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFireManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFireManager_Statics::ClassParams = {
	&AFireManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AFireManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AFireManager_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFireManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AFireManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFireManager()
{
	if (!Z_Registration_Info_UClass_AFireManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFireManager.OuterSingleton, Z_Construct_UClass_AFireManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFireManager.OuterSingleton;
}
template<> MIRA_IZZATUL_API UClass* StaticClass<AFireManager>()
{
	return AFireManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFireManager);
AFireManager::~AFireManager() {}
// End Class AFireManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EFireState_StaticEnum, TEXT("EFireState"), &Z_Registration_Info_UEnum_EFireState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2678549243U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FFireInstanceData::StaticStruct, Z_Construct_UScriptStruct_FFireInstanceData_Statics::NewStructOps, TEXT("FireInstanceData"), &Z_Registration_Info_UScriptStruct_FireInstanceData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFireInstanceData), 1962174022U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFireManager, AFireManager::StaticClass, TEXT("AFireManager"), &Z_Registration_Info_UClass_AFireManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFireManager), 3094111797U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_3472161455(TEXT("/Script/Mira_Izzatul"),
	Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
