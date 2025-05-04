#include <Factor.hpp>

#include <stdexcept>

std::map<std::string, Factor*> Factor::factorsDict;
int Factor::factorCount = 0;

Factor::Factor(const std::vector<Variable>& scope, const std::vector<double>& table)
    : id(Factor::factorCount++),
      original_scope(scope),
      original_table(table)
{
    // Sort a local copy of the scope
    std::vector<Variable> sorted_scope = scope;
    std::sort(sorted_scope.begin(), sorted_scope.end(), [](const Variable& a, const Variable& b) 
    {
        return a.getId() < b.getId();
    });

    // Check expected table size
    std::vector<size_t> original_shape;
    for (const auto& var : scope) 
    {
        original_shape.push_back(var.getDomainSize());
    }

    size_t expected_size = 1;
    for (size_t dim : original_shape) 
    {
        expected_size *= dim;
    }

    if (!table.empty() && table.size() != expected_size) 
    {
        throw std::invalid_argument("Table shape and scope domain sizes do not match.");
    }

    // Handle the table
    if (!table.empty()) 
    {
        if (scope != sorted_scope) 
        {
            std::cout << "Warning: Variables in the scope are not sorted by ID. Sorting." << std::endl;
        }
        this->table = table; // Need to add transpose handeling
    } 
    else 
    {
        this->table = std::vector<double>(expected_size, 0.0);
    }

    // Store the sorted scope
    this->scope = sorted_scope;

    // Build varID -> dimension index map
    for (size_t i = 0; i < sorted_scope.size(); ++i) 
    {
        varID_to_dim[sorted_scope[i].getId()] = static_cast<int>(i);
    }
}

std::vector<std::vector<int>> Factor::indices() const 
{
    std::vector<int> shape = this->getShape();

    return std::vector<std::vector<int>>();
}

std::vector<int> Factor::getShape() const
{
    std::vector<int> shape;
    for (const auto& var : this->scope)
    {
        shape.push_back(var.getDomainSize());
    }
    return shape;
}


// void Factor::print() const 
// {
//     for (const auto& val : table)
//     {
//         std::cout << val << ' ';
//     }
//     std::cout << std::endl;
// }

