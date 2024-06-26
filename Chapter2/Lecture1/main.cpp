#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"

namespace jm
{
	class House
	{
	private:
		RGB roof_color;
		vec2 pos;
		float angle = 0.0f;



	public :
		House()
			: roof_color(Colors::red), pos(0.0f, 0.0f), angle(0.0f)
		{}

		void setPos(const vec2& _pos) {
			pos = _pos;
		}

		void setAngle(const float& _angle) {
			angle = _angle;
		}

		void draw() {
			beginTransformation();
			{
				translate(pos);
				rotate(angle);

				// wall
				drawFilledBox(Colors::yellow, 0.2f, 0.2f);

				// roof
				drawFilledTriangle(roof_color, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });
				drawWiredTriangle(roof_color, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });

				// window
				drawFilledBox(Colors::skyblue, 0.1f, 0.1f);
				drawWiredBox(Colors::gray, 0.1f, 0.1f);
				drawLine(Colors::gray, { 0.0f, -0.05f }, Colors::gray, { 0.0f, 0.05f });
				drawLine(Colors::gray, { -0.05f, 0.0f }, Colors::gray, { 0.05f, 0.0f });

			}
			endTransformation();
		}
	};

	class Example : public Game2D
	{
		
	public:
		House houses[10];

		Example() : Game2D()
		{
			RandomNumberGenerator rnd;

			for (int i = 0; i < 10; i++) {
				houses[i].setPos(vec2(-1.3f + 0.3f * float(i), rnd.getFloat(-0.5f, 0.5f)));
			}
		}

		void update() override
		{

			for (int i = 0; i < 10; i++) {
				houses[i].draw();
			}


			//House left_house, center_house, right_house;

			//left_house.setPos({ -0.5f, 0.0f });
			//center_house.setPos({ 0.0f, 0.0f });
			//right_house.setPos({ 0.5f, 0.0f });

			//center_house.setAngle(10.0f);


			//left_house.draw();
			//center_house.draw();
			//right_house.draw();
		}
	};
}

int main(void)
{
	jm::Example().run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::PrimitivesGallery().run();

	return 0;
}
