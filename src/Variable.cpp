#include "Variable.hpp"
#include <stdexcept>


// defining static vars
int Variable::variableCount = 0;
std::unordered_map<std::string, Variable*> Variable::variablesDict;

Variable::Variable(int domainSize, std::string name, std::list<std::string> valueNames)
    : id(incr()), domainSize(domainSize)
{
    // If name was not provided, use ID as the name
    if (name.empty()) 
    {
        this->name = std::to_string(this->id);
    } 
    else 
    {
        this->name = name;
    }

    // Handle valueNames if provided
    if (!valueNames.empty()) 
    {
        if (valueNames.size() != static_cast<size_t>(this->domainSize)) 
        {
            throw std::invalid_argument("valueNames and domainSize not matching");
        }

        // Copy list into vector and build domainDict
        int i = 0;
        for (const std::string& val : valueNames) 
        {
            this->valueNames.push_back(val);
            this->domainDict[i++] = val;
        }
    } 
    else 
    {
        // Generate default valueNames and domainDict
        for (int i = 0; i < this->domainSize; ++i) 
        {
            std::string val = std::to_string(i);
            this->valueNames.push_back(val);
            this->domainDict[i] = val;
        }
    }

    // Check for duplicate variable name
    if (variablesDict.find(this->name) != variablesDict.end()) 
    {
        throw std::invalid_argument("Two Variables with same name.");
    }

    // Register this variable
    variablesDict[this->name] = this;
}

Variable::~Variable() 
{
    auto it = variablesDict.find(this->name);
    if (it != variablesDict.end()) {
        variablesDict.erase(it);
    }
}

std::ostream& operator<<(std::ostream& os, const Variable& var) 
{
    os << "Variable Name: " << var.name
       << ", ID: " << var.id
       << ", Domain Size: " << var.domainSize
       << ", Value Names: [";
    for (size_t i = 0; i < var.valueNames.size(); ++i) {
        os << var.valueNames[i];
        if (i != var.valueNames.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

int Variable::incr() {
    return ++variableCount;
}

const int Variable::getId() const
{
    return this->id;
}

const int Variable::getDomainSize() const
{
    return this->domainSize;
}

const std::string Variable::getName() const
{
    return this->name;
}