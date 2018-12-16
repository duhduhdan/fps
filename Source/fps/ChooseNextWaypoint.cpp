// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory
) {
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) return EBTNodeResult::Failed;

	auto PatrolPoints = PatrolRoute->getPatrolPoints();

	if (PatrolPoints.Num() <= 0) {
		UE_LOG(LogTemp, Warning, TEXT("No patrol points found a guard"));

		return EBTNodeResult::Failed;
	}

	// set next waypoint
	auto blackBoardComp = OwnerComp.GetBlackboardComponent();
	auto index = blackBoardComp->GetValueAsInt(indexKey.SelectedKeyName);
	blackBoardComp->SetValueAsObject(waypointKey.SelectedKeyName, PatrolPoints[index]);

	// cycle waypoint
	auto nextIndex = rand() % PatrolPoints.Num();
	blackBoardComp->SetValueAsInt(indexKey.SelectedKeyName, nextIndex);
	

	return EBTNodeResult::Succeeded;
}


