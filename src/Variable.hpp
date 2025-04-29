#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <list>

class Variable 
{
public:
    Variable(int domainSize, std::string name="", std::list<std::string> valueName={});
    friend std::ostream& operator<<(std::ostream& os, const Variable& v);
    ~Variable();

private:
    static int incr();

private:
    static int variableCount;
    static std::unordered_map<std::string, Variable*> variablesDict;

    int id;
    int domainSize;
    std::string name;
    std::vector<std::string> valueNames;
    std::unordered_map<int, std::string> domainDict;
};
