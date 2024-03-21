#pragma once
#include "Game2D.h"

namespace jm {
	class Box {
	public:
		vec2 pos = vec2{ 0.5f, 0.0f };
		RGB color = Colors::blue;
		float width = 0.25f;
		float height = 0.3f;

		void draw() {
			beginTransformation();
			{
				translate(vec2{ 0.5f, 0.0f });
				drawFilledBox(color, width, height);
			}
			endTransformation();
		}
	};
}