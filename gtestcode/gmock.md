

1  mocker类， 设置成员函数

继承，就可以了 然后 MOCK_METHOD 
class TestUser : public User {
public:
    MOCK_METHOD2(Login, bool(const std::string&, const std::string&));
    MOCK_METHOD1(Pay, bool(int));
    MOCK_METHOD0(Online, bool());
};


2   ON_CALL EXPECT_CALL


ON_CALL(pubObj, readBuf(1000)).WillByDefault(Return(mlen));
	ON_CALL(pubObj, writeBuf(4)).WillByDefault(Return(0));
 
	EXPECT_CALL(pubObj, readBuf(1000)).Times(1)

EXPECT_CALL(subObj, readBuf(1000))
    .Times(5)
    .WillOnce(Return(100))
    .WillOnce(Return(150))
    .WillRepeatedly(Return(200));
    
    
	    {
	        TestUser test_user;
	        EXPECT_CALL(test_user, Online()).WillOnce(testing::Return(true));
	        EXPECT_CALL(test_user, Login(_,_)).WillRepeatedly(testing::Return(false));
	        EXPECT_CALL(test_user, Pay(_)).WillRepeatedly(testing::Return(true));
	 
	        Biz biz;
	        biz.SetUser(&test_user);
	        std::string admin_ret = biz.pay("user", "", 1);
	        admin_ret = biz.pay("user", "", 1);
	    }



	    
 我们就可以设计测试场景了。在设计场景之前，我们先看一些Gmock的方法
	
	//   EXPECT_CALL(mock_object, Method(argument-matchers))
	//       .With(multi-argument-matchers)
	//       .Times(cardinality)
	//       .InSequence(sequences)
	//       .After(expectations)
	//       .WillOnce(action)
	//       .WillRepeatedly(action)
	//       .RetiresOnSaturation();
	//
	// where all clauses are optional, and .InSequence()/.After()/
	// .WillOnce() can appear any number of times.
? ? ? ? 我们可以使用

EXPECT_CALL声明一个调用期待，就是我们期待这个对象的这个方法按什么样的逻辑去执行。
mock_object是我们mock的对象，上例中就是TestUser的一个对象。
Method是mock对象中的mock方法，它的参数可以通过argument-matchers规则去匹配。
With是多个参数的匹配方式指定。
Times表示这个方法可以被执行多少次。如果超过这个次数，则按默认值返回了。
InSequence用于指定函数执行的顺序。它是通过同一序列中声明期待的顺序确定的。
After方法用于指定某个方法只能在另一个方法之后执行。
WillOnce表示执行一次方法时，将执行其参数action的方法。一般我们使用Return方法，用于指定一次调用的输出。
WillRepeatedly表示一直调用一个方法时，将执行其参数action的方法。需要注意下它和WillOnce的区别，WillOnce是一次，WillRepeatedly是一直。
RetiresOnSaturation用于保证期待调用不会被相同的函数的期待所覆盖
