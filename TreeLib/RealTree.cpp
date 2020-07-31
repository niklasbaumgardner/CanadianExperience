/**
 * \file RealTree.cpp
 *
 * \author Niklas Baumgardner
 */

#include "pch.h"
#include "RealTree.h"
#include "TreeLimb.h"
#include "FruitCounter.h"
#include <memory>

using namespace std;

/* Constructor */
CRealTree::CRealTree()
{
	// create root limb
	mRoot = make_shared<CTreeLimb>(this, mDepth);
	mRoot->SetTree(this);
}


void CRealTree::DrawTree(Gdiplus::Graphics* graphics)
{
	//this->SetRootLocation(100, 110);
	mRoot->Draw(graphics, 0, mPosition);
}


void CRealTree::SetTreeFrame(int frame)
{
	
	if (frame < mCurrentFrame)
	{
		Reset();
	}

	while (mCurrentFrame < frame) {
		mCurrentFrame++;
		mRoot->Grow();
	}
}


void CRealTree::SetWindSpeed(double speed)
{
	mWindSpeed = speed;
}


void CRealTree::Reset()
{
	mCurrentFrame = 0;
	mRoot = make_shared<CTreeLimb>(this, mDepth);
	mRandom = CPseudoRandom(mSeed);
	mHarvested = false;
}



std::vector<std::shared_ptr<CFruit>> CRealTree::Harvest()
{
	mHarvested = true;
	vector<shared_ptr<CFruit>> fruits;
	for (auto fruit : mFruits)
	{
		fruits.push_back(fruit);
		auto parent = fruit->GetParent();
		parent->RemoveChild(fruit);
	}
	mFruits.clear();
	return fruits;
}