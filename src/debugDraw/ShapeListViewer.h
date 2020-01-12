#ifndef WITHTHEBOOST_SHAPELISTVIEWER_H
#define WITHTHEBOOST_SHAPELISTVIEWER_H

#include "../IUpdatable.h"
#include "../data/ShapeLibrary.h"
#include <GL/glew.h>
#include <string>

class ShapeListViewer: public IUpdatable
{
public:
    ShapeListViewer(ShapeLibrary& shapeLibrary);
    
    void initialize();
    void setupTexture();
    void setupGeometry();
    void setupShader();
    GLuint compileShader(std::string shaderSource, GLenum shaderType);
    void update() override;

protected:
    ShapeLibrary& m_shapeLibrary;
    
    unsigned int VBO, VAO, EBO;
    GLuint m_shaderProgram;
};


#endif //WITHTHEBOOST_SHAPELISTVIEWER_H
