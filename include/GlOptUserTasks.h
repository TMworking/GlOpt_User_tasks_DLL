#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <memory>

#ifdef _WIN32
#ifdef GLOPT_USER_TASKS_EXPORTS
#define GLOPT_API __declspec(dllexport)
#else
#define GLOPT_API __declspec(dllimport)
#endif
#else
#define GLOPT_API __attribute__((visibility("default")))
#endif

using CoordinatesValues = std::vector<double>;
using GradientsValues = std::vector<double>;
using FunctionsValues = std::vector<double>;

extern "C" {
    GLOPT_API void Init();
    GLOPT_API void FreeResources();
    GLOPT_API void SetUserTaskNumber(int taskNumber);
    GLOPT_API int GetDim();
    GLOPT_API int GetCountCondition();
    GLOPT_API void GetGlobalMin(double* out);
    GLOPT_API double GetSolution();
    GLOPT_API void GetLeftBorder(double* out);
    GLOPT_API void GetRightBorder(double* out);
    GLOPT_API void GetTaskValues(double* res, const double* x);
    GLOPT_API void GetTaskGradients(double* res, const double* x);
}