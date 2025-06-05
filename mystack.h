/**
 * @file mystack.h
 * @brief ģ��ջ��ʵ�֡�
 * �ṩһ���̶���С��ջ��֧�ֻ����� push��pop �Ͳ�ѯ������
 */

#pragma once
#define OK 1
#define NO 0
typedef bool Status;

template<class Type>
class mystack {
private:
    Type* top;      /**< ջ��ָ�롣 */
    Type* base;     /**< ջ��ָ�롣 */
    static const int size = 100;    /**< ջ����������� */

public:
    /**
     * @brief ���캯������ʼ��ջ��
     * �����ڴ沢��ջ����ջ��ָ����Ϊ��ʼ״̬��
     */
    mystack() {
        init();
    }

    /**
     * @brief ��ʼ��ջ��
     * �����ڴ沢����ջ����ջ��ָ�롣
     *
     * @throws std::bad_alloc ����ڴ����ʧ�ܡ�
     */
    void init() {
        base = new Type[size]();
        top = base;
        if (!base) {
            throw std::bad_alloc();
        }
    }

    /**
     * @brief ���ջ�Ƿ�Ϊ�ա�
     * @return true ���ջΪ�գ����򷵻� false��
     */
    Status isempty() {
        return base == top;
    }

    /**
     * @brief ��ȡջ��Ԫ�ء�
     * @return ջ��Ԫ�ص����ã���ջΪ������Ϊδ���塣
     */
    Type& gettop() {
        if (!isempty()) {
            return *(top - 1);
        }
    }

    /**
     * @brief ��ȡջ�ĳ��ȡ�
     * ͳ��ջ��Ԫ�ص�������
     *
     * @return ջ��Ԫ�صĸ�����
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
     * @brief ��ջ��ѹ��Ԫ�ء�
     * ��ջδ������Ԫ��ѹ��ջ����
     *
     * @param element Ҫѹ���Ԫ�ء�
     */
    void push(Type& element) {
        if (stacklen() < size) {
            *top = element;
            top++;
        }
    }

    /**
     * @brief ��ջ�е�����Ԫ�ء�
     * ��ջ�ǿգ����Ƴ�ջ��Ԫ�ء�
     */
    void pop() {
        if (!isempty()) {
            top--;
        }
    }

    /**
     * @brief �����������ͷ�ջ�ڴ档
     */
    ~mystack() {
        delete[] base;
    }
};