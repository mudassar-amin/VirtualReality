


#include "cube.h"
#include "ProceduralMeshComponent.h"


Acube::Acube()
{
	/

	PrimaryActorTick.bCanEverTick = false;
	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMesh");
	RootComponent = ProceduralMesh;

}



void Acube::OnConstruction(const FTransform& Transform)
{


	Super::OnConstruction(Transform);

	
	ProceduralMesh->ClearAllMeshSections();

	// Define vertices for a right-angled triangle
	FVector BottomLeft = FVector(0, 0, 0);
	FVector BottomRight = FVector(100, 0, 0); // Base of the triangle
	FVector Top = FVector(0, 0, 100); // Height of the triangle

	Vertices.Empty();
	Triangles.Empty();
	UV0.Empty();

	Vertices.Add(BottomLeft);
	Vertices.Add(BottomRight);
	Vertices.Add(Top);

	// Define triangles to create the triangle
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	
	UV0.Add(FVector2D(0, 0)); // Bottom-left corner
	UV0.Add(FVector2D(1, 0)); // Bottom-right corner
	UV0.Add(FVector2D(0, 1)); // Top corner

	
	ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), UV0, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
	ProceduralMesh->SetMaterial(0, Material);

	
	FVector CubeFrontTopLeft = FVector(0, -50, 100);
	FVector CubeFrontTopRight = FVector(100, -50, 100);
	FVector CubeFrontBottomLeft = FVector(0, -50, 0);
	FVector CubeFrontBottomRight = FVector(100, -50, 0);
	FVector CubeBackTopLeft = FVector(0, 50, 100);
	FVector CubeBackTopRight = FVector(100, 50, 100);
	FVector CubeBackBottomLeft = FVector(0, 50, 0);
	FVector CubeBackBottomRight = FVector(100, 50, 0);

	Vertices.Empty();
	Triangles.Empty();
	UV0.Empty();

	// Front face
	Vertices.Add(CubeFrontTopLeft);
	Vertices.Add(CubeFrontTopRight);
	Vertices.Add(CubeFrontBottomLeft);
	Vertices.Add(CubeFrontBottomRight);

	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(1);
	Triangles.Add(3);
	Triangles.Add(2);

	// Back face
	Vertices.Add(CubeBackTopLeft);
	Vertices.Add(CubeBackTopRight);
	Vertices.Add(CubeBackBottomLeft);
	Vertices.Add(CubeBackBottomRight);

	Triangles.Add(4);
	Triangles.Add(6);
	Triangles.Add(5);
	Triangles.Add(5);
	Triangles.Add(6);
	Triangles.Add(7);

	// Left face
	Triangles.Add(0);
	Triangles.Add(2);
	Triangles.Add(4);
	Triangles.Add(2);
	Triangles.Add(6);
	Triangles.Add(4);

	// Right face
	Triangles.Add(1);
	Triangles.Add(5);
	Triangles.Add(3);
	Triangles.Add(3);
	Triangles.Add(5);
	Triangles.Add(7);

	// Top face
	Triangles.Add(0);
	Triangles.Add(4);
	Triangles.Add(1);
	Triangles.Add(1);
	Triangles.Add(4);
	Triangles.Add(5);

	// Bottom face
	Triangles.Add(2);
	Triangles.Add(3);
	Triangles.Add(6);
	Triangles.Add(3);
	Triangles.Add(7);
	Triangles.Add(6);

	
	UV0.Add(FVector2D(0, 0)); // Front top left
	UV0.Add(FVector2D(1, 0)); // Front top right
	UV0.Add(FVector2D(0, 1)); // Front bottom left
	UV0.Add(FVector2D(1, 1)); // Front bottom right
	UV0.Add(FVector2D(0, 0)); // Back top left
	UV0.Add(FVector2D(1, 0)); // Back top right
	UV0.Add(FVector2D(0, 1)); // Back bottom left
	UV0.Add(FVector2D(1, 1)); // Back bottom right

	// Create the procedural mesh for the cube
	ProceduralMesh->CreateMeshSection(1, Vertices, Triangles, TArray<FVector>(), UV0, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
	ProceduralMesh->SetMaterial(1, Material);


}





// Called when the game starts or when spawned
void Acube::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void Acube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

