#pragma once

#include <boost/smart_ptr/shared_ptr.hpp>

#include "IDrawer.h"
#include "texture/TextureStorage.h"
#include "display/DisplayObjectType.h"
#include "geom/Matrix.h"

class DisplayListDrawer : public IDrawer
{
public:
	DisplayListDrawer(boost::shared_ptr<TextureStorage> textureStorage);
	//~DisplayListDrawer() override;

	void initialize();

	void drawDisplayObject(const boost::shared_ptr<DisplayObject>& displayObject, const boost::shared_ptr<Matrix>& transform);
	void draw(const boost::shared_ptr<DisplayObject>& drawable, DrawingData drawingData) override;

private:
	boost::shared_ptr<TextureStorage> m_textureStorage;

	std::map<DisplayObjectType, boost::shared_ptr<IDrawer>> m_drawerMap;
	DrawingData m_drawingData;
};

