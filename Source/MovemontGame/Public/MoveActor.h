// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"

UCLASS()
class MOVEMONTGAME_API AMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UStaticMeshComponent* StaticMashComp;
	USceneComponent* SceneRoot;
	
	FVector StartLocation;
	
	UPROPERTY(Category=Movement, EditAnywhere)
	float MovementSpeed;
	UPROPERTY(Category=Movement, EditAnywhere)
	float RoctionSpeed;
	
	//왕복에 필요한 변수들
	UPROPERTY(Category=Movement, EditAnywhere)
	float MoveRange = 300.0f;
	
	UPROPERTY(Category=Movement, EditAnywhere)
	float TimeOffset = 0.0f;
	
	float RunningTime;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
