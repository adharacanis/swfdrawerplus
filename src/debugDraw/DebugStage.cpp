#include "DebugStage.h"

DebugStage::DebugStage()
: m_shapeListViewer(m_shapeLibrary)
, m_assetManager(m_shapeLibrary, m_textureStorage, m_textureManager)
{
    //initialize();
}

void DebugStage::initialize()
{
    std::cout << "DebugStage::initialize" << std::endl;
    m_assetManager.loadAssets();
    
    m_shapeListViewer.initialize();
}

void DebugStage::update()
{
    DisplayObjectContainer::update();
    m_shapeListViewer.update();
}
