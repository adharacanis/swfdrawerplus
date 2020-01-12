#ifndef WITHTHEBOOST_BYTEARRAY_H
#define WITHTHEBOOST_BYTEARRAY_H

#include "../Bytes.h"

typedef unsigned short UByte;
typedef short Byte;

class ByteArray
{
public:
    ByteArray()
    : m_data(1024)
    {};
    
    ByteArray(Bytes& a_data)
            : m_data(a_data)
    {};

    ByteArray(const Bytes& other) = delete;
    ByteArray(const Bytes&& other) = delete;

    ~ByteArray(){};
    
    int readInt();
    short readShort();
    float readFloat();
    UByte readUnsignedByte();
    Byte readByte();

    int get()
    {
        long pos = m_position;
        m_position += 1l;
        return m_data.get(pos);
    };

    template <typename T>
    T read(int length)
    {
        Endian endian = m_data.getEndian();
        T value;
        int mask = 0;

        if(endian == Little)
        {
            mask = 8 * length;
        }

        for(int i = 0; i < length; i++)
        {
            if(endian == Little) {
                value |= get() << mask;
                mask += 8;
            }
            else {
                value |= get() << mask;
                mask -= 8;
            }
        }

        return value;
    };

    unsigned long getPosition() const
    {
        return m_position;
    }

    void setPosition(unsigned long position)
    {
        ByteArray::m_position = position;
    }

    long getLength() const
    {
        return m_length;
    }

    void setLength(unsigned long length)
    {
        ByteArray::m_length = length;
    }

    Bytes& getData()
    {
        return m_data;
    }

protected:
    unsigned long m_position{0};
    unsigned long m_length;
    Bytes m_data;
};


#endif //WITHTHEBOOST_BYTEARRAY_H
