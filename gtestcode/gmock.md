

1  mocker�࣬ ���ó�Ա����

�̳У��Ϳ����� Ȼ�� MOCK_METHOD 
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



	    
 ���ǾͿ�����Ʋ��Գ����ˡ�����Ƴ���֮ǰ�������ȿ�һЩGmock�ķ���
	
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
? ? ? ? ���ǿ���ʹ��

EXPECT_CALL����һ�������ڴ������������ڴ������������������ʲô�����߼�ȥִ�С�
mock_object������mock�Ķ��������о���TestUser��һ������
Method��mock�����е�mock���������Ĳ�������ͨ��argument-matchers����ȥƥ�䡣
With�Ƕ��������ƥ�䷽ʽָ����
Times��ʾ����������Ա�ִ�ж��ٴΡ�������������������Ĭ��ֵ�����ˡ�
InSequence����ָ������ִ�е�˳������ͨ��ͬһ�����������ڴ���˳��ȷ���ġ�
After��������ָ��ĳ������ֻ������һ������֮��ִ�С�
WillOnce��ʾִ��һ�η���ʱ����ִ�������action�ķ�����һ������ʹ��Return����������ָ��һ�ε��õ������
WillRepeatedly��ʾһֱ����һ������ʱ����ִ�������action�ķ�������Ҫע��������WillOnce������WillOnce��һ�Σ�WillRepeatedly��һֱ��
RetiresOnSaturation���ڱ�֤�ڴ����ò��ᱻ��ͬ�ĺ������ڴ�������
