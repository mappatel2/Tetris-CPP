#ifndef TETRIS_RESOURCEMANAGER_H
#define TETRIS_RESOURCEMANAGER_H
#include "raylib.h"

class ResourceManager {
public:

    static ResourceManager& Get() {
        static ResourceManager instance;
        return instance;
    }

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    bool static LoadFont(const char*);
    Font static GetMainFont();
    void static Unload();

private:

    ResourceManager() = default;
    bool LoadFontInternal(const char*);
    void UnloadInternal() const;
    [[nodiscard]] Font GetMainFontInternal() const;

    Font m_MainFont = {0};

};

#endif //TETRIS_RESOURCEMANAGER_H
