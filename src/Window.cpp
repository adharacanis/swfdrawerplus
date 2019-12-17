#include "Window.h"

#define GLEW_STATIC
#include "GL/glew.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>

#include "Bytes.h"
#include "AtlasExporter.h"

using namespace std;

const GLint WIDTH = 800, HEIGHT = 600;

// Shaders
const GLchar* vertexShaderSource =
        "#version 330 core\n"\
        "layout (location = 0) in vec3 m_position;\n"
        "layout (location = 1) in vec3 colors;\n"
        "layout (location = 2) in vec2 vertexUV;\n"
        "out vec2 UV;\n"
        "void main()\n"
        "{\n"
        "gl_Position = vec4(m_position.x, m_position.y, m_position.z, 1.0);\n"
        "UV = vertexUV;\n"
        "}\0";

const GLchar* fragmentShaderSource =
        "#version 330 core\n"
        "in vec2 UV;\n"
        "out vec4 color;\n"
        "uniform sampler2D myTextureSampler;\n"
        "void main()\n"
        "{\n"
        //"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "color = texture(myTextureSampler, UV).rgba;\n"
        "}\n\0";

TextureSource<Bytes>* parseFile() {
    fstream file("bikerUncompress.ani", ios_base::in | ios_base::binary);
    
    file.seekg (0, file.end);
    cout << "file stream size: " << file.tellg() << endl;
    unsigned long size = static_cast<unsigned long>(file.tellg());
    file.seekg (0, file.beg);
    
    Bytes input(size);
    
    std::vector<unsigned char>* inputVector = input.getVectorData();
    
    //inputVector->insert(inputVector->begin(),
    //        std::istream_iterator<unsigned char>(file),
    //        std::istream_iterator<unsigned char>());
    
    file.read(reinterpret_cast<char*>(inputVector->data()), size);
    file.clear();
    file.seekg (0, file.beg);
    file.close();
    
    //unflate(input, out);
    
    int padding = input.get(0);
    int atlasSize = input.getInt32(1);
    int w = input.getInt16(5);
    int h = input.getInt16(7);
    
    ByteArray bytes(input);
    
    cout << "read BA " << bytes.readUnsignedByte() << ", " << bytes.readInt() << ", " << bytes.readShort() << ", " << bytes.readShort() << endl;
    cout << padding << ", " << atlasSize << ", " << w << ", " << h << endl;
    
    bytes.setPosition(0);
    
    AtlasExporter* exporter = new AtlasExporter();
    ShapeLibrary shapeLibrary;
    
    return exporter->importAtlas(bytes, shapeLibrary);
    //unsigned char* pixels = new unsigned char(atlasSize);
    //memcpy(pixels, iin + 9, atlasSize);
    
    //return iin;
}

Window::Window()
{

}

int Window::initialize()
{
    glewExperimental = GL_TRUE;
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL", nullptr, nullptr);
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    if (window == nullptr)
        std::cout << "Failed to initalize window" << std::endl;
    
    glfwMakeContextCurrent(window);
    
    if (GLEW_OK != glewInit()) {
        std::cout << "Faild to initalize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    
    glViewport(0, 0, screenWidth, screenHeight);
    
    // Build and compile our shader program
    // Vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
    
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    
    // Check for compile time errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    
    // Link shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    
    // Set up vertex m_data (and buffer(s)) and attribute pointers
    float vertices[] = {
            // positions          // colors           // texture coords
            0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
            0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
    };
    unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };
    
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    // m_position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
    
    
    glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
    
    GLuint textureID;
    glGenTextures(1, &textureID);

// "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);

// Give the image to OpenGL
    TextureSource<Bytes>* textureSource = parseFile();
    std::vector<unsigned char>* pixels = textureSource->getSource()->getData();
    
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 256, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, pixels->data());
    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 16, 0, GL_BGRA, GL_UNSIGNED_INT_8_8_8_8, pixels);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    stage.initialize();
    
    unsigned int frameCount = 0;
    double previousTime = 0.0;
    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        double currentTime = glfwGetTime();
        frameCount++;
        // If a second has passed.
        if ( currentTime - previousTime >= 1.0 )
        {
            // Display the frame count here any way you want.
            cout << frameCount << endl;
            
            frameCount = 0;
            previousTime = currentTime;
        }
        
        
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        
        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Draw our first triangle
        glUseProgram(shaderProgram);
        
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        
        update();
        
        // Swap the screen buffers
        glfwSwapBuffers(window);
        
        usleep(1000000);
    }
    
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    
    return EXIT_SUCCESS;
}

void Window::update()
{
    stage.update();
}
