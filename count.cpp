// count.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "cstdio"
#include "iostream"
#include "string"
#include "fstream"
#include "sstream"
#include "algorithm"
#include "vector" 
using namespace std;
class Save
{
public:
	string str;
	int number;
};

bool comparison(Save a, Save b) {
	//降序排列>
	return a.number>b.number;
}
string readFileIntoString()
{
	ifstream ifile;
	//先读入到buf
	ifile.open("d:\\words.txt");
	ostringstream buf;
	char ch;
	while (buf && ifile.get(ch))
	{
		buf.put(ch);
	}
	return buf.str();
}

//这个函数有点太长了，能否尝试分解一下。而且它的名字也没有准确反应它的功能。
void count(string s)
{
	string result;
	//record记录单词首字母
	int record = 0;
	//number记录单词出现次数
	int number = 1;
	//删除开头的空格
	int i = 0;
	int numOfWord = 0;
	vector <Save> save(100);
	while (s[i] == 32)
	{
		i++;
	}
	s = s.substr(i, s.size());
	//换行转化为空格
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '\n')
		{
			s[i] = 32;
		}
	}

	for (int i = 0; i <= s.size(); i++)
	{
		if (s[i] == 32)
		{
			//把遇到的第一个单词放在result中
			result.append(s, record, i - record);
			while (s[i] == 32)
			{
				i++;
			}
			s = s.substr(i, s.size());
			i = 0;
			//查找s中是否还有该单词，找到则从s中删除
			//cout << s << "  before  "<<endl;
			int pos;
			while ((pos = s.find(result)) != string::npos)
			{
				//cout << pos << "result" << endl;
				string s1 = s.substr(0, pos);

				string s2 = s.substr(pos + result.size(), s.size());
				s = s1 + s2;
				//cout << s1 << "  s1  " << endl;
				//cout << s2 << "  s2  " << endl;
				//cout << s << "  s  " << endl;
				number++;

			}
			//cout << result << " " << number << endl;
			save[numOfWord].str = result;
			save[numOfWord].number = number;
			numOfWord++;
			result = "";
			number = 1;
		}
		//处理最后一个单词
		if (i == s.size() && s != "")
		{
			//cout << s << " " << "1" << endl;
			save[numOfWord].str = s;
			save[numOfWord].number = 1;
			
		}
	}

	sort(save.begin(), save.end(), comparison);
	for (int i = 0; i <= numOfWord; i++)
	{
		cout << save[i].str << " " << save[i].number << endl;
	}
}

int main()
{
	string s;
	s = readFileIntoString();
	count(s);
    return 0;
}

