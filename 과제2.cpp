#include <iostream>
#include <string>
using namespace std;

class subject // ���� Ŭ����
{
private:
	string name;		// ���� �̸�
	string id;			// �м� ��ȣ
public:
	// Constructor
	subject();
	subject(string _name, string _id); // ������ �ߺ� ����

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


class student // �л� Ŭ����
{
private:
	int num;					// �����ϰ� �ִ� ������ ����
	string name;				// �̸�
	string Id;					// ���̵�
	string password;		// ��й�ȣ
	subject bag[3];			// ��ٱ���
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
	cout << "\n======== My ��ٱ��� ========\n";
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
			cout << "�̹� MY ��ٱ��Ͽ� ����� �ֽ��ϴ�.\n\n";
		else
		{
			bag[num].setName(_name);
			bag[num].setId(_id);
			num++;
		}
	}
	else
	{
		cout << "�� �̻� ��ٱ��Ͽ� ���� �� �����ϴ�.\n\n";
		return;
	}
}

class Member
{
private:
	int cnt;								// �ý��ۿ� ���Ե� �л��� ��
	student* studentList;		// �ý��ۿ� ���Ե� �л��� ����
public:
	// Constructor
	Member();

	// Destructor
	~Member();

	// Func
	void Enrollment();	// ȸ������
	student* Login();		// �α���
};

Member::Member()
{
	this->cnt = 0;
	this->studentList = new student[10]; // �ʱ� ����Ʈ�� ũ��� 10���� ��
}

Member::~Member()
{
	delete[] studentList;
}

void Member::Enrollment()
{
	string inputName, inputId, inputPassword;

	cout << "�̸�: ";
	cin >> inputName;

	cout << "���̵�: ";
	cin >> inputId;

	cout << "��й�ȣ: ";
	cin >> inputPassword;

	this->studentList[this->cnt].setName(inputName);				// �Է¹��� �̸����� �л� �̸� ����
	this->studentList[this->cnt].setId(inputId);							// �Է¹��� ���̵�� �л� ���̵� ����
	this->studentList[this->cnt].setPassword(inputPassword);	// �Է¹��� ��й�ȣ�� �л� ��й�ȣ ����
	this->cnt++;																			// ����Ʈ ���� �л� �� ����

	if (this->cnt < 10)
		cout << "\n=== ȸ������ ���� ===\n\n";
	else
		cout << "\n=== ȸ������ ���� ===\n\n";
}

student* Member::Login()
{
	string inputId, inputPassword;

	cout << "���̵�: ";
	cin >> inputId;

	cout << "��й�ȣ: ";
	cin >> inputPassword;

	bool chk = false;
	int idx = -1;
	for (int i = 0; i < this->cnt; i++)
	{
		if (this->studentList[i].getId() == inputId)
		{
			idx = i;	// �ش� ���̵��� �ε��� ����
			chk = true;
			break;
		}
	}

	if (chk) // ����Ʈ ���� ���̵� �ִٸ�, ��й�ȣ�� �˻�
	{
		if (this->studentList[idx].getPassword() == inputPassword) // ��й�ȣ�� ��ġ�Ѵٸ�
		{
			cout << "\n=== �α��� ���� ===\n\n";
			cout << this->studentList[idx].getName() << "�� ȯ���մϴ�\n\n";
			return this->studentList + idx; // �ش��ϴ� �л��� ������ ��ȯ��
		}
		else
		{
			cout << "���̵� Ȥ�� ��й�ȣ�� Ʋ�Ƚ��ϴ�.\n\n";
			return nullptr; // �α��� ����
		}
	}
	else
	{
		cout << "���̵� Ȥ�� ��й�ȣ�� Ʋ�Ƚ��ϴ�.\n\n";
		return nullptr; // �α��� ����
	}
}

class cart
{
public:
	// Func
	void run(student* _stu, subject* list, int n);					// ��ٱ��� ��� ����
	void printMenu();															// ��ٱ��� �޴�
	void print(subject* list, int n);										// 1�� ���
	void bag_course(student* _stu, subject* list, int n);		// 2�� ���
	void put_bag(student* _stu);										// 3�� ���
};

void cart::printMenu()
{
	cout << "=========================\n";
	cout << "1. ��ٱ���\n";
	cout << "2. ���� ���\n";
	cout << "3. ������û Ȯ��\n";
	cout << "4. �α׾ƿ�\n";
	cout << "��ȣ�� �Է��ϼ���: ";
}

void cart::print(subject* list, int n)
{
	cout << "\n========== ���Ǹ�� ==========\n";
	for (int i = 0; i < n; i++)
		cout << "[" << i + 1 << "] " << list[i].getName() << " >> " << list[i].getId() << '\n';
	cout << '\n';
}

void cart::bag_course(student* _stu, subject* list, int n)
{
	string id;
	cout << "\n�߰��� �м���ȣ >> ";
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
			cout << "---------- �α׾ƿ� ----------\n";
			cout << "�α׾ƿ� �Ǿ����ϴ�. �ȳ��� ������.\n\n";
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

	// ���Ǹ��
	subject list[3] = {
		{"c++ ���α׷���", "0001"},
		{"linux ���α׷���", "0002"},
		{"������", "0003"}
	};

	while (true)
	{
		printStartMenu();
		cout << "��ȣ�� �Է��ϼ��� >> ";
		cin >> menuSelect;

		if (menuSelect == 1)  // ȸ������
		{
			cout << "-------------------------------------------------------------------------\n\n";
			mb->Enrollment();
		}
		else if (menuSelect == 2) // �α���
		{
			cout << "-------------------------------------------------------------------------\n\n";
			searched = mb->Login();

			if (searched != nullptr) // nullptr�� �ƴ϶�� �α��� ����
				cart.run(searched, list, 3);	// cart���� (�α��ε� �л��� ����, ����Ʈ, ���� �� ����)
		}
		else
		{
			cout << "1 �Ǵ� 2�� �Է����ּ���\n";
			cout << "-------------------------------------------------------------------------\n\n";
			continue;
		}
	}
}

void System::printStartMenu()
{
	cout << "--------------------- ���￩�ڴ��б� ���������ý��� ---------------------\n";
	cout << "1. ȸ������\n";
	cout << "2. �α���\n\n";
}

int main(int argc, char argv[])
{
	System program;
	program.run();
	return 0;
}