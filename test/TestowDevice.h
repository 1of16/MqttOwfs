#include <cassert>
#include "UnitTest.h"
#include "../src/owDevice.h"

using namespace std;

class TestowDevice : public TestClass<TestowDevice>
{
public:
    TestowDevice();
    ~TestowDevice();

	bool TestCopyConstructor();
    bool TestDisplayName();
    bool TestRound();
    bool TestValue();
};
