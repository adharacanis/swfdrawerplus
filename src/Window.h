#ifndef WITHTHEBOOST_WINDOW_H
#define WITHTHEBOOST_WINDOW_H

#include "IUpdatable.h"
#include "display/Stage.h"
#include "debugDraw/DebugStage.h"

class Window: public IUpdatable
{
public:
    Window();
    
    int initialize();
    
    void update() override;

protected:
    DebugStage stage;
    //Stage stage;
};


#endif //WITHTHEBOOST_WINDOW_H
