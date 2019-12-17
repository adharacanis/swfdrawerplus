#include "TextureStorage.h"

using namespace boost;

boost::shared_ptr<ITexture> TextureStorage::getTexture(const TextureID textureID)
{
    auto map_iterator = m_textures.find(textureID);
    if (map_iterator != m_textures.end())
        return map_iterator->second;
    
    return nullptr;
}

void TextureStorage::putTexture(TextureID textureID, boost::shared_ptr<ITexture> texture)
{
    m_textures.emplace(textureID, texture);
}
