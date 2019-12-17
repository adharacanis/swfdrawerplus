#include "ShapeLibraryItem.h"

boost::shared_ptr<ShapeData> ShapeLibraryItem::getShapeData()
{
    return m_shapeData;
}

void ShapeLibraryItem::clear()
{
}

float ShapeLibraryItem::correctScale(float a, float a2)
{
    if (a == a2)
        return a2;
    
    if (a < 0)
        a = -a;
    
    if (a > a2)
        return a;
    else
        return a2;
}

void ShapeLibraryItem::checkTransform(Matrix matrix, float tx, float ty)
{
    transform.scaleX = correctScale(matrix.a, transform.scaleX);  //Math.max(Math.abs(matrix.a), transform.scaleX);
    transform.scaleY = correctScale(matrix.d, transform.scaleY);  //Math.max(Math.abs(matrix.d), transform.scaleY);
    
    transform.tx = tx;
    transform.ty = ty;
    
}
