//#include<iostream>
//using namespace std;
//
//template<typename T>
//class stack {
//private:
//	T* stArr;
//	int capacity;
//	int size;
//
//	void regrow() {
//		int newcapacity = capacity * 2;
//		T* newArr = new T[newcapacity];
//
//		for (int i = 0; i < size; i++) {
//			newArr[i] = stArr[i];
//		}
//
//		delete[] stArr;
//		stArr = newArr;
//		capacity = newcapacity;
//	}
//
//public:
//	stack(int cap) {
//		capacity = cap;
//		stArr = new T[capacity];
//		size = 0;
//	}
//
//	bool isempty() {
//		if (size == 0) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	bool isfull() {
//		if (size == capacity) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	void push(T v) {
//		if (isfull()) {
//			regrow();
//		}
//		stArr[size++] = v;
//	}
//
//	T pop() {
//		if (!isempty()) {
//			return stArr[--size];
//		}
//		else {
//			cout << "stack is Empty!" << endl;
//			return T();
//		}
//	}
//
//	T top() {
//		if (!isempty()) {
//			return stArr[size - 1];
//		}
//		else {
//			cout << "stack is Empty!" << endl;
//			return T();
//		}
//	}
//
//	void display() {
//		for (int i = 0; i < size; i++) {
//			cout << stArr[i] << " ";
//		}
//		cout << endl;
//	}
//
//	~stack() {
//		if (stArr) {
//			delete[] stArr;
//		}
//		stArr = nullptr;
//		capacity = 0;
//		size = 0;
//	}
//};
//void sortStack(stack<int>& in_stack) {
//	stack<int> temp_stack(10);
//
//	while (!in_stack.isempty()) {
//		int temp = in_stack.pop();
//
//		
//		while (!temp_stack.isempty() && temp_stack.top() > temp) {
//			in_stack.push(temp_stack.pop());
//		}
//
//		temp_stack.push(temp);
//	}
//
//	
//	while (!temp_stack.isempty()) {
//		in_stack.push(temp_stack.pop());
//	}
//}
//int main() {
//	stack<int> s(5);
//
//	s.push(3);
//	s.push(1);
//	s.push(4);
//	s.push(2);
//
//	sortStack(s);
//
//	cout << "Sorted Stack (Top to Bottom): ";
//	while (!s.isempty()) {
//		cout << s.pop() << " ";
//	}
//
//	return 0;
//}