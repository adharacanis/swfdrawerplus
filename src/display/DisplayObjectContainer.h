#ifndef WITHTHEBOOST_DISPLAYOBJECTCONTAINER_H
#define WITHTHEBOOST_DISPLAYOBJECTCONTAINER_H

#include "IUpdatable.h"

class DisplayObjectContainer: public IUpdatable
{
public:
    DisplayObjectContainer();
    
    virtual ~DisplayObjectContainer();
    
    void update() override;
    
    
};


#endif //WITHTHEBOOST_DISPLAYOBJECTCONTAINER_H
