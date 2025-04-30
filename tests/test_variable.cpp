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
    ASSERT_TRUE(Variable::variablesDict.find("X") != Variable::variablesDict.end());
    EXPECT_EQ(Variable::variablesDict["X"], &var);
}

TEST(VariableTest, NameDefaultsToId) 
{
    Variable v(2);  // no name
    EXPECT_EQ(v.getName(), std::to_string(v.getId()));
}

TEST(VariableTest, ThrowsOnDuplicateName) 
{
    Variable v1(2, "X");

    EXPECT_THROW({
        Variable v2(2, "X");
    }, std::invalid_argument);
}