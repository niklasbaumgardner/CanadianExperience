/**
 * \file RealBasket.cpp
 *
 * \author Niklas Baumgardner
 */

#include "pch.h"
#include "RealBasket.h"
#include "TreeImage.h"
#include "PseudoRandom.h"
#include <string>


CRealBasket::CRealBasket() : CBasket()
{
}

void CRealBasket::AddToBasket(std::vector < std::shared_ptr<CFruit>> fruits)
{
	for (auto fruit : fruits)
	{
		mBasket.push_back(fruit);
	}
}

void CRealBasket::DrawBasket(Gdiplus::Graphics* graphics)
{
	mBack.DrawImage(graphics, 0, 1, mLocation.X, mLocation.Y);
	auto rand = CPseudoRandom(69);
	int x;
	int y;
	double angle;
	for (auto fruit : mBasket)
	{
		x = rand.Random(-30, 30);
		y = rand.Random(-70, -50);
		angle = rand.Random(180, 360);
		mFruitImage.DrawImage(graphics, angle, .31, mLocation.X + x, mLocation.Y + y);
	}
	mFront.DrawImage(graphics, 0, 1, mLocation.X, mLocation.Y);
}