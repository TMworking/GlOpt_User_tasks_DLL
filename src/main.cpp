#include <iostream>
#include "GlOptUserTasks.h" 

int main() {
    Init();

    SetUserTaskNumber(1);

    int dim = GetDim();
    int conditions = GetCountCondition();
    double solution = GetSolution();

    std::cout << "Task 1: " << std::endl;
    std::cout << "Dimension: " << dim << std::endl;
    std::cout << "Conditions: " << conditions << std::endl;
    std::cout << "Solution value: " << solution << std::endl;

    double x[] = { 0.94248, 0.94526 };
    double values[4];
    double gradients[8];

    GetTaskValues(values, x);
    GetTaskGradients(gradients, x);

    std::cout << "\nFunction values:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "res[" << i << "] = " << values[i] << std::endl;
    }

    std::cout << "\nGradients:" << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cout << "grad[" << i << "] = " << gradients[i] << std::endl;
    }

    FreeResources();
    return 0;
}