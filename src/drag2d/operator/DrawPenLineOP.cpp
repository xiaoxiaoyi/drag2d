/*
* Copyright (c) 2012-2013 Guang Zhu http://runnersoft.net
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#include "DrawPenLineOP.h"

#include "view/MultiShapesImpl.h"
#include "dataset/ChainShape.h"

using namespace d2d;

DrawPenLineOP::DrawPenLineOP(EditPanel* editPanel, MultiShapesImpl* shapesImpl)
	: DrawPolylineOP(editPanel, false)
	, m_shapesImpl(shapesImpl)
{
}

bool DrawPenLineOP::onMouseLeftDClick(int x, int y)
{
	if (DrawPolylineOP::onMouseLeftDClick(x, y)) return true;

	m_shapesImpl->insertShape(new ChainShape(m_polyline, false));
	m_polyline.clear();
	m_currPos.setInvalid();

	return false;
}
