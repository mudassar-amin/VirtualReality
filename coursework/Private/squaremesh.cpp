// squaremesh.cpp
#include "squaremesh.h"
#include "ProceduralMeshComponent.h"

Asquaremesh::Asquaremesh()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create a root component if one doesn't exist
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
	ProceduralMesh->SetupAttachment(RootComponent);

	// Set up default values for Vertices, Triangles, UV0, and Material here if needed
}

void Asquaremesh::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	ProceduralMesh->ClearAllMeshSections();
	ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), UV0, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
	ProceduralMesh->SetMaterial(0, Material);
}

void Asquaremesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
