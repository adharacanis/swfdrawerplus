#include "ByteArray.h"

UByte ByteArray::readUnsignedByte()
{
    UByte value = ByteArray::m_data.get(m_position);
    m_position += 1l;
    return value;
}

int ByteArray::readInt()
{
    int value = ByteArray::m_data.getInt32(m_position);
    m_position += 4l;
    return value;
}

short ByteArray::readShort()
{
    short value = ByteArray::m_data.getInt16(m_position);
    m_position += 2l;
    return value;
}
