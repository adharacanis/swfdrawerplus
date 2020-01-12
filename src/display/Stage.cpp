#include "Stage.h"
#include <boost/make_shared.hpp>

void Stage::update()
{
	for (auto element : m_displayObjects)
	{
		boost::shared_ptr<IUpdatable> updatable = boost::dynamic_pointer_cast<IUpdatable>(element);
		if (updatable)
		{
			updatable->update();
		}
	}

	for (auto element : m_displayObjects)
	{
		m_displayListDrawer.drawDisplayObject(element, boost::make_shared<Matrix>());
	}
}
