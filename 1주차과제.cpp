#include<iostream> 
#include<cstring>
using namespace std;
int main()
{
	cout << "����� �̸��� �����Դϱ�? \n"; //�̸� �Է¹ޱ�
	char name[10];
	cin.getline(name, 10, '\n');
	cout << "�ݰ����ϴ�." << name << "��.\n";    //�̸��� �Բ� �λ� ���
	cout << "----------SWING30----------" <<std::endl;

	int coke;  //���� ���ݰ� ������ �Է� ���� ���� ����
	int water;
	int fanta;
	int coke_number;
	int water_number;
	int fanta_number;

	cout << "������ ���� �Է��� �����մϴ�. \n\n";

	cout << "�ݶ��� ���� : ";  //������ ������ �Է¹ޱ�
	cin >> coke;
	cout << "��ټ��� ���� : ";
	cin >> water;
	cout << "ȯŸ�� ���� : ";
	cin >> fanta;
	cout << "\n"; 

	cout << "������ �Է����ּ���. \n\n"; //������ ������ �Է¹ޱ�
	cout << "�ݶ� ���� : ";
	cin >> coke_number;
	cout << "��ټ� ���� : ";
	cin >> water_number;
	cout << "ȯŸ ���� : ";
	cin >> fanta_number;
	cout << "----------------- \n";

	int price;
	price = coke * coke_number + water * water_number + fanta * fanta_number; //�ݾ��� �� �� ����� ���
	cout << "500�� ���ι޾� �� " << price - 500 << "�� �Դϴ�. \n"; //�� �ݾ׿��� 500�� ����

	return 0;

}
