#ifndef WITHTHEBOOST_ASSETLOADER_H
#define WITHTHEBOOST_ASSETLOADER_H

#include <string>
#include "AssetsStorage.h"

class AssetLoader
{
public:
    AssetLoader(AssetsStorage& assetStorage)
    : m_assetStorage(assetStorage)
    {};
    
    void addToQueue(const std::string& path);
    void load();

protected:
    bool isBinary(const std::string& extension);
    void loadNext();
    std::string getExtension(const std::string& path);
    void loadComplete(Bytes& data);
    void finishLoading();
    void loadBinary(std::string& path);
    
    bool m_isLoadingInProgress = false;
    
    AssetsStorage& m_assetStorage;
    std::vector<std::string> m_loadQue;
    std::vector<std::string> m_binaryTypes {"animation", "ani", "ppx", "jpg", "jpeg", "png"};
    
    std::string m_currentLoading;
};


#endif //WITHTHEBOOST_ASSETLOADER_H
