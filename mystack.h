/**
 * @file mystack.h
 * @brief 模板栈类实现。
 * 提供一个固定大小的栈，支持基本的 push、pop 和查询操作。
 */

#pragma once
#define OK 1
#define NO 0
typedef bool Status;

template<class Type>
class mystack {
private:
    Type* top;      /**< 栈顶指针。 */
    Type* base;     /**< 栈底指针。 */
    static const int size = 100;    /**< 栈的最大容量。 */

public:
    /**
     * @brief 构造函数，初始化栈。
     * 分配内存并将栈顶和栈底指针置为初始状态。
     */
    mystack() {
        init();
    }

    /**
     * @brief 初始化栈。
     * 分配内存并设置栈顶和栈底指针。
     *
     * @throws std::bad_alloc 如果内存分配失败。
     */
    void init() {
        base = new Type[size]();
        top = base;
        if (!base) {
            throw std::bad_alloc();
        }
    }

    /**
     * @brief 检查栈是否为空。
     * @return true 如果栈为空，否则返回 false。
     */
    Status isempty() {
        return base == top;
    }

    /**
     * @brief 获取栈顶元素。
     * @return 栈顶元素的引用，若栈为空则行为未定义。
     */
    Type& gettop() {
        if (!isempty()) {
            return *(top - 1);
        }
    }

    /**
     * @brief 获取栈的长度。
     * 统计栈中元素的数量。
     *
     * @return 栈中元素的个数。
     */
    int stacklen() {
        int ans = 0;
        Type* p = top;
        while (p != base) {
            ans++;
            p--;
        }
        return ans;
    }

    /**
     * @brief 向栈中压入元素。
     * 若栈未满，则将元素压入栈顶。
     *
     * @param element 要压入的元素。
     */
    void push(Type& element) {
        if (stacklen() < size) {
            *top = element;
            top++;
        }
    }

    /**
     * @brief 从栈中弹出顶元素。
     * 若栈非空，则移除栈顶元素。
     */
    void pop() {
        if (!isempty()) {
            top--;
        }
    }

    /**
     * @brief 析构函数，释放栈内存。
     */
    ~mystack() {
        delete[] base;
    }
};