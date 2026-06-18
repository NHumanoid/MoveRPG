// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActor.h"

// Sets default values
AMoveActor::AMoveActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SetRootComponent(SceneRoot);
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	
	StaticMashComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMash"));
	StaticMashComp->SetupAttachment(SceneRoot);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MashAsset(TEXT("/Game/Fab/Sci-fi_Computer_CC3/sci_fi_computer_cc3/StaticMeshes/sci_fi_computer_cc3.sci_fi_computer_cc3"));
	if (MashAsset.Succeeded()) // 만약에 메시 불러오기에 성공했다면
	{
		StaticMashComp->SetStaticMesh(MashAsset.Object); //스태틱 메시 컴포넌트에 메시 설정
		
	}
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("/Game/Fab/Sci-fi_Computer_CC3/sci_fi_computer_cc3/Materials/triangle_pc.triangle_pc"));
	if (MaterialAsset.Succeeded()) // 만약에 머티리얼 불러오기에 성공했다면
	{
		StaticMashComp->SetMaterial(0, MaterialAsset.Object); //스태틱 메시 컴포넌트에 머티리얼 설정
	}
}
// Called when the game starts or when spawned
void AMoveActor::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorRotation(FRotator(0.0f, 0.0f, 90.0f));
	SetActorScale3D(FVector(2.0f));
	
	StartLocation = GetActorLocation();
	
}

// Called every frame
void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RoctionSpeed)) // 만약 회전 속도가 0이 아니면
	{
		AddActorLocalRotation(FRotator(0.0f, RoctionSpeed * DeltaTime, 0.0f)); //이 엑터의 로컬 좌표계를 기준으로 회전값을 더해라!
	}
	if (!FMath::IsNearlyZero(MovementSpeed))
	{
		RunningTime += DeltaTime;
		
		float TimeFactor = FMath::Sin((RunningTime+TimeOffset)*MovementSpeed);
		
		// 4. 기준 위치에 '비율 * 범위'를 계산해서 새로운 Y축 좌표를 만듭니다.
		FVector CurrentLocation = StartLocation;
		CurrentLocation.Y += TimeFactor * MoveRange;
		// 5. 액터의 위치를 최종 업데이트합니다.
		SetActorLocation(CurrentLocation);
		// AddActorWorldOffset(FVector( MovementSpeed * DeltaTime,0.0f,0.0f));
	}
}

