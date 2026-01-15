// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ActorSpawner.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MIRA_IZZATUL_ActorSpawner_generated_h
#error "ActorSpawner.generated.h already included, missing '#pragma once' in ActorSpawner.h"
#endif
#define MIRA_IZZATUL_ActorSpawner_generated_h

#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_16_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCandidate_Statics; \
	MIRA_IZZATUL_API static class UScriptStruct* StaticStruct();


template<> MIRA_IZZATUL_API UScriptStruct* StaticStruct<struct FCandidate>();

#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_32_DELEGATE \
static void FOnMaxSpawnableChanged_DelegateWrapper(const FMulticastScriptDelegate& OnMaxSpawnableChanged, int32 MaxSpawnable);


#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetMaxSpawnable); \
	DECLARE_FUNCTION(execRecomputeCachedCandidates); \
	DECLARE_FUNCTION(execGenerateScene);


#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAActorSpawner(); \
	friend struct Z_Construct_UClass_AActorSpawner_Statics; \
public: \
	DECLARE_CLASS(AActorSpawner, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Mira_Izzatul"), NO_API) \
	DECLARE_SERIALIZER(AActorSpawner)


#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AActorSpawner(AActorSpawner&&); \
	AActorSpawner(const AActorSpawner&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AActorSpawner); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AActorSpawner); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AActorSpawner) \
	NO_API virtual ~AActorSpawner();


#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_23_PROLOG
#define FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_26_INCLASS_NO_PURE_DECLS \
	FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MIRA_IZZATUL_API UClass* StaticClass<class AActorSpawner>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_User_Documents_Unreal_Projects_FireSpreading_Simulation_Mira_Izzatul_Source_Mira_Izzatul_Public_ActorSpawner_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
