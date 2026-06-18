// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "PlayerGameMode.h"
#include "SpartaPlayerController.h"

APlayerGameMode::APlayerGameMode()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
	PlayerControllerClass = ASpartaPlayerController::StaticClass();
}