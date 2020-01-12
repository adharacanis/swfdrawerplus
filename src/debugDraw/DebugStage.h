#ifndef WITHTHEBOOST_DEBUGSTAGE_H
#define WITHTHEBOOST_DEBUGSTAGE_H

#include "ShapeListViewer.h"
#include "../display/Stage.h"
#include "../texture/TextureStorage.h"
#include "../renderer/TextureManager.h"
#include "../AssetManager.h"

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
    ShapeListViewer m_shapeListViewer = m_shapeLibrary;
};


#endif //WITHTHEBOOST_DEBUGSTAGE_H
