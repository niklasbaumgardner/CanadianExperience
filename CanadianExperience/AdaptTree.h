/**
 * \file AdaptTree.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include "Drawable.h"
#include "Tree.h"

/** Tree adpater class */
class CAdaptTree : public CDrawable
{
public:
	/**
	* \param name */
	CAdaptTree(const std::wstring& name);

	/// Virtual destructor
	virtual ~CAdaptTree();

	/** \brief Default constructor disabled */
	CAdaptTree() = delete;
	/** \brief Copy constructor disabled */
	CAdaptTree(const CAdaptTree&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAdaptTree&) = delete;

	/**
	* \param frame */
	virtual void SetKeyFrame(int frame);

	/**
	* \param x
	* \param y
	*/
	void SetPosition(int x, int y);

	/**
	* \param graphics
	*/
	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/**
	* \param tree
	*/
	void SetTree(std::shared_ptr<CTree> tree) { mTree = tree; }

	/**
	* \param pos
	* \return false
	*/
	bool HitTest(Gdiplus::Point pos) { return false; }

	/**
	* \param timeline */
	void SetTimeline(CTimeline* timeline) { mTimeline = timeline; CDrawable::SetTimeline(timeline); }

	/**
	* \param seed */
	void SetSeed(int seed) { mTree->SetSeed(seed); mSeed = seed; }

	/**
	* \return the seed
	*/
	int GetSeed() { return mSeed; }

	/**
	* \return harvested
	*/
	std::vector<std::shared_ptr<CFruit>> Harvest() { return mTree->Harvest(); }


private:
	/// The x location
	Gdiplus::Point mLocation = Gdiplus::Point(0, 0);

	/// The intial frame for the tree
	int mInitialFrame = 0;

	/// The timeline that we're working on 
	CTimeline* mTimeline = nullptr;

	/// The tree that we're working on
	std::shared_ptr<CTree> mTree;

	/// The seed for the random numbers
	int mSeed = 69;
};

