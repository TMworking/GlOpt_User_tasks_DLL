#include "Tasks.h"

std::vector<Task> tasks;
int currentTask = 1;

void Init() {
	tasks.clear();
	tasks.push_back(createTask1());
	tasks.push_back(createTask2());
	tasks.push_back(createTask3());
	tasks.push_back(createTask4());
	tasks.push_back(createTask5());
}

void FreeResources() {
	tasks.clear();
	currentTask = 1;
}

void SetUserTaskNumber(int taskNumber) {
	currentTask = taskNumber;
}

int GetDim() {
	return tasks[currentTask - 1].getDimension();
}

int GetCountCondition() {
	return tasks[currentTask - 1].getConditionsCount();
}

double* GetGlobalMin() {
	return tasks[currentTask - 1].getMinPoint();
}

double GetSolution() {
	return tasks[currentTask - 1].getSolutionValue();
}

double* GetLeftBorder() {
	return tasks[currentTask - 1].getLeftBorder();
}

double* GetRightBorder() {
	return tasks[currentTask - 1].getRightBorder();
}

void GetTaskValues(double* res, const double* x) {
	tasks[currentTask - 1].getTaskValue(res, x);
}

void GetTaskGradients(double* res, const double* x) {
	tasks[currentTask - 1].getTaskGradient(res, x);
}