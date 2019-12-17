#ifndef WITHTHEBOOST_TEXTURETRANSFORM_H
#define WITHTHEBOOST_TEXTURETRANSFORM_H


#include <ostream>

class TextureTransform
{
public:
    TextureTransform(float tx = 0, float ty = 0, float scaleX = 1, float scaleY = 1)
            : tx(tx), ty(ty), scaleX(scaleX), scaleY(scaleY)
    {
    }

    friend std::ostream &operator<<(std::ostream &os, const TextureTransform &transform)
    {
        os << "tx: " << transform.tx << " ty: " << transform.ty << " scaleX: " << transform.scaleX << " scaleY: "
           << transform.scaleY;
        return os;
    }


public:
    float tx, ty;
    float scaleX, scaleY;
};


#endif //WITHTHEBOOST_TEXTURETRANSFORM_H
