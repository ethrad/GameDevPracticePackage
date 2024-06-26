#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"
using namespace std;

namespace jm
{
	class RotatingStarExample : public Game2D {
		float time = 0.0f;

	public:
		void update() override {
			rotate(time * 180.0f);
			drawFilledStar(Colors::gold, 0.4f, 0.25f);

			time += this->getTimeStep();
		}
	};

	class TransformationsExample1 : public Game2D {
	public:
		void update() override {
			const vec2 point = vec2(0.0f, 0.0f);	// const vec2 point(0.0f, 0.0f); 의 형태로도 작성 가능
			drawPoint(Colors::black, point, 5.0f);

			//const float dx = 0.1f;

			//const vec2 p0(0.0f + dx, 0.0f);
			//const vec2 p1(0.5f + dx, 0.5f);
			//const vec2 p2(0.5f + dx, 0.0f);

			//drawLine(Colors::red, p0, Colors::blue, p1);
			//drawLine(Colors::red, p1, Colors::blue, p2);
			//drawLine(Colors::red, p2, Colors::blue, p0);

			translate(0.1f, 0.2f);

			const vec2 p0(0.0f, 0.0f);
			const vec2 p1(0.5f, 0.5f);
			const vec2 p2(0.5f, 0.0f);

			drawLine(Colors::red, p0, Colors::blue, p1);
			drawLine(Colors::red, p1, Colors::blue, p2);
			drawLine(Colors::red, p2, Colors::blue, p0);

			translate(-0.1f, -0.2f); // 변화가 누적되어서 원점에 그려짐

			drawLine(Colors::red, p0, Colors::blue, p1);
			drawLine(Colors::red, p1, Colors::blue, p2);
			drawLine(Colors::red, p2, Colors::blue, p0);



			beginTransformation(); // 변화를 누적시키고 싶지 않을 때

			translate(0.1f, 0.2f);

			drawLine(Colors::red, p0, Colors::blue, p1);
			drawLine(Colors::red, p1, Colors::blue, p2);
			drawLine(Colors::red, p2, Colors::blue, p0);

			translate(-0.1f, -0.2f);

			drawLine(Colors::red, p0, Colors::blue, p1);
			drawLine(Colors::red, p1, Colors::blue, p2);
			drawLine(Colors::red, p2, Colors::blue, p0);
		}
	};

	class TransformationsExample2 : public Game2D {
	public:
		void update() override {
			setLineWidth(3.0f);

			drawWiredBox(Colors::gold, 0.5f, 0.25f);

			beginTransformation();
			rotate(30.0f);
			drawWiredBox(Colors::skyblue, 0.5f, 0.25f);
			endTransformation();

			beginTransformation();
			// 회전 먼저 적용되고 이동 됨, 그래픽스 API가 역순으로 적용됨
			translate(0.25f, 0.0f);
			rotate(30.0f);
		
			drawWiredBox(Colors::red, 0.5f, 0.25f);
			endTransformation();

			beginTransformation();
			rotate(30.0f);
			translate(0.25f, 0.0f);

			drawWiredBox(Colors::blue, 0.5f, 0.25f);
			endTransformation();
		}
	};

	class TransformationsExample3 : public Game2D {
	public:
		void update() override {
			setLineWidth(3.0f);

			const vec2 center_of_rot(-0.4f, 0.0f);
			drawWiredBox(Colors::skyblue, 0.5f, 0.25f);

			translate(center_of_rot);
			rotate(45.0f);
			translate(-center_of_rot);
			drawWiredBox(Colors::gold, 0.5f, 0.25f);
			drawPoint(Colors::black, center_of_rot, 5.0f);
		}
	};

	class TransformationsExample4 : public Game2D {
	public:
		float time = 0;

		void update() override {
			setLineWidth(3.0f);

			
			scale(2.0f, 0.25f);
			rotate(time * 90.0f);
			drawWiredBox(Colors::gold, 0.5f, 0.5f);

			time += this->getTimeStep();
		}
	};

	class Homework1 : public Game2D {
	public:
		float time = 0;

		void update() override {
			setLineWidth(3.0f);

			// 태양
			beginTransformation();
			scale(0.4f, 0.4f);
			rotate(time * 90.0f);
			drawFilledStar(Colors::gold, 0.5f, 0.3f);
			endTransformation();


			// 지구 
			rotate(time * 90.0f);
			translate(0.8f, 0.0f);
			scale(0.25f, 0.25f);
			drawFilledCircle(Colors::blue, 0.4f);

			// 달
			rotate(time * 90.0f);
			translate(1.0f, 0.0f);
			drawFilledCircle(Colors::yellow, 0.2f);
			drawWiredCircle(Colors::red, 0.2f);

			time += this->getTimeStep();
		}
	};

	class MouseExample : public Game2D {
	public :
		void update() override {
			// 왼쪽 위가 (0, 0)이고 오른쪽 아래가 (999, 999)인 윈도우 좌표계
			//const vec2 mouse_pos = getCursorPos(false);
			//cout << mouse_pos << endl;

			// 가운데가 (0, 0)인 화면 좌표계
			const vec2 mouse_pos = getCursorPos(true);
			//cout << mouse_pos << endl;

			if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_1) == true) {
				translate(mouse_pos);
				drawFilledCircle(Colors::gold, 0.1f);
			}
			
			if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_2)) {
				translate(mouse_pos);
				drawFilledCircle(Colors::red, 0.1f);
			}

			
		}
	};
}


int main(void)
{
	jm::MouseExample().init("This is my digital canvas!", 1000, 1000, false).run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::RotatingStarExample().init("Rotating Star", 1000, 1000, false).run();
	//jm::PrimitivesGallery().init("Primitive Gallery", 1280, 960, false).run();
	//jm::SolarSystem().run();
	//jm::FaceExample().run();
	//jm::WalkingPerson().run(); => 팔다리 만들고 점프 만들기
	//jm::TankExample().run();
	//jm::Homework1().run();

	return 0;
}
