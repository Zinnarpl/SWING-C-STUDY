#include <iostream>
using namespace std;

class Box
{
    int width, height;  // 가로, 세로 크기
    char fillchar;      // 채울 문자
public:
    Box(int w, int h);          // 생성자
    void setFill(char f);       // 채울 문자를 설정하는 함수
    void setSize(int w, int h); // 크기를 조정하는 함수
    void draw();                // 그리는 함수
};

Box::Box(int w, int h)
{
    width = w;
    height = h;
    fillchar = '*';     // 기본 문자 설정
}
void Box::setFill(char f)
{
    fillchar = f;
}
void Box::setSize(int w, int h)
{
    width = w;
    height = h;
}
void Box::draw()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cout << fillchar;
        cout << endl;
    }
}
int main()
{
    Box bx(3, 4);
    bx.draw();
    cout << "\n";

    bx.setSize(6, 10); // 크기변경
    bx.setFill('^');   // 채울문자 변경
    bx.draw();
}
