//
//  ShaderLoader.c
//  ShaderTest
//
//  Created by Dimitriy Dounaev on 4/05/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include <stdio.h>
#include "ShaderLoader.h"


void printShaderInfoLog(GLuint obj)
{
    int infologLength = 0;
    int charsWritten  = 0;
    char *infoLog;
    
    glGetShaderiv(obj, GL_INFO_LOG_LENGTH,&infologLength);
    
    if (infologLength > 0)
    {
        infoLog = (char *)malloc(infologLength);
        glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog);
        printf("%s\n",infoLog);
        free(infoLog);
    }
}

GLuint compileShader(GLenum shaderType,char *source)
{
    GLuint shaderHandle = glCreateShader(shaderType);
    glShaderSource(shaderHandle, 1, &source, NULL);
    glCompileShader(shaderHandle);
    
    printShaderInfoLog(shaderHandle);
    
    return shaderHandle;
}


GLuint createShaderProgram(char *sourceVS, char *sourceFS)
{
    GLuint programHandle = glCreateProgram();
    
    glAttachShader(programHandle, compileShader(GL_VERTEX_SHADER, sourceVS));
    glAttachShader(programHandle, compileShader(GL_FRAGMENT_SHADER, sourceFS));
    
    glLinkProgram(programHandle);
    
    return programHandle;
}