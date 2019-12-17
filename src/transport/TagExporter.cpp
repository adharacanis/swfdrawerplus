#include "TagExporter.h"
#include "SwfPackerTagExporter.h"
#include "DefineSpriteExporter.h"
#include "PlaceObjectExporter.h"
#include "RemoveObjectExporter.h"
#include "SymbolClassExporter.h"

TagExporter::TagExporter()
{

}

void TagExporter::importTags(std::vector<PackerTag*>& tags, ByteArray& input)
{
    //int index = 0;
    while (input.getPosition() != input.getLength())
    {
        PackerTag* tag = importSingleTag(input);
        
        if (tag == nullptr)
            break;
        
        tags.push_back(tag);
    }
}

PackerTag* TagExporter::importSingleTag(ByteArray& input)
{
    /*var tagType:Int = input.readUnsignedByte();
    
    var importer:SwfPackerTagExporter = importers[tagType];
    
    if (importer != null)
    {
        var constructor = tagConstructorsObject[tagType];
        var tag = constructor.createInstance();
        importer.importTag(tag, input);
        
        return tag;
    }
    else
        throw new Error("no importer for tag " + tagType);
    
    return null; */
    
    return nullptr;
}

void TagExporter::initialize()
{
    importers[ExporterTypes::END] = /*exporters[0] =*/ new SwfPackerTagExporter(ExporterTypes::END);
    importers[ExporterTypes::SHOW_FRAME] = /*exporters[1] =*/ new SwfPackerTagExporter(ExporterTypes::SHOW_FRAME);
    
    importers[ExporterTypes::DEFINE_SPRITE] = /*exporters[39] =*/ new DefineSpriteExporter(*this);
    importers[ExporterTypes::PLACE_OBJECT] = /*exporters[4] =*/ new PlaceObjectExporter();
    importers[ExporterTypes::REMOVE_OBJECT] = /*exporters[5] =*/ new RemoveObjectExporter();
    importers[ExporterTypes::SYMBOL_CLASS] = /*exporters[76] =*/ new SymbolClassExporter();
    
    /*tagConstructorsObject[ExporerTypes.END] = SwfPackerTagEnd;
    tagConstructorsObject[ExporerTypes.SHOW_FRAME] = SwfPackerTagShowFrame;
    tagConstructorsObject[ExporerTypes.DEFINE_SPRITE] = SwfPackerTagDefineSprite;
    tagConstructorsObject[ExporerTypes.PLACE_OBJECT] = SwfPackerTagPlaceObject;
    tagConstructorsObject[ExporerTypes.REMOVE_OBJECT] = SwfPackerTagRemoveObject;
    tagConstructorsObject[ExporerTypes.SYMBOL_CLASS] = SwfPackerTagSymbolClass; */
}
