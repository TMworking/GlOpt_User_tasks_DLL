#include "Tasks.h"

const double _PI = 3.14159265358979323846;

void task1(double* res, const double* x) {
	// -1.5 * x^2 * exp(1 - x^2 - 20.25 * (x - y)^2) - (0.5 * (x - 1) * (y - 1))^4 * exp(2 - (0.5 * (x - 1))^4 * (y - 1)^4)
	res[0] = -1.5 * x[0] * x[0] * exp(1 - x[0] * x[0] - 20.25 * (x[0] - x[1]) * (x[0] - x[1])) - (0.5 * (x[0] - 1) * (x[1] - 1)) * (0.5 * (x[0] - 1) * (x[1] - 1)) * (0.5 * (x[0] - 1) * (x[1] - 1)) * (0.5 * (x[0] - 1) * (x[1] - 1)) * exp(2 - (0.5 * (x[0] - 1)) * (0.5 * (x[0] - 1)) * (0.5 * (x[0] - 1)) * (0.5 * (x[0] - 1)) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1));
	// 0.001 * ((x - 2.2)^2 + (y - 1.2)^2 - 2.25)
	res[1] = 0.001 * ((x[0] - 2.2) * (x[0] - 2.2) + (x[1] - 1.2) * (x[1] - 1.2) - 2.25);
	// 100 * (1 - ((x - 2) / 1.2 )^2 - (0.5 * y) ^ 2)
	res[2] = 100 * (1 - ((x[0] - 2.0) / 1.2) * ((x[0] - 2.0) / 1.2) - 0.25 * x[1] * x[1]);
	// 10 * (y - 1.5 - 1.5 * sin(2 * pi * (x - 1.75)))
	res[3] = 10 * (x[1] - 1.5 - 1.5 * sin(2 * _PI * (x[0] - 1.75)));
}

void gradient_task1(double* grad, const double* x) {
	// 0.015625 * (x - 1)^3 * (y - 1)^4 * exp⁡(2 - 0.0625 * (x - 1)^4 - (y - 1)^4) * ((x - 1)^4 - 16) + (63.75 * x^3 - 60.75 * x^2 * y - 3x) * exp⁡(1 - x^2 - 20.25 * (x - y)^2)
	grad[0] = -3 * x[0] * exp(-(x[0] * x[0]) - 20.25 * (x[0] - x[1]) * (x[0] * x[1]) + 1) - 1.5 * x[0] * x[0] * exp(-(x[0] * x[0]) - 20.25 * (x[0] - x[1]) * (x[0] - x[1]) + 1) * (-40.5 * (x[0] - x[1]) - 2 * x[0]) + 0.015625 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * exp(-0.0625 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) - (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) + 2) - 0.25 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * exp(-0.0625 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) - (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) + 2);
	//grad[0] = 0.015625 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * exp(2 - 0.0625 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) - (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1)) * ((x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) - 16) + (63.75 * x[0] * x[0] * x[0] - 60.75 * x[0] * x[0] * x[1] - 3 * x[0]) * exp(1 - x[0] * x[0] - 20.25 * (x[0] - x[1]) * (x[0] - x[1]));
	// 0.25 * (x - 1)^4 * (y - 1)^3 * exp⁡(2 - 0.0625 * (x - 1)^4 - (y - 1)^4) * ((y - 1)^4 - 1) - (-60.75 * x^3 + 60.75 * x^2 * y) * exp⁡(1 - x^2 - 20.25 * (x - y)^2)
	//grad[1] = 0.25 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * exp(2 - 0.0625 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) - (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1)) * ((x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) - 1) - (-60.75 * x[0] * x[0] * x[0] + 60.75 * x[0] * x[0] * x[1]) * exp(1 - x[0] * x[0] - 20.25 * (x[0] - x[1]) * (x[0] - x[1]));
	grad[1] = -60.75 * x[0] * x[0] * exp(-(x[0] * x[0]) - 20.25 * (x[0] - x[1]) * (x[0] - x[1]) + 1) * (x[0] - x[1]) + 0.25 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * exp(-0.0625 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) - (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) + 2) - 0.25 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * exp(-0.0625 * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) * (x[0] - 1) - (x[1] - 1) * (x[1] - 1) * (x[1] - 1) * (x[1] - 1) + 2);
	// 0.002 * (x - 2.2)
	grad[2] = 0.002 * (x[0] - 2.2);
	// 0.002 * (y - 1.2)
	grad[3] = 0.002 * (x[1] - 1.2);
	// (1250 / 9) * (2 - x)
	grad[4] = -(1250 / 9) * (x[0] - 2);
	// -50 * y
	grad[5] = -50 * x[1];
	// -30 * pi * cos((4 * pi * x - 7 * pi) / 2)
	grad[6] = -30 * _PI * sin(4 * _PI - 2 * _PI * x[0]);
	// 10
	grad[7] = 10;
}

