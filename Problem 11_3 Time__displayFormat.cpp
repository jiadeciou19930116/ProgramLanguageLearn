/*	Problem 11_3 Time__displayFormat

	Please implement a member function 
– Print out 08:09:06 if hour is 8, minute is 9, and second is 6. 

	Given three time moments, print out the latest one nicely. 
*/
#include<iostream>
#include<iomanip>
using namespace std;


class Time
{
private:
	int hour;
	int minute;
	int second;
	static bool isTwelveHC; // true if twelve-hour clock
public:
	Time(int h, int m, int s);
	~Time();
	static bool getIsTwelveHC();
	static void setIsTwelveHC(bool HC);
	bool isEarlierThan(Time t);
	void printNicely();
};

bool Time::isTwelveHC = false;

int main()
{
	int h1 = 0, h2 = 0, h3 = 0;
	int m1 = 0, m2 = 0, m3 = 0;
	int s1 = 0, s2 = 0, s3 = 0;
	int hourClock = 0;
	
	cout << "請輸入三組時間，每個數字間用空格隔開:" << endl;
	cin >> h1 >> m1 >> s1;
	cin >> h2 >> m2 >> s2;
	cin >> h3 >> m3 >> s3;
	Time t1(h1, m1, s1);
	Time t2(h2, m2, s2);
	Time t3(h3, m3, s3);
	
	cout << "如果是24小時制請輸入24，12小時制請輸入12:" << endl;
	cin >> hourClock;
	if(hourClock == 12)
	{
		Time::setIsTwelveHC(true);
	}

	// find the last time
	if(t2.isEarlierThan(t1))
	{
		if(t3.isEarlierThan(t1))
		{
			t1.printNicely();
		}
		else
		{
			t3.printNicely();
		}
	}
	else
	{
		if(t3.isEarlierThan(t2))
		{
			t2.printNicely();
		}
		else
		{
			t3.printNicely();
		}
	}
	
	return 0;
}

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
	return;
}
Time::~Time()
{
	return;
}

bool Time::getIsTwelveHC()
{
	return isTwelveHC;
};

void Time::setIsTwelveHC(bool HC)
{
	isTwelveHC = HC;
	return;
};


bool Time::isEarlierThan(Time t)
{
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

void Time::printNicely()
{
	bool displayFormat = false; // true for 12-hour clock
	bool amOrPm; // true for am
	if(Time::getIsTwelveHC())
	{
		displayFormat = true;
		if(hour > 12)
		{
			hour -= 12;
			amOrPm = false;
		}
		else if(hour == 12)
		{
			amOrPm = false;
		}
		else if(hour == 0)
		{
			hour = 12;
			amOrPm = true;
		}
		else 
		{
			amOrPm = true;
		}
	}
	
	cout << setfill('0') << setw(2) << hour;
	cout << ":";
	cout << setfill('0') << setw(2) << minute;
	cout << ":";
	cout << setfill('0') << setw(2) << second;
	
	if(displayFormat)
	{
		cout << " " ;
		if(amOrPm)
		{
			cout << "AM";
		}
		else
		{
			cout << "PM";
		}
	}
	return;
};


