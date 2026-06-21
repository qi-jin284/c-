#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <locale>
#include <clocale>
#include <limits>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cctype>
#define MAX 1000
using namespace std;

//�����ϵ�˽ṹ��
struct Person {
	//����
	string m_Name;
	//�Ա� 
	int m_Sex;
	// ����
	int m_Age;
	//�绰
	string m_Phone1;
	string m_Phone2;
	//����
	string m_Email;
	//סַ
	string m_Addr;

};
//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	 Person personArray[MAX];
	//ͨѶ¼��ǰ��¼��ϵ�˸���
	int m_Size;

};


//���ߺ���
void tool() {
	system("pause");
	system("cls");
}


//1��������ϵ��

void addPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ�������
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷����ӣ�" << endl;
		return;
	}
	else
	{
		//���Ӿ�����ϵ��

		//����
		string name;
		while (true) {
			cout << "������������" << endl;
			cin >> name;
			if (!name.empty()) {
				abs->personArray[abs->m_Size].m_Name = name;
				break;
			}
			cout << "��������Ϊ�գ�" << endl;
		}
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) {
			//����1��2�����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2) {

				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}
		//����
		cout << "������������䣺 " << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age >0 && age<100) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
				cout << "��������ȷ�����䣡" << endl;
		}
		
		//�绰
		cout << "���������ĵ绰1��" << endl;
		string Phone1;
		cin >> Phone1;
		abs->personArray[abs->m_Size].m_Phone1 = Phone1;
		cout << "���������ĵ绰2������#������" << endl;
		string Phone2;
		cin >> Phone2;
		abs->personArray[abs->m_Size].m_Phone2 = Phone2;
		//����
		cout << "�������������䣺" << endl;
		string email;
		cin >> email;
		abs->personArray[abs->m_Size].m_Email = email;
		//סַ
		cout << "����������סַ�� " << endl;
		cin.ignore();
		string address;
		getline(cin, address);
		abs->personArray[abs->m_Size].m_Addr = address;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "���ӳɹ�" << endl;
		tool();
	}


}
//2����ʾ��ϵ��
void showPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;

	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "����: " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << "�绰1�� " << abs->personArray[i].m_Phone1 << "\t";
			cout << "�绰2�� " << abs->personArray[i].m_Phone2 << "\t";
			cout << "���䣺 " << abs->personArray[i].m_Email << endl;
			cout << "סַ�� " << abs->personArray[i].m_Addr << endl;
		}
	}
	tool();
}
//3�������ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1  ͨѶ¼  ����2  �Ա�����
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		//�ҵ��û����������
		if (abs->personArray[i].m_Name == name)
		{
			return i;//�ҵ����������
		}

	}
	return -1;//�����������û�ҵ�������-1

}
//3��ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs) {

	if (abs->m_Size == 0) {
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		tool();
		return;
	}
	string keyword;
	cout << "������ؼ���(����/�ֻ���)��" << endl;
	cin >> keyword;

	bool isfound = false;
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name.find(keyword) != string::npos ||
			abs->personArray[i].m_Phone1.find(keyword) != string::npos ||
			abs->personArray[i].m_Phone2.find(keyword) != string::npos) {

			cout << " ������" << i + 1 << " ������" << abs->personArray[i].m_Name <<
				" �Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") <<
				"���䣺" << abs->personArray[i].m_Age << " �绰1��" <<
				abs->personArray[i].m_Phone1 << " �绰2" <<
				abs->personArray[i].m_Phone2 << " ���䣺" <<
				abs->personArray[i].m_Email << " סַ��" << abs->personArray[i].m_Addr << endl;
			isfound = true;
		}
	}
	if (!isfound) cout << "��ƥ������" << endl;
	tool();
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	//ret=-1  δ�鵽
	//ret!=-1  �鵽��
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//���ҵ��ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_Size-1; i++) {
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];

		}
		abs->m_Size--;//����ͨѶ¼��Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;

	}
	tool();
}
//4(1)��������ϵ��
void findPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		return;
	}
	
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж��Ƿ����
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "������ " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա� " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰1�� " << abs->personArray[ret].m_Phone1 << "\t";
		cout << "�绰2�� " << abs->personArray[ret].m_Phone2 << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_Email << endl;
		cout << "סַ�� " << abs->personArray[ret].m_Addr << endl;

	}
	else {
		cout << "���޴���" << endl;

	}
	tool();
}

