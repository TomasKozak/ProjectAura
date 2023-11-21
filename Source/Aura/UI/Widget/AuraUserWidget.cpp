// Copyright Coherence Studios


#include "AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController) {
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
