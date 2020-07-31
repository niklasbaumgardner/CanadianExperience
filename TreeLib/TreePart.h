/**
 * \file TreePart.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include <gdiplus.h>

class CRealTree;
class CFruitVisitor;
class CTreeLimb;

/** Tree part class */
class CTreePart
{
public:
	/**
	* \param tree
	* \param depth */
	CTreePart(CRealTree* tree, int depth) : mTree(tree), mDepth(depth) {};
	/**
	* \param graphics
	* \param angle
	* \param pos */
	virtual void Draw(Gdiplus::Graphics* graphics, double angle, Gdiplus::Point pos) = 0;
	/** Grow */
	virtual void Grow() = 0;
	
	/**
	* \return scale */
	double GetScale() { return mScale; }
	/**
	* \param scale */
	void SetScale(double scale) { mScale = scale; }

	/**
	* \return max scale */
	double GetMaxScale() { return mMaxScale; }
	/**
	* \param max */
	void SetMaxScale(double max) { mMaxScale = max; }

	/**
	* \return depth */
	int GetDepth() { return mDepth; }
	/**
	* \param depth */
	void SetDepth(int depth) { mDepth = depth; }

	/**
	* \return tree */
	CRealTree* GetTree() { return mTree; }
	/**
	* \param tree */
	void SetTree(CRealTree* tree) { mTree = tree; }

	/**
	* \param parent */
	void SetParent(CTreeLimb* parent) { mParent = parent; }
	/**
	* \return parent */
	CTreeLimb* GetParent() { return mParent; }

	/**
	* \param angle */
	void SetAngle(double angle) { mAngle = angle; }
	/**
	* \return angle */
	double GetAngle() { return mAngle; }

	/**
	* \param pos */
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }
	/**
	* \return position */
	Gdiplus::Point GetPosition() { return mPosition; }

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CFruitVisitor* visitor) = 0;

protected:
	

private:
	/// angle
	double mAngle = 0;
	/// position
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	/// scale
	double mScale = .069;
	/// max scale
	double mMaxScale = 0.25;
	/// depth
	int mDepth = 1;
	/// tree
	CRealTree* mTree = nullptr;
	/// parent
	CTreeLimb* mParent = nullptr;
};

