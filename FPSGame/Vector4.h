//
//  Vector4.h
//  FPSGame
//
//  Created by Dimitriy Dounaev on 3/07/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __FPSGame__Vector4__
#define __FPSGame__Vector4__

#include "FPSGame-Prefix.h"

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
} Vector4;


Vector4 makeVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

#endif /* defined(__FPSGame__Vector4__) */
