#pragma once
#include "Game2D.h"

namespace jm {
	class GeometricObject {
	public:
		vec2 pos;
		RGB color;

		void init(const RGB& _color, const vec2& _pos) {
			color = _color;
			pos = _pos;
		}

		void draw() {
			beginTransformation();
			{
				translate(pos);
				drawGeometry();
			}
			endTransformation();
		}

		virtual void drawGeometry() const = 0;
	};
}