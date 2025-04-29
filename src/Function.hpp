// Ive kept the same order as Function.py so if you are confused what each function
// is corresponding to, please refer to that.

#pragma once
#include <vector>
#include <string>

class Function 
{
public:
    // Virtual destructor is required in abstract base classes
    virtual ~Function() = default;
protected:
    // C++ requires at least one valid constructor (cannot be abstract)
    // I've made it protected so it cannot be called from an instance of
    // this object, giving us pretty much a pure abstract class
    Function() = default;

public:
    /*
    // pure virtual functions in C++:
    // virtual keyword declares a function that we want to be defined in 
    // any class that extends this one.
    // setting it = to 0 in header file makes it a pure virtual function
    // meaning that it will not be defined in the parent class at all
    */
    virtual void init (const std::vector<std::string>& scope,
                       const std::vector<double>& table,
                       const std::string& name,
                       const std::vector<double>& inputVals) = 0;
    virtual void exp (double val) = 0;
    virtual void log (double sum) = 0;
    virtual void sum (int varLoc) = 0;
    virtual void maximum (const std::vector<std::string>& variables) = 0;
    virtual void minimum (int varLoc) = 0;
    virtual void expand_dims(const std::vector<std::string> sset,
                             const std::vector<std::vector<std::string>>& iters) = 0;
    virtual Function* operator*(const Function& funct) const = 0;
    virtual Function* operator+(const Function& funct) const = 0;
    virtual Function* radd(const Function& funct) = 0;
    virtual Function* operator-(const Function& funct) const = 0;
    virtual Function* operator/(const Function& funct) const = 0;
    virtual Function* rtruediv(const Function& funct) const = 0;

    virtual void print() const = 0;
};
