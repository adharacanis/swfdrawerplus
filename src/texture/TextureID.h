#ifndef WITHTHEBOOST_TEXTUREID_H
#define WITHTHEBOOST_TEXTUREID_H

#include <iostream>

class TextureID
{
public:
    TextureID(int textureID, int atlasID)
    : m_textureID(textureID)
    , m_atlasID(atlasID)
    {
        m_value = m_textureID << 16 | m_atlasID;
    };
    
    operator int()
    {
        return m_value;
    }
    
    operator int() const
    {
        return m_value;
    }
    
    bool operator<(TextureID const& other) const
    {
        return m_value < other.m_value;
    }

protected:
    int m_textureID = {};
    int m_atlasID = {};
    int m_value = {};
};

#endif //WITHTHEBOOST_TEXTUREID_H
