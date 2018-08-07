
#include "Simple1.h"
#include  "gmock/gmock.h"
#include "MockInterface.h"


TEST(MockINTER, more)
{

    int   value = 100 ;
    MockTestInterface  mockFoo;
    EXPECT_CALL(mockFoo, GetId()).Times(1). WillOnce( ::testing::Return(value) );
    int returnValue = mockFoo.GetId();
    std::cout << "Returned Value: " << returnValue << std::endl;

}