Task createTask1() {
	static double minPoint[2] = { 0.94248, 0.94526 };
	static double leftBorder[2] = { 0.0, -1.0 };
	static double rightBorder[2] = { 4.0, 3.0 };

	return Task(
		2, // dimension
		3, // conditions
		minPoint, // minimum point
		-1.48968, // global minimum
		leftBorder, // left border
		rightBorder, // right border
		&task1,
		&gradient_task1
	);
}

void task2(double* res, const double* x) {
	// (4 - 2.1 * x^2 + x^4 / 3) * x^2 + x * y + (4 * y^2 - 4) * y^2
	res[0] = (4 - 2.1 * x[0] * x[0] + x[0] * x[0] * x[0] * x[0] / 3) * x[0] * x[0] + x[0] * x[1] + (4 * x[1] * x[1] - 4) * x[1] * x[1];
	// -(1.5 * x - y - 0.2)^2 - (2 * sin(2 * y) + 0.2)^2 + 7
	res[1] = -(1.5 * x[0] - x[1] - 0.2) * (1.5 * x[0] - x[1] - 0.2) - (2 * sin(2 * x[1]) + 0.2) * (2 * sin(2 * x[1]) + 0.2) + 7;
	// -14 + |x + 0.1|^3 + 2 * |y - 0.2|^3
	res[2] = -14 + abs(x[0] + 0.1) * abs(x[0] + 0.1) * abs(x[0] + 0.1) + 2 * abs(x[1] - 0.2) * abs(x[1] - 0.2) * abs(x[1] - 0.2);
}

void gradient_task2(double* grad, const double* x) {
	// 2 * x^5 - 8.4 * x^3 + 8 * x + y
	grad[0] = 2 * x[0] * x[0] * x[0] * x[0] * x[0] - 8.4 * x[0] * x[0] * x[0] + 8 * x[0] + x[1];
	// x + 16 * y^3 - 8 * y
	grad[1] = x[0] + 16 * x[1] * x[1] * x[1] - 8 * x[1];
	// -4.5 * x + 3 * y + 0.6
	grad[2] = -4.5 * x[0] + 3 * x[1] + 0.6;
	// 3 * x - 2 * y - 16 * (sin(2 * y) + 0.1) * cos(2 * y) - 0.4
	grad[3] = 3 * x[0] - 2 * x[1] - 16 * (sin(2 * x[1]) + 0.1) * cos(2 * x[1]) - 0.4;
	// 3 * (x + 0.1) * |x + 0.1|
	grad[4] = 3 * (x[0] + 0.1) * abs(x[0] + 0.1);
	// 6 * (y - 0.2) * |y - 0.2|
	grad[5] = 6 * (x[1] - 0.2) * abs(x[1] - 0.2);
}

Task createTask2() {
	static double minPoint[2] = { -0.32520, 0.78197 };
	static double leftBorder[2] = { -2.5, -1.5 };
	static double rightBorder[2] = { 2.5, 1.5 };

	return Task(
		2, // dimension
		2, // conditions
		minPoint, // minimum point
		-0.80467, // global minimum
		leftBorder, // left border
		rightBorder, // right border
		&task2,
		&gradient_task2
	);
}

void task3(double* res, const double* x) {
	// 0.01 * (x * y + (x - pi)^2 + 3 * (y - pi)^2) - (sin(x) * sin(2 * y))^2
	res[0] = 0.01 * (x[0] * x[1] + (x[0] - _PI) * (x[0] - _PI) + 3 * (x[1] - _PI) * (x[1] - _PI)) - (sin(x[0]) * sin(2 * x[1])) * (sin(x[0]) * sin(2 * x[1]));
	// -(x - pi + 0.1)^2 - (2 * sin(y) + 0.2)^2 + 6
	res[1] = 6 - (x[0] - _PI + 0.1) * (x[0] - _PI + 0.1) - (2 * sin(x[1]) + 0.2) * (2 * sin(x[1]) + 0.2);
}

