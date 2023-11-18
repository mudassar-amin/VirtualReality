// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "cube.generated.h"

class UProceduralMeshComponent;
class UmaterialInterface;

UCLASS()
class MUDASSAR_API Acube : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	Acube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	TArray<FVector> Vertices;

	UPROPERTY(EditAnywhere)
	TArray<int32> Triangles;

	UPROPERTY(EditAnywhere)
	TArray<FVector2D> UV0;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	

	UPROPERTY()
	UProceduralMeshComponent* ProceduralMesh;

};
