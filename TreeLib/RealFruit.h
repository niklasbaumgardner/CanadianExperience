/**
 * \file RealFruit.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include "TreeHanging.h"
#include "Fruit.h"
#include "FruitVisitor.h"

/** Real fruit class */
class CRealFruit : public CTreeHanging, public CFruit
{
public:
	/**
	* \param tree
	* \param depth */
	CRealFruit(CRealTree* tree, int depth);
	/**
	* \param x
	* \param y */
	virtual void SetBasketPosition(int x, int y);
	/**
	* \param graphics
	* \param x
	* \param y */
	virtual void DrawInBasket(Gdiplus::Graphics* graphics, int x, int y);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CFruitVisitor* visitor) override { visitor->VisitFruit(this); }

};

