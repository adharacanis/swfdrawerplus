#ifndef WITHTHEBOOST_ASSETMANAGER_H
#define WITHTHEBOOST_ASSETMANAGER_H

#include "AtlasExporter.h"
#include "TextureStorage.h"
#include "TextureManager.h"
#include "AssetLoader.h"

class AssetManager
{
public:
    AssetManager(ShapeLibrary& shapesLibrary, TextureStorage& textureStorage, TextureManager& textureManager);
    
    void loadAssets();
    void onAssetsLoaded();
    void parseAssets(const std::string& path);

protected:
    AssetsStorage m_assetStorage;
    AssetLoader m_assetLoader;
    AtlasExporter m_exporter;
    
    ShapeLibrary& m_shapesLibrary;
    TextureStorage& m_textureStorage;
    TextureManager& m_textureManager;
};


#endif //WITHTHEBOOST_ASSETMANAGER_H
