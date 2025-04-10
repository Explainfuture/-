#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct StudentInfo
{
	string name;
	string number; 
	int score[3];
};

void Show();
void Exit();
void WriteInTheSystem();
void ShowScore();
void DeleteScore();
bool compareByScores(const StudentInfo& a, const StudentInfo& b);
void SortScore();
int main(){
	while(1)
	{
		Show();
		char numMain;
		cin>>numMain;
		switch (numMain)
		{
		case '1':
			WriteInTheSystem();
			break;
		case '2':
			DeleteScore();
			break;
		case '3':
			ShowScore();
			break;
		case '4':
			SortScore();
			break;
		case '5':
			Exit();
			break;
		}
		
	}
}

void Show()
{
	cout<<"           ��ӭ����ѧ������ϵͳ��              "<<endl;
	cout<<"              ��������Ҫ�Ĳ���                 "<<endl;
	cout<<endl; 
	cout<<"***-----------ѧ���ɼ�����ϵͳ--------------***"<<endl;
	cout<<"   (1) �ɼ�¼��         (2) �ɼ�ɾ��           "<<endl;
	cout<<"   (3) �ɼ���ѯ         (4) �ɼ�����           "<<endl;
	cout<<"              (5) �˳�ϵͳ                     "<<endl;
	cout<<"***-----------------------------------------***"<<endl; 
}

void Exit()
{
	system("cls");
	cout<<"��ӭ�ٴ�ʹ�ã�"<<endl;
	exit(0); 
}

void WriteInTheSystem()
{
	system("cls");
	cout<<"***-----------ѧ���ɼ�����ϵͳ--------------***"<<endl;
	cout<<"                  �ɼ�¼��                     "<<endl;
	fstream f;
	f.open("ScoreTable.txt",ios::in | ios::out |ios::app);
	if (f)
	{
		cout<<"������Ҫ¼���ѧ��������"<<endl;
		int num;
		cin>>num;
		StudentInfo student[num];
		cout<<"�밴��ѧ������ - ѧ�� - ���� - ��ѧ - Ӣ���˳������"<<endl;
		for (int i = 0;i<num;i++)
		{
			cin>>student[i].name>>student[i].number;
			for (int j = 0;j<3;j++)
			{
				cin>>student[i].score[j];
			}
		}
		for (int i = 0;i<num;i++)
		{
			f<<student[i].name<<","<<student[i].number<<",";
			for (int j = 0;j<2;j++)
			{
				f<<student[i].score[j]<<",";
			}
			f<<student[i].score[2]<<";";
		}
		cout<<"д����ɣ�"<<endl;
	}
	else cout<<"�ļ���ʧ�ܣ�����·��"<<endl;
	system("pause");
    system("cls");
}

