#ifndef WITHTHEBOOST_ASSETMANAGER_H
#define WITHTHEBOOST_ASSETMANAGER_H

#include "data/ShapeLibrary.h"
#include "texture/TextureStorage.h"
#include "renderer/TextureManager.h"
#include "assets/AssetsStorage.h"
#include "transport/AtlasExporter.h"
#include "assets/AssetLoader.h"

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
