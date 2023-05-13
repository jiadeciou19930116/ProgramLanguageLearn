/*	Problem 11_1 Time__isEarlerThan()

	Please implement a member function bool Time::isEarlierThan(Time t);

– Return true if and only if the invoking object’s time is earlier than that of t.

*/
#include<iostream>
using namespace std;


class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h, int m, int s);
	~Time(); //stack 儲存construct次序，destruct時按照pop出的順序消滅 
	void print();
	bool isEarlierThan(Time t);
};
int main()
{
	int h1 = 0, h2 = 0, h3 = 0;
	int m1 = 0, m2 = 0, m3 = 0;
	int s1 = 0, s2 = 0, s3 = 0;
	cout << "請輸入三組時間，每個數字間用空格隔開:" << endl;
	cin >> h1 >> m1 >> s1;
	cin >> h2 >> m2 >> s2;
	cin >> h3 >> m3 >> s3;
	
	cout << "Declare t1, t2 and t3." << endl;
	Time t3(h3, m3, s3);
	Time t1(h1, m1, s1);
	Time t2(h2, m2, s2);

	cout << "Find the last time. " << endl;
	if(t2.isEarlierThan(t1))
	{
		if(t3.isEarlierThan(t1))
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 3 << endl;
		}
	}
	else
	{
		if(t3.isEarlierThan(t2))
		{
			cout << 2 << endl;
		}
		else
		{
			cout << 3 << endl;
		}
	}
	cout << "This process will end." << endl;
	return 0;
}

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
	cout << "Constructor  " << hour << ":" << minute << ":" << second << endl;
}
void Time::print()
{
	cout << hour << ":" << minute << ":" << second;
}

bool Time::isEarlierThan(Time t)
{
	cout << "Compare ";
	cout << hour << ":" << minute << ":" << second;
	cout << " and " << t.hour << ":" << t.minute << ":" << t.second << endl;
	if(hour < t.hour)
	{
		return true;
	}
	else if(hour == t.hour)
	{
		if(minute < t.minute)
		{
			return true;
		}
		else if(minute == t.minute)
		{
			if(second < t.second)
			{
				return true;
			}
		}
	}
	return false;
};

Time::~Time()
{
	cout << "Destructor  ";
	cout << hour << ":" << minute << ":" << second << endl;
	return;
};
