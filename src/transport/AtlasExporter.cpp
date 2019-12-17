#include "AtlasExporter.h"
#include "TextureSource.h"
#include "Rectangle.h"
#include "TextureTransform.h"
#include "ReadUtils.h"

#include <iostream>

AtlasExporter::AtlasExporter()
{

}

AtlasExporter::~AtlasExporter()
{

}

TextureSource<Bytes>* AtlasExporter::importAtlas(ByteArray& input, ShapeLibrary& shapesList)
{
    int padding = input.readUnsignedByte();
    unsigned long atlasSize = static_cast<unsigned long>(input.readInt());
    int width = input.readShort();
    int height = input.readShort();

    Bytes* textureData = new Bytes(atlasSize);
    textureData->blit(atlasSize, input.getData(), input.getPosition(), 0);
    TextureSource<Bytes>* textureSource = new TextureSource<Bytes>(textureData, width, height);
    input.setPosition(input.getPosition() + (long)atlasSize);
    
    int atlasID = 0; //TODO: get next atlas ID method

    std::cout << "padding: " << padding << " atlasSize: " << atlasSize << " width: " << width << " height: " << height << std::endl;

    int texturesCount = input.readShort();
    std::cout << "texturesCount: " << texturesCount << std::endl;
    for (int i = 0; i < texturesCount; i++)
    {
        short id = input.readShort();
        auto textureTransform = ReadUtils::readTransform(input);
        auto textureRegion = ReadUtils::readRectangle(input);
        auto shapeBounds = ReadUtils::readRectangle(input);

        //std::cout << "id: " << id << std::endl;
        //std::cout << "textureTransform: " << (*textureTransform) << std::endl;
        //std::cout << "textureRegion: " << (*textureRegion) << std::endl;
        //std::cout << "m_shapeBounds: " << (*m_shapeBounds) << std::endl;
    
        TextureID textureID(id, atlasID);
        
        auto shapeData = boost::shared_ptr<ShapeData>(new ShapeData(textureID, shapeBounds));
        shapesList.addShape(shapeData);
    }

    return textureSource;
}

