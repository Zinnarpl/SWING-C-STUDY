#include<iostream>
#include <typeinfo>  // 클래스 이름
using namespace std;

class Shape
{
	string NAME;
	int A, B, C;
public:
	Shape();
	Shape(int a, int b);
	Shape(int a, int b, int c);
	int getA();
	int getB();
	int getC();
	void setTwo(int a, int b);
	void setThree(int a, int b, int c);
	void setName(string name);
	void AreaOval();
	void AreaLadder();
	void AreaRect();
	~Shape();
};
Shape::Shape()
{
	A = 0;
	B = 0;
	C = 0;
}
Shape::Shape(int a, int b)
{
	A = a;
	B = b;
}
Shape::Shape(int a, int b, int c)
{
	A = a;
	B = b;
	C = c;
}
Shape::~Shape()
{
	cout << "Shape 소멸 " << NAME << "클래스" << endl;
}
int Shape::getA()
{
	return A;
}
int Shape::getB()
{
	return B;
}

int Shape::getC()
{
	return C;
}

void Shape::setTwo(int a, int b)
{
	A = a;
	B = b;
}
void Shape::setThree(int a, int b, int c)
{
	A = a;
	B = b;
	C = c;
}
void Shape::setName(string name)
{
	NAME = name;
}
void Shape::AreaOval()
{
	// 타원의 넚이
	cout << "타원의 넓이는 " << 3.14 * A * B << "이다." << endl;
}
void Shape::AreaLadder()
{
	// 사다리꼴의 넚이
	cout << "사다리꼴의 넓이는 " << (A + C) * B / 2.0 << "이다." << endl;
}
void Shape::AreaRect()
{
	// 사각형의 넚이
	cout << "사각형의 넓이는 " << A * B << "이다." << endl;
}
int main()
{
	{
		Shape a;
		Shape b(10, 20);
		Shape c(3, 7, 4);

		a.setName("CircleA");
		b.setName("Rectangular");
		c.setName("Ladder");

		a.setTwo(1, 5);
		a.AreaOval();
		b.AreaRect();
		c.AreaLadder();

		c.setThree(4, 10, 5);
		c.AreaLadder();
	}
}