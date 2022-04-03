#include<iostream> 
#include<cstring>
using namespace std;
int main()
{
	cout << "당신의 이름은 무엇입니까? \n"; //이름 입력받기
	char name[10];
	cin.getline(name, 10, '\n');
	cout << "반갑습니다." << name << "님.\n";    //이름과 함께 인사 출력
	cout << "----------SWING30----------" <<std::endl;

	int coke;  //음료 가격과 수량을 입력 받을 변수 지정
	int water;
	int fanta;
	int coke_number;
	int water_number;
	int fanta_number;

	cout << "음료의 가격 입력을 시작합니다. \n\n";

	cout << "콜라의 가격 : ";  //음료의 가격을 입력받기
	cin >> coke;
	cout << "삼다수의 가격 : ";
	cin >> water;
	cout << "환타의 가격 : ";
	cin >> fanta;
	cout << "\n"; 

	cout << "개수를 입력해주세요. \n\n"; //음료의 수량을 입력받기
	cout << "콜라 수량 : ";
	cin >> coke_number;
	cout << "삼다수 수량 : ";
	cin >> water_number;
	cout << "환타 수량 : ";
	cin >> fanta_number;
	cout << "----------------- \n";

	int price;
	price = coke * coke_number + water * water_number + fanta * fanta_number; //금액의 총 합 계산해 출력
	cout << "500원 할인받아 총 " << price - 500 << "원 입니다. \n"; //총 금액에서 500원 할인

	return 0;

}