void gradient_task3(double* grad, const double* x) {
	// -2 * sin(x) * cos(x) * sin^2(2 * y) + 0.02 * x + 0.01 * y - pi / 50
	grad[0] = -2 * sin(x[0]) * cos(x[0]) * sin(2 * x[1]) * sin(2 * x[1]) + 0.02 * x[0] + 0.01 * x[1] - _PI / 50;
	// -4 * sin^2(x) * sin(2 * y) * cos(2 * y) + 0.01 * x + 0.06 * y - 3 * pi / 50
	grad[1] = -4 * sin(x[0]) * sin(x[0]) * sin(2 * x[1]) * cos(2 * x[1]) + 0.01 * x[0] + 0.06 * x[1] - 3 * _PI / 50;
	// -2 * x + 2 * pi - 0.2
	grad[2] = -2 * x[0] + 2 * _PI - 0.2;
	// -8 * cos(y) * (sin(y) + 0.1)
	grad[3] = -8 * cos(x[1]) * (sin(x[1]) + 0.1);
}

Task createTask3() {
	static double minPoint[2] = { 1.30499, 2.27249 };
	static double leftBorder[2] = { 0, 0 };
	static double rightBorder[2] = { 2 * _PI, 2 * _PI };

	return Task(
		2, // dimension
		1, // conditions
		minPoint, // minimum point
		-0.81911, // global minimum
		leftBorder, // left border
		rightBorder, // right border
		&task3,
		&gradient_task3
	);
}

void task4(double* res, const double* x) {
	// sum[i = 1; N](x[i]^2 - cos(18 * x[i]^2))
	res[0] = 0.0;
	for (int i = 0; i < sizeof(x); ++i) {
		res[0] += x[i] * x[i] - cos(18 * x[i] * x[i]);
	}
	// sum[i = 2; N](|x[i]|) + 0.1 - x[1]
	res[1] = 0.1 - x[0];
	for (int i = 1; i < sizeof(x); ++i) {
		res[1] += abs(x[i]);
	}
}

void gradient_task4(double* grad, const double* x) {
	// 2 * x * (1 + 18 * sin(18 * x^2))
	for (int i = 0; i < sizeof(x); ++i)
		grad[i] = 2 * x[i] * (1 + 18 * sin(18 * x[i] * x[i]));
	// x / |x| - 1
	grad[sizeof(x)] = -1;
	for (int i = 1; i < sizeof(x); ++i) {
		grad[sizeof(x) + i] = x[i] / abs(x[i]);
	}
	//for (uint i = 0; i < x.size(); ++i)
	//	grad[x.size() + i] = x[i] / abs(x[i]) - 1; // ПРОВЕРИТЬ НА -1
}

Task createTask4() {
	static double minPoint[3] = { 0.1, 0.0, 0.0 };
	static double leftBorder[3] = { -1.0, -1.0, -1.0 };
	static double rightBorder[3] = { 1.0, 1.0, 1.0 };

	return Task(
		3, // dimension
		1, // conditions
		minPoint, // minimum point
		-2.97384, // global minimum
		leftBorder, // left border
		rightBorder, // right border
		&task4,
		&gradient_task4
	);
}

void task5(double* res, const double* x) {
	// (pi / N) * (10 * sin^2(pi * y1) + sum[i = 1; N - 1]((yi - 1)^2 * (1 + 10 * sin^2(pi * yi+1))) + (yN - 1)^2), yi = 1 + (1 / 4) * (xi - 1), i = 1,...,N
	/*double prev = 0;
	double next = 0;

	next = 1 + 0.25 * (x[0] - 1);
	res[0] = 10 * sin(_PI * next) * sin(_PI * next);
	for (uint i = 0; i < x.size() - 2; ++i) {
		prev = next;
		next = 1 + 0.25 * (x[i + 1] - 1);
		res[0] = res[0] + (prev - 1) * (prev - 1) * (1 + 10 * sin(_PI * next) * sin(_PI * next));
	}
	res[0] = res[0] + (next - 1) * (next - 1);
	res[0] = res[0] * _PI / x.size();*/
	res[0] = 10 * sin(_PI * (1 + 0.25 * (x[0] - 1))) * sin(_PI * (1 + 0.25 * (x[0] - 1)));
	for (int i = 1; i < sizeof(x) - 1; ++i)
		res[0] += ((1 + 0.25 * (x[i - 1])) - 1) * ((1 + 0.25 * (x[i - 1])) - 1) * (1 + 10 * sin(_PI * (1 + 0.25 * (x[i] - 1))) * sin(_PI * (1 + 0.25 * (x[i] - 1))));
	res[0] += (x[sizeof(x) - 1] - 1) * (x[sizeof(x) - 1] - 1);

	// (2 / 5) - 10 * (x1 - 1.1)^2 + sum[i = 2; N](i * (xi - 1)^2)
	res[1] = 0.4 - 10 * (x[0] - 1.1) * (x[0] - 1.1);
	for (int i = 1; i < sizeof(x); ++i)
		res[1] = res[1] + (i + 1.0) * (x[i] - 1) * (x[i] - 1);
}

