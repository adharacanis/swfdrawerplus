#ifndef WITHTHEBOOST_ATLASEXPORTER_H
#define WITHTHEBOOST_ATLASEXPORTER_H

#include "..//TextureSource.h"
#include "../utils/ByteArray.h"
#include "../data/ShapeLibrary.h"

class AtlasExporter
{
public:
    AtlasExporter();

    virtual ~AtlasExporter();

    TextureSource<Bytes>* importAtlas(ByteArray& input, ShapeLibrary& shapesList);
};


#endif //WITHTHEBOOST_ATLASEXPORTER_H
