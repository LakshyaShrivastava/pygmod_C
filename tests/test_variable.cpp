#include <gtest/gtest.h>
#include "Variable.hpp"

TEST(VariableTest, NameDefaultsToId) {
    Variable v(2);  // no name
    EXPECT_EQ(v.getName(), std::to_string(v.getId()));
}

TEST(VariableTest, ThrowsOnDuplicateName) {
    Variable v1(2, "X");

    EXPECT_THROW({
        Variable v2(2, "X");
    }, std::invalid_argument);
}