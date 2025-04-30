#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <iostream>

class Variable 
{
public:
    static int variableCount;
    static std::unordered_map<std::string, Variable*> variablesDict;

    Variable(int domainSize, std::string name = "", std::list<std::string> valueNames = {});
    ~Variable();

    // Static methods
    static int incr();

    // Accessors
    const std::string getName() const;
    const int getId() const;
    const int getDomainSize() const;
    const std::vector<std::string>& getValueNames() const;
    const std::unordered_map<int, std::string>& getDomainDict() const;

    // Required for comparisons (fixes std::sort and vector ==)
    bool operator==(const Variable& other) const 
    {
        return id == other.id;  // Or also check name/domainSize if needed
    }

    bool operator!=(const Variable& other) const 
    {
        return !(*this == other);
    }

    bool operator<(const Variable& other) const 
    {
        return id < other.id;
    }

    // For printing
    friend std::ostream& operator<<(std::ostream& os, const Variable& var);

private:
    int id;
    std::string name;
    int domainSize;
    std::vector<std::string> valueNames;
    std::unordered_map<int, std::string> domainDict;
};
