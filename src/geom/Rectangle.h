#ifndef WITHTHEBOOST_RECTANGLE_H
#define WITHTHEBOOST_RECTANGLE_H

#include <type_traits>
#include <ostream>

template <class T>
class Rectangle
{
public:
    Rectangle(T m_x = 0, T m_y = 0, T m_width = 0, T m_height = 0) : m_x(m_x), m_y(m_y), m_width(m_width), m_height(m_height)
    {
    }

    virtual ~Rectangle()
    {

    }

    T getX()
    {
        return m_x;
    }

    void setX(T x)
    {
        m_x = x;
    }

    T getY()
    {
        return m_y;
    }

    void setY(T y)
    {
        m_y = y;
    }

    T getWidth()
    {
        return m_width;
    }

    void setWidth(T width)
    {
        m_width = width;
    }

    T getHeight()
    {
        return m_height;
    }

    void setHeight(T height)
    {
        m_height = height;
    }

    friend std::ostream &operator<<(std::ostream &os, const Rectangle& rectangle)
    {
        os << "m_x: " << rectangle.m_x << " m_y: " << rectangle.m_y << " m_width: " << rectangle.m_width
           << " m_height: " << rectangle.m_height;
        return os;
    }

protected:
    T m_x {}, m_y {}, m_width {}, m_height {};
};

class RectangleFloat: public Rectangle<float>
{
    using Rectangle<float>::Rectangle;
};


#endif //WITHTHEBOOST_RECTANGLE_H
