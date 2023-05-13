/* Problem 11_7b: Event array
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
	Time();	
	Time(int h, int m, int s);
	~Time();
	
	static bool getIsTwelveHC();
	static void setIsTwelveHC(bool HC);//HC = true for 12-hour clock
	
	bool isEarlierThan(Time t);
	void printNicely();
};

class Event
{
private:
	char* name;
	Time start;
	Time end;
public:
	Event();
	Event(char* n, Time s, Time t);
	~Event();
	
	void printNicely();
	void setName(char* n);
};

bool Time::isTwelveHC = false;

int main()
{
	char n1[] = "PD";
	Event e1(n1, Time(14, 20, 0),	Time(17, 20, 0));
	Event* schedule = new Event[10];
	schedule[0] = e1;
	schedule[0].printNicely();
	
	delete [] schedule;
	return 0;
}

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
	return;
};


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

Event::Event()
{
	name = nullptr;
	return;
};

Event::Event(char* n, Time s, Time t)
{
	name = n;
	start = s;
	end = t;
	return;
};

Event::~Event()
{
	delete name;
	return;
};

void Event::printNicely()
{
	cout << "\"" << name << "\"" << endl;
	cout << left << setfill(' ') << setw(7) << "Start:";
	start.printNicely();
	cout << endl << left << setfill(' ') << setw(7) << "End:";
	end.printNicely();
	cout << endl;
}

void Event::setName(char* n)
{
	name = n;
};
