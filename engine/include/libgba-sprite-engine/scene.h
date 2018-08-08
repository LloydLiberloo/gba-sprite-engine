//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_SCRENE_H
#define GBA_SPRITE_ENGINE_SCRENE_H

#include <vector>
#include <functional>
#include <libgba-sprite-engine/background/background.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/palette/palette_manager.h>

class GBAEngine;

class scene {
protected:
    std::unique_ptr<ForegroundPaletteManager> foregroundPalette;
    std::unique_ptr<BackgroundPaletteManager> backgroundPalette;
    std::shared_ptr<GBAEngine> engine;

public:
    ForegroundPaletteManager* getForegroundPalette() { return foregroundPalette.get(); }
    BackgroundPaletteManager* getBackgroundPalette() { return backgroundPalette.get(); }

    // WHY raw pointers? they're unwrapped unique_ptrs managed by the scene implementation - will be cleaned up in engine
    virtual std::vector<Sprite*> sprites() = 0;
    virtual std::vector<Background*> backgrounds() = 0;

    virtual void load() = 0;
    virtual void tick(u16 i) = 0;

    scene(std::shared_ptr<GBAEngine> engine) : engine(engine) { }
    virtual ~scene() {
        // scenes should manage their own resources - use std::unique_ptr
    }

};


#endif //GBA_SPRITE_ENGINE_SCRENE_H