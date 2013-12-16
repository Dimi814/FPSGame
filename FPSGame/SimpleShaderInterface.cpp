//
//  SimpleShaderInterface.cpp
//  FPSGame
//
//  Created by Dimitriy Dounaev on 3/07/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "SimpleShaderInterface.h"
#include "ShaderLoader.h"
#include "ReadWriteText.h"

GLint SimpleShaderInterface::getProgramHandle()
{
    return _programHandle;
}

GLint SimpleShaderInterface::get_aPositionCoordinates()
{
    return _aPositionCoordinates;
}

GLint SimpleShaderInterface::get_aNormalCoordinates()
{
    return _aNormalCoordinates;
}

SimpleShaderInterface::SimpleShaderInterface()
{
    _programHandle = createShaderProgram(textFileRead("SimpleShader.vsh"), textFileRead("SimpleShader.fsh"));
    
    _aPositionCoordinates = glGetAttribLocation(_programHandle, "aPositionCoordinates");
    _aNormalCoordinates = glGetAttribLocation(_programHandle, "aNormalCoordinates");
}

SimpleShaderInterface::~SimpleShaderInterface()
{
    
}