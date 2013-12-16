//
//  Vector3.h
//  FPSGame
//
//  Created by Dimitriy Dounaev on 1/07/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __FPSGame__Vector3__
#define __FPSGame__Vector3__

#include "FPSGame-Prefix.h"

typedef struct {
    
    GLfloat x;
    GLfloat y;
    GLfloat z;

} Vector3;

Vector3 makeVector3(GLfloat x, GLfloat y, GLfloat z);
Vector3 addVector3(Vector3 firstVector, Vector3 secondVector);

#endif /* defined(__FPSGame__Vector3__) */
