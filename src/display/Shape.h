#pragma once

#include <utility>

#include <boost/shared_ptr.hpp>

#include "geom/Rectangle.h"
#include "texture/TextureID.h"
#include "DisplayObject.h"

class Shape : public DisplayObject
{
public:
	Shape(const TextureID characterID, boost::shared_ptr<RectangleFloat> shapeBounds)
        : m_characterId(characterID)
        , m_shapeBounds(std::move(shapeBounds))
    {}
	
    Shape(const Shape& other) = delete;
    Shape(const Shape&& other) = delete;
	Shape& operator=(const Shape& other) = delete;
    Shape& operator=(Shape&& other) = delete;

    ~Shape() = default;

    TextureID getCharacterID() const;

private:
    TextureID m_characterId;
    boost::shared_ptr<RectangleFloat> m_shapeBounds;
};
