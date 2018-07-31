#include <iostream>
#include <map>
#include <utility>

class FunctionResult
{
public:
    class Parameters {
    public:
        int first;
        int second;
        Parameters(int f, int s) : first(f), second(s) {};
        bool operator< (const Parameters& other) const
        {
            return (first < other.first) || (first == other.first && second < other.second);
        }

    };
    //struct ParamComparator
    //{
    //    bool operator()(const Parameters& left, const Parameters& right) const
    //    {
    //        return (left.first == left.first && left.second == right.second);
    //    }
    //};

    FunctionResult(int(*func)(int, int))
    {
        this->func = func;
    }

    int calculate(int first, int second)
    {
        Parameters args(first, second);
        std::map<Parameters, int>::iterator it = calculations.find(args);
        if (it != calculations.end())
            return it->second;

        int calculation = func(first, second);
        calculations[args] = calculation;
        return calculation;
    }

private:
    std::map<Parameters, int> calculations;
    int(*func)(int, int);
};

#ifndef RunTests
int modulo(int a, int b)
{
    std::cout << "Function modulo has been called.\n";
    return a % b;
}

int main()
{
    FunctionResult functionResult(modulo);

    // Function modulo should be called.
    std::cout << functionResult.calculate(5, 2) << '\n';

    // Function modulo should be called.
    std::cout << functionResult.calculate(7, 4) << '\n';

    // Function modulo shouldn't be called because we have already made a call with arguments (5, 2)!
    // Instead, result should be pulled from the cache!
    std::cout << functionResult.calculate(5, 2) << '\n';
}
#endif
