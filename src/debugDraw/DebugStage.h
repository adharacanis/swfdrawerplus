#ifndef WITHTHEBOOST_DEBUGSTAGE_H
#define WITHTHEBOOST_DEBUGSTAGE_H

#include "Stage.h"
#include "ShapeListViewer.h"
#include "AssetManager.h"

class DebugStage: public Stage
{
public:
    DebugStage();
    
    void initialize();
    void update() override;

protected:
    TextureManager m_textureManager;
    TextureStorage m_textureStorage;
    AssetManager m_assetManager;
    
    ShapeLibrary m_shapeLibrary;
    ShapeListViewer m_shapeListViewer;
};


#endif //WITHTHEBOOST_DEBUGSTAGE_H
