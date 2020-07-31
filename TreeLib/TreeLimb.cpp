/**
 * \file TreeLimb.cpp
 *
 * \author Niklas Baumgardner
 */

#include "pch.h"
#include "TreeLimb.h"
#include "PseudoRandom.h"
#include "RealTree.h"
#include "TreePart.h"
#include "TreeImage.h"
#include "Leaf.h"
#include "RealFruit.h"

using namespace Gdiplus;
using namespace std;

/// growth rate
const double GrowthRate = 0.31;
/// pi
const double pi = 3.1415;

CTreeLimb::CTreeLimb(CRealTree* tree, int depth) : CTreePart(tree, depth)
{
}

void CTreeLimb::Draw(Gdiplus::Graphics* graphics, double angle, Point pos)
{
	CRealTree* tree = GetTree();
	auto wind = tree->GetWind();
	double useAngle = angle + this->GetAngle() + wind * .0013;
	
	double dy = cos(useAngle) * mHeight;
	double dx = sin(useAngle) * mHeight;

	auto p1 = Point(pos.X - dx, pos.Y - dy);
	this->SetPosition(p1);
	Pen limbPen(Color(139, 69, 19), mWidth);
	limbPen.SetEndCap(LineCapRound);
	graphics->DrawLine(&limbPen, pos, p1);

	for (auto child : mChildren)
	{
		child->Draw(graphics, useAngle, p1);
	}

}

void CTreeLimb::Grow()
{
	auto delta = 1 / 30.0;
	double growRate = pow((1.0 + GrowthRate), delta);

	mHeight *= growRate;
	mWidth *= growRate;

	for (auto child : mChildren)
	{
		child->Grow();		
	}

	
	CRealTree* tree = GetTree();
	CPseudoRandom* rand = tree->GetRandom();
	double depth = this->GetDepth();
	int maxDepth = tree->GetMaxDepth();
	
	if (depth < maxDepth)
	{
		
		if (mChildren.size() < 2 && depth < 11 && rand->Random(0.0, 1.0) < 0.048)
		{
			auto limb = make_shared<CTreeLimb>(tree, depth + 1);
			double angle = rand->Random(-0.69, 0.69);
			limb->SetAngle(angle);
			this->AddChild(limb);
		}

		else if (mChildren.size() < 2 && depth > 7 && rand->Random(0.0, 1.0) < .69)
		{
			auto leaf = make_shared<CLeaf>(tree, depth + 1);
			auto angle = this->GetAngle();
			leaf->SetAngle(-angle);
			this->AddChild(leaf);
		}
		
		else if (mChildren.size() < 2 && depth > 7 && rand->Random(0.0, 1.0) < .11)
		{
			auto fruit = make_shared<CRealFruit>(tree, depth + 1);
			fruit->SetAngle(pi);
			this->AddChild(fruit);
			tree->AddFruit(fruit);
		}
	}

	else if (mChildren.size() < 2)
	{
		auto leaf = make_shared<CLeaf>(tree, depth + 1);
		auto angle = this->GetAngle();
		leaf->SetAngle(-angle + pi);
		this->AddChild(leaf);
	}
}

void CTreeLimb::AddChild(std::shared_ptr<CTreePart> child)
{
	mChildren.push_back(child);
	child->SetParent(this);
	child->SetTree(this->GetTree());
}

void CTreeLimb::RemoveChild(std::shared_ptr<CRealFruit> fruit)
{
	vector<shared_ptr<CTreePart>>::iterator it;
	it = find(mChildren.begin(), mChildren.end(), fruit);
	auto loc = distance(mChildren.begin(), it);
	mChildren.erase(mChildren.begin() + loc);
}