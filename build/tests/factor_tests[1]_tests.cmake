add_test([=[FactorSanityTest.AlwaysPasses]=]  [==[C:/Users/LakshCPlusPLus/OneDrive - UC Irvine/Desktop/AI_Research/pygmod_C/build/bin/Debug/factor_tests.exe]==] [==[--gtest_filter=FactorSanityTest.AlwaysPasses]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[FactorSanityTest.AlwaysPasses]=]  PROPERTIES WORKING_DIRECTORY [==[C:/Users/LakshCPlusPLus/OneDrive - UC Irvine/Desktop/AI_Research/pygmod_C/build/tests]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  factor_tests_TESTS FactorSanityTest.AlwaysPasses)
