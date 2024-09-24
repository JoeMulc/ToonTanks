// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToonTanks/TowerPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTowerPawn() {}
// Cross Module References
	TOONTANKS_API UClass* Z_Construct_UClass_ABasePawn();
	TOONTANKS_API UClass* Z_Construct_UClass_ATowerPawn();
	TOONTANKS_API UClass* Z_Construct_UClass_ATowerPawn_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ToonTanks();
// End Cross Module References
	void ATowerPawn::StaticRegisterNativesATowerPawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATowerPawn);
	UClass* Z_Construct_UClass_ATowerPawn_NoRegister()
	{
		return ATowerPawn::StaticClass();
	}
	struct Z_Construct_UClass_ATowerPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATowerPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABasePawn,
		(UObject* (*)())Z_Construct_UPackage__Script_ToonTanks,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATowerPawn_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "TowerPawn.h" },
		{ "ModuleRelativePath", "TowerPawn.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATowerPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATowerPawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATowerPawn_Statics::ClassParams = {
		&ATowerPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATowerPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATowerPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATowerPawn()
	{
		if (!Z_Registration_Info_UClass_ATowerPawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATowerPawn.OuterSingleton, Z_Construct_UClass_ATowerPawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATowerPawn.OuterSingleton;
	}
	template<> TOONTANKS_API UClass* StaticClass<ATowerPawn>()
	{
		return ATowerPawn::StaticClass();
	}
	ATowerPawn::ATowerPawn() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATowerPawn);
	ATowerPawn::~ATowerPawn() {}
	struct Z_CompiledInDeferFile_FID_Unreal_ToonTanks_ToonTanks_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_TowerPawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ToonTanks_ToonTanks_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_TowerPawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATowerPawn, ATowerPawn::StaticClass, TEXT("ATowerPawn"), &Z_Registration_Info_UClass_ATowerPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATowerPawn), 2421919170U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_ToonTanks_ToonTanks_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_TowerPawn_h_2730140972(TEXT("/Script/ToonTanks"),
		Z_CompiledInDeferFile_FID_Unreal_ToonTanks_ToonTanks_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_TowerPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_ToonTanks_ToonTanks_ToonTanksProjectSetup_4_25_ToonTanks_Source_ToonTanks_TowerPawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
