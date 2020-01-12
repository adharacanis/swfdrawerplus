#pragma once

#include <boost/smart_ptr/shared_ptr.hpp>

#include "DrawingData.h"
#include "display/DisplayObject.h"

class IDrawer
{
public:
	virtual ~IDrawer() = 0;
	virtual void draw(const boost::shared_ptr<DisplayObject>& drawable, DrawingData drawingData) = 0;
};

inline IDrawer::~IDrawer() = default;