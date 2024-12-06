#pragma once

#ifndef UTIL_H
#define UTIL_H

#include <SFML/Graphics.hpp>
#include <iostream>

void INIT(sf::RenderWindow& w);
void Render(sf::RenderWindow& w);
void Move(int s);
void MoveBall();
void DIR(sf::RenderWindow &w);
bool END();
void RenderEnd(sf::RenderWindow& w);
#endif
