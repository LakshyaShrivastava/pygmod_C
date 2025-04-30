#include <gtest/gtest.h>
#include <string>
#include <list>
#include "Variable.hpp"


TEST(VariableTest, InitializationWithAllArgs) 
{
    std::list<std::string> names = {"Red", "Green", "Blue"};
    std::unordered_map<int, std::string> expected = {
        {0, "Red"}, {1, "Green"}, {2, "Blue"}
    };

    Variable var(3, "X", names);

    EXPECT_EQ(var.getName(), "X");
    EXPECT_EQ(var.getValueNames(), std::vector<std::string>({"Red", "Green", "Blue"}));
    EXPECT_EQ(var.getDomainDict(), expected);
    EXPECT_EQ(var.getId(), 1);
    EXPECT_EQ(var.getDomainSize(), 3);
    ASSERT_TRUE(Variable::variablesDict.find("X") != Variable::variablesDict.end());
    EXPECT_EQ(Variable::variablesDict["X"], &var);
}

TEST(VariableTest, InitializationWithDomainSizeOnly) 
{
    Variable v(2);
    std::list<std::string> expected_names = {"1", "2"};
    std::unordered_map<int, std::string> expected_domainDict = {{0, "1"}, {1, "2"}};

    EXPECT_EQ(v.getName(), std::to_string(v.getId()));
    EXPECT_EQ(v.getDomainSize(), 2);
    // EXPECT_EQ(v.getValueNames(), expected_names);
    // EXPECT_EQ(v.getDomainDict(), expected_domainDict);
    // Need to fix these errors. Something wrong with 
    // not being able to make those comparisons with ==
}

TEST(VariableTest, ThrowsOnDuplicateName) 
{
    Variable v1(2, "X");

    EXPECT_THROW({
        Variable v2(2, "X");
    }, std::invalid_argument);
}

TEST(VariableTest, ThrowsOnMismatchedValueNames)
{   
    std::list<std::string> expected_names = {"A", "B", "C"};
    EXPECT_THROW({
        Variable v(2, "X", expected_names);
    }, std::invalid_argument);
}
