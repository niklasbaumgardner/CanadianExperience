/**
 * \file PictureFactory.h
 *
 * \author Charles B. Owen
 *
 * A factory class that builds our picture.
 */

#pragma once

#include <memory>

#include "Picture.h"

class CAdaptTree;

/**
 * A factory class that builds our picture.
 */
class CPictureFactory
{
public:
    CPictureFactory();
    virtual ~CPictureFactory();

    std::shared_ptr<CPicture> Create();
	/**
	* \return tree1 */
	std::shared_ptr<CAdaptTree> GetTree1() { return mTree1; }
	/**
	* \return tree2 */
	std::shared_ptr<CAdaptTree> GetTree2() { return mTree2; }


private:
	/// The first ree
	std::shared_ptr<CAdaptTree> mTree1;

	/// The second tree
	std::shared_ptr<CAdaptTree> mTree2;
};

