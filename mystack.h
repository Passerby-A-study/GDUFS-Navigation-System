#pragma once
#define OK 1
#define NO 0
typedef bool Status;

template<class Type>
class mystack {
private:
    Type* top;
    Type* base;
    static const int size = 100;
public:
    mystack() {
        init();
    }

    void init() {
        base = new Type[size]();
        top = base;
        if (!base) {
            throw std::bad_alloc();
        }
    }

    Status isempty() {
        return base == top;
    }

    Type& gettop() {
        if (!isempty()) {
            return *(top - 1);
        }
    }

    int stacklen() {
        int ans = 0;
        Type* p = top;
        while (p != base) {
            ans++;
            p--;
        }
        return ans;
    }

    void push(Type& element) {
        if (stacklen() < size) {
            *top = element;
            top++;
        }
    }

    void pop() {
        if (!isempty()) {
            top--;
        }
    }

    ~mystack() {
        delete[] base;
    }
};