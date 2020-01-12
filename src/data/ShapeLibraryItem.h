#ifndef WITHTHEBOOST_SHAPELIBRARYITEM_H
#define WITHTHEBOOST_SHAPELIBRARYITEM_H

#include "display/Shape.h"
#include "../geom/TextureTransform.h"
#include "../geom/Matrix.h"

class ShapeLibraryItem
{
public:
    ShapeLibraryItem(boost::shared_ptr<Shape> shapeData)
    : m_shapeData(shapeData)
    {};
    
    ShapeLibraryItem(const ShapeLibraryItem& other) = delete;
    ShapeLibraryItem(const ShapeLibraryItem&& other) = delete;
    
    boost::shared_ptr<Shape> getShapeData();
    
    void clear();
    float correctScale(float a, float a2);
    void checkTransform(Matrix matrix, float tx, float ty);

protected:
    boost::shared_ptr<Shape> m_shapeData;
    TextureTransform transform;
};


#endif //WITHTHEBOOST_SHAPELIBRARYITEM_H
