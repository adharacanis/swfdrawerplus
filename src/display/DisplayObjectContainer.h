#pragma once

#include <vector>
#include <boost/smart_ptr/shared_ptr.hpp>

#include "IUpdatable.h"
#include "DisplayObject.h"

class DisplayObjectContainer: public IUpdatable
{
public:
    DisplayObjectContainer();
    
    virtual ~DisplayObjectContainer();
    
    void update() override;
    
protected:
    std::vector <boost::shared_ptr<DisplayObject>> m_displayObjects;
	
};
