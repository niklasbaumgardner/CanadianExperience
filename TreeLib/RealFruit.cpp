/**
 * \file RealFruit.cpp
 *
 * \author Niklas Baumgardner
 */

#include "pch.h"
#include "RealFruit.h"

/// fruit file name
const std::wstring& fruitFilename = L"images/apple.png";

CRealFruit::CRealFruit(CRealTree* tree, int depth) : CTreeHanging(tree, depth, fruitFilename), CFruit()
{
}

void CRealFruit::SetBasketPosition(int x, int y)
{

}

void CRealFruit::DrawInBasket(Gdiplus::Graphics* graphics, int x, int y)
{
	DrawImage(graphics, 0, this->GetScale(), x, y);
}