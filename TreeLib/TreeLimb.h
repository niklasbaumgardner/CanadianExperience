/**
 * \file TreeLimb.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include "TreePart.h"
#include "FruitVisitor.h"
#include <gdiplus.h>
#include <vector>
#include <memory>

/** Tree limb class */
class CTreeLimb : public CTreePart
{
public:
	/**
	* \param tree
	* \param depth */
	CTreeLimb(CRealTree* tree, int depth);
	/**
	* \param graphics
	* \param angle
	* \param pos */
	virtual void Draw(Gdiplus::Graphics* graphics, double angle, Gdiplus::Point pos);
	/**
	* \param child */
	void AddChild(std::shared_ptr<CTreePart> child);
	/// Grow
	virtual void Grow();
	/**
	* \param w */
	void SetWidth(double w) { mWidth = w; }
	/**
	* \param h */
	void SetHeight(double h) { mHeight = h; }
	/**
	* \return children */
	std::vector<std::shared_ptr<CTreePart>> GetChildren() { return mChildren; }
	/**
	* \param fruit */
	void RemoveChild(std::shared_ptr<CRealFruit> fruit);

	//void SetAngle(double angle) { mAngle = angle; }

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CFruitVisitor* visitor) override { visitor->VisitLimb(this); }


private:
	/// width
	double mWidth = 1;
	/// height
	double mHeight = 4;
	/// children
	std::vector<std::shared_ptr<CTreePart>> mChildren;

};

