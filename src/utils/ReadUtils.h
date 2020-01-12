
#ifndef WITHTHEBOOST_READUTILS_H
#define WITHTHEBOOST_READUTILS_H

#include <math.h>
#include <iostream>
#include "ByteArray.h"

static float FIXED_PRECISSION_VALUE = 65536;
static float FIXED_PRECISSION_VALUE_MULTIPLIER = 1 / FIXED_PRECISSION_VALUE;

inline float roundPixels20(float value)
{
    return round(value * 100) / 100;
}

inline float unpackValue(int value)
{
    return roundPixels20(static_cast<float>(value) / 20);
}

namespace ReadUtils {
    inline boost::shared_ptr<RectangleFloat> readRectangle(ByteArray& input)
    {
        int x = input.readInt();
        int w = input.readInt();
        int y = input.readInt();
        int h = input.readInt();

        return boost::shared_ptr<RectangleFloat>(new RectangleFloat(unpackValue(x), unpackValue(y), unpackValue(w), unpackValue(h)));
    }

    inline boost::shared_ptr<TextureTransform> readTransform(ByteArray& input)
    {
        float scaleX = 1;
        float scaleY = 1;

        if (input.readUnsignedByte() == 1)
        {
            int readX = input.readInt();
            scaleX = readX / FIXED_PRECISSION_VALUE;
            scaleY = input.readInt() / FIXED_PRECISSION_VALUE;
        }

        int translateX = input.readInt();
        int translateY = input.readInt();

        return boost::shared_ptr<TextureTransform>(new TextureTransform(scaleX, scaleY, translateX / 2000, translateY / 2000));
    }
}

#endif //WITHTHEBOOST_READUTILS_H
