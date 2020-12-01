// Copyright 2020 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelEnums.h"
#include "VoxelMinimal.h"
#include "VoxelGeneratorInit.generated.h"

class AVoxelWorld;
class UVoxelMaterialCollectionBase;
class FVoxelGeneratorCache;

USTRUCT(BlueprintType)
struct VOXEL_API FVoxelGeneratorInit
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	float VoxelSize = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	int32 WorldSize = 1 << 12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	EVoxelRenderType RenderType = EVoxelRenderType::MarchingCubes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	EVoxelMaterialConfig MaterialConfig = EVoxelMaterialConfig::RGB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	const UVoxelMaterialCollectionBase* MaterialCollection = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Init")
	const AVoxelWorld* World = nullptr; // Can be null

	FVoxelGeneratorInit() = default;
	FVoxelGeneratorInit(
		float VoxelSize,
		uint32 WorldSize,
		EVoxelRenderType RenderType,
		EVoxelMaterialConfig MaterialConfig,
		const UVoxelMaterialCollectionBase* MaterialCollection,
		const AVoxelWorld* World)
		: VoxelSize(VoxelSize)
		, WorldSize(WorldSize)
		, RenderType(RenderType)
		, MaterialConfig(MaterialConfig)
		, MaterialCollection(MaterialCollection)
		, World(World)
	{
	}

	FVoxelGeneratorCache& GetGeneratorCache() const;
	void AddReferencedObjects(FReferenceCollector& Collector);

private:
	mutable TVoxelSharedPtr<FVoxelGeneratorCache> GeneratorCache;

	friend class FVoxelGeneratorCache;

public:
	VOXEL_DEPRECATED(1.2, "Seeds are now regular generator parameters")
	TMap<FName, int32> Seeds;
};

VOXEL_DEPRECATED(1.2, "Use FVoxelGeneratorInit instead of FVoxelWorldGeneratorInit.")
typedef FVoxelGeneratorInit FVoxelWorldGeneratorInit;