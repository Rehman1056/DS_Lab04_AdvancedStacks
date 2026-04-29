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
//		return size == 0;
//	}
//
//	bool isfull() {
//		return size == capacity;
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
//	~stack() {
//		delete[] stArr;
//	}
//};
//
//int precedence(char op) {
//	if (op == '+' || op == '-') return 1;
//	if (op == '*' || op == '/') return 2;
//	return 0;
//}
//
//void reverse(string& str) {
//	int i = 0, j = str.length() - 1;
//	while (i < j) {
//		swap(str[i], str[j]);
//		i++; j--;
//	}
//}
//
//void swapBrackets(string& str) {
//	for (int i = 0; i < str.length(); i++) {
//		if (str[i] == '(') str[i] = ')';
//		else if (str[i] == ')') str[i] = '(';
//	}
//}
//
//
//string convertInfixToPrefix(string infix) {
//	stack<char> s(10);
//	string postfix = "";
//
//
//	reverse(infix);
//
//	
//	swapBrackets(infix);
//
//	
//	for (int i = 0; i < infix.length(); i++) {
//		char ch = infix[i];
//
//		if (isdigit(ch)) {
//			postfix += ch;
//		}
//		else if (ch == '(') {
//			s.push(ch);
//		}
//		else if (ch == ')') {
//			while (!s.isempty() && s.top() != '(') {
//				postfix += s.pop();
//			}
//			s.pop();
//		}
//		else {
//			while (!s.isempty() && precedence(s.top()) >= precedence(ch)) {
//				postfix += s.pop();
//			}
//			s.push(ch);
//		}
//	}
//
//	while (!s.isempty()) {
//		postfix += s.pop();
//	}
//
//	
//	reverse(postfix);
//	return postfix;
//}
//
//
//float applyOp(float a, float b, char op) {
//	if (op == '+') return a + b;
//	if (op == '-') return a - b;
//	if (op == '*') return a * b;
//	if (op == '/') return a / b;
//	return 0;
//}
//
//
//float evaluatePrefix(string prefix) {
//	stack<float> s(10);
//
//
//	for (int i = prefix.length() - 1; i >= 0; i--) {
//		char ch = prefix[i];
//
//		if (isdigit(ch)) {
//			s.push(ch - '0');
//		}
//		else {
//			float op1 = s.pop();
//			float op2 = s.pop();
//			s.push(applyOp(op1, op2, ch));
//		}
//	}
//
//	return s.pop();
//}
//
//
//int main() {
//	int choice;
//	string infix, prefix;
//
//	do {
//		cout << "\n1. Infix to Prefix";
//		cout << "\n2. Evaluate Prefix";
//		cout << "\n3. Exit";
//		cout << "\nEnter choice: ";
//		cin >> choice;
//
//		if (choice == 1) {
//			cout << "Enter Infix: ";
//			cin >> infix;
//
//			string result = convertInfixToPrefix(infix);
//			cout << "Prefix: " << result << endl;
//		}
//		else if (choice == 2) {
//			cout << "Enter Prefix: ";
//			cin >> prefix;
//
//			cout << "Result: " << evaluatePrefix(prefix) << endl;
//		}
//
//	} while (choice != 3);
//
//	return 0;
//}