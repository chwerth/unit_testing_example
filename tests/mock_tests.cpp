#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "shapes.hpp"

// Mock class for testing the Shape class
class MockShape : public Shape {
public:
    // Signature: MOCK_METHOD(return_type, method_name, (parameter_types), (qualifiers));
    MOCK_METHOD(double, calculateArea, (), ());
};

// Test calculateArea() using a mock object
TEST(MockShapeTest, CalculateArea) {
    MockShape mockShape;

    // Set up the expectation for the calculateArea() method
    EXPECT_CALL(mockShape, calculateArea())
        .WillOnce(testing::Return(10.0));

    double area = mockShape.calculateArea();
    EXPECT_EQ(area, 10.0);
}

// Test printArea() using a mock object
TEST(MockPrintAreaTest, PrintArea) {
    MockShape mockShape;

    // Set up the expectation for the calculateArea() method
    EXPECT_CALL(mockShape, calculateArea())
        .WillOnce(testing::Return(20.0));

    testing::internal::CaptureStdout();
    printArea(mockShape);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Area: 20\n");
}

// Test calculateArea() using a strict mock object
TEST(MockStrictShapeTest, CalculateArea) {
    testing::StrictMock<MockShape> strictMockShape;

    // Set up the expectation for the calculateArea() method
    EXPECT_CALL(strictMockShape, calculateArea())
        .WillOnce(testing::Return(30.0));

    double area = strictMockShape.calculateArea();
    EXPECT_EQ(area, 30.0);
}

// Test calculateArea() using a nice mock object
TEST(MockNiceShapeTest, CalculateArea) {
    testing::NiceMock<MockShape> niceMockShape;

    // No expectations set

    double area = niceMockShape.calculateArea();
    EXPECT_EQ(area, 0.0); // The default return value is used (0.0 for double)
}


/**
In Google Mock, a "nice" mock and a "strict" mock refer to different levels of strictness in enforcing expectations during testing.
A nice mock is more lenient and allows unexpected calls to mock methods without failing the test.
If no expectations are set for a particular method call, the nice mock will return a default value appropriate for the return type of the method.
This can be useful when you are only interested in specific method calls and want to focus on testing specific scenarios without
being overly concerned about every single method invocation.
On the other hand, a strict mock is more rigid and enforces strict behavior by failing the test if there is any unexpected call to a mock method.
It ensures that every method call is explicitly expected and specified in the test, and any deviation from the specified expectations will result in a test failure.
Strict mocks are useful when you want to ensure that the test covers all possible method calls and that the behavior is precisely as expected, 
leaving no room for any unexpected or unintended interactions.

To summarize:

- Nice Mock: Allows unexpected calls, returns default values for unmocked methods (default).
- Strict Mock: Enforces strict behavior, fails the test on unexpected calls.

The choice between a nice mock and a strict mock depends on the specific requirements of your test scenario.
Nice mocks can be helpful in situations where you want to focus on specific aspects of the code under test,
while strict mocks ensure that all interactions are explicitly defined and verified.
*/