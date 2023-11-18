#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ramp.generated.h"

class UProceduralMeshComponent;
class UMaterialInterface;

UCLASS()
class MUDASSAR_API Aramp : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    Aramp();

protected:
    // Called when the game starts or when spawned
    virtual void OnConstruction(const FTransform& Transform) override;

    UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
    UMaterialInterface* Material;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    UProceduralMeshComponent* ProceduralMesh;

    void CreateRampMesh();
};
