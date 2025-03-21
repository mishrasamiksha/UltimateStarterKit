## Introduction
Base character class

## Dependencies
The <code>USKCharacter</code> relies on other components of this plugin to work:
<ul>
	<li><a href="../logger">Logger</a>: Used to log useful information to help you debug any issues you might experience</li>
	<li><a href="../audio">Audio</a>: Used to play sound effects either 2D or at a specified location</li>
</ul>

## Components
The <code>USKCharacter</code> uses the following components:
<table>
	<tr>
		<th>Name</th>
		<th>Description</th>
		<th>Type</th>
	</tr>
	<tr>
		<td>CameraComponent</td>
		<td>Base character class</td>
		<td>UCameraComponent*</td>
	</tr>
	<tr>
		<td>CrouchTimeline</td>
		<td>The timeline component used for smooth crouching</td>
		<td>UTimelineComponent*</td>
	</tr>
</table>

## API Reference
### Properties
<table>
	<tr>
		<th>Property</th>
		<th>Description</th>
		<th>Type</th>
		<th>Default Value</th>
	</tr>
	<tr>
		<td>InputMappingContext</td>
		<td>The input mapping context used by the character</td>
		<td>UInputMappingContext*</td>
		<td><code>nullptr</code></td>
	</tr>
	<tr>
		<td>MoveAction</td>
		<td>The move input action</td>
		<td>UInputAction*</td>
		<td><code>nullptr</code></td>
	</tr>
	<tr>
		<td>LookAroundAction</td>
		<td>The camera rotation input action</td>
		<td>UInputAction*</td>
		<td><code>nullptr</code></td>
	</tr>
	<tr>
		<td>JumpAction</td>
		<td>The jump input action</td>
		<td>UInputAction*</td>
		<td><code>nullptr</code></td>
	</tr>
	<tr>
		<td>FireWeaponAction</td>
		<td>The fire weapon input action</td>
		<td>UInputAction*</td>
		<td><code>nullptr</code></td>
	</tr>
	<tr>
		<td>CrouchAction</td>
		<td>The crouch input action</td>
		<td>UInputAction*</td>
		<td><code>nullptr</code></td>
	</tr>
	<tr>
		<td>LeanAction</td>
		<td>The lean input action</td>
		<td>UInputAction*</td>
		<td><code>nullptr</code></td>
	</tr>
	<tr>
		<td>ShadowDecalClass</td>
		<td>The shadow decal class used to draw a shadow below the character while in the air</td>
		<td>TSubclassOf&lt;AShadowDecal&gt;</td>
		<td></td>
	</tr>
	<tr>
		<td>JumpSoundEffects</td>
		<td>An array of sound effects played when jumping</td>
		<td>TArray&lt;USoundBase*&gt;</td>
		<td></td>
	</tr>
	<tr>
		<td>JumpParticleFx</td>
		<td>The particle effects spawned when jumping</td>
		<td>UNiagaraSystem*</td>
		<td><code>nullptr</code></td>
	</tr>
	<tr>
		<td>JumpParticleFxSpawnOffset</td>
		<td>The offset applied to the location of the jump particles when spawning</td>
		<td>FVector</td>
		<td></td>
	</tr>
	<tr>
		<td>LandedSoundEffects</td>
		<td>An array of sound effects played when landing</td>
		<td>TArray&lt;USoundBase*&gt;</td>
		<td></td>
	</tr>
	<tr>
		<td>LandParticleFx</td>
		<td>The particle effects spawned when landing</td>
		<td>UNiagaraSystem*</td>
		<td><code>nullptr</code></td>
	</tr>
	<tr>
		<td>LandParticleFxSpawnOffset</td>
		<td>The offset applied to the location of the land particles when spawning</td>
		<td>FVector</td>
		<td></td>
	</tr>
	<tr>
		<td>VariableJumpHeight</td>
		<td>Does the character support variable jump height?</td>
		<td>bool</td>
		<td>true</td>
	</tr>
	<tr>
		<td>VariableJumpHeightMaxHoldTime</td>
		<td>The amount of time to hold the jump button to reach the max height</td>
		<td>float</td>
		<td>0.3f</td>
	</tr>
	<tr>
		<td>JumpVelocity</td>
		<td>The velocity applied to the character when jumping</td>
		<td>float</td>
		<td>500.0f</td>
	</tr>
	<tr>
		<td>AirControl</td>
		<td>The amount of lateral movement control available to the character while in the air</td>
		<td>float</td>
		<td>1000.0f</td>
	</tr>
	<tr>
		<td>FallingFriction</td>
		<td>The amount of friction to apply to lateral air movement when falling</td>
		<td>float</td>
		<td>3.5f</td>
	</tr>
	<tr>
		<td>Gravity</td>
		<td>The amount of gravity applied to the character</td>
		<td>float</td>
		<td>2.0f</td>
	</tr>
	<tr>
		<td>CanDoubleJump</td>
		<td>Can the character perform a double jump?</td>
		<td>bool</td>
		<td>true</td>
	</tr>
	<tr>
		<td>CanCoyoteJump</td>
		<td>Does the character support coyote time when trying to jump?</td>
		<td>bool</td>
		<td>true</td>
	</tr>
	<tr>
		<td>CoyoteJumpTime</td>
		<td>The amount of coyote time for the character</td>
		<td>float</td>
		<td>0.375f</td>
	</tr>
	<tr>
		<td>CoyoteJumpVelocity</td>
		<td>The velocity applied to the character when performing a coyote jump</td>
		<td>float</td>
		<td>700.0f</td>
	</tr>
	<tr>
		<td>bCanStompJump</td>
		<td>Can the character perform a high jump directly after landing from a stomp?</td>
		<td>bool</td>
		<td>true</td>
	</tr>
	<tr>
		<td>StompJumpDuration</td>
		<td>The duration after the stomp that the character can perform the stomp jump</td>
		<td>float</td>
		<td>0.35f</td>
	</tr>
	<tr>
		<td>StompJumpVelocity</td>
		<td>The velocity applied to the character when performing a stomp jump</td>
		<td>float</td>
		<td>1250.0f</td>
	</tr>
	<tr>
		<td>bCanCrouchJump</td>
		<td>Can the character perform a high jump while crouching?</td>
		<td>bool</td>
		<td>true</td>
	</tr>
	<tr>
		<td>CrouchJumpVelocity</td>
		<td>The velocity applied to the character when performing a crouch jump</td>
		<td>float</td>
		<td>1250.0f</td>
	</tr>
	<tr>
		<td>IsDoubleJumping</td>
		<td>Is the character double jumping?</td>
		<td>bool</td>
		<td></td>
	</tr>
	<tr>
		<td>BrakingFriction</td>
		<td>Friction coefficient applied when braking</td>
		<td>float</td>
		<td>10.0f</td>
	</tr>
	<tr>
		<td>MaxAcceleration</td>
		<td>The rate of change of velocity</td>
		<td>float</td>
		<td>2500.0f</td>
	</tr>
	<tr>
		<td>bCanCrouch</td>
		<td>Can the character crouch?</td>
		<td>bool</td>
		<td>true</td>
	</tr>
	<tr>
		<td>bHoldToCrouch</td>
		<td>Should the crouch action be held down to crouch?</td>
		<td>bool</td>
		<td>true</td>
	</tr>
	<tr>
		<td>CrouchCurve</td>
		<td>The float curve used for smooth crouching</td>
		<td>UCurveFloat*</td>
		<td><code>nullptr</code></td>
	</tr>
	<tr>
		<td>bCanStomp</td>
		<td>Can the character perform a stomp?</td>
		<td>bool</td>
		<td>true</td>
	</tr>
	<tr>
		<td>MinAirTimeBeforeStomping</td>
		<td>The minimum air time before the character can perform a stomp</td>
		<td>float</td>
		<td>0.3f</td>
	</tr>
	<tr>
		<td>StompVelocity</td>
		<td>The velocity applied to the character after performing a stomp</td>
		<td>float</td>
		<td>-5000.0f</td>
	</tr>
	<tr>
		<td>StompZeroGravityDuration</td>
		<td>The amount of time the character will be in zero gravity after performing a stomp</td>
		<td>float</td>
		<td>0.5f</td>
	</tr>
	<tr>
		<td>StompLandVelocity</td>
		<td>The velocity applied to the character when landing after performing a stomp</td>
		<td>float</td>
		<td>750.0f</td>
	</tr>
	<tr>
		<td>StompCameraShake</td>
		<td>The camera shake applied when performing a stomp</td>
		<td>TSubclassOf&lt;UCameraShakeBase&gt;</td>
		<td></td>
	</tr>
	<tr>
		<td>bCanLean</td>
		<td>Can the character lean?</td>
		<td>bool</td>
		<td>true</td>
	</tr>
	<tr>
		<td>LeanSpeed</td>
		<td>The speed used when leaning</td>
		<td>float</td>
		<td>5.0f</td>
	</tr>
	<tr>
		<td>LeanOffset</td>
		<td>The offset applied to the camera when leaning</td>
		<td>float</td>
		<td>50.0f</td>
	</tr>
	<tr>
		<td>LeanRotation</td>
		<td>The rotation applied to the camera when leaning</td>
		<td>float</td>
		<td>25.0f</td>
	</tr>
	<tr>
		<td>DefaultWeaponClass</td>
		<td>The default weapon the character will equip on spawn</td>
		<td>TSubclassOf&lt;AWeapon&gt;</td>
		<td></td>
	</tr>
