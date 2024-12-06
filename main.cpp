#include <SFML/Graphics.hpp>
#include <iostream>
#include "util.h"
using namespace sf;

int main() {
  int GAMESTATE = 0;
  RenderWindow window(VideoMode(640, 720), "pong");
  window.setFramerateLimit(30);
  INIT(window);
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case Event::Closed:
          window.close();
          break;
        case Event::KeyPressed:
          if (event.key.code == Keyboard::W) {Move(1);}
          if (event.key.code == Keyboard::S) {Move(2);}
          if (event.key.code == Keyboard::Up) {Move(3);}
          if (event.key.code == Keyboard::Down) {Move(4);}
          if (event.key.code == Keyboard::Escape) { 
            GAMESTATE = 0;
            INIT(window);}
      }
    }
    window.clear();
    if (END()) { GAMESTATE = 1; }
    if (GAMESTATE == 0) {
      Render(window);
    } else if (GAMESTATE == 1) {
      RenderEnd(window);
    }
    window.display();
  }
  return 1;
}
