﻿// Created by Henry Jooste

#include "USKCharacterAnimationInstance.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "USK/Logger/Log.h"

/**
 * @brief Executed when begin play is called on the owning component
 */
void UUSKCharacterAnimationInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	USK_LOG_TRACE("Initializing character animation instance");
	Character = dynamic_cast<AUSKCharacter*>(TryGetPawnOwner());
}

/**
 * @brief Native update override point
 * @param DeltaSeconds Game time elapsed during last frame modified by the time dilation
 */
void UUSKCharacterAnimationInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (Character == nullptr)
	{
		USK_LOG_WARNING("Character is nullptr");
		return;
	}

	const float NewMovementSpeed = UKismetMathLibrary::VSizeXY(Character->GetMovementComponent()->Velocity);
	MovementSpeed = FMath::Lerp(MovementSpeed, NewMovementSpeed, DeltaSeconds * MovementBlendSpeed);
	IsInAir = Character->GetMovementComponent()->IsFalling();
	bIsCrouching = !IsInAir && Character->IsCrouching();
	bIsEndingCrouch = Character->IsEndingCrouch();
    bIsStomping = Character->IsStomping();
    bIsStompStarting = Character->IsStompStarting();
	LeanCameraRoll = Character->GetLeanCameraRoll() * LeanCameraRotationModifier;

	if (!Character->IsDoubleJumping)
	{
		IsDoubleJumping = false;
		return;
	}

	if (!IsDoubleJumping)
	{
		IsDoubleJumping = true;
		return;
	}

	USK_LOG_TRACE("Resetting character double jump");
	Character->IsDoubleJumping = false;
}

/**
 * @brief Get the idle animation based on the current armed state
 * @return The idle animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetIdleAnimation() const
{
	return GetAnimation(IdleAnimation, IdleWeaponOneHandedAnimation, IdleWeaponTwoHandedAnimation);
}

/**
 * @brief Get the walk animation based on the current armed state
 * @return The walk animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetWalkAnimation() const
{
	return GetAnimation(WalkAnimation, WalkWeaponOneHandedAnimation, WalkWeaponTwoHandedAnimation);
}

/**
 * @brief Get the run animation based on the current armed state
 * @return The run animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetRunAnimation() const
{
	return GetAnimation(RunAnimation, RunWeaponOneHandedAnimation, RunWeaponTwoHandedAnimation);
}

/**
 * @brief Get the jump animation based on the current armed state
 * @return The jump animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetJumpAnimation() const
{
	return GetAnimation(JumpAnimation, JumpWeaponOneHandedAnimation, JumpWeaponTwoHandedAnimation);
}

/**
 * @brief Get the double jump animation based on the current armed state
 * @return The double jump animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetDoubleJumpAnimation() const
{
	return GetAnimation(DoubleJumpAnimation, DoubleJumpWeaponOneHandedAnimation, DoubleJumpWeaponTwoHandedAnimation);
}

/**
 * @brief Get the fall animation based on the current armed state
 * @return The fall animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetFallAnimation() const
{
	return bIsStomping
		? GetAnimation(StompFallAnimation, StompFallWeaponOneHandedAnimation, StompFallWeaponTwoHandedAnimation)
		: GetAnimation(FallAnimation, FallWeaponOneHandedAnimation, FallWeaponTwoHandedAnimation);
}

/**
 * @brief Get the land animation based on the current armed state
 * @return The land animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetLandAnimation() const
{
	return bIsStomping
		? GetAnimation(StompLandAnimation, StompLandWeaponOneHandedAnimation, StompLandWeaponTwoHandedAnimation)
		: GetAnimation(LandAnimation, LandWeaponOneHandedAnimation, LandWeaponTwoHandedAnimation);
}

/**
 * @brief Get the crouch start animation based on the current armed state
 * @return The crouch start animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetCrouchStartAnimation() const
{
	return GetAnimation(CrouchStartAnimation,
		CrouchStartWeaponOneHandedAnimation, CrouchStartWeaponTwoHandedAnimation);
}

/**
 * @brief Get the crouch end animation based on the current armed state
 * @return The crouch end animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetCrouchEndAnimation() const
{
	return GetAnimation(CrouchEndAnimation,
		CrouchEndWeaponOneHandedAnimation, CrouchEndWeaponTwoHandedAnimation);
}

/**
 * @brief Get the crouch idle animation based on the current armed state
 * @return The crouch idle animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetCrouchIdleAnimation() const
{
	return GetAnimation(CrouchIdleAnimation,
		CrouchIdleWeaponOneHandedAnimation, CrouchIdleWeaponTwoHandedAnimation);
}

/**
 * @brief Get the crouch walk animation based on the current armed state
 * @return The crouch walk animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetCrouchWalkAnimation() const
{
	return GetAnimation(CrouchWalkAnimation,
		CrouchWalkWeaponOneHandedAnimation, CrouchWalkWeaponTwoHandedAnimation);
}

/**
 * @brief Get the stomp start animation based on the current armed state
 * @return The stomp start animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetStompStartAnimation() const
{
	return GetAnimation(StompStartAnimation, StompStartWeaponOneHandedAnimation, StompStartWeaponTwoHandedAnimation);
}

/**
 * @brief Get an animation based on the current armed state
 * @param UnarmedAnimation The unarmed animation
 * @param WeaponOneHandedAnimation The one handed weapon animation
 * @param WeaponTwoHandedAnimation The two handed weapon animation
 * @return The animation to play
 */
UAnimSequence* UUSKCharacterAnimationInstance::GetAnimation(UAnimSequence* UnarmedAnimation,
	UAnimSequence* WeaponOneHandedAnimation, UAnimSequence* WeaponTwoHandedAnimation) const
{
	if (!IsValid(Character) || !IsValid(Character->GetWeapon()))
	{
		return UnarmedAnimation;
	}

	switch (Character->GetWeapon()->WeaponType)
	{
	case EWeaponType::WeaponOneHanded:
		return WeaponOneHandedAnimation;
	case EWeaponType::WeaponTwoHanded:
		return WeaponTwoHandedAnimation;
	default:
		USK_LOG_ERROR("Invalid weapon type");
		return nullptr;
	}
}