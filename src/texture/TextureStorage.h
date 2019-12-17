#ifndef WITHTHEBOOST_TEXTURESTORAGE_H
#define WITHTHEBOOST_TEXTURESTORAGE_H

#include "TextureID.h"
#include "ITexture.h"
#include <map>
#include <boost/shared_ptr.hpp>

class TextureStorage
{
public:
    TextureStorage(){};
    
    boost::shared_ptr<ITexture> getTexture(const TextureID textureID);
    void putTexture(TextureID textureID, boost::shared_ptr<ITexture> texture);
    
protected:
    std::map<TextureID, boost::shared_ptr<ITexture>> m_textures;
};


#endif //WITHTHEBOOST_TEXTURESTORAGE_H
