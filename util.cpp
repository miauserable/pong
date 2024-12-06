#include "util.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
using namespace sf;
Font font;
int Direction = 0; // 0 <- , 1 ->

int LPY;
int RPY;
int BPX;
int BPY;
Text LP("l", font, 96);
Text RP("l", font, 96);
Text BALL(".", font, 24);
Text ENDT("GAME OVER", font, 24);
Text RESTART("press esc to restart", font, 8);
std::unordered_map<std::string, FloatRect> textBoundsMap;
void INIT(RenderWindow& w) {
  if (!font.loadFromFile("font.ttf")) { std::cerr << "e" << std::endl; }
  LP.setFont(font);
  RP.setFont(font);
  BALL.setFont(font);
  ENDT.setFont(font);
  RESTART.setFont(font);
  RESTART.setFillColor(Color(242,130,221));
  ENDT.setPosition(240, 160);
  RESTART.setPosition(280, 200);
  LPY = 120;
  RPY = 120;
  BPX = 320;
  BPY = 120; }
void Render(RenderWindow& w) {
  MoveBall();
  DIR(w);
  LP.setPosition(24, LPY);
  RP.setPosition(616, RPY);
  BALL.setPosition(BPX, BPY);
  w.draw(LP);
  w.draw(RP);
  w.draw(BALL);
} void Move(int s) {
  if ( s == 1 && LPY >= 0 ) { LPY -= 25; }
  if ( s == 2 && LPY <= 580) { LPY += 25; }
  if ( s == 3 && RPY >= 0) { RPY -= 25; }
  if ( s == 4 && RPY <= 580) { RPY += 25; }
} void MoveBall() {
    if ( Direction == 0 ) {BPX -= 10;}
    else if (Direction == 1) {BPX += 10;}
} void DIR(sf::RenderWindow& w) {
    textBoundsMap["LP"] = LP.getGlobalBounds();
    textBoundsMap["RP"] = RP.getGlobalBounds();
    FloatRect ballBounds = BALL.getGlobalBounds();
    FloatRect LPB = textBoundsMap["LP"];
    FloatRect RPB = textBoundsMap["RP"];

    if (ballBounds.intersects(LPB)) { Direction = 1; }
    else if (ballBounds.intersects(RPB)) { Direction = 0; }
} bool END() {
  return (BPX < 10 || BPX > 650);
} void RenderEnd(RenderWindow& w) {
  w.draw(ENDT);
  w.draw(RESTART); }
