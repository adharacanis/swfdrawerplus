#ifndef WITHTHEBOOST_SHAPELIBRARY_H
#define WITHTHEBOOST_SHAPELIBRARY_H

#include "ShapeLibraryItem.h"
#include "display/Shape.h"
#include <map>

class ShapeLibrary
{
public:
    std::map<TextureID, boost::shared_ptr<ShapeLibraryItem>>& getShapesMap();
    boost::shared_ptr<Shape> getShape(TextureID id);
    
    void clear(bool clearChihlds);
    void addShape(boost::shared_ptr<Shape> shapeData);

protected:
    int m_numShapes = {};
    std::map<TextureID, boost::shared_ptr<ShapeLibraryItem>> m_shapes;
};

#endif //WITHTHEBOOST_SHAPELIBRARY_H
