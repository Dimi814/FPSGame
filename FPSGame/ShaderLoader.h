//
//  ShaderLoader.h
//  ShaderTest
//
//  Created by Dimitriy Dounaev on 4/05/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef ShaderTest_ShaderLoader_h
#define ShaderTest_ShaderLoader_h

#include <GL/glfw.h>
#include <iostream>

GLuint compileShader(GLenum shaderType, char *source);
GLuint createShaderProgram( char *sourceVS, char *sourceFS);



#endif
