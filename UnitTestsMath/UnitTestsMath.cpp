#include "pch.h"
#include "CppUnitTest.h"
#include "../Math-Lib/Types/vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsMath
{
	TEST_CLASS(UnitTestsMath)
	{
	public:
		
		TEST_METHOD(magnitudeTest)
		{
			vector3 vectorTest = vector3(10.f, 10.f, 10.f);
			//float magnitudeResult = vectorTest.magnitude();
			//float magnitudeResult2 = magnitude(vectorTest);

			//Assert::AreEqual(magnitudeResult, magnitudeResult2);
		}
	};
}
