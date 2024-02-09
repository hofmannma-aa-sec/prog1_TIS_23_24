template <typename T>
class MyClass {
private:
    T data;

public:
    MyClass(T value) : data(value) {}

    T getData() const {
        return data;
    }

    void setData(T value) {
        data = value;
    }
};
