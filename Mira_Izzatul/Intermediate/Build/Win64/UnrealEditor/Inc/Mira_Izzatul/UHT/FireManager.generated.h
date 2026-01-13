// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FireManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MIRA_IZZATUL_FireManager_generated_h
#error "FireManager.generated.h already included, missing '#pragma once' in FireManager.h"
#endif
#define MIRA_IZZATUL_FireManager_generated_h

#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FFireInstanceData_Statics; \
	MIRA_IZZATUL_API static class UScriptStruct* StaticStruct();


template<> MIRA_IZZATUL_API UScriptStruct* StaticStruct<struct FFireInstanceData>();

#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_56_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execToggleWindVisual); \
	DECLARE_FUNCTION(execUpdateNewWindSpeed); \
	DECLARE_FUNCTION(execCalculateWindDirection); \
	DECLARE_FUNCTION(execSetSimulationRunning);


#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_56_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFireManager(); \
	friend struct Z_Construct_UClass_AFireManager_Statics; \
public: \
	DECLARE_CLASS(AFireManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Mira_Izzatul"), NO_API) \
	DECLARE_SERIALIZER(AFireManager)


#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_56_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFireManager(AFireManager&&); \
	AFireManager(const AFireManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFireManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFireManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFireManager) \
	NO_API virtual ~AFireManager();


#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_53_PROLOG
#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_56_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_56_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_56_INCLASS_NO_PURE_DECLS \
	FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h_56_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MIRA_IZZATUL_API UClass* StaticClass<class AFireManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_FireManager_h


#define FOREACH_ENUM_EFIRESTATE(op) \
	op(EFireState::Fresh) \
	op(EFireState::Burning) \
	op(EFireState::Burnt) 

enum class EFireState : uint8;
template<> struct TIsUEnumClass<EFireState> { enum { Value = true }; };
template<> MIRA_IZZATUL_API UEnum* StaticEnum<EFireState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
