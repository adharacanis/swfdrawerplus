#include "AssetsStorage.h"
#include <boost/assign/ptr_list_inserter.hpp>

using namespace boost;

shared_ptr<BinaryAsset> AssetsStorage::getAsset(std::string name)
{
    return m_binaryAssets[name];
}

void AssetsStorage::addAsset(std::string name, std::string extension, Bytes data)
{
    shared_ptr<BinaryAsset> content = shared_ptr<BinaryAsset>(new BinaryAsset(name, extension, data));
    m_binaryAssets.insert(std::make_pair(name, content));
    //ptr_insert<BinaryAsset>(m_binaryAssets)(new BinaryAsset(name, extension, data));
}
