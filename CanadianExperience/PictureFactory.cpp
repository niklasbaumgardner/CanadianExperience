/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "TreeFactory.h"
#include "AdaptTree.h"
#include "AdaptBasket.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

	CTreeFactory tfactory;

	// Create basket
	auto basket = tfactory.CreateBasket();
	auto basketActor = make_shared<CActor>(L"Basket");
	auto adaptBasket = make_shared<CAdaptBasket>(L"Basket");

	adaptBasket->SetPosition(900, 500);
	adaptBasket->SetBasket(basket);
	basketActor->AddDrawable(adaptBasket);
	picture->AddActor(basketActor);

	// Create first tree
	auto tree = tfactory.CreateTree();
	auto treeActor = make_shared<CActor>(L"Tree");
	mTree1 = make_shared<CAdaptTree>(L"Tree");

	mTree1->SetTimeline(picture->GetTimeline());
	mTree1->SetPosition(1000, 300);
	mTree1->SetKeyFrame(660);
	mTree1->SetTree(tree);

	treeActor->AddDrawable(mTree1);
	picture->AddActor(treeActor);

	// Create second tree
	auto tree2 = tfactory.CreateTree();
	auto treeActor2 = make_shared<CActor>(L"Tree1");
	mTree2 = make_shared<CAdaptTree>(L"Tree1");

	mTree2->SetTimeline(picture->GetTimeline());
	mTree2->SetPosition(200, 700);
	mTree2->SetKeyFrame(450);
	mTree2->SetTree(tree2);

	treeActor2->AddDrawable(mTree2);
	picture->AddActor(treeActor2);


    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(700, 450));
    picture->AddActor(sparty);


    return picture;
}
