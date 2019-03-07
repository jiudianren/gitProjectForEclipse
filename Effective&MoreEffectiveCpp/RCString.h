template<class T> // template class for smart
class RCPtr { // pointers-to-T objects; T
public: // must inherit from RCObject
    RCPtr(T* realPtr = 0);
    RCPtr(const RCPtr& rhs);
    ~RCPtr();
    RCPtr& operator=(const RCPtr& rhs);
    T* operator->() const;
    T& operator*() const;
private:
    T *pointee;
    void init();
};


class RCObject { // base class for referencepublic: // counted objects
    void addReference();
    void removeReference();
    void markUnshareable();


    bool isShareable() const;
    bool isShared() const;
protected:
    RCObject();
    RCObject(const RCObject& rhs);
    RCObject& operator=(const RCObject& rhs);
    virtual ~RCObject() = 0;
private:
    int refCount;
    bool shareable;
};
class String { // class to be used by
public: // application developers
    String(const char *value = "");
    const char& operator[](int index) const;
    char& operator[](int index);
private:
    // class representing string values
    struct StringValue: public RCObject {
        char *data;
        StringValue(const char *initValue);
        StringValue(const StringValue& rhs);
        void init(const char *initValue);
        ~StringValue();
    };
    RCPtr<StringValue> value;
};
