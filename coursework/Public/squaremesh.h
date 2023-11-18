// squaremesh.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "squaremesh.generated.h"

class UProceduralMeshComponent;
class UMaterialInterface;

UCLASS()
class MUDASSAR_API Asquaremesh : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	Asquaremesh();

protected:
	// Called when the game starts or when spawned
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	TArray<FVector> Vertices;

	UPROPERTY(EditAnywhere)
	TArray<int> Triangles;

	UPROPERTY(EditAnywhere)
	TArray<FVector2D> UV0;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* ProceduralMesh;
};
