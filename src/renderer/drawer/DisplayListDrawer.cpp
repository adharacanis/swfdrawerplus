#include "DisplayListDrawer.h"
#include "ShapeDrawer.h"
#include <boost/make_shared.hpp>

DisplayListDrawer::DisplayListDrawer(boost::shared_ptr<TextureStorage> textureStorage)
	: m_textureStorage(std::move(textureStorage))
{
	initialize();
}

void DisplayListDrawer::initialize()
{
	const auto shapeDrawer = boost::make_shared<ShapeDrawer>(m_textureStorage);

	m_drawerMap[DisplayObjectType::SHAPE] = shapeDrawer;
}

void DisplayListDrawer::drawDisplayObject(const boost::shared_ptr<DisplayObject>& displayObject,
	const boost::shared_ptr<Matrix>& transform)
{
	draw(displayObject, m_drawingData);
}

void DisplayListDrawer::draw(const boost::shared_ptr<DisplayObject>& drawable, DrawingData drawingData)
{
	const auto type = drawable->getDisplayObjectType();
	auto drawer = m_drawerMap[type];

	if (drawer)
	{
		drawer->draw(drawable, drawingData);
	}
	else
	{
		std::cout << "drawer for DRAWABLE is not defined" << std::endl;
	}
}
