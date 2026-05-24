#include "ResourceManager.h"
#include "raylib.h"

bool ResourceManager::LoadFont(const char* fontFilePath) {
    return Get().LoadFontInternal(fontFilePath);
}

bool ResourceManager::LoadFontInternal(const char* fontFilePath) {
    m_MainFont = LoadFontEx(fontFilePath, 32, nullptr, 0);
    return IsFontValid(m_MainFont);
}

Font ResourceManager::GetMainFont() {
    return Get().GetMainFontInternal();
}

Font ResourceManager::GetMainFontInternal() const {
    return m_MainFont;
}

void ResourceManager::Unload() {
    return Get().UnloadInternal();
}

void ResourceManager::UnloadInternal() const {
    if (IsFontValid(m_MainFont)) {
        UnloadFont(m_MainFont);
    }
}