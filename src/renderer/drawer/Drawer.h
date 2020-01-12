#pragma once

#include "IDrawer.h"
#include "display/DisplayObject.h"

class Drawer : public IDrawer
{
public:
	Drawer() = default;
	void draw(const boost::shared_ptr<DisplayObject>& drawable, DrawingData drawingData) override;
};

