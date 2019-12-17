#ifndef WITHTHEBOOST_BYTES_H
#define WITHTHEBOOST_BYTES_H

#include <boost/shared_ptr.hpp>
#include <vector>

enum Endian {
    Big, Little
};

class Bytes {
public:
    Bytes(unsigned long size)
        : m_size(size)
        , m_bytes(size)
        {}
    
    std::vector<unsigned char>* getVectorData()
    {
        return &m_bytes;
    }
    
    std::vector<unsigned char>* getData();

    long getSize() const;
    void setSize(long);

    void setEndian(Endian);
    Endian getEndian() const;

    unsigned char get(long) const;
    void set(long, unsigned char);

    int getInt32(long) const;
    int setInt32(long, int);

    int getInt16(long) const;
    void setInt16(long, int);

    void blit(unsigned long, Bytes&, unsigned long, unsigned long);

    ~Bytes();
protected:
    long m_size;
    std::vector<unsigned char> m_bytes;
    Endian m_endian{Little};
};


#endif //WITHTHEBOOST_BYTES_H
