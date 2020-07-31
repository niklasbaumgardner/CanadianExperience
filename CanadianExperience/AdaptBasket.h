/**
 * \file AdaptBasket.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include "Drawable.h"
#include "Basket.h"

/** Basket adapter */
class CAdaptBasket : public CDrawable
{
public:
	/**
	* \param name */
	CAdaptBasket(const std::wstring& name) : CDrawable(name) {}

	/// Virtual destructor
	virtual ~CAdaptBasket() {}

	/// Default constructor deleted
	CAdaptBasket() = delete;
	/** \brief Copy constructor disabled */
	CAdaptBasket(const CAdaptBasket&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CAdaptBasket&) = delete;

	/**
	* \param frame
	*/
	void SetKeyFrame(int frame) { mInitialFrame = frame; }

	/**
	* \param x
	* \param y
	*/
	void SetPosition(int x, int y) { mLocation = Gdiplus::Point(x, y); }

	/**
	* \param graphics
	*/
	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/**
	* \param basket
	*/
	void SetBasket(std::shared_ptr<CBasket> basket) { mBasket = basket; }

	/**
	* \param pos
	* \return bool
	*/
	bool HitTest(Gdiplus::Point pos) { return false; }

	/**
	* \param fruit
	*/
	void AddToBasket(std::vector<std::shared_ptr<CFruit>> fruit) { mBasket->AddToBasket(fruit); }

private:
	/// location
	Gdiplus::Point mLocation = Gdiplus::Point(0, 0);
	/// The initial draw frame
	int mInitialFrame;
	/// The basket object
	std::shared_ptr<CBasket> mBasket;
};

