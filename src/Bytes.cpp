#include "Bytes.h"

using namespace boost;

Bytes::~Bytes()
{

}

std::vector<unsigned char>* Bytes::getData()
{
    return &m_bytes;
}

unsigned char Bytes::get(long index) const
{
    return m_bytes[index];
}

void Bytes::set(long index, unsigned char value)
{
    m_bytes[index] = value;
}

void Bytes::blit(unsigned long len, Bytes& src, unsigned long srcPos, unsigned long outPos)
{
    //TODO: mb memcopy?
    for(unsigned long i = 0; i < len; i++) {
        set(i, src.get(srcPos + i));
    }
}

long Bytes::getSize() const
{
    return m_size;
}

void Bytes::setSize(long)
{

}

//unsigned char* Bytes::getData() {
//    return m_bytes;
//}

int Bytes::getInt32(long index) const
{
    unsigned char byte1 = get(index);
    unsigned char byte2 = get(index + 1);
    unsigned char byte3 = get(index + 2);
    unsigned char byte4 = get(index + 3);

    int value;

    if (m_endian == Little)
        value = (byte4 << 24) | (byte3 << 16) | (byte2 << 8) | byte1;
    else
        value = (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4;

    //if ((value & 0x80000000) != 0)
    //    return value | 0x80000000;
    //else
    //    return value;
    return value;
}

int Bytes::setInt32(long, int)
{
    return 0;
}

int Bytes::getInt16(long index) const
{
    unsigned char byte1 = get(index);
    unsigned char byte2 = get(index + 1);

    int value;

    if (m_endian == Little)
        value = ((byte2 << 8) | byte1);
    else
        value = ((byte1 << 8) | byte2);

    if ((value & 0x8000) != 0)
        return value - 0x10000;
    else
        return value;
}

void Bytes::setInt16(long, int)
{

}

void Bytes::setEndian(Endian endian)
{
    m_endian = endian;
}

Endian Bytes::getEndian() const
{
    return m_endian;
}


