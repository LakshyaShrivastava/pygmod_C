#pragma once

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>
#include <iomanip>
#include <cmath>            // For std::log, std::pow
#include <algorithm>        // for std::sort

// note in c++ if we include with "" compiler looks within our directory
// whereas if we use <> it checks within the included libraries. 
#include "Function.hpp"
#include "Variable.hpp"

class Factor //: Function 
{
public:
    static std::map<std::string, Factor*> factorsDict;
    static int factorCount;

    int id;
    std::vector<Variable> scope;
    std::vector<Variable> original_scope;
    std::vector<double> table;
    std::vector<double> original_table;
    std::map<int, int> varID_to_dim;

public:
    Factor(const std::vector<Variable>& scope, const std::vector<double>& table = {});
    
    std::vector<std::vector<int>> indices() const;
    void fill_table(double multiplying_factor);

    static std::vector<std::vector<int>> expand_dims(const std::vector<Variable>& sset,
                                                     const std::vector<std::vector<Variable>>& iters);
    /*
    std::unique_ptr<Function> log(double base = std::exp(1.0)) override;
    std::unique_ptr<Function> maximum(const std::vector<Variable>& variables) override;
    std::unique_ptr<Function> minimum(const std::vector<Variable>& variables) override;
    std::unique_ptr<Function> sum(const std::vector<Variable>& variables) override;
    void print() const override;
    
    std::unique_ptr<Function> operator*(const Function& funct) const override;
    std::unique_ptr<Function> operator+(const Function& funct) const override;
    std::unique_ptr<Function> radd(const Function& funct) const override;
    std::unique_ptr<Function> operator-(const Function& funct) const override;
    std::unique_ptr<Function> rsub(const Function& funct) const override;
    std::unique_ptr<Function> operator-() const override;
    std::unique_ptr<Function> operator/(const Function& funct) const override;
    std::unique_ptr<Function> rtruediv(const Function& funct) const override;
    */

    // Helpers
    std::vector<int> getShape() const;
};