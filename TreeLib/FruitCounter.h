/**
 * \file FruitCounter.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include "FruitVisitor.h"
#include "Fruit.h"
#include <vector>
#include <memory>

/** class to get fruit */
class CFruitCounter : public CFruitVisitor
{
public:
	/**
	* \param fruit */
	void VisitFruit(std::shared_ptr<CFruit> fruit) { mFruits.push_back(fruit); }
	/**
	* \return fruits */
	std::vector<std::shared_ptr<CFruit>> GetFruits() { return mFruits; }

private:
	/// fruits
	std::vector<std::shared_ptr<CFruit>> mFruits;
};

