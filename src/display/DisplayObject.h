#pragma once

#include "DisplayObjectType.h"

class DisplayObject
{
public:
	DisplayObject() = default;
	~DisplayObject() = default;

	virtual DisplayObjectType getDisplayObjectType() const
	{
		return m_displayObjectType;
	}

	

private:
	DisplayObjectType m_displayObjectType {};
};