</table>

### Functions
<table>
	<tr>
		<th>Name</th>
		<th>Description</th>
		<th>Params</th>
		<th>Return</th>
	</tr>
	<tr>
		<td>GetCameraComponent</td>
		<td>Get the camera used by the character</td>
		<td></td>
		<td><strong>UCameraComponent*</strong><br/>The camera used by the character</td>
	</tr>
	<tr>
		<td>SetWeapon</td>
		<td>Set the current weapon used by the character</td>
		<td><strong>NewWeapon (AWeapon*)</strong><br/>The new weapon</td>
		<td></td>
	</tr>
	<tr>
		<td>GetWeapon</td>
		<td>Get the current weapon used by the character</td>
		<td></td>
		<td><strong>AWeapon*</strong><br/>The current weapon used by the character</td>
	</tr>
	<tr>
		<td>IsCrouching</td>
		<td>Check if the character is crouching</td>
		<td></td>
		<td><strong>bool</strong><br/>A boolean value indicating if the character is crouching</td>
	</tr>
	<tr>
		<td>IsEndingCrouch</td>
		<td>Check if the character is busy ending the crouch</td>
		<td></td>
		<td><strong>bool</strong><br/>A boolean value indicating if the character is busy ending the crouch</td>
	</tr>
	<tr>
		<td>IsStomping</td>
		<td>Check if the character is stomping</td>
		<td></td>
		<td><strong>bool</strong><br/>A boolean value indicating if the character is stomping</td>
	</tr>
	<tr>
		<td>IsStompStarting</td>
		<td>Check if the character is starting to stomp</td>
		<td></td>
		<td><strong>bool</strong><br/>A boolean value indicating if the character is starting to stomp</td>
	</tr>
	<tr>
		<td>GetLeanCameraRoll</td>
		<td>Get the current lean camera roll</td>
		<td></td>
		<td><strong>float</strong><br/>The current lean camera roll</td>
	</tr>
	<tr>
		<td>StartFiringWeapon</td>
		<td>Start firing the current weapon</td>
		<td></td>
		<td></td>
	</tr>
	<tr>
		<td>StopFiringWeapon</td>
		<td>Stop firing the current weapon</td>
		<td></td>
		<td></td>
	</tr>
	<tr>
		<td>StartCrouching</td>
		<td>Start crouching</td>
		<td></td>
		<td></td>
	</tr>
	<tr>
		<td>StopCrouching</td>
		<td>Stop crouching</td>
		<td></td>
		<td></td>
	</tr>
	<tr>
		<td>UpdateCharacterMeshLocationWhileCrouching</td>
		<td>Update the character mesh location while crouching</td>
		<td><strong>SizeDifference (float)</strong><br/>The difference between the original capsule size and the crouched capsule size</td>
		<td></td>
	</tr>
</table>

## Blueprint Usage
There is no additional functions exposed to Blueprints. Just create the character and add it to your level