/**
 * \file Leaf.cpp
 *
 * \author Niklas Baumgardner
 */

#include "pch.h"
#include "Leaf.h"

/// Leaf file name
const std::wstring& leafFilename = L"images/leaf2.png";

CLeaf::CLeaf(CRealTree* tree, int depth) : CTreeHanging(tree, depth, leafFilename)
{
	this->SetMaxScale(0.69);
}
