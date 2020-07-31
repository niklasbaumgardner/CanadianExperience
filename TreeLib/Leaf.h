/**
 * \file Leaf.h
 *
 * \author Niklas Baumgardner
 *
 * 
 */

#pragma once

#include "TreeHanging.h"
#include "FruitVisitor.h"

/** Class for leaf */
class CLeaf : public CTreeHanging
{
public:
	/**
	* \param tree
	* \param depth */
	CLeaf(CRealTree* tree, int depth);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CFruitVisitor* visitor) override { visitor->VisitLeaf(this); }

};

