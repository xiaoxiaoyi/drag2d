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

#ifndef D2D_EDIT_RECT_OP_H
#define D2D_EDIT_RECT_OP_H

#include "ZoomViewOP.h"
#include "NodeCapture.h"

namespace d2d
{
	class MultiShapesImpl;
	class DrawRectCMPT;
	class ChainShape;

	class EditRectOP : public ZoomViewOP
	{
	public:
		EditRectOP(EditPanel* editPanel, MultiShapesImpl* shapesImpl,
			DrawRectCMPT* cmpt);

		virtual bool onMouseLeftDown(int x, int y);
		virtual bool onMouseLeftUp(int x, int y);
		virtual bool onMouseMove(int x, int y);
		virtual bool onMouseDrag(int x, int y);

		virtual bool onDraw() const;
		virtual bool clear();

	private:
		static bool isRect(const ChainShape* chain);

	private:
		MultiShapesImpl* m_shapesImpl;

		DrawRectCMPT* m_cmpt;

		Vector m_start, m_end;

		NodeAddr m_captured;

	}; // EditRectOP
}