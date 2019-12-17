#ifndef WITHTHEBOOST_BINARYASSET_H
#define WITHTHEBOOST_BINARYASSET_H

#include "Bytes.h"
#include "Asset.h"

class BinaryAsset: public Asset<Bytes>
{
public:
    BinaryAsset(std::string name, std::string extension, Bytes content)
    : Asset(name, extension, content)
    {};
    
    /*
    BinaryAsset(BinaryAsset&& other)
    : Asset(other.m_name, other.m_extension, other.m_content)
    {};*/
    
};


#endif //WITHTHEBOOST_BINARYASSET_H
