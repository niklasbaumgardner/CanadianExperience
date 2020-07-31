/**
 * \file RealTree.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include <vector>
#include <memory>
#include "Tree.h"
#include "PseudoRandom.h"
#include "RealFruit.h"

class CTreeLimb;
class CTreePart;
class CRealBasket;

/** Real tree class */
class CRealTree : public CTree
{
public:
	/// Constructor
	CRealTree();

	/// Destructor
	virtual ~CRealTree() {}

	/// Copy constructor/disabled
	CRealTree(const CRealTree&) = delete;

	/// Assignment operator/disabled
	void operator=(const CRealTree&) = delete;

	/**
	* Set the position for the root of the tree
	* \param x X location (pixels)
	* \param y Y location (pixels)
	*/
	virtual void SetRootLocation(int x, int y) { mPosition = Gdiplus::Point(x, y); }

	/**
	* Draw the tree at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	virtual void DrawTree(Gdiplus::Graphics* graphics);

	/**
	* Set the current tree frame
	* \param frame Frame number
	*/
	virtual void SetTreeFrame(int frame);

	/**
	* Set  the wind speed
	* \param speed Wind speed in miles per hour
	*/
	virtual void SetWindSpeed(double speed);

	/**
	* Set the tree seed
	* \param seed An integer number. Each number makes a different tree
	*/
	virtual void SetSeed(int seed) override { mSeed = seed; }
	/**
	* \return wind speed */
	double GetWind() { return mWindSpeed; }

	/**
	 * Get the current tree seed
	 * \return Tree seed integer
	 */
	virtual int GetSeed() { return mSeed; }
	/**
	* \return current frame */
	int GetFrame() { return mCurrentFrame; }
	/**
	* \return framerate */
	int GetFrameRate() { return mFrameRate; }
	/// reset
	void Reset();
	/**
	* \return random */
	CPseudoRandom * GetRandom() { return &mRandom; }
	/**
	* \return depth */
	int GetDepth() { return mDepth; }
	/**
	* \param depth */
	void SetDepth(int depth) { mDepth = depth; }

	/**
	* \param fruit */
	void AddFruit(std::shared_ptr<CRealFruit> fruit) { mFruits.push_back(fruit); }
	/**
	* \return max depth */
	int GetMaxDepth() { return mMaxDepth; }

	/**
	 * Harvest all of the fruit
	 * \return Vector of objects of type CFruit
	 */
	virtual std::vector<std::shared_ptr<CFruit>> Harvest();

private:
	/// wind speed
	double mWindSpeed = 0;
	/// depth
	int mDepth = 1;
	/// tree seed
	int mSeed = 29311;//13351, 2296, 18176, 25458
	/// positon
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	/// current frame
	int mCurrentFrame = 0;
	/// frame rate
	int mFrameRate = 30;
	/// harvested
	bool mHarvested = false;
	/// max tree depth
	int mMaxDepth = 9;
	/// root limb
	std::shared_ptr<CTreeLimb> mRoot;
	/// Random number
	CPseudoRandom mRandom = CPseudoRandom(mSeed);
	/// fruits
	std::vector<std::shared_ptr<CRealFruit>> mFruits;
	/// basket
	std::shared_ptr<CRealBasket> mBasket;

};