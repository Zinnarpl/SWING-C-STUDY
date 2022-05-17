#include <iostream>
using namespace std;

class Box
{
    int width, height;  // ����, ���� ũ��
    char fillchar;      // ä�� ����
public:
    Box(int w, int h);          // ������
    void setFill(char f);       // ä�� ���ڸ� �����ϴ� �Լ�
    void setSize(int w, int h); // ũ�⸦ �����ϴ� �Լ�
    void draw();                // �׸��� �Լ�
};

Box::Box(int w, int h)
{
    width = w;
    height = h;
    fillchar = '*';     // �⺻ ���� ����
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

    bx.setSize(6, 10); // ũ�⺯��
    bx.setFill('^');   // ä�﹮�� ����
    bx.draw();
}
