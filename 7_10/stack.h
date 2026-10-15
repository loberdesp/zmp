template <typename T>
class Stack {

    T data[100];
    int top = 0;
    
    public:
        void push(T value);
        T pop();
};

template <typename T>
void Stack<T>::push(T value) {
    data[top++] = value;
}

template <typename T>
T Stack<T>::pop() {
    return data[--top];
}