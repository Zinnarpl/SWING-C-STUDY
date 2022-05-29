#include <iostream>
#include <string>
using namespace std;

class subject // 과목 클래스
{
private:
	string name;		// 과목 이름
	string id;			// 학수 번호
public:
	// Constructor
	subject();
	subject(string _name, string _id); // 생성자 중복 정의

	// Destructor
	~subject();

	// Accessor
	string getName();
	string getId();

	// Mutator
	void setName(string _name);
	void setId(string _id);
};

subject::subject()
{
	this->name = "";
	this->id = "";
}

subject::subject(string _name, string _id)
{
	this->name = _name;
	this->id = _id;
}

subject::~subject()
{
	// nothing to do...
}

string subject::getName()
{
	return this->name;
}

string subject::getId()
{
	return this->id;
}

void subject::setName(string _name)
{
	this->name = _name;
}

void subject::setId(string _id)
{
	this->id = _id;
}


class student // 학생 클래스
{
private:
	int num;					// 수강하고 있는 과목의 개수
	string name;				// 이름
	string Id;					// 아이디
	string password;		// 비밀번호
	subject bag[3];			// 장바구니
public:
	// Constructor
	student();

	// Destructor
	~student();

	// Accessor
	string getName();
	string getId();
	string getPassword();
	int getNum();

	// Mutator
	void setName(string _name);
	void setId(string _id);
	void setPassword(string _password);

	// Func
	void printBag();
	void addSubject(string _name, string _id);
};

student::student()
{
	this->num = 0;
	this->name = "";
	this->Id = "";
	this->password = "";
	for (int i = 0; i < 3; i++)
		this->bag[i].setName("");
}

student::~student()
{
	// nothing to do...
}

string student::getName()
{
	return this->name;
}

string student::getId()
{
	return this->Id;
}

string student::getPassword()
{
	return this->password;
}

int student::getNum()
{
	return this->num;
}

void student::setName(string _name)
{
	this->name = _name;
}

void student::setId(string _id)
{
	this->Id = _id;
}

void student::setPassword(string _password)
{
	this->password = _password;
}

void student::printBag()
{
	cout << "\n======== My 장바구니 ========\n";
	for (int i = 0; i < 3; i++)
		cout << i + 1 << ". " << bag[i].getName() << '\n';
	cout << '\n';
}

void student::addSubject(string _name, string _id)
{
	if (num < 3)
	{
		bool chk = false;
		for (int i = 0; i < num; i++)
		{
			if (bag[i].getId() == _id)
			{
				chk = true;
				break;
			}
		}
		if (chk)
			cout << "이미 MY 장바구니에 담겨져 있습니다.\n\n";
		else
		{
			bag[num].setName(_name);
			bag[num].setId(_id);
			num++;
		}
	}
	else
	{
		cout << "더 이상 장바구니에 넣을 수 없습니다.\n\n";
		return;
	}
}

class Member
{
private:
	int cnt;								// 시스템에 가입된 학생의 수
	student* studentList;		// 시스템에 가입된 학생의 정보
public:
	// Constructor
	Member();

	// Destructor
	~Member();

	// Func
	void Enrollment();	// 회원가입
	student* Login();		// 로그인
};

Member::Member()
{
	this->cnt = 0;
	this->studentList = new student[10]; // 초기 리스트의 크기는 10으로 함
}

Member::~Member()
{
	delete[] studentList;
}

void Member::Enrollment()
{
	string inputName, inputId, inputPassword;

	cout << "이름: ";
	cin >> inputName;

	cout << "아이디: ";
	cin >> inputId;

	cout << "비밀번호: ";
	cin >> inputPassword;

	this->studentList[this->cnt].setName(inputName);				// 입력받은 이름으로 학생 이름 설정
	this->studentList[this->cnt].setId(inputId);							// 입력받은 아이디로 학생 아이디 설정
	this->studentList[this->cnt].setPassword(inputPassword);	// 입력받은 비밀번호로 학생 비밀번호 설정
	this->cnt++;																			// 리스트 내의 학생 수 증가

	if (this->cnt < 10)
		cout << "\n=== 회원가입 성공 ===\n\n";
	else
		cout << "\n=== 회원가입 실패 ===\n\n";
}

