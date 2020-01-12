#include "AssetManager.h"
#include "utils/ByteArray.h"

AssetManager::AssetManager(ShapeLibrary& shapesLibrary, TextureStorage& textureStorage, TextureManager& textureManager)
: m_shapesLibrary(shapesLibrary)
, m_textureStorage(textureStorage)
, m_textureManager(textureManager)
, m_assetLoader(m_assetStorage)
{}

void AssetManager::loadAssets()
{
    std::cout << "Start load assets" << std::endl;
    m_assetLoader.addToQueue("bikerUncompress.ani");
    m_assetLoader.load();
    
    onAssetsLoaded(); // only one thread so it complete immediate
}

void AssetManager::onAssetsLoaded()
{
    std::cout << "Load complete" << std::endl;
    parseAssets("bikerUncompress.ani");
}

void AssetManager::parseAssets(const std::string& path)
{
    std::cout << "parse assets" << std::endl;
    boost::shared_ptr<BinaryAsset> asset = m_assetStorage.getAsset(path);
    
    if (asset == nullptr)
        throw "something went wrong, call parse asset but BinaryAsset is not found";
    
    ByteArray data = asset->getContent();
    m_exporter.importAtlas(data, m_shapesLibrary);
}
