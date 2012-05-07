#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

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
private:
    struct TextureData;
    TextureData* data;
};

} // end namespace vik

#endif // TEXTURE_H_INCLUDED