//4(2)��ģ������
void searchPersonfuzzy(Addressbooks*abs) {
	tool();
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		return;
	}
	string keyword;
	cout << "������ؼ���(����/�ֻ���)��" << endl;
	cin >> keyword;

	bool isfound = false;
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name.find(keyword) != string::npos ||
			abs->personArray[i].m_Phone1.find(keyword) != string::npos ||
			abs->personArray[i].m_Phone2.find(keyword) != string::npos||
			abs->personArray[i].m_Addr.find(keyword) != string::npos
			) {
			cout << " ������" << i + 1 << " ������" << abs->personArray[i].m_Name <<
				" �Ա�" << (abs->personArray[i].m_Sex==1?"��":"Ů")<<
				"���䣺"<< abs->personArray[i].m_Age<<" �绰1��" <<
				abs->personArray[i].m_Phone1 << " �绰2" <<
				abs->personArray[i].m_Phone2 <<" ���䣺" <<
				abs->personArray[i].m_Email <<" סַ��"<< abs->personArray[i].m_Addr<<endl;
			isfound = true;
		}
	}

	if (!isfound) cout << "��ƥ������"<<endl;
	tool();
}

//5���޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs) {

	if (abs->m_Size == 0) {
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		return;
	}
	string keyword;
	cout << "������ؼ���(����/�ֻ���)��" << endl;
	cin >> keyword;

	bool isfound = false;
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name.find(keyword) != string::npos ||
			abs->personArray[i].m_Phone1.find(keyword) != string::npos ||
			abs->personArray[i].m_Phone2.find(keyword) != string::npos) {

			cout << " ������" << i + 1 << " ������" << abs->personArray[i].m_Name <<
				" �Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") <<
				"���䣺" << abs->personArray[i].m_Age << " �绰1��" <<
				abs->personArray[i].m_Phone1 << " �绰2����ѡ��" <<
				abs->personArray[i].m_Phone2 << " ���䣺" <<
				abs->personArray[i].m_Email << " סַ��" << abs->personArray[i].m_Addr << endl;
			isfound = true;
		}
	}
	if (!isfound) cout << "��ƥ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//�ҵ�ָ����ϵ��
	{
		//����
		string name;
		while (true) {
			cout << "������������" << endl;
			cin >> name;
			if (!name.empty()) {
				abs->personArray[ret].m_Name = name;
				break;
			}
			cout << "��������Ϊ�գ�" << endl;
		}
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		cin >> sex;
		while (true) {
			if (sex == 1 || sex == 2) {
				//������ȷ �˳�ѭ������
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������� ��������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age > 1 && age < 100) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "��������ȷ�����䣡" << endl;
		}

		//�绰
		cout << "��������ϵ�绰1" << endl;
		string  phone1;
		cin >> phone1;
		abs->personArray[ret].m_Phone1 = phone1;

		cout << "��������ϵ�绰2" << endl;
		string  phone2;
		cin >> phone2;
		abs->personArray[ret].m_Phone2 = phone2;
		//����
		cout << "����������" << endl;
		string email;
		cin >> email;
		abs->personArray[ret].m_Email = email;

		//סַ
		cout << "������һ����ַ" << endl;
		cin.ignore();
		string addr;
		getline(cin, addr);
		abs->personArray[ret].m_Addr = addr;
		cout << "�޸ĳɹ�" << endl;
	}
	else {
		//δ�ҵ���ϵ��
		cout << "���޴���" << endl;
	}
	tool();
}
//6�������ϵ��
void cleanPerson(Addressbooks* abs) {
 //����ǰ��¼����ϵ��������Ϊ0�����߼����
	cout << "ȷ�����ͨѶ¼?(1-ȷ��/0-ȡ��)" << endl;
	int confirm = 0;
	cin >> confirm;
	if (confirm == 1) {
		abs->m_Size = 0;
		cout << "ͨѶ¼����գ�" << endl;
	}
	else {
		cout << "ȡ����ղ�����" << endl;
	}
	tool();
}


//��ϵ������
// compareType���������ͣ�1=������2=���䣬3=�Ա�
void bubbleSort(Addressbooks* abs, int compareType) {
	// 1. �ظ��߼����ж�ͨѶ¼Ϊ��
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		system("pause");
		return;
	}

	// 2. �ظ��߼���ð������˫��ѭ��
	for (int i = 0; i < abs->m_Size - 1; i++) {
		for (int j = 0; j < abs->m_Size - 1 - i; j++) {
			// ֻ���������֡��ȽϹ��򡱣�Ψһ�ı仯�㣩
			bool needSwap = false; // �Ƿ���Ҫ����
			switch (compareType) {
			case 1: // �������Ƚ�
				needSwap = abs->personArray[j].m_Name > abs->personArray[j + 1].m_Name;
				break;
			case 2: // ������Ƚ�
				needSwap = abs->personArray[j].m_Age > abs->personArray[j + 1].m_Age;
				break;
			case 3: // ���Ա�Ƚ�
				needSwap = abs->personArray[j].m_Sex > abs->personArray[j + 1].m_Sex;
				break;
			}

			// 3. �ظ��߼�������Ԫ��
			if (needSwap) {
				Person temp = abs->personArray[j];
				abs->personArray[j] = abs->personArray[j + 1];
				abs->personArray[j + 1] = temp;
			}
		}
	}
}

// ����������
void sortPersonname(Addressbooks* abs) {
	bubbleSort(abs, 1); // ��1=������
	cout << "�������������" << endl;
	tool();
}

