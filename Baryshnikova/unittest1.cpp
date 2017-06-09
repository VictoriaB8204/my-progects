#include "stdafx.h"
#include "CppUnitTest.h"
#include "Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBase64
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod0)
		{
			// [ENCODE] input any string
			string input = encode("Hello, World!");
			string output = "SGVsbG8sIFdvcmxkIQ==";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod1)
		{
			// [DECODE] input any string
			string input = decode("SGVsbG8sIFdvcmxkIQ==");
			string output = "Hello, World!";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod2)
		{
			// [ENCODE] input 1 symbol
			string input = encode("1");
			string output = "MQ==";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod3)
		{
			// [ENCODE] input 2 symbols
			string input = encode("12");
			string output = "MTI=";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod4)
		{
			// [ENCODE] input 3 symbols
			string input = encode("123");
			string output = "MTIz";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod5)
		{
			// [ENCODE] input 4 symbols
			string input = encode("1234");
			string output = "MTIzNA==";
			Assert::AreEqual(input, output);
		}
		TEST_METHOD(TestMethod6)
		{
			// [ENCODE] input 5 symbols
			string input = encode("12345");
			string output = "MTIzNDU=";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod7)
		{
			// [ENCODE] input 6 symbols
			string input = encode("123456");
			string output = "MTIzNDU2";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod8)
		{
			// [DECODE] input 1 symbol
			string input = decode("MQ==");
			string output = "1";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod9)
		{
			// [DECODE] input 2 symbols
			string input = decode("MTI=");
			string output = "12";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod10)
		{
			// [DECODE] input 3 symbols
			string input = decode("MTIz");
			string output = "123";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod11)
		{
			// [DECODE] input 4 symbols
			string input = decode("MTIzNA==");
			string output = "1234";
			Assert::AreEqual(input, output);
		}
		TEST_METHOD(TestMethod12)
		{
			// [DECODE] input 5 symbols
			string input = decode("MTIzNDU=");
			string output = "12345";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod13)
		{
			// [DECODE] input 6 symbols
			string input = decode("MTIzNDU2");
			string output = "123456";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod14)
		{
			// [ENCODE] input empty string
			string input = encode("");
			string output = "";
			Assert::AreEqual(input, output);
		}

		TEST_METHOD(TestMethod15)
		{
			// [DECODE] input empty string
			string input = decode("");
			string output = "";
			Assert::AreEqual(input, output);
		}

	};
}