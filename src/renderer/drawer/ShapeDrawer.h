#pragma once

#include "Drawer.h"
#include "display/Shape.h"
#include "texture/TextureStorage.h"

class ShapeDrawer : public Drawer
{
public:
	ShapeDrawer(boost::shared_ptr<TextureStorage> textureStorage)
	: m_textureStorage(std::move(textureStorage))
	{}

	~ShapeDrawer() = default;

	void draw(const boost::shared_ptr<DisplayObject>& drawable, DrawingData drawingData) override;

private:
	boost::shared_ptr<TextureStorage> m_textureStorage;
};

