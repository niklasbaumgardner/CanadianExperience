/**
 * \file FruitVisitor.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

class CTreeLimb;
class CLeaf;
class CRealFruit;

/** Fruit visitor */
class CFruitVisitor
{
public:
	/**
	* \param limb */
	virtual void VisitLimb(CTreeLimb *limb) {}
	/**
	* \param leaf */
	virtual void VisitLeaf(CLeaf *leaf) {}
	/**
	* \param fruit */
	virtual void VisitFruit(CRealFruit *fruit) {}
};