void ShowScore()
{
    system("cls");
    cout << "***-----------ѧ���ɼ�����ϵͳ--------------***" << endl;
    cout << "                  �ɼ���ѯ                     " << endl;
    cout << "               ��ѡ���ѯ��ʽ                  " << endl;
    cout << "   (1) ������ѯ         (2) ѧ�Ų�ѯ           " << endl;
    cout << "            (3) ��ѯ������Ϣ                   " << endl;
    char lookup;
    cin >> lookup;

    fstream f("ScoreTable.txt", ios::in);
    if (!f) {
        cout << "�ļ���ʧ�ܣ�����·��" << endl;
        return;
    }

    if (lookup == '1')
	{
        cout << "��������Ҫ��ѯ��ѧ��������" << endl;
        string TargetName;
        cin >> TargetName;

        string line;
        bool found = false;
        while (getline(f, line, ';')) {
            stringstream ss(line);
            string name, number, score1, score2, score3;
            getline(ss, name, ',');
            getline(ss, number, ',');
            getline(ss, score1, ',');
            getline(ss, score2, ',');
            getline(ss, score3, ',');

            if (name == TargetName) {
                cout << "�ɹ��ҵ�:" << endl;
                cout << "����:" << setw(5) << name
                     << " ѧ��:" << setw(5) << number
                     << " ����:" << setw(5) << score1
                     << " ��ѧ:" << setw(5) << score2
                     << " Ӣ��:" << setw(5) << score3
                     << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "û���ҵ� " << TargetName << endl;
        }
        system("pause");
        system("cls");
    }
	else if (lookup == '2')
	{
        cout << "��������Ҫ��ѯ��ѧ��ѧ�ţ�" << endl;
        string TargetNum;
        cin >> TargetNum;

        string line;
        bool found = false;
        while (getline(f, line, ';')) {
            stringstream ss(line);
            string name, number, score1, score2, score3;
            getline(ss, name, ',');
            getline(ss, number, ',');
            getline(ss, score1, ',');
            getline(ss, score2, ',');
            getline(ss, score3, ',');

            if (number == TargetNum) {
                cout << "�ɹ��ҵ�:" << TargetNum << endl;
                cout << "����:" << setw(5) << name
                     << " ѧ��:" << setw(5) << number
                     << " ����:" << setw(5) << score1
                     << " ��ѧ:" << setw(5) << score2
                     << " Ӣ��:" << setw(5) << score3
                     << endl;
                found = true;
                break;
			}
		}
        if (!found) {
            cout << "û���ҵ�ѧ��Ϊ " << TargetNum << " ��ѧ��" << endl;
        }
        system("pause");
        system("cls");
    }
    else if (lookup == '3') 
	{
    cout << "ȫ��ѧ���ɼ����£�" << endl;
    string line;
    int count = 0;
    while (getline(f, line, ';')) {
        stringstream ss(line);
        string name, number, s1, s2, s3;
        getline(ss, name, ',');
        getline(ss, number, ',');
        getline(ss, s1, ','); getline(ss, s2, ','); getline(ss, s3, ',');

        cout << left << setw(3) << ++count << " ����:" << setw(10) << name
             << "ѧ��:" << setw(10) << number
             << "����:" << setw(6) << s1
             << "��ѧ:" << setw(6) << s2
             << "Ӣ��:" << setw(6) << s3 << endl;
    }
    system("pause");
    system("cls");
}

    f.close();
}

void DeleteScore()
{
    system("cls");
    cout << "***-----------ѧ���ɼ�����ϵͳ--------------***" << endl;
    cout << "                  �ɼ�ɾ��                     " << endl;
    cout << "��ѡ��ɾ����ʽ��" << endl;
    cout << "   (1) ������ɾ��      (2) ��ѧ��ɾ��          " << endl;

    char choice;
    cin >> choice;

    fstream f("ScoreTable.txt", ios::in);
    if (!f) {
        cout << "�ļ���ʧ�ܣ�" << endl;
        return;
    }

    vector<string> records;
    string line;
    while (getline(f, line, ';')) {
        records.push_back(line);
    }
    f.close();

    string target;
    if (choice == '1') {
        cout << "������Ҫɾ����ѧ��������" << endl;
        cin >> target;
    } else if (choice == '2') {
        cout << "������Ҫɾ����ѧ��ѧ�ţ�" << endl;
        cin >> target;
    } else {
        cout << "������Ч" << endl;
        return;
    }

    bool deleted = false;
    vector<string> updated;
    for (const string& record : records) {
        stringstream ss(record);
        string name, number, s1, s2, s3;
        getline(ss, name, ',');
        getline(ss, number, ',');
        getline(ss, s1, ','); getline(ss, s2, ','); getline(ss, s3, ',');

        if ((choice == '1' && name == target) || (choice == '2' && number == target)) {
            deleted = true; // �ҵ�������
        } else {
            updated.push_back(record);
        }
    }

    ofstream out("ScoreTable.txt", ios::trunc); // ����ļ���д��
    for (const string& r : updated) {
        out << r << ";";
    }
    out.close();

    if (deleted)
        cout << "ɾ���ɹ���" << endl;
    else
        cout << "δ�ҵ���ѧ����Ϣ��" << endl;

    system("pause");
    system("cls");
}

void SortScore() {
    system("cls");
    cout << "***-----------ѧ���ɼ�����ϵͳ--------------***" << endl;
    cout << "                  �ɼ�����                     " << endl;

    ifstream f("ScoreTable.txt");
    if (!f) {
        cout << "�ļ���ʧ�ܣ�" << endl;
        return;
    }

    vector<StudentInfo> students;
    string line;
    while (getline(f, line, ';')) {
        stringstream ss(line);
        StudentInfo s;
        string s1, s2, s3;
        getline(ss, s.name, ',');
        getline(ss, s.number, ',');
        getline(ss, s1, ',');
        getline(ss, s2, ',');
        getline(ss, s3, ',');
        s.score[0] = stoi(s1);
        s.score[1] = stoi(s2);
        s.score[2] = stoi(s3);
        students.push_back(s);
    }
    f.close();

    sort(students.begin(), students.end(), compareByScores);

    cout << "���ɼ����������£�" << endl;
    int i = 1;
    for (const auto& s : students) {
        cout << left << setw(3) << i++
             << "����:" << setw(10) << s.name
             << "ѧ��:" << setw(10) << s.number
             << "����:" << setw(6) << s.score[0]
             << "��ѧ:" << setw(6) << s.score[1]
             << "Ӣ��:" << setw(6) << s.score[2] << endl;
    }
    system("pause");
    system("cls");
}

bool compareByScores(const StudentInfo& a, const StudentInfo& b) {
    if (a.score[0] != b.score[0]) return a.score[0] > b.score[0];
    if (a.score[1] != b.score[1]) return a.score[1] > b.score[1];
    return a.score[2] > b.score[2];
}
