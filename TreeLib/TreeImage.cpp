/**
 * \file TreeImage.cpp
 *
 * \author Niklas Baumgardner
 */

#include "pch.h"
#include "TreeImage.h"

using namespace std;
using namespace Gdiplus;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

void CTreeImage::LoadImage(const std::wstring& filename)
{
	mImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (mImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}

void CTreeImage::DrawImage(Gdiplus::Graphics* graphics, double angle, double scale, double x, double y)
{
	auto state = graphics->Save();
	graphics->TranslateTransform((float)x, (float)y);
	graphics->RotateTransform((float)(angle * RtoD));
	graphics->ScaleTransform((float)scale, (float)scale);
	graphics->DrawImage(mImage.get(), -(int)mImage->GetWidth() / 2, -(int)mImage->GetHeight(), mImage->GetWidth(), mImage->GetHeight());
	graphics->Restore(state);
}