//
//  GameWindow.cpp
//  FPSGame
//
//  Created by Dimitriy Dounaev on 1/07/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#include "GameWindow.h"
#include "SimpleShaderInterface.h"

typedef struct {
  
    Vector3 positionCoordinates;
    Vector3 normalCoordinates;
    
} VertexData;

void GameWindow::setRunning(bool running)
{
    _running = running;
}

bool GameWindow::getRunning()
{
    return _running;
}

GameWindow::GameWindow(bool running): _running(running), _vertexBufferID(0), _rotatingValue(0.0f)
{
    glClearColor(0.3f, 0.3f, 0.8f, 1.0f);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, Default_Window_Width, Default_Window_Height);
    gluPerspective(75, Default_Window_Width/Default_Window_Height, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_MULTISAMPLE);
    
    SimpleShaderInterface shaderInterface;
    
    VertexData vertices[] = {
        0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 0.0f, //B
        0.5f, 0.5f, -0.5f,         1.0f, 0.0f, 0.0f, //C
        0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 0.0f, //Bb
        0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 0.0f, //Bb
        0.5f, 0.5f, -0.5f,         1.0f, 0.0f, 0.0f,//C
        0.5f, 0.5f, 0.5f,           1.0f, 0.0f, 0.0f,  //Cc
        
        0.5f, 0.5f, -0.5f,         0.0f, 1.0f, 0.0f, //C
        -0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f, //D
        0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f, //Cc
        0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f, //Cc
        -0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f, //D
        -0.5f, 0.5f, 0.5f,         0.0f, 1.0f, 0.0f, //Dd
        
        -0.5f, 0.5f, -0.5f,        -1.0f, 0.0f, 0.0f, //D
        -0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f, //A
        -0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f, //Dd
        -0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f, //Dd
        -0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f, //A
        -0.5f, -0.5f, 0.5f,        -1.0f, 0.0f, 0.0f, //Aa
        
        -0.5f, -0.5f, -0.5f,       0.0f, -1.0f, 0.0f, //A
        0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f, //B
        -0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f, //Aa
        -0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f, //Aa
        0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f, //B
        0.5f, -0.5f, 0.5f,         0.0f, -1.0f, 0.0f, //Bb
        
        0.5f, 0.5f, 0.5f,          0.0f, 0.0f, 1.0f, //Cc
        -0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Dd
        0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Bb
        0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Bb
        -0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Dd
        -0.5f, -0.5f, 0.5f,        0.0f, 0.0f, 1.0f, //Aa
        
        0.5f, -0.5f, -0.5f,        0.0f, 0.0f, -1.0f, //B
        -0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f, //A
        0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f, //C
        0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f, //C
        -0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f, //A
        -0.5f, 0.5f, -0.5f,        0.0f, 0.0f, -1.0f  //D
    };
    
    glUseProgram(shaderInterface.getProgramHandle());

    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(shaderInterface.get_aPositionCoordinates());
    glVertexAttribPointer(shaderInterface.get_aPositionCoordinates(), 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void *)(offsetof(VertexData, positionCoordinates)));
    
    glEnableVertexAttribArray(shaderInterface.get_aNormalCoordinates());
    glVertexAttribPointer(shaderInterface.get_aNormalCoordinates(), 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void *)(offsetof(VertexData, normalCoordinates)));
}

GameWindow::~GameWindow()
{
}

void GameWindow::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    
    gluLookAt(3.0f, 4.0f, 8.0f, //Camera Position
              0.0f, 0.0f, 0.0f, //Looking At
              0.0f, 1.0f, 0.0f);
    
    glRotatef(_rotatingValue, 1.0f, 1.0f, 1.0f);
    
    glScalef(3.0f, 3.0f, 3.0f);
    
    glDrawArrays(GL_TRIANGLES, 0, 36);
    
    glfwSwapBuffers();
}

void GameWindow::update()
{
    _rotatingValue += 0.1f;
}