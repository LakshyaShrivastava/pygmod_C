#include <gtest/gtest.h>
#include "Variable.hpp"
#include "Factor.hpp"

class FactorTest : public ::testing::Test 
{
protected:
    void SetUp() override
    {
        // Called before every test
        Variable::variablesDict.clear();
        Variable::variableCount = 0;
        Factor::factorCount = 0;
    }

    void TearDown() override {
        // Called after each test
    }
};

TEST_F(FactorTest, ConstructorInitializesCorrectly)
{
    Variable A(2, "A", {"0", "1"});
    Variable B(3, "B", {"x", "y", "z"});

    std::vector<Variable> scope = {B, A};
    std::vector<double> table = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};

    Factor f(scope, table);

    EXPECT_EQ(f.id, 0);
    EXPECT_EQ(f.scope[0].getName(), "A");
    EXPECT_EQ(f.scope[1].getName(), "B");

    EXPECT_EQ(f.table.size(), 6);

    for (size_t i = 0; i < table.size(); ++i) 
    {
        EXPECT_DOUBLE_EQ(f.table[i], table[i]);
    }

    EXPECT_EQ(f.varID_to_dim.at(A.getId()), 0);
    EXPECT_EQ(f.varID_to_dim.at(B.getId()), 1);
}

TEST_F(FactorTest, GetShapeReturnsCorrectDomainSizes)
{
    Variable A(2, "A");
    Variable B(4, "B");
    std::vector<Variable> scope = {A, B};
    Factor f(scope);  // no table provided

    // Act
    std::vector<int> shape = f.getShape();

    // Assert
    std::vector<int> expected = {2, 4};
    EXPECT_EQ(shape, expected);
}

TEST_F(FactorTest, IndicesSingleVariable) 
{
    Variable A(2, "A", {"0", "1"});
    Factor f({A});  // No table provided = zero-filled

    auto idx = f.indices();

    std::vector<std::vector<int>> expected = {
        {0},
        {1}
    };

    EXPECT_EQ(idx, expected);
}

TEST_F(FactorTest, IndicesTwoVariables) 
{
    Variable A(2, "A");
    Variable B(3, "B");

    Factor f({A, B});

    auto idx = f.indices();

    std::vector<std::vector<int>> expected = {
        {0, 0}, {0, 1}, {0, 2},
        {1, 0}, {1, 1}, {1, 2}
    };

    EXPECT_EQ(idx, expected);
}

TEST_F(FactorTest, IndicesThreeVariables) 
{
    Variable A(2, "A");
    Variable B(2, "B");
    Variable C(2, "C");

    Factor f({A, B, C});

    auto idx = f.indices();

    std::vector<std::vector<int>> expected = {
        {0, 0, 0}, {0, 0, 1},
        {0, 1, 0}, {0, 1, 1},
        {1, 0, 0}, {1, 0, 1},
        {1, 1, 0}, {1, 1, 1}
    };

    EXPECT_EQ(idx, expected);
}

TEST_F(FactorTest, IndicesEmptyScope) 
{
    Factor f({});  // no variables

    auto idx = f.indices();
    EXPECT_EQ(idx.size(), 1);  // only one "index": the empty one
    EXPECT_EQ(idx[0], std::vector<int>{});
}


