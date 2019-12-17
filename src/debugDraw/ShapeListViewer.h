#ifndef WITHTHEBOOST_SHAPELISTVIEWER_H
#define WITHTHEBOOST_SHAPELISTVIEWER_H


#include <GL/glew.h>
#include "ShapeLibrary.h"
#include "IUpdatable.h"

class ShapeListViewer: public IUpdatable
{
public:
    ShapeListViewer(ShapeLibrary& shapeLibrary);
    
    void initialize();
    void setupTexture();
    void setupGeometry();
    void setupShader();
    GLuint compileShader(std::string shaderSource, uint shaderType);
    void update() override;

protected:
    ShapeLibrary& m_shapeLibrary;
    
    unsigned int VBO, VAO, EBO;
    GLuint m_shaderProgram;
};


#endif //WITHTHEBOOST_SHAPELISTVIEWER_H
