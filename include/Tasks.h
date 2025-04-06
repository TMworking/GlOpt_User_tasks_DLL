#include "GlOptUserTasks.h"

class Task {
private:
    int dim;
    int condCount;
    double* minPoint;
    double minValue;
    double* leftBorder;
    double* rightBorder;

    std::function<void (double*, const double*)> taskFunc;
    std::function<void (double*, const double*)> taskGrad;

public:
    Task(int _dim, int _condCount,
        double* _minPoint,
        double _minValue,
        double* _leftBorder,
        double* _rightBorder,
        std::function<void (double*, const double*)> _taskFunc,
        std::function<void (double*, const double*)> _taskGrad)
        :dim(_dim), condCount(_condCount),
        minPoint(_minPoint), minValue(_minValue),
        leftBorder(_leftBorder), rightBorder(_rightBorder),
        taskFunc(_taskFunc), taskGrad(_taskGrad)
    {};

    int getDimension() const { return dim; }
    int getConditionsCount() const { return condCount; }
    double* getMinPoint() const { return minPoint; }
    double getSolutionValue() const { return minValue; }
    double* getLeftBorder() const { return leftBorder; }
    double* getRightBorder() const { return rightBorder; }

    void getTaskValue(double* res, const double* x) const { return taskFunc(res, x); };
    void getTaskGradient(double* grad, const double* x) const { return taskGrad(grad, x); };
};

Task createTask1();
Task createTask2();
Task createTask3();
Task createTask4();
Task createTask5();