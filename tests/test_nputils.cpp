#include <gtest/gtest.h>
#include "np_utils.hpp"

TEST(UnravelIndexTests, VariousShapesTests)
{
    // Shape [2,3]
    EXPECT_EQ(unravel_index(0, {2, 3}), std::vector<int>({0, 0}));
    EXPECT_EQ(unravel_index(1, {2, 3}), std::vector<int>({0, 1}));
    EXPECT_EQ(unravel_index(2, {2, 3}), std::vector<int>({0, 2}));
    EXPECT_EQ(unravel_index(3, {2, 3}), std::vector<int>({1, 0}));
    EXPECT_EQ(unravel_index(4, {2, 3}), std::vector<int>({1, 1}));
    EXPECT_EQ(unravel_index(5, {2, 3}), std::vector<int>({1, 2}));

    // Shape [3, 2, 2]
    EXPECT_EQ(unravel_index(0,  {3, 2, 2}), std::vector<int>({0, 0, 0}));
    EXPECT_EQ(unravel_index(1,  {3, 2, 2}), std::vector<int>({0, 0, 1}));
    EXPECT_EQ(unravel_index(2,  {3, 2, 2}), std::vector<int>({0, 1, 0}));
    EXPECT_EQ(unravel_index(3,  {3, 2, 2}), std::vector<int>({0, 1, 1}));
    EXPECT_EQ(unravel_index(4,  {3, 2, 2}), std::vector<int>({1, 0, 0}));
    EXPECT_EQ(unravel_index(5,  {3, 2, 2}), std::vector<int>({1, 0, 1}));
    EXPECT_EQ(unravel_index(6,  {3, 2, 2}), std::vector<int>({1, 1, 0}));
    EXPECT_EQ(unravel_index(7,  {3, 2, 2}), std::vector<int>({1, 1, 1}));
    EXPECT_EQ(unravel_index(8,  {3, 2, 2}), std::vector<int>({2, 0, 0}));
    EXPECT_EQ(unravel_index(9,  {3, 2, 2}), std::vector<int>({2, 0, 1}));
    EXPECT_EQ(unravel_index(10, {3, 2, 2}), std::vector<int>({2, 1, 0}));
    EXPECT_EQ(unravel_index(11, {3, 2, 2}), std::vector<int>({2, 1, 1}));

    // Shape [1]
    EXPECT_EQ(unravel_index(0, {1}), std::vector<int>({0}));

    // Shape [2, 2, 2, 2]
    EXPECT_EQ(unravel_index(0,   {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(1,   {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(2,   {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(3,   {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(4,   {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(5,   {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(6,   {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(7,   {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(8,   {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(9,   {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(10,  {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(11,  {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(12,  {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(13,  {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(14,  {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
    EXPECT_EQ(unravel_index(15,  {2, 2, 2, 2}), std::vector<int>({0, 0, 0, 0}));
}