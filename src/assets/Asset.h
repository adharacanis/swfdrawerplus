#ifndef WITHTHEBOOST_ASSET_H
#define WITHTHEBOOST_ASSET_H

#include <string>

template <class T>
class Asset
{
public:
    Asset(std::string name, std::string extension, T content)
    : m_name(name)
    , m_extension(extension)
    , m_content(content)
    {};
    
    T& getContent()
    {
        return m_content;
    };

protected:
    std::string m_name;
    std::string m_extension;
    T m_content;
};

#endif //WITHTHEBOOST_ASSET_H
