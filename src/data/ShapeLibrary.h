#ifndef WITHTHEBOOST_SHAPELIBRARY_H
#define WITHTHEBOOST_SHAPELIBRARY_H

#include "ShapeLibraryItem.h"
#include "ShapeData.h"
#include <map>

class ShapeLibrary
{
public:
    std::map<TextureID, boost::shared_ptr<ShapeLibraryItem>>& getShapesMap();
    boost::shared_ptr<ShapeData> getShape(TextureID id);
    
    void clear(bool clearChihlds);
    void addShape(boost::shared_ptr<ShapeData> shapeData);

protected:
    int m_numShapes = {};
    std::map<TextureID, boost::shared_ptr<ShapeLibraryItem>> m_shapes;
};

#endif //WITHTHEBOOST_SHAPELIBRARY_H
