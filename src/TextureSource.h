#ifndef WITHTHEBOOST_TEXTURESOURCE_H
#define WITHTHEBOOST_TEXTURESOURCE_H

template <class T>
class TextureSource
{
public:
    TextureSource(T* source, int width, int height) : source(source), width(width), height(height)
    {
    }

    virtual ~TextureSource()
    {

    }

    T* getSource() const
    {
        return source;
    }

    void setSource(T* source)
    {
        TextureSource::source = source;
    }

    int getWidth() const
    {
        return width;
    }

    void setWidth(int width)
    {
        TextureSource::width = width;
    }

    int getHeight() const
    {
        return height;
    }

    void setHeight(int height)
    {
        TextureSource::height = height;
    }

protected:
    T* source;

    int width, height;
};


#endif //WITHTHEBOOST_TEXTURESOURCE_H
