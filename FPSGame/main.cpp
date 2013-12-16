#include "FPSGame-Prefix.h"
#include "GameWindow.h"

GameWindow *gameWindow;

int main(int argc, char **argv)
{
    glfwInit();
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 16);
    glfwOpenWindow(Default_Window_Width, Default_Window_Height, 8, 8, 8, 8, 24, 0, GLFW_WINDOW);
    glfwSetWindowTitle("FPSGame");
    glfwSwapInterval(0);
    
    gameWindow = new GameWindow(true);
    
    double deltaTime = 0.0f;
    double lastTime = glfwGetTime();
    
    while (gameWindow->getRunning()) {
        
        gameWindow->render();
        
        deltaTime += (glfwGetTime() - lastTime)*Updates_Per_Second;
        lastTime = glfwGetTime();
        if (deltaTime >= 1.0f) {
            gameWindow->update();
            --deltaTime;
        }
        
        gameWindow->setRunning(glfwGetWindowParam(GLFW_OPENED));
    }
    
    delete gameWindow;
    glfwTerminate();
    
    return 0;
}