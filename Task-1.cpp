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
//	bool isempty() { return size == 0; }
//	bool isfull() { return size == capacity; }
//
//	void push(T v) {
//		if (isfull()) regrow();
//		stArr[size++] = v;
//	}
//
//	T pop() {
//		if (!isempty()) return stArr[--size];
//		cout << "Stack Empty!\n";
//		return T();
//	}
//
//	T top() {
//		if (!isempty()) return stArr[size - 1];
//		cout << "Stack Empty!\n";
//		return T();
//	}
//};
//
//int precedence(char op) {
//	if (op == '^') return 3;
//	if (op == '*' || op == '/') return 2;
//	if (op == '+' || op == '-') return 1;
//	return 0;
//}
//
//bool isMatching(char open, char close) {
//	return (open == '(' && close == ')') ||
//		(open == '[' && close == ']') ||
//		(open == '{' && close == '}');
//}
//
//string convertInfixToPostfix(string infix) {
//	stack<char> s(10);
//	string postfix = "";
//
//	for (int i = 0; i < infix.length(); i++) {
//		char ch = infix[i];
//
//		if (isdigit(ch)) {
//			postfix += ch;
//
//			if (i + 1 < infix.length() && isdigit(infix[i + 1])) {
//				continue;
//			}
//			postfix += ' '; 
//		}
//
//		else if (ch == '(' || ch == '[' || ch == '{') {
//			s.push(ch);
//		}
//
//		else if (ch == ')' || ch == ']' || ch == '}') {
//			while (!s.isempty() && !isMatching(s.top(), ch)) {
//				postfix += s.pop();
//				postfix += ' ';
//			}
//			s.pop(); 
//		}
//
//		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
//
//			while (!s.isempty() && precedence(s.top()) >= precedence(ch)) {
//				postfix += s.pop();
//				postfix += ' ';
//			}
//			s.push(ch);
//		}
//	}
//
//	while (!s.isempty()) {
//		postfix += s.pop();
//		postfix += ' ';
//	}
//
//	return postfix;
//}
//
//float applyOp(float a, float b, char op) {
//	if (op == '+') return a + b;
//	if (op == '-') return a - b;
//	if (op == '*') return a * b;
//	if (op == '/') return a / b;
//	if (op == '^') return pow(a, b);
//	return 0;
//}
//
//float evaluatePostfix(string postfix) {
//	stack<float> s(10);
//
//	for (int i = 0; i < postfix.length(); i++) {
//
//		if (postfix[i] == ' ') continue;
//
//		if (isdigit(postfix[i])) {
//			float num = 0;
//
//			while (i < postfix.length() && isdigit(postfix[i])) {
//				num = num * 10 + (postfix[i] - '0');
//				i++;
//			}
//			i--; 
//			s.push(num);
//		}
//		else {
//			float op2 = s.pop();
//			float op1 = s.pop();
//
//			float result = applyOp(op1, op2, postfix[i]);
//			s.push(result);
//		}
//	}
//
//	return s.pop();
//}
//
//int main() {
//	string infix;
//
//	cout << "Enter Infix Expression: ";
//	cin >> infix;
//
//	string postfix = convertInfixToPostfix(infix);
//	cout << "Postfix: " << postfix << endl;
//
//	cout << "Result: " << evaluatePostfix(postfix) << endl;
//
//	return 0;
//}