#ifndef WITHTHEBOOST_DEFINESPRITEEXPORTER_H
#define WITHTHEBOOST_DEFINESPRITEEXPORTER_H

#include "PackerTagExporter.h"
#include "TagExporter.h"

class DefineSpriteExporter: public PackerTagExporter
{
public:
    DefineSpriteExporter(TagExporter& tagExporter);
};

#endif //WITHTHEBOOST_DEFINESPRITEEXPORTER_H
