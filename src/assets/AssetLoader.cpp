#include "AssetLoader.h"
#include <iostream>
#include <fstream>

using namespace std;

void AssetLoader::addToQueue(const std::string& path)
{
    m_loadQue.push_back(path);
}

void AssetLoader::load()
{
    loadNext();
}

bool AssetLoader::isBinary(const string& extension)
{
    return find(m_binaryTypes.begin(), m_binaryTypes.end(), extension) != m_binaryTypes.end();
}

void AssetLoader::loadNext()
{
    if (m_isLoadingInProgress)
        return;
    
    m_currentLoading = m_loadQue.back();
    m_loadQue.pop_back();
    
    string extension = getExtension(m_currentLoading);
    bool isFileBinary = isBinary(extension);
    
    if (isFileBinary)
        loadBinary(m_currentLoading);
    else
        throw "unknown extension " + extension;
}

std::string AssetLoader::getExtension(const string& path)
{
    unsigned long extensionPosition = path.find_last_of('.') + 1;
    return path.substr(extensionPosition, 3);
}

void AssetLoader::loadComplete(Bytes& data)
{
    //unsigned long slashIndex = m_currentLoading.find_last_of("/") + 1;
    
    string extension = getExtension(m_currentLoading);
    string fileName = m_currentLoading;
    
    m_assetStorage.addAsset(fileName, extension, data);
    
    if (m_loadQue.size() == 0)
    {
        finishLoading();
    }
    else
    {
        loadNext();
    }
}

void AssetLoader::finishLoading()
{

}

void AssetLoader::loadBinary(string& path)
{
    fstream file(m_currentLoading, ios_base::in | ios_base::binary);
    
    file.seekg (0, file.end);
    unsigned long size = static_cast<unsigned long>(file.tellg());
    file.seekg (0, file.beg);
    
    Bytes input(size);
    
    std::vector<unsigned char>* inputVector = input.getVectorData();
    
    file.read(reinterpret_cast<char*>(inputVector->data()), size);
    file.clear();
    file.seekg (0, file.beg);
    file.close();
    
    loadComplete(input);
}
