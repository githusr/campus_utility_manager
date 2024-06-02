#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#define MAX 100

using namespace std;
class Person
{
public:
	string Id;
	string name;
	double power;
	double water;
	double watermoney;
	double powermoney;
	string flag;
public:
	Person(string id =0, string na = 0, double p = 0, double w = 0, double wm = 0, double pm = 0, string f = "否")
	{
		Id = id;
		name = na;
		power = p;
		 water=w;
		 watermoney=wm;
		 powermoney=pm;
		 flag=f;
	}

};
int amount = 0;
class Student :virtual public Person
{
public:
	string classroom;
public:
	Student(string id = 0, string na = 0, double p = 0, double w = 0, double wm = 0, double pm = 0, string f = "否", string cr = 0) :Person(id, na, p, w, wm, pm, f)
	{
		classroom = cr;
	}
	void Input();
	void Add();
	void Search();
	void Show();
	void Compile();
	void Delete();
	void Total();
	void Save();
	void Read();
	void studentMenu();
};
Student stu[MAX];
int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
//排序有错
void Student :: Input()
{
	cout << "请输入学号：" << endl;
	cin >> Id;
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入本月用水量：" << endl;
	cin >> water;
	cout << "请输入本月用电量：" << endl;
	cin >> power;
	if (power > 10)
		powermoney = (power - 10) * 0.5;
	if (water > 10)
		watermoney = (water - 10) * 0.5;
}
void Student::Add()
{
	if (amount >= 100)
	{
		cout << "用户已满！" << endl;
		return;
	}
	Student s;
	cout << "请输入新添加学生信息" << endl;
	s.Input();
	for (int i = 0;i < amount;i++)
	{
		if (s.Id ==stu[i].Id)
		{
			cout << "该编号用户已存在！" << endl;
			return;
		}
	}
	stu[amount] = s;
	cout << "添加成功。" << endl;
	amount++;
	Save();
}
void Student::Search()
{
	if (amount == 0)
	{
		cout << "当前系统为空。" << endl;
		return;
	}
	int choice;
	cout << "请选择查询方式：1.按姓名查询 2.按用水量查询 3.按用电量查询" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		string name;
		cout << "输入查找姓名" << endl;
		cin >> name;
		int k = 0;
		cout << "\t" << "编号：" << "\t" << "姓名：" << "\t" << "用水量：" << "\t" << "水费：" << "\t" << "用电量：" << "\t"<<"电费："<<"\t"<<"是否缴费："<<endl;
		for (int i = 0;i < amount;i++)
		{
			if (stu[i].name == name)
			{
				cout << "\t" << stu[i].Id<< "\t" << stu[i].name << "\t" << stu[i]. water<< "\t" << stu[i].watermoney << "\t" << stu[i].power<< "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
				k = 1;
			}
		}
		if (k == 0)
		{
			cout << "查无此人！" << endl;
		}
		break;
	}
	case 2:
	{
		double water;
		cout << "输入查找用水量" << endl;
		cin >> water;
		int k = 0;
		cout << "\t" << "编号：" << "\t" << "姓名：" << "\t" << "用水量：" << "\t" << "水费：" << "\t" << "用电量：" << "\t" << "电费：" << "\t" << "是否缴费：" << endl;
		for (int i = 0;i < amount;i++)
		{
			if (stu[i].water == water)
			{
				cout << "\t" << stu[i].Id << "\t" << stu[i].name << "\t" << stu[i].water << "\t" << stu[i].watermoney << "\t" << stu[i].power << "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
				k = 1;
			}
		}
		if (k == 0)
		{
			cout << "查无此用水量！" << endl;
		}
		break;
	}
	case 3:
	{
		double power;
		cout << "输入查找用电量" << endl;
		cin >> power;
		int k = 0;
		cout << "\t" << "编号：" << "\t" << "姓名：" << "\t" << "用水量：" << "\t" << "水费：" << "\t" << "用电量：" << "\t" << "电费：" << "\t" << "是否缴费：" << endl;
		for (int i = 0;i < amount;i++)
		{
			if (stu[i].power == power)
			{
				cout << "\t" << stu[i].Id << "\t" << stu[i].name << "\t" << stu[i].water << "\t" << stu[i].watermoney << "\t" << stu[i].power << "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
				k = 1;
			}
		}
		if (k == 0)
		{
			cout << "查无此用电量！" << endl;
		}
		break;
	}
	default:
	{
		cout << "无此选项，请重试！" << endl;
		break;
	}
	}
}
void Student::Show()
{
	if (amount == 0)
	{
		cout << "当前无存储记录" << endl;
		return;
	}
	cout << "学生信息：" << endl;
	cout << "\t" << "编号：" << "\t" << "姓名：" <<" \t"<<"班级："<<"\t" << " 用水量：" << "\t" << "水费：" << "\t" << "用电量：" << "\t" <<  "电费：" << "\t" << "是否缴费：" << endl;
	for (int i = 0;i < amount;i++)
	{
		cout << "\t" << stu[i].Id << "\t" << stu[i].name << "\t" << stu[i].classroom<< "\t" << stu[i].water << "\t" << stu[i].watermoney << "\t" << stu[i].power << "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
	}
}
void Student::Compile()
{
	if (amount == 0)
	{
		cout << "当前无存储记录" << endl;
		return;
	}
	string Ids;
	cout << "请输入要修改的学号：" << endl;
	cin >> Ids;
	int k = 0;
	for (int i = 0;i < amount;i++)
	{
		if(stu[i].Id==Ids)
		{
			cout << "原来学生信息：" << endl;
			cout << "\t" << "编号：" << "\t" << "姓名：" << " \t" << "班级：" << "\t" << " 用水量：" << "\t" << "水费：" << "\t" << "用电量：" << "\t" << "电费：" << "\t" << "是否缴费：" << endl;
			cout << "\t" << stu[i].Id << "\t" << stu[i].name << "\t" << stu[i].classroom << "\t" << stu[i].water << "\t" << stu[i].watermoney << "\t" << stu[i].power << "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
			cout << "请对该学生进行信息修改：" << endl;
			Student s;
			s.Input();
			for (int t = 0;t < amount;t++)
			{
				if (s.Id==stu[t].Id)
				{
					if (t == i)
					{
						cout << "该编号用户已存在，修改失败！" << endl;
						return;
					}
				}
			}
			stu[i] = s;
			cout << "现在学生信息：" << endl;
			cout << "\t" << "编号：" << "\t" << "姓名：" << " \t" << "班级：" << "\t" << " 用水量：" << "\t" << "水费：" << "\t" << "用电量：" << "\t" << "电费：" << "\t" << "是否缴费：" << endl;
			cout << "\t" << stu[i].Id << "\t" << stu[i].name << "\t" << stu[i].classroom << "\t" << stu[i].water << "\t" << stu[i].watermoney << "\t" << stu[i].power << "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
			cout << "修改成功." << endl;
			k = 1;
		}
		if (k == 0)
		{
			cout << "查无此人。" << endl;
		}
		Save();
	}
	
}
void Student::Delete()
{
	if (amount == 0)
	{
		cout << "系统无记录。" << endl;
		return;
	}
	cout << "1.按学号删除" << "\t" << "2.按姓名删除" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入学号：" << endl;
		string Ids;
		cin >> Ids;
		int k = 0;
		for (int i = 0;i < amount;i++)
		{
			if (stu[i].Id == Ids)
			{
				cout << "需要删除学生的信息：" << endl;
				cout << "\t" << "编号：" << "\t" << "姓名：" << " \t" << "班级：" << "\t" << " 用水量：" << "\t" << "水费：" << "\t" << "用电量：" << "\t" << "电费：" << "\t" << "是否缴费：" << endl;
				cout << "\t" << stu[i].Id << "\t" << stu[i].name << "\t" << stu[i].classroom << "\t" << stu[i].water << "\t" << stu[i].watermoney << "\t" << stu[i].power << "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
				int choice = 0;
				cout << "是否确认删除：1.否 2.是" << endl;
				switch (choice)
				{
					case 1:
					{
						k = 2;
						break;
					}
					case 2:
					{
						for (int j = i;j < amount;j++)
						{
							stu[j] = stu[j + 1];
						}
						amount = amount - 1;
						k = 1;
						break;
					}
				default:
					{
						cout << "无此项！" << endl;
						break;
					}
				}
			}
			if (k == 1)
			{
				cout << "删除成功！" << endl;
			}
			else if (k == 2)
			{
				cout << "查询到此学号，但未删除。" << endl;
			}
			else
			{
				cout << "未查询到此学号。" << endl;
			}
		}
		Save();
	}
	case 2:
	{
		cout << "请输入姓名：" << endl;
		string names;
		cin >> names;
		int k = 0;
		for (int i = 0;i < amount;i++)
		{
			if (stu[i].name == names)
			{
				cout << "需要删除学生的信息：" << endl;
				cout << "\t" << "编号：" << "\t" << "姓名：" << " \t" << "班级：" << "\t" << " 用水量：" << "\t" << "水费：" << "\t" << "用电量：" << "\t" << "电费：" << "\t" << "是否缴费：" << endl;
				cout << "\t" << stu[i].Id << "\t" << stu[i].name << "\t" << stu[i].classroom << "\t" << stu[i].water << "\t" << stu[i].watermoney << "\t" << stu[i].power << "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
				int choice = 0;
				cout << "是否确认删除：1.否 2.是" << endl;
				switch (choice)
				{
				case 1:
				{
					k = 2;
					break;
				}
				case 2:
				{
					for (int j = i;j < amount;j++)
					{
						stu[j] = stu[j + 1];
					}
					amount = amount - 1;
					k = 1;
					break;
				}
			default:
				{
					cout << "无此项！" << endl;
					break;
				}
				}
			}
			if (k == 1)
			{
				cout << "删除成功！" << endl;
			}
			else if (k == 2)
			{
				cout << "查询到此学号，但未删除。" << endl;
			}
			else
			{
				cout << "未查询到此学号。" << endl;
			}
			Save();
		}
	}
	default:
	{
		cout << "无此项。" << endl;
		break;
	}
	}
}
void Student::Total()
{
	if (amount == 0)
	{
		cout << "当前无存储记录" << endl;
		return;
	}
	cout << "未缴费学生：" << endl;
	cout << "\t" << "编号：" << "\t" << "姓名：" << " \t" << "班级：" << "\t" << " 用水量：" << "\t" << "水费：" << "\t" << "用电量：" << "\t" << "电费：" << "\t" << "是否缴费：" << endl;
	int t = 0;
	for (int i = 0;i < amount;i++)
	{
		if (stu[i].flag == "否")
		{
			cout << "\t" << stu[i].Id << "\t" << stu[i].name << "\t" << stu[i].classroom << "\t" << stu[i].water << "\t" << stu[i].watermoney << "\t" << stu[i].power << "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
			t = 1;
		}
		if (t == 0)
		{
			cout << "无未缴费学生。" << endl;
		}
	}
}
void Student::Save()//更新记录
{
	qsort(stu, amount, sizeof(stu[0]), compare);//排序
	ofstream out_file("学生.txt", ios::out);//添加记录到文件中
	if (!out_file)
	{
		cout << "文件打开失败。" << endl;
		return;
	}
	for (int i = 0;i < amount;i++)
	{
		out_file << "\t" << stu[i].Id << "\t" << stu[i].name << "\t" << stu[i].classroom << "\t" << stu[i].water << "\t" << stu[i].watermoney << "\t" << stu[i].power << "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
	}
	out_file.close();
}
//save中有排序错误，需要改
void Student::Read()
{
	ifstream in_file("学生.txt", ios::in);
	if (!in_file)
	{
		cout << "打开失败！" << endl;
		return;
	}
	int i = 0;
	cout << "学生信息：" << endl;
	cout << "\t" << "编号：" << "\t" << "姓名：" << " \t" << "班级：" << "\t" << " 用水量：" << "\t" << "水费：" << "\t" << "用电量：" << "\t" << "电费：" << "\t" << "是否缴费：" << endl;
	while (in_file >> stu[i].Id >> stu[i].name >> stu[i].classroom >> stu[i].water >> stu[i].watermoney >> stu[i].power >> stu[i].powermoney >> stu[i].flag)
	{
		cout << "\t" << stu[i].Id << "\t" << stu[i].name << "\t" << stu[i].classroom << "\t" << stu[i].water << "\t" << stu[i].watermoney << "\t" << stu[i].power << "\t" << stu[i].powermoney << "\t" << stu[i].flag << endl;
	}
	in_file.close();
}
void studentMenu()
{
	amount = 0;
	ifstream in_file("学生.txt", ios::in);
	if (!in_file)
	{
		cout << "打开文件失败。" << endl;
	}
	while (in_file >> stu[amount].Id >> stu[amount].name >> stu[amount].classroom >> stu[amount].water >> stu[amount].watermoney >> stu[amount].power >> stu[amount].powermoney >> stu[amount].flag)
	{
		amount++;
	}
	in_file.close();
	Student students;
	int choice = 8;
	while (choice != 0)
	{
		cout << "*******************************************" << endl;
		cout << "学生水电管理系统\n" << endl;
	}
	cout << "请输入你的选择：" << endl;
	switch (choice)
	{
	case 1:	void Add();break;
	case 2:	void Search();break;
	case 3:void Show();break;
	case 4:void Compile();break;
	case 5:void Delete();break;
	case 6:void Total();break;
	case 7:void Save();break;
	case 0:main();break;
	default:cout << "不存在" << endl;break;
	}
}
int main()
{
	int choice = 3;
	while (choice)
	{
		cout << "*******************************************" << endl;
		cout << "*      高校水电费管理系统     *" << endl;
		cout << "*     0.退出系统   1.教师系统   2.学生系统     *" << endl;
		cout << "*******************************************" << endl;
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:cout << "您已退出系统。" << endl;
		case 2:studentMenu();break;
		default:cout << "不存在，请重新选择。" << endl;break;
		}
		cout << "欢迎你的下次使用。" << endl;
	}
	return 0;
}