student* Member::Login()
{
	string inputId, inputPassword;

	cout << "아이디: ";
	cin >> inputId;

	cout << "비밀번호: ";
	cin >> inputPassword;

	bool chk = false;
	int idx = -1;
	for (int i = 0; i < this->cnt; i++)
	{
		if (this->studentList[i].getId() == inputId)
		{
			idx = i;	// 해당 아이디의 인덱스 저장
			chk = true;
			break;
		}
	}

	if (chk) // 리스트 내에 아이디가 있다면, 비밀번호도 검사
	{
		if (this->studentList[idx].getPassword() == inputPassword) // 비밀번호가 일치한다면
		{
			cout << "\n=== 로그인 성공 ===\n\n";
			cout << this->studentList[idx].getName() << "님 환영합니다\n\n";
			return this->studentList + idx; // 해당하는 학생의 정보를 반환함
		}
		else
		{
			cout << "아이디 혹은 비밀번호가 틀렸습니다.\n\n";
			return nullptr; // 로그인 실패
		}
	}
	else
	{
		cout << "아이디 혹은 비밀번호가 틀렸습니다.\n\n";
		return nullptr; // 로그인 실패
	}
}

class cart
{
public:
	// Func
	void run(student* _stu, subject* list, int n);					// 장바구니 기능 수행
	void printMenu();															// 장바구니 메뉴
	void print(subject* list, int n);										// 1번 기능
	void bag_course(student* _stu, subject* list, int n);		// 2번 기능
	void put_bag(student* _stu);										// 3번 기능
};

void cart::printMenu()
{
	cout << "=========================\n";
	cout << "1. 장바구니\n";
	cout << "2. 강의 담기\n";
	cout << "3. 수강신청 확인\n";
	cout << "4. 로그아웃\n";
	cout << "번호를 입력하세요: ";
}

void cart::print(subject* list, int n)
{
	cout << "\n========== 강의목록 ==========\n";
	for (int i = 0; i < n; i++)
		cout << "[" << i + 1 << "] " << list[i].getName() << " >> " << list[i].getId() << '\n';
	cout << '\n';
}

void cart::bag_course(student* _stu, subject* list, int n)
{
	string id;
	cout << "\n추가할 학수번호 >> ";
	cin >> id;

	bool chk = false;
	int idx = -1;
	for (int i = 0; i < n; i++)
	{
		if (list[i].getId() == id)
		{
			chk = true;
			idx = i;
			break;
		}
	}
	if (chk)
		_stu->addSubject(list[idx].getName(), list[idx].getId());
	else
		return;
}

void cart::put_bag(student* _stu)
{
	_stu->printBag();
}

void cart::run(student* _stu, subject* list, int n)
{
	int menuSelect;

	while (true)
	{
		printMenu();
		cin >> menuSelect;

		if (menuSelect == 1)
		{
			print(list, n);
		}
		else if (menuSelect == 2)
		{
			bag_course(_stu, list, n);
		}
		else if (menuSelect == 3)
		{
			put_bag(_stu);
		}
		else if (menuSelect == 4)
		{
			cout << "---------- 로그아웃 ----------\n";
			cout << "로그아웃 되었습니다. 안녕히 가세요.\n\n";
			return;
		}
	}
}

class System
{
public:
	void run();
	void printStartMenu();
};

void System::run()
{
	int menuSelect;
	Member* mb = new Member();
	student* searched = new student();
	cart cart;

	// 강의목록
	subject list[3] = {
		{"c++ 프로그래밍", "0001"},
		{"linux 프로그래밍", "0002"},
		{"리버싱", "0003"}
	};

	while (true)
	{
		printStartMenu();
		cout << "번호를 입력하세요 >> ";
		cin >> menuSelect;

		if (menuSelect == 1)  // 회원가입
		{
			cout << "-------------------------------------------------------------------------\n\n";
			mb->Enrollment();
		}
		else if (menuSelect == 2) // 로그인
		{
			cout << "-------------------------------------------------------------------------\n\n";
			searched = mb->Login();

			if (searched != nullptr) // nullptr이 아니라면 로그인 성공
				cart.run(searched, list, 3);	// cart실행 (로그인된 학생의 정보, 리스트, 과목 수 전달)
		}
		else
		{
			cout << "1 또는 2만 입력해주세요\n";
			cout << "-------------------------------------------------------------------------\n\n";
			continue;
		}
	}
}

void System::printStartMenu()
{
	cout << "--------------------- 서울여자대학교 종합정보시스템 ---------------------\n";
	cout << "1. 회원가입\n";
	cout << "2. 로그인\n\n";
}

int main(int argc, char argv[])
{
	System program;
	program.run();
	return 0;
}