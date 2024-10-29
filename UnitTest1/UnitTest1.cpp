#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1(it).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyTestNamespace
{
    TEST_CLASS(StringFunctionsTests)
    {
    public:

        TEST_METHOD(TestChange)
        {
            char str1[101] = "nno";
            Change(str1);
            Assert::AreEqual(str1, "**"); // Change nno to **

            char str2[101] = "n1o";
            Change(str2);
            Assert::AreEqual(str2, "**"); // Change n1o to **

            char str3[101] = "hello";
            Change(str3);
            Assert::AreEqual(str3, "hello"); // No change

            char str4[101] = "nno nno";
            Change(str4);
            Assert::AreEqual(str4, "** **"); // Change both nno's to **

            char str5[101] = "nnoo";
            Change(str5);
            Assert::AreEqual(str5, "**o"); // Change nno to **

        }
    };
}
