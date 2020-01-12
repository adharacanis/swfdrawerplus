#pragma once

#include "DisplayObjectContainer.h"
#include "renderer/drawer/DisplayListDrawer.h"

class Stage: public DisplayObjectContainer
{
public:
    Stage(boost::shared_ptr<TextureStorage> textureStorage)
	: m_displayListDrawer(textureStorage)
	, m_textureStorage(std::move(textureStorage))
	{}

	void update() override;
	
	~Stage() = default;;

private:
    DisplayListDrawer m_displayListDrawer;
	boost::shared_ptr<TextureStorage> m_textureStorage;
};
