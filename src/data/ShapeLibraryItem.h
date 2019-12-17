#ifndef WITHTHEBOOST_SHAPELIBRARYITEM_H
#define WITHTHEBOOST_SHAPELIBRARYITEM_H

#include "Matrix.h"
#include "TextureTransform.h"
#include "ShapeData.h"

class ShapeLibraryItem
{
public:
    ShapeLibraryItem(boost::shared_ptr<ShapeData> shapeData)
    : m_shapeData(shapeData)
    {};
    
    ShapeLibraryItem(const ShapeLibraryItem& other) = delete;
    ShapeLibraryItem(const ShapeLibraryItem&& other) = delete;
    
    boost::shared_ptr<ShapeData> getShapeData();
    
    void clear();
    float correctScale(float a, float a2);
    void checkTransform(Matrix matrix, float tx, float ty);

protected:
    boost::shared_ptr<ShapeData> m_shapeData;
    TextureTransform transform;
};


#endif //WITHTHEBOOST_SHAPELIBRARYITEM_H
