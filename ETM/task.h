#pragma once
#include <string>
#include <string.h>
#include <queue>
#include <list>

using namespace std;
class task
{

public:
	string title, discription, employeeName;
	int priority;
	int count;
	int assignDate[3], requiredEndingDate[3];
	string state;
	task();
	void addTask();
	void display();
	//void postpone();
	void rememberTask();
	void update();
	//void completeTaskes();
	void deleteTask();
	void edittask();

	//void copyQueue(priority_queue<list<task>> tmp_q);

	bool operator < (const task& taskobj) const
	{
		return priority > taskobj.priority;
	}
	~task();
};
