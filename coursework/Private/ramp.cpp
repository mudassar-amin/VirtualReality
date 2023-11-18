#include "ramp.h"
#include "ProceduralMeshComponent.h"
#include "Materials/MaterialInterface.h"

Aramp::Aramp()
{
    PrimaryActorTick.bCanEverTick = false;

   
    ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
    RootComponent = ProceduralMesh; 

    
    Material = nullptr;
}

void Aramp::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    CreateRampMesh();
}

void Aramp::CreateRampMesh()
{
    
    TArray<FVector> Vertices = {
    // Bottom face
     FVector(-50, -50, 0), FVector(50, -50, 0), FVector(-50, 50, 0),
     FVector(50, -50, 0), FVector(50, 50, 0), FVector(-50, 50, 0),

     
     FVector(-50, -50, 50), FVector(50, -50, 50), FVector(-50, 50, 50),
     FVector(50, 50, 50)
    };

    // Define the triangles to create the faces
    TArray<int32> Triangles = {
        
    0, 1, 2, 3, 4, 5,

    // Front side 
    0, 2, 3, 3, 2, 5,

    // Back side 
    1, 4, 5, 5, 4, 7,

    // Left side 
    0, 3, 1, 1, 3, 4,

    // Right side 
    2, 5, 7, 2, 7, 6,

    // Top back side 
    3, 5, 7, 3, 7, 4
    };

    // Create the ramp mesh
    ProceduralMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    ProceduralMesh->ClearAllMeshSections();
    ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);

    // Set the material if it's assigned
    if (Material)
    {
        ProceduralMesh->SetMaterial(0, Material);
    }
}

void Aramp::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
