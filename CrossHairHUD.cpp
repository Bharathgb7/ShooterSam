// Fill out your copyright notice in the Description page of Project Settings.


#include "CrossHairHUD.h"

void UCrossHairHUD::SetHealthPercent(float NewPercent)
{
	if (NewPercent >= 0.0f && NewPercent <= 1.0f)
	{
		HealthBar->SetPercent(NewPercent);
	}
}
