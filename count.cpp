// count.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//��������>
	return a.number>b.number;
}
string readFileIntoString()
{
	ifstream ifile;
	//�ȶ��뵽buf
	ifile.open("d:\\words.txt");
	ostringstream buf;
	char ch;
	while (buf && ifile.get(ch))
	{
		buf.put(ch);
	}
	return buf.str();
}

void count(string s)
{
	string result;
	//record��¼��������ĸ
	int record = 0;
	//number��¼���ʳ��ִ���
	int number = 1;
	//ɾ����ͷ�Ŀո�
	int i = 0;
	int numOfWord = 0;
	vector <Save> save(100);
	while (s[i] == 32)
	{
		i++;
	}
	s = s.substr(i, s.size());
	//����ת��Ϊ�ո�
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
			//�������ĵ�һ�����ʷ���result��
			result.append(s, record, i - record);
			while (s[i] == 32)
			{
				i++;
			}
			s = s.substr(i, s.size());
			i = 0;
			//����s���Ƿ��иõ��ʣ��ҵ����s��ɾ��
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
		//�������һ������
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

