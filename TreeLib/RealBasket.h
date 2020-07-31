/**
 * \file RealBasket.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include "Basket.h"
#include "TreeImage.h"

/** Real basket class */
class CRealBasket : public CBasket
{
public:
	/// constructor
	CRealBasket();

	/**
	* Set the position for the basket.
	* \param x X location (pixels)
	* \param y Y location (pixels)
	*/
	virtual void SetBasketLocation(int x, int y) override { mLocation = Gdiplus::Point(x, y); }
	/**
	* \return location */
	Gdiplus::Point GetLocation() { return mLocation; }

	/**
	* Draw the basket at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	virtual void DrawBasket(Gdiplus::Graphics* graphics) override;

	/**
	 * Add fruit to the basket
	 * \param fruits Vector of fruit objects
	 */
	virtual void AddToBasket(std::vector < std::shared_ptr<CFruit>> fruits) override;

	/**
	 * Empty all fruit from the basket
	 */
	virtual void EmptyBasket() override { mBasket.clear(); }

private:
	/// basket file name
	const std::wstring& basketFilename = L"images/basket.png";
	/// front basket file name
	const std::wstring& frontFilename = L"images/basket-front.png";
	/// fruit file name
	const std::wstring& fruitFilename = L"images/apple.png";
	/// basket
	std::vector<std::shared_ptr<CFruit>> mBasket;
	/// front of basket
	CTreeImage mFront = CTreeImage(frontFilename);
	/// back of basket
	CTreeImage mBack = CTreeImage(basketFilename);
	/// fruit
	CTreeImage mFruitImage = CTreeImage(fruitFilename);
	/// location
	Gdiplus::Point mLocation = Gdiplus::Point(0, 0);
};

