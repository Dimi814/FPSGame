//
//  Vector3.cpp
//  FPSGame
//
//  Created by Dimitriy Dounaev on 1/07/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "Vector3.h"

Vector3 makeVector3(GLfloat x, GLfloat y, GLfloat z)
{
    Vector3 newVector;
    newVector.x = x;
    newVector.y = y;
    newVector.z = z;
    
    return newVector;
}

Vector3 addVector3(Vector3 firstVector, Vector3 secondVector)
{
    Vector3 newVector;
    newVector.x = firstVector.x + secondVector.x;
    newVector.y = firstVector.y + secondVector.y;
    newVector.z = firstVector.z + secondVector.z;

    return newVector;
}