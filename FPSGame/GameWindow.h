//
//  GameWindow.h
//  FPSGame
//
//  Created by Dimitriy Dounaev on 1/07/13.
//  Copyright (c) 2013 Dimitriy Dounaev. All rights reserved.
//

#ifndef __FPSGame__GameWindow__
#define __FPSGame__GameWindow__

#include "FPSGame-Prefix.h"

class GameWindow
{
private:
    
    bool _running;
    GLuint _vertexBufferID;
    GLfloat _rotatingValue;
    
public:
    
    void setRunning(bool running);
    bool getRunning();
    
    GameWindow(bool running);
    ~GameWindow();
    
    void render();
    void update();

};

#endif /* defined(__FPSGame__GameWindow__) */
