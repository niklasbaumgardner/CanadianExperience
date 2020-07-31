/**
 * \file TreeHanging.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include "TreePart.h"
#include "TreeImage.h"

/** Class for stuff hanging from tree */
class CTreeHanging : public CTreePart, public CTreeImage
{
public:
	/**
	* \param tree
	* \param depth
	* \param filename */
	CTreeHanging(CRealTree* tree, int depth, const std::wstring& filename);
	/// Grow
	virtual void Grow();
	/**
	* \param graphics
	* \param angle
	* \param pos */
	virtual void Draw(Gdiplus::Graphics* graphics, double angle, Gdiplus::Point pos);

};

