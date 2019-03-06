class String {

public:


	String(const char *initValue = "");
	String(const String& rhs);
	~String();

	String& operator=(const String& rhs);

	const char& 	operator[](int index) const; // for const Strings
	char& operator[](int index); // for non-const Strings

private:
	struct StringValue {
		bool shareable; // add this

		int refCount;
		char *data;
		StringValue(const char *initValue);
		~StringValue();
	};
	// and a string value
	StringValue *value; // value of this String
};


