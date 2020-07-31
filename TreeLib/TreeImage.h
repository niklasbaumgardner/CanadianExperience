/**
 * \file TreeImage.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include <string>
#include <memory>

 /**
  * Class that represents an image used by our system.
  */
class CTreeImage
{
public:
	/**
	* \param name */
	CTreeImage(const std::wstring name) { LoadImage(name); }

	/// Destructor
	virtual ~CTreeImage() {}
	/**
	* \param filename */
	void LoadImage(const std::wstring& filename);
	/**
	* \param graphics
	* \param angle
	* \param scale
	* \param x
	* \param y*/
	void DrawImage(Gdiplus::Graphics* graphics, double angle, double scale, double x, double y);

private:
	std::shared_ptr<Gdiplus::Bitmap> mImage; ///< The part image

};