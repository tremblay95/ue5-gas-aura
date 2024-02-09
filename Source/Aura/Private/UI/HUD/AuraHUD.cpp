// Copyright Marc Tremblay


#include "UI/HUD/AuraHUD.h"

#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "UI/WidgetController/LayoutWidgetController.h"

ULayoutWidgetController* AAuraHUD::GetLayoutWidgetController(const FWidgetControllerParams& WCParams)
{
	if (LayoutWidgetController == nullptr)
	{
		LayoutWidgetController = NewObject<ULayoutWidgetController>(this, LayoutWidgetControllerClass);
		LayoutWidgetController->SetWidgetControllerParams(WCParams);

		LayoutWidgetController->BindCallbacksToDependencies();
	}

	return LayoutWidgetController;
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	if (AttributeMenuWidgetController == nullptr)
	{
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->SetWidgetControllerParams(WCParams);

		AttributeMenuWidgetController->BindCallbacksToDependencies();
	}

	return AttributeMenuWidgetController;
}

USpellMenuWidgetController* AAuraHUD::GetSpellMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	if (SpellMenuWidgetController == nullptr)
	{
		SpellMenuWidgetController = NewObject<USpellMenuWidgetController>(this, SpellMenuWidgetControllerClass);
		SpellMenuWidgetController->SetWidgetControllerParams(WCParams);

		SpellMenuWidgetController->BindCallbacksToDependencies();
	}
	
	return SpellMenuWidgetController;
}

void AAuraHUD::InitLayout(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(LayoutWidgetClass, TEXT("Layout Widget Class uninitialized, please fill out BP_AuraHUD"));
	checkf(LayoutWidgetControllerClass, TEXT("Layout Widget Controller Class uninitialized, please fill out BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), LayoutWidgetClass);
	LayoutWidget = Cast<UAuraUserWidget>(Widget);

	ULayoutWidgetController* WidgetController = GetLayoutWidgetController({PC, PS, ASC, AS});

	LayoutWidget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}
