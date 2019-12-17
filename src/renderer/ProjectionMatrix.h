#ifndef WITHTHEBOOST_PROJECTIONMATRIX_H
#define WITHTHEBOOST_PROJECTIONMATRIX_H

#include <vector>

class ProjectionMatrix
{
public:
    ProjectionMatrix(std::vector<float> data)
    : m_data(data)
    {}
    
    //void ortho(p_width:Float, p_height:Float, p_transform:Matrix3D = null)

protected:
    std::vector<float> m_data;
};


#endif //WITHTHEBOOST_PROJECTIONMATRIX_H