void gradient_task5(double* grad, const double* x) {
	// (pi / (8 * N)) * (40 * pi * sin((pi / 4) * (x + 3)) * cos((pi/4) * (x+3)) + (x - 1) * (10 * sin^2((pi / 4) * (y + 3)) + 1))
	//grad[0] = (_PI / (8 * x.size())) * (40 * _PI * sin((_PI / 4) * (x[0] + 3)) * cos((_PI / 4) * (x[0] + 3)) + (x[0] - 1) * (10 * sin((_PI / 4) * (x[1] + 3)) * sin((_PI / 4) * (x[1] + 3)) + 1));
	grad[0] = (_PI * ((x[0] - 1) * (10 * sin(0.25 * _PI * (x[1] + 3)) * sin(0.25 * _PI * (x[1] + 3)) + 1) + 40 * _PI * sin(0.25 * _PI * (x[0] + 3)) * cos(0.25 * _PI * (x[0] + 3)))) / (8 * sizeof(x));

	// (pi / (16 * N)) * (5 * pi * (x - 1)^2 * sin((pi / 4) * (y + 3)) * cos((pi / 4) * (y + 3)) + 2 * (y - 1) * (10 * sin^2((pi / 4) * (z + 3)) + 1))
	//for (uint i = 0; i < x.size() - 2; ++i)
		//grad[i + 1] = (_PI / (16 * x.size())) * (5 * _PI * (x[i] - 1) * (x[i] - 1) * sin((_PI / 4) * (x[i + 1] + 3)) * cos((_PI / 4) * (x[i + 1] + 3)) + 2 * (x[i + 1] - 1) * (10 * sin((_PI / 4) * (x[i + 2] + 3)) * sin((_PI / 4) * (x[i + 2] + 3)) + 1));
	for (int i = 1; i < sizeof(x) - 1; ++i)
		grad[i] = (_PI * (5 * _PI * (x[i - 1] - 1) * (x[i - 1] - 1) * sin(0.25 * _PI * (x[i] + 3)) + 2 * (x[1] - 1) * (10 * sin(0.25 * _PI * (x[i + 1] + 3)) * sin(0.25 * _PI * (x[i + 1] + 3)) + 1))) / (16 * sizeof(x));

	// (pi / N) * (((5 * pi) / 16) * (y - 1)^2 * sin((pi / 4) * (z + 3)) * cos((pi / 4) * (z + 3)) + 2 * (z - 1))
	//grad[x.size() - 1] = (_PI / x.size()) * (((5 * _PI) / 16) * (x[x.size() - 2] - 1) * (x[x.size() - 2] - 1) * sin((_PI / 4) * (x[x.size() - 1] + 3)) * cos((_PI / 4) * (x[x.size() - 1] + 3)) + 2 * (x[x.size() - 1] - 1));
	grad[sizeof(x) - 1] = (_PI * (5 * _PI * (x[sizeof(x) - 2] - 1) * (x[sizeof(x) - 2] - 1) * sin(0.25 * _PI * (x[sizeof(x) - 1] + 3)) * cos(0.25 * _PI * (x[sizeof(x) - 1] + 3)) + 2 * (x[sizeof(x) - 1] - 1))) / (16 * sizeof(x));

	// -20 * (x - 1.1)
	grad[sizeof(x)] = 22 - 20 * x[0];

	// 2 * i * (y - 1)
	for (int i = 1; i < sizeof(x); ++i)
		grad[sizeof(x) + i] = 2 * (i + 1) * (x[i] - 1);
}

Task createTask5() {
	static double minPoint[2] = { 0.9, 1.0 };
	static double leftBorder[2] = { -10, -10 };
	static double rightBorder[2] = { 10, 10 };

	return Task(
		2, // dimension
		1, // conditions
		minPoint, // minimum point
		0.09768, // global minimum
		leftBorder, // left border
		rightBorder, // right border
		&task5,
		&gradient_task5
	);
}