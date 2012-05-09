#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include "viking/core/types.h"

namespace vik
{

class Texture
{
public:
    Texture();
    ~Texture();
    // return true if successful
    bool Load(const char* filename, bool useMipMap = false);
    void Free();
    void Bind();

    u32 GetWidth() const;
    u32 GetHeight() const;
private:
    struct TextureData;
    TextureData* data;
};

} // end namespace vik

#endif // TEXTURE_H_INCLUDED
