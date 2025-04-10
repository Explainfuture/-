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
	cout<<"           欢迎来到学生管理系统！              "<<endl;
	cout<<"              请输入需要的操作                 "<<endl;
	cout<<endl; 
	cout<<"***-----------学生成绩管理系统--------------***"<<endl;
	cout<<"   (1) 成绩录入         (2) 成绩删除           "<<endl;
	cout<<"   (3) 成绩查询         (4) 成绩排序           "<<endl;
	cout<<"              (5) 退出系统                     "<<endl;
	cout<<"***-----------------------------------------***"<<endl; 
}

void Exit()
{
	system("cls");
	cout<<"欢迎再次使用！"<<endl;
	exit(0); 
}

void WriteInTheSystem()
{
	system("cls");
	cout<<"***-----------学生成绩管理系统--------------***"<<endl;
	cout<<"                  成绩录入                     "<<endl;
	fstream f;
	f.open("ScoreTable.txt",ios::in | ios::out |ios::app);
	if (f)
	{
		cout<<"请输入要录入的学生数量："<<endl;
		int num;
		cin>>num;
		StudentInfo student[num];
		cout<<"请按照学生姓名 - 学号 - 语文 - 数学 - 英语的顺序输入"<<endl;
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
		cout<<"写入完成！"<<endl;
	}
	else cout<<"文件打开失败，请检查路径"<<endl;
	system("pause");
    system("cls");
}

void ShowScore()
{
    system("cls");
    cout << "***-----------学生成绩管理系统--------------***" << endl;
    cout << "                  成绩查询                     " << endl;
    cout << "               请选择查询方式                  " << endl;
    cout << "   (1) 姓名查询         (2) 学号查询           " << endl;
    cout << "            (3) 查询所有信息                   " << endl;
    char lookup;
    cin >> lookup;

    fstream f("ScoreTable.txt", ios::in);
    if (!f) {
        cout << "文件打开失败，请检查路径" << endl;
        return;
    }

    if (lookup == '1')
	{
        cout << "请输入你要查询的学生姓名：" << endl;
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
                cout << "成功找到:" << endl;
                cout << "姓名:" << setw(5) << name
                     << " 学号:" << setw(5) << number
                     << " 语文:" << setw(5) << score1
                     << " 数学:" << setw(5) << score2
                     << " 英语:" << setw(5) << score3
                     << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "没有找到 " << TargetName << endl;
        }
        system("pause");
        system("cls");
    }
	else if (lookup == '2')
	{
        cout << "请输入你要查询的学生学号：" << endl;
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
                cout << "成功找到:" << TargetNum << endl;
                cout << "姓名:" << setw(5) << name
                     << " 学号:" << setw(5) << number
                     << " 语文:" << setw(5) << score1
                     << " 数学:" << setw(5) << score2
                     << " 英语:" << setw(5) << score3
                     << endl;
                found = true;
                break;
			}
		}
        if (!found) {
            cout << "没有找到学号为 " << TargetNum << " 的学生" << endl;
        }
        system("pause");
        system("cls");
    }
    else if (lookup == '3') 
	{
    cout << "全部学生成绩如下：" << endl;
    string line;
    int count = 0;
    while (getline(f, line, ';')) {
        stringstream ss(line);
        string name, number, s1, s2, s3;
        getline(ss, name, ',');
        getline(ss, number, ',');
        getline(ss, s1, ','); getline(ss, s2, ','); getline(ss, s3, ',');

        cout << left << setw(3) << ++count << " 姓名:" << setw(10) << name
             << "学号:" << setw(10) << number
             << "语文:" << setw(6) << s1
             << "数学:" << setw(6) << s2
             << "英语:" << setw(6) << s3 << endl;
    }
    system("pause");
    system("cls");
}

    f.close();
}

void DeleteScore()
{
    system("cls");
    cout << "***-----------学生成绩管理系统--------------***" << endl;
    cout << "                  成绩删除                     " << endl;
    cout << "请选择删除方式：" << endl;
    cout << "   (1) 按姓名删除      (2) 按学号删除          " << endl;

    char choice;
    cin >> choice;

    fstream f("ScoreTable.txt", ios::in);
    if (!f) {
        cout << "文件打开失败！" << endl;
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
        cout << "请输入要删除的学生姓名：" << endl;
        cin >> target;
    } else if (choice == '2') {
        cout << "请输入要删除的学生学号：" << endl;
        cin >> target;
    } else {
        cout << "输入无效" << endl;
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
            deleted = true; // 找到就跳过
        } else {
            updated.push_back(record);
        }
    }

    ofstream out("ScoreTable.txt", ios::trunc); // 清空文件再写入
    for (const string& r : updated) {
        out << r << ";";
    }
    out.close();

    if (deleted)
        cout << "删除成功！" << endl;
    else
        cout << "未找到该学生信息。" << endl;

    system("pause");
    system("cls");
}

void SortScore() {
    system("cls");
    cout << "***-----------学生成绩管理系统--------------***" << endl;
    cout << "                  成绩排序                     " << endl;

    ifstream f("ScoreTable.txt");
    if (!f) {
        cout << "文件打开失败！" << endl;
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

    cout << "按成绩排序结果如下：" << endl;
    int i = 1;
    for (const auto& s : students) {
        cout << left << setw(3) << i++
             << "姓名:" << setw(10) << s.name
             << "学号:" << setw(10) << s.number
             << "语文:" << setw(6) << s.score[0]
             << "数学:" << setw(6) << s.score[1]
             << "英语:" << setw(6) << s.score[2] << endl;
    }
    system("pause");
    system("cls");
}

bool compareByScores(const StudentInfo& a, const StudentInfo& b) {
    if (a.score[0] != b.score[0]) return a.score[0] > b.score[0];
    if (a.score[1] != b.score[1]) return a.score[1] > b.score[1];
    return a.score[2] > b.score[2];
}