// ����������
void sortPersonage(Addressbooks* abs) {
	bubbleSort(abs, 2); // ��2=������
	cout << "�������������" << endl;
	tool();
}

// ���Ա�����
void sortPersonsex(Addressbooks* abs) {
	bubbleSort(abs, 3); // ��3=���Ա�
	cout << "���Ա��������" << endl;
	tool();
}

//��ȡ��ϵ��
void readFile(Addressbooks* abs) {
	ifstream ifs("addressbook.txt");
	if (!ifs.is_open()) {
		cout << "������ϵ������" << endl;
		return;
	}
	abs->m_Size = 0;
	// ѭ������ֱ���ļ�����
	while (abs->m_Size < MAX &&
	ifs >> abs->personArray[abs->m_Size].m_Name
		>> abs->personArray[abs->m_Size].m_Sex
		>> abs->personArray[abs->m_Size].m_Age
		>> abs->personArray[abs->m_Size].m_Phone1
		>> abs->personArray[abs->m_Size].m_Phone2
		>> abs->personArray[abs->m_Size].m_Email
		>> abs->personArray[abs->m_Size].m_Addr) {
		abs->m_Size++;
	}
	ifs.close();
	cout << "�ɹ����� " << abs->m_Size << " ����ϵ��" << endl;
}

//������ϵ����Ϣ���ļ�
void saveFile(Addressbooks*abs) {
	ofstream ofs("addressbook.txt",ios::out);
	for (int i = 0; i < abs->m_Size; i++) {
		ofs   << abs->personArray[i].m_Name << "\t"
			  << abs->personArray[i].m_Sex<< "\t"
			  << abs->personArray[i].m_Age << "\t"
			  << abs->personArray[i].m_Phone1 << "\t"
			  << abs->personArray[i].m_Phone2 << "\t"
			  << abs->personArray[i].m_Email << "\t"
			  << abs->personArray[i].m_Addr << endl;
	}
	ofs.close();
	cout << "��ϵ�˴洢�ɹ�" << endl;
	tool();
}

//�˵�����
void showMenu() {
	system("cls");
	cout << "***********ͨѶ¼********" << endl;
	cout << "***** 1��������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 7��������ϵ�� *****" << endl;
	cout << "***** 8��������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "***������(0-8)ѡ����***" << endl;
	cout << "*************************" << endl;

}

//�����Ӳ˵�
void sortshowMenu() {
	system("cls");
	cout << " ************************" << endl;
	cout << " *****�������Ӳ˵�*****" << endl;
	cout << " *****1������������******" << endl;
	cout << " *****2������������******" << endl;
	cout << " *****3�����Ա�����******" << endl;
	cout << " *****0���˳��Ӳ˵�******" << endl;
	cout << " ************************" << endl;
}

//�����Ӳ˵�
void findPersonmenu() {
	cout << "*****************************" << endl;
	cout << "*******���ҹ����Ӳ˵�********" << endl;
	cout << "********1����ȷ����**********" << endl;
	cout << "********2��ģ������**********" << endl;
	cout << "********0���˳�**************" << endl;
	cout << "*****************************" << endl;
}


int main()
{   // 设置控制台编码支持中文
	setlocale(LC_ALL, "chs");
	// 设置控制台颜色
	system("color 0A");
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	readFile(&abs);
	//��ȡ��ϵ����Ϣ
	int select = 0;//�����û�ѡ������ı���
	int num2= 0;//�����û��Ӳ˵�ѡ������ı���
	int num1 = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://������ϵ��
			addPerson(&abs);//���õ�ַ���ݣ���������ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://������ϵ��
		{
			bool sign = true;
			while (sign) {
				findPersonmenu();
				cout<<"����������:"<<endl;
				cin >> num2;
				switch (num2) {
				case 1://��ȷ����
					findPerson(& abs);
					break;

				case 2://ģ������
					searchPersonfuzzy(&abs);
					break;

				case 0:
					cout << "�˳������Ӳ˵�" << endl;
					tool();
					sign = false;
					break;
				default:
					cout << "������� ����������" << endl;
					tool();
					break;
				}
			}
			break;
		}
		break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;

		case 7://������ϵ��
		{
			bool slogn = true;

			while (slogn) {
				sortshowMenu();
				cin >> num1;
				switch (num1) {

				case 1://����������
					sortPersonname(&abs);
					showPerson(&abs);
					break;

				case 2://����������
					sortPersonage(&abs);
					showPerson(&abs);
					break;

				case 3://���Ա�����
					sortPersonsex(&abs);
					showPerson(&abs);
					break;

				case 0:
					cout << "�˳��Ӳ˵�" << endl;
					tool();
					slogn = false;
					break;
				default:
					cout << "������� ����������" << endl;
					tool();
					break;
				}
			}
		}
			break;

		case 8:
			saveFile(&abs);
			tool();
			break;

		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}