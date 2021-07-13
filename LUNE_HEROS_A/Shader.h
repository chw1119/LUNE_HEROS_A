#ifndef SHADER_H
#define SHADER_H

#include "./modules/glew-2.1.0-win32/glew-2.1.0/include/GL/glew.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>




class Shader
{

private:

public:
    unsigned int ID;

    Shader();

    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

    ~Shader();


    void Use();

    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
};

#endif