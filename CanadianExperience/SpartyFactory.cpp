/**
 * \file SpartyFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "SpartyFactory.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 */
CSpartyFactory::CSpartyFactory()
{
}


/**
 * Destructor
 */
CSpartyFactory::~CSpartyFactory()
{
}

/** This is a concrete factory method that creates our Harold actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CSpartyFactory::Create()
{
    shared_ptr<CActor> actor = make_shared<CActor>(L"Sparty");

    auto torso = make_shared<CImageDrawable>(L"Torso", L"images/sparty_torso.png");
    torso->SetCenter(Point(70, 100));
    torso->SetPosition(Point(0, -200));
    actor->SetRoot(torso);

    auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/sparty_lleg.png");
    lleg->SetCenter(Point(40, 20));
    lleg->SetPosition(Point(30, 80));
    torso->AddChild(lleg);

    auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/sparty_rleg.png");
    rleg->SetCenter(Point(40, 20));
    rleg->SetPosition(Point(-30, 80));
    torso->AddChild(rleg);

    auto larm = make_shared<CImageDrawable>(L"Left Arm", L"images/sparty_larm.png");
    larm->SetCenter(Point(20, 20));
    larm->SetPosition(Point(50, -80));
    torso->AddChild(larm);

    auto rarm = make_shared<CImageDrawable>(L"Right Arm", L"images/sparty_rarm.png");
    rarm->SetCenter(Point(90, 20));
    rarm->SetPosition(Point(-50, -80));
    torso->AddChild(rarm);

    auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/sparty_lhead.png");
    headb->SetCenter(Point(55, 20));
    headb->SetPosition(Point(0, -90));
    torso->AddChild(headb);

    auto headt = make_shared<CHeadTop>(L"Head Top", L"images/sparty_head.png");
    headt->SetCenter(Point(50, 140));
    headt->SetPosition(Point(-2, -18));
    headb->AddChild(headt);
    headt->SetEyesCenter(Point(54, 110));
    headt->GetLeftEye()->LoadImage(L"images/sparty_leye.png");
    headt->GetLeftEye()->SetCenter(Point(14, 14));
    headt->GetRightEye()->LoadImage(L"images/sparty_reye.png");
    headt->GetRightEye()->SetCenter(Point(17, 16));
    headt->SetInterocularDistance(30);

	auto mug = make_shared<CImageDrawable>(L"Mug", L"images/mug.png");
	mug->SetCenter(Point(0, 30));
	mug->SetPosition(Point(-50, 125));
	rarm->AddChild(mug);

    actor->AddDrawable(lleg);
    actor->AddDrawable(rleg);
    actor->AddDrawable(torso);
    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);
	actor->AddDrawable(mug);
    actor->AddDrawable(headb);
    actor->AddDrawable(headt);

    return actor;
}
