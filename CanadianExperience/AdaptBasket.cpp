/**
 * \file AdaptBasket.cpp
 *
 * \author Niklas Baumgardner
 */

#include "pch.h"
#include "AdaptBasket.h"

using namespace Gdiplus;

void CAdaptBasket::Draw(Graphics* graphics)
{
	mBasket->SetBasketLocation(mLocation.X, mLocation.Y); 
	mBasket->DrawBasket(graphics);
}