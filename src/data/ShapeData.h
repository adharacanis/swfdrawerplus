#ifndef WITHTHEBOOST_SHAPEDATA_H
#define WITHTHEBOOST_SHAPEDATA_H

#include <boost/shared_ptr.hpp>
#include "TextureID.h"
#include "Rectangle.h"

class ShapeData
{
public:
    ShapeData(TextureID characterID, boost::shared_ptr<RectangleFloat> shapeBounds)
    : m_characterId(characterID)
    , m_shapeBounds(shapeBounds) {}
    
    ShapeData(const ShapeData& other) = delete;
    ShapeData(const ShapeData&& other) = delete;
    
    TextureID m_characterId;
    boost::shared_ptr<RectangleFloat> m_shapeBounds;
};


#endif //WITHTHEBOOST_SHAPEDATA_H
