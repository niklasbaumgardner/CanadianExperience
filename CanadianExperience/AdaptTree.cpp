/**
 * \file AdaptTree.cpp
 *
 * \author Niklas Baumgardner
 */

#include "pch.h"
#include "AdaptTree.h"
#include "Timeline.h"

using namespace Gdiplus;

CAdaptTree::CAdaptTree(const std::wstring& name) :CDrawable(name)
{

}

CAdaptTree::~CAdaptTree()
{
}

void CAdaptTree::Draw(Gdiplus::Graphics* graphics)
{
	mTree->SetRootLocation(mLocation.X, mLocation.Y);
	if (mTimeline->GetCurrentFrame() >= mInitialFrame)
	{
		mTree->SetTreeFrame(mTimeline->GetCurrentFrame() - mInitialFrame);
	}
	else
	{
		mTree->SetTreeFrame(0);
	}
	mTree->DrawTree(graphics);
}

void CAdaptTree::SetPosition(int x, int y)
{
	mLocation = Point(x, y);
}

void CAdaptTree::SetKeyFrame(int frame)
{
	mInitialFrame = frame;
	if (mTree != nullptr)
	{
		mTree->SetTreeFrame(frame);
		mSeed = mTree->GetSeed();
	}
}
