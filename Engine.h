/**
 * Copyright (C) 2022-2025 Ryan Hermle <rhermle>
 * Modified Works by LoganMD, WaitingKeptYouHuh, and deathsdebtor
 * Copyright (C) 2026 topLeftTable

Particles is free software: you can redistribute it and/or modify
its terms under the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Particles is distributed in the hope that it will be useful,
but WITHOUT WARRANTY. See <https://www.gnu.org/licenses/> for details.
**/

#pragma once
#pragma once
#include "Particle.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Engine
{
  private:
	// A regular RenderWindow
	RenderWindow m_Window;

	// vector for Particles
	vector<Particle> m_particles;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

	bool pressed = false;
	unsigned int framesSinceLastDrag = 0;

	sf::Text text;
	sf::Font font;

  public:
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();
};