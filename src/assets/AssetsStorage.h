#ifndef WITHTHEBOOST_ASSETSSTORAGE_H
#define WITHTHEBOOST_ASSETSSTORAGE_H


#include "BinaryAsset.h"
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/optional.hpp>
#include <map>
#include <iostream>

class AssetsStorage
{
public:
    AssetsStorage(){};
    //AssetsStorage(const AssetsStorage&) = delete;
    AssetsStorage(const AssetsStorage& other)
    {
        std::cout << "copy constructor" << std::endl;
    };
    
    AssetsStorage(const AssetsStorage&& other) noexcept
    {
        std::cout << "move constructor" << std::endl;
    };
    
    AssetsStorage operator=(AssetsStorage& t)
    {
        return *this;
    };
    
    boost::shared_ptr<BinaryAsset> getAsset(std::string name);
    void addAsset(std::string name, std::string extension, Bytes data);
    
    std::map<std::string, boost::shared_ptr<BinaryAsset>> m_binaryAssets;
};


#endif //WITHTHEBOOST_ASSETSSTORAGE_H
