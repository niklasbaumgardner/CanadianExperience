/**
 * \file TreeHanging.cpp
 *
 * \author Niklas Baumgardner
 */

#include "pch.h"
#include "TreeHanging.h"

/// growth rate
const double GrowthRate = 0.31;

CTreeHanging::CTreeHanging(CRealTree* tree, int depth, const std::wstring& filename) : CTreePart(tree, depth), CTreeImage(filename)
{
}

void CTreeHanging::Draw(Gdiplus::Graphics* graphics, double angle, Gdiplus::Point pos)
{
	DrawImage(graphics, GetAngle(), GetScale(), pos.X, pos.Y);
}

void CTreeHanging::Grow()
{
	auto currentScale = GetScale();
	if (currentScale <= 0.25)
	{
		auto delta = 1 / 30.0;
		double growRate = pow((1.0 + GrowthRate), delta);
		SetScale(GetScale() * growRate);
	}
}
