#include "ShapeListViewer.h"
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

ShapeListViewer::ShapeListViewer(ShapeLibrary& shapeLibrary)
: m_shapeLibrary(shapeLibrary)
{}

void ShapeListViewer::initialize()
{
    setupTexture();
    setupGeometry();
    setupShader();
}

void ShapeListViewer::setupTexture()
{

}

void ShapeListViewer::setupGeometry()
{
    float size = 50.0f;
    float vertices[] = {
             // position             // texture coords
             size,  size, 0.0f,      1.0f, 1.0f,   // top right
             size, -size, 0.0f,      1.0f, 0.0f,   // bottom right
            -size, -size, 0.0f,      0.0f, 0.0f,   // bottom left
            -size,  size, 0.0f,      0.0f, 1.0f    // top left
    };
    unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    // m_position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void ShapeListViewer::setupShader()
{
    cout << "setup shaders" << endl;
    const std::string vertexShaderSource =
            "#version 330 core\n"
            "uniform mat4 projection;\n"
            "layout (location = 0) in vec3 m_position;\n"
            "layout (location = 1) in vec2 vertexUV;\n"
            "out vec2 UV;\n"
            "void main()\n"
            "{\n"
            "gl_Position = projection * vec4(m_position.x, m_position.y, m_position.z, 1.0);\n"
            "UV = vertexUV;\n"
            "}\0";
    
    const std::string fragmentShaderSource =
            "#version 330 core\n"
            "in vec2 UV;\n"
            "out vec4 color;\n"
            "uniform sampler2D myTextureSampler;\n"
            "void main()\n"
            "{\n"
            //"color = texture(myTextureSampler, UV).rgba;\n"
            "color = vec4(1, 1, 1, 0.005);\n"
            "}\n\0";
    
    GLint success;
    GLchar infoLog[512];
    
    GLuint vertexShader = compileShader(vertexShaderSource, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
    
    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, vertexShader);
    glAttachShader(m_shaderProgram, fragmentShader);
    glLinkProgram(m_shaderProgram);
    
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
    
    if (!success)
    {
        glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

GLuint ShapeListViewer::compileShader(std::string shaderSource, GLenum shaderType)
{
    cout << "compile shader " << shaderType << endl;
    
    GLuint shader = glCreateShader(shaderType);
    const char* shaderSourceRaw = shaderSource.c_str();
    glShaderSource(shader, 1, &shaderSourceRaw, NULL);
    glCompileShader(shader);
    
    GLint success;
    GLchar infoLog[512];
    
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    return shader;
}

void ShapeListViewer::update()
{
    cout << "ShapeListViewer::update" << endl;
    
    glm::mat4 projection = glm::ortho(0, 800, 600, 0);
    
    glUseProgram(m_shaderProgram);
    
    GLint projectionLocation = glGetUniformLocation(m_shaderProgram, "projection");
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0]);
    
    auto shapesList = m_shapeLibrary.getShapesMap();
    
    auto it = shapesList.begin();
    while (it != shapesList.end())
    {
        boost::shared_ptr<ShapeLibraryItem> libraryItem = it->second;
        boost::shared_ptr<ShapeData> content = libraryItem->getShapeData();
    
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    
        GLenum err;
        while((err = glGetError()) != GL_NO_ERROR)
        {
            cout << "error: " << err << endl;
        }
        
        //cout << *content->m_shapeBounds << endl;
        
        it++;
    }
}
