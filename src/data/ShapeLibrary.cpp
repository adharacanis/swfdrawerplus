#include <iostream>
#include "ShapeLibrary.h"

using namespace std;

boost::shared_ptr<ShapeData> ShapeLibrary::getShape(TextureID id)
{
    return m_shapes[id]->getShapeData();
}

std::map<TextureID, boost::shared_ptr<ShapeLibraryItem>>& ShapeLibrary::getShapesMap()
{
    return m_shapes;
}

void ShapeLibrary::clear(bool clearChilds)
{

}

void ShapeLibrary::addShape(boost::shared_ptr<ShapeData> shapeData)
{
    //std::cout << "add shape " << int(shapeData.m_characterId) << std::endl;
    //auto shapeIterator = m_shapes.find(shapeData.m_characterId);
    //if (shapeIterator != m_shapes.end())
    //    return;
    auto shapeLibraryItem = boost::shared_ptr<ShapeLibraryItem>(new ShapeLibraryItem(shapeData));
    m_shapes.insert(std::make_pair(shapeData->m_characterId, shapeLibraryItem));
}
