#include <stdio.h>
#include <iostream>
#include <thread> 
#include <inttypes.h>
#include "GraphLines.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

void renderingThread(sf::RenderWindow* window)
{
    // the rendering loop  
    GraphLines glines(window->getSize().x,window->getSize().y);
    glines.setPoint(32);
    glines.setPoint(58);
    glines.setPoint(134);
    glines.setPoint(4);
    glines.setPoint(82);
    glines.setPoint(16);
    glines.setPoint(256);
    window->setActive(true);
    while (window->isOpen())
    {
        window->clear();
        glines.update();
        window->draw(glines);
        window->display();
    }
}

int main( int argc, const char* argv[] )
{
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    window.setFramerateLimit(60);
    window.setActive(false);
    std::thread first (renderingThread, &window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
    }

    return 0;
}