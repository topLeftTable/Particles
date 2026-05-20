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
#include "Matrices.h"
#include <SFML/Graphics.hpp>

// #define M_PI 3.1415926535897932384626433
const float G = 1000;  // Gravity
const float TTL = 5.0; // Time To Live
const float SCALE = 0.999;

using namespace Matrices;
using namespace sf;
class Particle : public Drawable
{
  public:
	Particle(RenderTarget &target, int numPoints, Vector2i mouseClickPosition, bool circleSpawn = false);
	virtual void draw(RenderTarget &target, RenderStates states) const override;
	void update(float dt);
	float getTTL() { return m_ttl; }

	// Functions for unit testing
	bool almostEqual(double a, double b, double eps = 0.0001);
	void unitTests();

	void colorShift(int amt, int rate);

  private:
	float m_ttl;
	int m_numPoints;
	Vector2f m_centerCoordinate;
	float m_radiansPerSec;
	float m_vx;
	float m_vy;
	View m_cartesianPlane;
	Color m_color1;
	Color m_color2;
	Matrix m_A;

	int colorShiftCounter = 0;
	bool rDir = true;
	bool gDir = true;
	bool bDir = true;


	/// rotate Particle by theta radians counter-clockwise
	/// construct a RotationMatrix R, left mulitply it to m_A
	void rotate(double theta);

	/// Scale the size of the Particle by factor c
	/// construct a ScalingMatrix S, left multiply it to m_A
	void scale(double c);

	/// shift the Particle by (xShift, yShift) coordinates
	/// construct a TranslationMatrix T, add it to m_A
	void translate(double xShift, double yShift);
};
