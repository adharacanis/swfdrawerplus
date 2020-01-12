#pragma once

#include <iostream>

class TextureID
{
public:
    TextureID(int textureID, int atlasID)
    : m_textureID(textureID)
    , m_atlasID(atlasID)
    {
        m_value = m_textureID << 16 | m_atlasID;
    }

	TextureID(const TextureID& other)
		: m_textureID(other.m_textureID)
		, m_atlasID(other.m_atlasID)
		, m_value(other.m_value)
	{}

	TextureID(TextureID&& other) noexcept
		: m_textureID(other.m_textureID)
		, m_atlasID(other.m_atlasID)
		, m_value(other.m_value)
	{}

	TextureID& operator=(const TextureID& other)
	{
		if (this == &other)
			return *this;
		m_textureID = other.m_textureID;
		m_atlasID = other.m_atlasID;
		m_value = other.m_value;
		return *this;
	}

	TextureID& operator=(TextureID&& other) noexcept
	{
		if (this == &other)
			return *this;
		m_textureID = other.m_textureID;
		m_atlasID = other.m_atlasID;
		m_value = other.m_value;
		return *this;
	}

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
