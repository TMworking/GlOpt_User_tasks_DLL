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

void GetGlobalMin(double* out) {
	const double* src = tasks[currentTask - 1].getMinPoint();
	int dim = GetDim();
	for (int i = 0; i < dim; ++i)
		out[i] = src[i];
}

double GetSolution() {
	return tasks[currentTask - 1].getSolutionValue();
}

void GetLeftBorder(double* out) {
	const double* src = tasks[currentTask - 1].getLeftBorder();
	int dim = GetDim();
	for (int i = 0; i < dim; ++i)
		out[i] = src[i];
}

void GetRightBorder(double* out) {
	const double* src = tasks[currentTask - 1].getRightBorder();
	int dim = GetDim();
	for (int i = 0; i < dim; ++i)
		out[i] = src[i];
}

void GetTaskValues(double* res, const double* x) {
	tasks[currentTask - 1].getTaskValue(res, x);
}

void GetTaskGradients(double* res, const double* x) {
	tasks[currentTask - 1].getTaskGradient(res, x);
}