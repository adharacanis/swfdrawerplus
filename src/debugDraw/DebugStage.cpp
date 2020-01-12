#include "DebugStage.h"
#include <boost/make_shared.hpp>

DebugStage::DebugStage()
	: Stage(boost::make_shared<TextureStorage>(m_textureStorage))
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
