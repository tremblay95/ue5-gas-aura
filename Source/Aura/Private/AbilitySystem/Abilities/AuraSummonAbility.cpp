// Copyright Marc Tremblay


#include "AbilitySystem/Abilities/AuraSummonAbility.h"

TArray<FVector> UAuraSummonAbility::GetSpawnLocations() const
{
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();
	const float DeltaSpread = MinionSpawnCount > 1 ? SpawnSpread / (MinionSpawnCount - 1) : 0.0f;
	const FVector LeftSpreadBoundary = MinionSpawnCount > 1 ? Forward.RotateAngleAxis(-SpawnSpread / 2.0f, FVector::UpVector) : Forward;

	TArray<FVector> SpawnLocations;
	for (int32 i = 0; i < MinionSpawnCount; ++i)
	{
		const FVector Direction = LeftSpreadBoundary.RotateAngleAxis(DeltaSpread * i, FVector::UpVector);
		FVector ChosenSpawnLocation = Location + Direction * FMath::FRandRange(MinSpawnDistance, MaxSpawnDistance);

		FHitResult Hit;
		if (GetWorld()->LineTraceSingleByChannel(Hit, ChosenSpawnLocation + FVector(0.0f, 0.0f, 400.0f), ChosenSpawnLocation - FVector(0.0f, 0.0f, 400.0f), ECC_Visibility))
		{
			ChosenSpawnLocation = Hit.ImpactPoint;
		}
		
		SpawnLocations.Add(ChosenSpawnLocation);
	}

	return SpawnLocations;
}

TSubclassOf<APawn> UAuraSummonAbility::GetRandomMinionClass() const
{
	const int32 Selection = FMath::RandRange(0, MinionClasses.Num() - 1);
	return MinionClasses[Selection];
}
