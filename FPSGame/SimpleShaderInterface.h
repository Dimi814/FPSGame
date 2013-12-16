//
//  SimpleShaderInterface.h
//  FPSGame
//
//  Created by Dimitriy Dounaev on 3/07/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __FPSGame__SimpleShaderInterface__
#define __FPSGame__SimpleShaderInterface__

#include "FPSGame-Prefix.h"

class SimpleShaderInterface
{
private:
    
    GLuint _programHandle;
    GLint _aPositionCoordinates;
    GLint _aNormalCoordinates;
    
public:
    
    GLint getProgramHandle();
    GLint get_aPositionCoordinates();
    GLint get_aNormalCoordinates();
    
    SimpleShaderInterface();
    ~SimpleShaderInterface();
};

#endif /* defined(__FPSGame__SimpleShaderInterface__) */
