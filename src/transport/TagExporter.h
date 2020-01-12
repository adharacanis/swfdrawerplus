#ifndef WITHTHEBOOST_TAGEXPORTER_H
#define WITHTHEBOOST_TAGEXPORTER_H

#include "PackerTagExporter.h"
#include <map>
#include <vector>
#include "tags/PackerTag.h"
#include "../utils/ByteArray.h"

enum class ExporterTypes
{
    END,
    SHOW_FRAME,
    DEFINE_SPRITE,
    PLACE_OBJECT,
    REMOVE_OBJECT,
    SYMBOL_CLASS,
};

class TagExporter
{
public:
    TagExporter();
    
    void importTags(std::vector<PackerTag*>& tags, ByteArray& input);

protected:
    PackerTag* importSingleTag(ByteArray& input);
    void initialize();
    
    std::map<ExporterTypes, PackerTagExporter*> exporters;
    std::map<ExporterTypes, PackerTagExporter*> importers;
};


#endif //WITHTHEBOOST_TAGEXPORTER_H
