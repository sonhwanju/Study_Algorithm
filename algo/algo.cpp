//20211 손환주
#include <iostream>
#include <stack>
#include <Windows.h>
#include <vector>
#include <queue>
#include <string>
#include <ctype.h> 
#include <stdlib.h>

using namespace std;

int main() {


	return 0;
}

//스택

//int main() {
//	//문제 1
//
//	/*int a;
//	int b;
//	cin >> a;
//	stack<int> stack1;
//	if (a <= 1000) {
//		for (int i = 0; i < a; i++)
//		{
//			cin >> b;
//			stack1.push(b);
//		}
//		for (int j = 0; j < a; j++)
//		{
//			cout << stack1.top() << " ";
//			stack1.pop();
//		}
//	}
//	else {
//		cout << "1000이하 입력하셈" << endl;
//		return 0;
//	}*/
//
//	//문제 2
//	//다른 링크
//
//	//문제 3
//	/*stack<char> st;
//	
//	int input = 0;
//	char arr[300];
//	char* arrNum;
//	cin >> input;
//	cin >> arr;
//	arrNum = arr;
//	int num = 0;
//
//	for (int i = input-1; i >= 0; i--)
//	{
//		if (i == 0) {
//			st.push(*arrNum);
//		}
//		else if (i % 3 == 0) {
//			st.push(*arrNum);
//			st.push(',');
//			num++;
//		}
//		else {
//			st.push(*arrNum);
//		}
//		*arrNum++;
//	}
//	input += num;
//	for (int i = 0; !st.empty(); i++)
//	{
//		arr[i] = st.top();
//		st.pop();
//	}
//	for (int i = input-1; i >= 0; i--)
//	{
//		cout << arr[i];
//	}*/
//	
//	return 0;
//}



//스택계산기

////중위를 후위로 바꾸기 위한 연산
//class CharStack {
//private: //class 내부 접근
//	int stack[100];
//	int top;
//public: // 내부/외부 접근 가능
//	CharStack() { top = -1; }
//	void push(char val) { stack[++top] = val; }  //stack 에 val 값 넣기
//	char pop() { return stack[top--]; }   //stack 에 값 빼기
//	int isEmpty() { return top == -1; }
//	int isFull() { return top == 99; }
//	char getTop() { return stack[top]; }
//};
//
////intStack  -- postfix result 연산위한 stack
//class IntStack {
//private:
//	int stack[100];
//	int top;
//public:
//	IntStack() { top = -1; }
//	void push(int val) { stack[++top] = val; }
//	int pop() { return stack[top--]; }
//	int isEmpty() { return top == -1; }
//	int isFull() { return top == 99; }
//};
//
////calculator class 정의
//class Calculator {
//private:
//	char buffer[80];
//	char postfix[80];
//
//	IntStack s1;
//	CharStack s2;
//
//	void infixTopostfix();
//	void result();
//	int priority(char);
//
//public:
//	void calculate(char[]);
//};
//
//int Calculator::priority(char ch) { // 연산자에 우선순위를 지정해 준다
//	if (ch == ')')
//		return 4;
//	else if (ch == '*' || ch == '/')
//		return 3;
//	else if (ch == '+' || ch == '-')
//		return 2;
//	else
//		return 1;
//}
//
//void Calculator::calculate(char infix[]) { // 중위 표기법인 연산들을 buffer[i]에 넣어준다
//	for (int i = 0; i < 80; i++)
//		buffer[i] = infix[i];
//	infixTopostfix();
//	result();
//}
//
//void Calculator::infixTopostfix() { //중위 표기법 -> 후위 표기법
//	int i = 0, j = 0;
//	char ch;
//
//	while (buffer[i] != NULL) {
//		if (buffer[i] == ' ') //공백이면 다음 버퍼로 넘어간다
//			i++;
//		else if (isdigit(buffer[i])) { //buffer[i]의 값이 숫자면 postfix에 출력
//			while (isdigit(buffer[i]))
//				postfix[j++] = buffer[i++];
//			postfix[j++] = ' ';
//		}
//
//		else if (buffer[i] == '(') { //시작 괄호는 스택에 넣어준다
//			s2.push(buffer[i]);
//			i++;
//		}
//		else if (buffer[i] == ')') { //마침 괄호를 발견 할때까지 연산자들을 pop
//			ch = s2.pop();
//			while (ch != '(') {
//				postfix[j++] = ch;
//				postfix[j++] = ' ';
//				ch = s2.pop();
//			}
//			i++;
//		}
//
//		else if (buffer[i] == '{') {
//			s2.push(buffer[i]);
//			i++;
//		}
//		else if (buffer[i] == '}') {
//			ch = s2.pop();
//			while (ch != '{') {
//				postfix[j++] = ch;
//				postfix[j++] = ' ';
//				ch = s2.pop();
//			}
//			i++;
//		}
//		else if (buffer[i] == '[') {
//			s2.push(buffer[i]);
//			i++;
//		}
//		else if (buffer[i] == ']') {
//			ch = s2.pop();
//			while (ch != '[') {
//				postfix[j++] = ch;
//				postfix[j++] = ' ';
//				ch = s2.pop();
//			}
//			i++;
//		}
//		else {
//			if (s2.isEmpty())
//				s2.push(buffer[i++]);
//			else { //스택에 있는 자기보다 높거나 같은 연산자들을 모두 postfix에 출력하고 자신은 스택에 push
//				while (!s2.isEmpty() && priority(s2.getTop()) >= priority(buffer[i])) {
//					ch = s2.pop();
//					postfix[j++] = ch;
//					postfix[j++] = ' ';
//				}
//				s2.push(buffer[i]);
//				i++;
//			}
//		}
//	}
//	while (!s2.isEmpty()) { //수식이 끝나면 stack내용 pop
//		ch = s2.pop();
//		postfix[j++] = ch;
//		postfix[j++] = ' ';
//	}
//	postfix[j] = NULL;
//
//
//	cout << "postfix : " << postfix << endl;
//}
//
//void Calculator::result() {
//	int i = 0, k;
//	char token[5];
//	int num, number, num1, num2;
//	char ch;
//
//	while (postfix[i] != NULL) {
//		if (isdigit(postfix[i])) {//postfix의 값이 숫자면 반환(true), 연산자 이면(false)
//			k = 0;
//			while (isdigit(postfix[i]))
//				token[k++] = postfix[i++];
//			token[k] = NULL;
//			num = atoi(token); //문자열을 int형으로 변환
//			s1.push(num);
//		}
//		else if (postfix[i] == ' ')
//			i++;
//		else { //연산자는 스택에서 두 수를 pop하여 연산하고 다시 push
//			ch = postfix[i++];
//			num1 = s1.pop();
//			num2 = s1.pop();
//			if (ch == '+') number = num2 + num1;
//			else if (ch == '-') number = num2 - num1;
//			else if (ch == '*') number = num2 * num1;
//			else if (ch == '/') number = num2 / num1;
//			else if (ch == '/' && num1 == 0) number = 0;
//			s1.push(number);
//		}
//		i++;
//	}
//	if (ch == '(')
//		cout << "result = " << "괄호의 짝이 맞지 않습니다" << endl;
//	else
//		cout << "result = " << s1.pop() << endl;
//}
//
//
//void main()
//{
//	char infix[80];
//	char infix1[40] = { '(','(','(','5','-','7',')','/','2','+','2',')','*',
//	 '(','3','*','2','/','6', ')','-','3','*','3',')' };
//	char infix3[40] = { '(','(','(','5','-','7',')','/','2','+','2',')','*',
//	 '(','3','*','2','/','6','-','3','*','3',')' };
//
//	Calculator myInput;
//
//
//	for (int n = 0; n < 1; n++) {
//
//		cout << "1번 infix = (((5-7)/2+2)*(3*2/6)-3*3) " << endl;
//		myInput.calculate(infix1);
//		cout << "_____________________________________________________________" << endl << endl;
//
//
//		cout << "2번 infix = (((5-7)/2+2)*(3*2/6-3*3) " << endl;
//		myInput.calculate(infix3);
//		cout << "_____________________________________________________________" << endl << endl;
//	}
//
//	//무한 루프 - 값 입력 받아 수행
//	while (1) {
//		cout << "중위연산자(infix) 수식 입력" << endl;
//		cout << "infix : ";
//		cin >> infix;
//		myInput.calculate(infix);
//		cout << "_____________________________________________________________" << endl << endl;
//	}
//}


//큐 구현하기

/*#define NEXT(index, QSIZE) ((index+1)%QSIZE)

typedef struct Queue {
	int* buf;
	int qsize;
	int front;
	int rear;
	int count;
}Queue;

void InitQueue(Queue* queue, int qsize);
int IsFull(Queue* queue);
int IsEmpty(Queue* queue);
void Enqueue(Queue* queue, int data);
int Dequeue(Queue* queue);

int main() {
	int i;
	Queue queue;
	InitQueue(&queue, 10);
	for (int i = 1; i <= 5; i++)
	{
		cout << i << "입력" << endl;
		Enqueue(&queue, i);
	}
	cout << endl;
	while (!IsEmpty(&queue))
	{
		cout << Dequeue(&queue) << "출력" << endl;
	}
	cout << endl;



	return 0;
}
void InitQueue(Queue* queue, int qsize) {
	queue->buf = new int[qsize];
	queue->qsize = qsize;
	queue->front = queue->rear = 0;
	queue->count = 0;
}
int IsFull(Queue* queue) {
	return queue->count == queue->qsize;
}
int IsEmpty(Queue* queue) {
	return queue->count == 0;
}
void Enqueue(Queue* queue, int data) {
	if (IsFull(queue)) {
		cout << "꽉찼다"<<endl;
		return;
	}
	queue->buf[queue->rear] = data;
	queue->rear = NEXT(queue->rear, queue->qsize);
	queue->count++;
}
int Dequeue(Queue* queue) {
	int re = 0;
	if (IsEmpty(queue)) {
		cout << "비었다" << endl;
		return re;
	}
	re = queue->buf[queue->front];
	queue->front = NEXT(queue->front, queue->qsize);
	queue->count--;
	return re;
}*/

//큐 삽입 삭제

/*#define QUEUE_SIZE 5
#define NEXT(index) ((index+1)%QUEUE_SIZE)

typedef struct Queue {
	int buf[QUEUE_SIZE];
	int front;
	int rear;
}Queue;

void InitQueue(Queue* queue);
int IsFull(Queue* queue);
int IsEmpty(Queue* queue);
void Enqueue(Queue* queue, int data);
int Dequeue(Queue* queue);

int main(void) {
	int select = -1;
	Queue queue;
	InitQueue(&queue);
	while (1)
	{
		cout << "1.Enqueue 2.Dequeue" << endl;
		cout << ">>";
		cin >> select;
		switch (select)
		{
		case 1:
			int value;
			cout << "inputdata:";
			cin >> value;
			Enqueue(&queue, value);
			break;
		case 2:
			Dequeue(&queue);
			break;
		}
		cout << endl;
	}



}
void InitQueue(Queue* queue) {
	queue->front = queue->rear = 0;
}
int IsFull(Queue* queue) {
	return NEXT(queue->rear) == queue->front;
}
int IsEmpty(Queue* queue) {
	return queue->front == queue->rear;
}
void Enqueue(Queue* queue, int data) {
	if (IsFull(queue)) {
		cout << "꽉찼다" << endl;
		return;
	}
	queue->buf[queue->rear] = data;
	queue->rear = NEXT(queue->rear);
}
int Dequeue(Queue* queue) {
	int re = 0;
	if (IsEmpty(queue)) {
		cout << "비었다" << endl;
		return re;
	}
	re = queue->buf[queue->front];
	queue->front = NEXT(queue->front, queue->qsize);
	cout << "dequeue : " << re;
	return re;
}*/

//원형 큐 실습

//#define NEXT(index,QSIZE) ((index+1)%QSIZE)
//
//typedef struct Queue {
//	int* buf;
//	int qsize;
//	int front;
//	int rear;
//	int count;
//}Queue;
//
//void InitQueue(Queue* queue,int qsize);
//int IsFull(Queue* queue);
//int IsEmpty(Queue* queue);
//void Enqueue(Queue* queue, int data);
//int Dequeue(Queue* queue);
//
//int main() {
//	int i, size;
//	int select = -1;
//	Queue queue;
//
//	cout << "큐 크기 입력 :";
//	cin >> size;
//
//	InitQueue(&queue, size);
//	
//	while (1)
//	{
//		cout << "1.Enqueue 2.Dequeue" << endl;
//		cout << ">>";
//		cin >> select;
//		switch (select)
//		{
//		case 1:
//			int value;
//			cout << "inputdata:";
//			cin >> value;
//			Enqueue(&queue, value);
//			break;
//		case 2:
//			Dequeue(&queue);
//			break;
//		}
//		cout << endl;
//	}
//
//
//}
//void InitQueue(Queue* queue, int qsize) {
//	queue->buf = new int[qsize];
//	queue->qsize = qsize;
//	queue->front = queue->rear = 0;
//	queue->count = 0;
//}
//int IsFull(Queue* queue) {
//	return queue->count == queue->qsize;
//}
//int IsEmpty(Queue* queue) {
//	return queue->count == 0;
//}
//void Enqueue(Queue* queue, int data) {
//	if (IsFull(queue)) {
//		cout << "꽉찼다" << endl;
//		return;
//	}
//	queue->buf[queue->rear] = data;
//	queue->rear = NEXT(queue->rear, queue->qsize);
//	queue->count++;
//}
//int Dequeue(Queue* queue) {
//	int re = 0;
//	if (IsEmpty(queue)) {
//		cout << "비었다" << endl;
//		return re;
//	}
//	re = queue->buf[queue->front];
//	queue->front = NEXT(queue->front, queue->qsize);
//	cout << "dequeue : " << re;
//	queue->count--;
//	return re;
//}



//#define SIZE 10
//
//typedef struct {
//	char stackArr[SIZE];
//	int topindex;
//	char name;
//}stack;
//
//typedef stack* pstack;
//void init(pstack ps, char c);
//
//void push(pstack ps, char ch);
//
//char pop(pstack ps);



//typedef struct linked {
//	int data;
//	struct linked* next;
//}node;
//
//node* head = NULL;
//node* tail = NULL;
//
//void Init();
//void Insert(node* ptr);
//void PrintList(node* ptr);
//void Modify(node* ptr);
//void InsertData(node* ptr);
//void Delete(node* ptr);
//
//int main() {
//	int menu = 0;
//	Init();
//
//	while (true)
//	{
//		cout << "1.입력 2.출력 3.수정 4.삽입 5.삭제 6.종료" << endl;
//		cout << "input menu : ";
//		cin >> menu;
//
//		switch (menu)
//		{
//		case 1:
//			Insert(tail);
//			break;
//		case 2:
//			PrintList(head);
//			break;
//		case 3:
//			Modify(head);
//			break;
//		case 4:
//			InsertData(head);
//			break;
//		case 5:
//			Delete(head);
//			break;
//		case 6:
//			break;
//		default:
//			cout << "select menu error.." << endl;
//			//break;
//		}
//		if (menu == 6) break;
//	}
//	return 0;
//}
//void Init() {
//	head = new node;
//	head->data = 0;
//	head->next = NULL;
//	tail = head;
//	return;
//}
//void Insert(node* ptr) {
//	node* newnode = new node;
//	int num = 0;
//	cout << "Input number : ";
//	cin >> num;
//
//	newnode->data = num;
//	newnode->next = NULL;
//
//	ptr->next = newnode;
//	tail = newnode;
//
//	return;
//}
//void PrintList(node* ptr) {
//	node* view = ptr->next;
//
//	while (view != NULL)
//	{
//		cout << view->data;
//		view = view->next;
//	}
//	cout << endl;
//	return;
//}
//void Modify(node* ptr) {
//	int index = 0;
//	int num = 0;
//	int i;
//
//	cout << "input modify index : ";
//	cin >> index;
//
//	cout << "input modify data : ";
//	cin >> num;
//
//	for (i = 0; i < index; i++)
//	{
//		ptr = ptr->next;
//	}
//	ptr->data = num;
//	return;
//}
//void InsertData(node* ptr) {
//	node* newnode = new node;
//
//	int index = 0, num = 0;
//	int i;
//
//	cout << "input InsertData index: ";
//	cin >> index;
//
//	cout << "input data: ";
//	cin >> num;
//
//	for (i = 0; i < index; i++)
//	{
//		ptr = ptr->next;
//	}
//	newnode->data = num;
//	newnode->next = NULL;
//	if (ptr->next == NULL) {
//		ptr->next = newnode;
//		tail = newnode;
//	}
//	else {
//		newnode->next = ptr->next;
//		ptr->next = newnode;
//	}
//	return;
//}
//void Delete(node* ptr) {
//	node* temp = 0;
//	int i;
//	int index;
//
//	if (head == tail) {
//		cout << "not found data" << endl;
//		return;
//	}
//	cout << "input delete index: ";
//	cin >> index;
//
//	for (i = 0; i < index - 1; i++)
//	{
//		ptr = ptr->next;
//	}
//	temp = ptr->next;
//
//	if (temp->next == NULL) {
//		ptr->next = NULL;
//		tail = ptr;
//	}
//	else {
//		ptr->next = temp->next;
//	}
//	delete(temp);
//	return;
//}

//struct Node {
//	int data;
//	struct Node* nextNode;
//	struct Node* prevNode;
//};
//struct Node* CreateNode(int data) {
//	Node* temp = new Node;
//	temp->data = data;
//	temp->nextNode = NULL;
//	temp->prevNode = NULL;
//	return temp;
//}
//void AppendNode(Node** head, Node* newNode) {
//	if (*head == NULL) {
//		*head = newNode;
//	}
//	else {
//		Node* tail = *head;
//
//		while (tail->nextNode !=NULL)
//		{
//			tail = tail->nextNode;
//		}
//		tail->nextNode = newNode;
//		newNode->prevNode = tail;
//		newNode->nextNode = NULL;
//	}
//}
//int CountNode(Node** head) {
//	int count = 0;
//	struct Node* current = *head;
//	while (current != NULL) {
//		current = current->nextNode;
//		count++;
//	}
//	return count;
//}
//struct Node* SearchNode(Node** head, int index) {
//	struct Node* current = *head;
//	while (current->nextNode !=NULL && -(index) >= 0)
//	{
//		current = current->nextNode;
//	}
//	return current;
//}
//void RemoveNode(Node** head, Node* remove) {
//	if (*head == NULL) {
//		cout << endl << "There is no list data." << endl << endl;
//
//		*head = remove->nextNode;
//		remove->prevNode = NULL;
//		remove->nextNode = NULL;
//		delete(remove);
//	}
//	else {
//		Node* temp = *head;
//		while (temp->nextNode != remove)
//		{
//			temp = temp->nextNode;
//		}
//		temp->nextNode = remove->nextNode;
//		remove->nextNode->prevNode = temp;
//		remove->nextNode = NULL;
//		remove->prevNode = NULL;
//		delete(remove);
//	}
//}
//void InsertNodeAfter(Node* current, Node* newNode) {
//	newNode->prevNode = current;
//	newNode->nextNode = current->nextNode;
//	current->nextNode->prevNode = newNode;
//	current->nextNode = newNode;
//}
//void InsertNodeBefore(Node* current, Node* newNode) {
//	newNode->prevNode = current;
//	newNode->nextNode = current->prevNode;
//	current->prevNode->nextNode = newNode;
//}
//int main() {
//	Node* node = NULL;
//	Node* head = NULL;
//	Node* mynode = NULL;
//
//	int i = 0;
//	int count = 0;
//	for ( i = 0; i < 10; i++)
//	{
//		node = CreateNode(i);
//		AppendNode(&head, node);
//	}
//	cout << endl << "counting Node.." << endl << endl;
//	count = CountNode(&head);
//	cout << count << endl;
//	cout << endl << "Checking Node" << endl << endl;
//	for ( i = 0; i < count; i++)
//	{
//		mynode = SearchNode(&head, i);
//		cout << "[" << i << "]" << mynode->data << endl;
//	}
//	cout << endl << "removing node" << endl;
//	mynode = SearchNode(&head, 3);
//	RemoveNode(&head, mynode);
//	count = CountNode(&head);
//	for (i = 0; i < count; i++)
//	{
//		mynode = SearchNode(&head, i);
//		cout << "[" << i << "]" << mynode->data << endl;
//	}
//	cout << endl << "inserting after node" << endl;
//	node = CreateNode(3000);
//	mynode = SearchNode(&head, 6);
//	InsertNodeAfter(mynode, node);
//
//	count = CountNode(&head);
//	for (i = 0; i < count; i++)
//	{
//		mynode = SearchNode(&head, i);
//		
//		printf_s("[%d] %d \n", i, mynode->data);
//	}
//	cout << "inserting before node" << endl;
//	node = CreateNode(1000);
//	mynode = SearchNode(&head, 2);
//	InsertNodeBefore(mynode, node);
//	count = CountNode(&head);
//	for (i = 0; i < count; i++)
//	{
//		mynode = SearchNode(&head, i);
//		cout << "[" << i << "]" << mynode->data << endl;
//	}
//	return 0;
//}

//#define MAZESIZE_X 12
//#define MAZESIZE_Y 22
//#define EXIT_X 11
//#define EXIT_Y 16
//
//typedef struct Position {
//	int x;
//	int y;
//	int d;
//} Position;
//typedef struct Mtable {
//	int x;
//	int y;
//} Mtable;
//
//int Maze[MAZESIZE_X][MAZESIZE_Y] = {
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1},
//	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
//	{1,0,0,1,0,1,0,1,0,0,1,1,1,1,1,0,0,1,1,1,0,1},
//	{1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1},
//	{1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1},
//	{1,1,1,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
//	{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};
//Mtable Move[4] = {
//	{0,1},
//	{1,0},
//	{0,-1},
//	{-1,0}
//};
//int Mark[MAZESIZE_X][MAZESIZE_Y] = {0,};
//int top;
//Position Trace[(MAZESIZE_X - 2) * (MAZESIZE_Y - 2)];
//void ShowMaze(Position);
//void Push(Position);
//void Pop(Position* p);
//
//int main(void) {
//	int isFound = false;
//	int i, dir;
//	Position Now = { 1,1,0 };
//	Position Next;
//	Push(Now);
//	while (!isFound && top > 0)
//	{
//		Pop(&Now);
//		dir = Now.d;
//
//		while (dir < 4)
//		{
//			Next.x = Now.x + Move[dir].x;
//			Next.y = Now.y + Move[dir].y;
//
//			if (Next.x == EXIT_X && Next.y == EXIT_Y) {
//				Next.d = dir;
//				Push(Next);
//				isFound = true;
//				break;
//			}
//			else if ((Maze[Next.x][Next.y] == 0) && (Mark[Next.x][Next.y] == 0)) {
//				Now.d = ++dir;
//				Push(Now);
//				Now.x = Next.x;
//				Now.y = Next.y;
//				dir = 0;
//				Mark[Next.x][Next.y] = 1;
//			}
//			else {
//				dir++;
//			}
//			ShowMaze(Now);
//		}
//	}
//	if (isFound == true) {
//		for (int i = 0; i < top; i++)
//		{
//			ShowMaze(Trace[i]);
//		}
//	}
//	else {
//		cout << "Not Found!" << endl;
//	}
//	system("pause");
//
//	return 0;
//}
//
//void ShowMaze(Position P) {
//	int i, j;
//	Sleep(50);
//	system("cls");
//	cout << "출구는 (11,16)" << endl;
//	cout << "현재 좌표는 " << P.x << " " << P.y << " " << P.d << endl;
//
//	for ( i = 0; i < MAZESIZE_X; i++)
//	{
//		for ( j = 0; j < MAZESIZE_Y; j++)
//		{
//			if (Maze[i][j] == 1) cout << "#";
//			else if (P.x == i && P.y == j) cout << "&";
//			else cout << " ";
//		}
//		cout << endl;
//	}
//
//}
//void Push(Position P) {
//	Trace[top].x = P.x;
//	Trace[top].y = P.y;
//	Trace[top].d = P.d;
//	top++;
//}
//void Pop(Position* P) {
//	top--;
//	P->x = Trace[top].x;
//	P->y = Trace[top].y;
//	P->d = Trace[top].d;
//}

//
////문제1
//	/*stack s1, s2;
//	int i;
//
//	init(&s1, 'A');
//	init(&s2, 'B');
//	cout << endl;
//	push(&s1, 'd');
//	push(&s1, 'a');
//	push(&s1, 't');
//	push(&s1, 'a');
//
//	push(&s2, 's');
//	push(&s2, 't');
//	push(&s2, 'a');
//	push(&s2, 'c');
//	push(&s2, 'k');
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "Pop s1: " << pop(&s1) << endl;
//	}
//	cout << endl;
//
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "Pop s2: " << pop(&s2) << endl;
//	}*/
//
//
//	//문제 2
//
//	//2반 건욱이가 도와줬습니다
//stack<int, vector<int>> st;
//string as;
//cin >> as;
//
//for (int i = 0; i < as.length(); i++)
//{
//	if (0 < as[i] - '0' && as[i] - '0' < 9) {
//		st.push(as[i]);
//	}
//	else {
//		cout << "숫자 이외 ㄴㄴ";
//		return 0;
//	}
//}
//while (!st.empty())
//{
//	cout << st.top() - '0';
//	st.pop();
//}
//cout << endl;
//
//
////문제 3
///*stack<int> s;
//int a[3];
//for (int i = 0; i < 3; i++)
//{
//	cin >> a[i];
//	s.push(a[i]);
//}
//while (!s.empty())
//{
//	cout << s.top() << endl;
//	s.pop();
//}*/

//void init(pstack ps, char c) {
//	ps->topindex = 0;
//	ps->name = c;
//	cout << "Constructing stack " << ps->name << endl;
//}
//
//void push(pstack ps, char ch) {
//	if (ps->topindex == SIZE) {
//		cout << "Stak" << ps->name << " is full" << endl;
//		return;
//	}
//	ps->stackArr[ps->topindex] = ch;
//	ps->topindex++;
//}
//
//char pop(pstack ps) {
//	if (ps->topindex == 0) {
//		cout << "Stack " << ps->name << " is Empty" << endl;
//		return 0;
//	}
//	ps->topindex--;
//
//	return ps->stackArr[ps->topindex];
//}

#pragma region 대충 정리
////int a = 0;
//
//#pragma region 팩토리얼
///*int Factorial(int n) {
//
//	if (n == 0) {
//		return 1;
//	}
//	else {
//		return (n * Factorial(n - 1));
//	}
//	
//}*/
//#pragma endregion
//
//
//#pragma region 가우스
///*int Gauss(int max) {
//	return ((1 + max) * max) / 2;
//}*/
//#pragma endregion
//
//
///*int NoGauss(int sum) {
//
//	a += sum;
//	sum--;
//
//	if (sum == 0) {
//		return a;
//	}
//	else {
//		return NoGauss(sum);
//	}
//}*/
//
//#pragma region 피보나치
//int Fibonacci(int n) {
//	if(n == 1 || n == 2) {
//		return 1;
//	}
//	else {
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//
//}
//#pragma endregion
//
//#pragma region 하노이탑
//void HanoiTower(int num, char from, char by, char to) {
//	if (num == 1) {
//		cout << "원반 1을" << from << "에서" << to << "로 이동" << endl;
//	}
//	else {
//		HanoiTower(num - 1, from, to, by);
//
//		cout << "원반" << num << "을" << from << "에서" << to << "로 이동" << endl;
//
//		HanoiTower(num - 1, by, from, to);
//	}
//}
//#pragma endregion
//
//
///*int NoGauss2(int sum) {
//
//	a += sum;
//	sum--;
//
//	if (sum == 0) {
//		return a;
//	}
//	else {
//		return NoGauss2(sum);
//	}
//}*/
//
////int c = 1;
//
///*int Bonus2(int a)
//{
//	//ex: 258 -> 852
//	if (a == 0) {
//		return 0;
//	}
//	else {
//		int b = Bonus2(a / 10) + (a % 10) * c;
//		c *= 10;
//		return b;
//	}
//}*/
//
///*int NoFactorial(int max) {
//	// cin >> n --> 1-n까지의 곱  cin >> 4    1*2*3*4
//	int b = 1;
//
//	for (int i = 1; i < max + 1; i++)
//	{
//		b = b * i;
//	}
//	return b;
//
//}*/
//
//
////#define MAX_SIZE 5
////
////void GetNumbers(int number[MAX_SIZE])
////{
////	int counter = 0;
////	int numberInput = 0;
////	int loop = 1;
////
////	while (counter < MAX_SIZE)
////	{
////		loop = 1;
////
////		while (loop == 1)
////		{
////			cout << "배열에 저장할 " << counter + 1 << " 번째 정수를 입력하시오" << endl;
////			fflush(stdin);
////
////			cin >> numberInput;
////
////			if (numberInput >= 0)
////			{
////				number[counter] = numberInput;
////				++counter;	loop = 0;
////			}
////			else
////			{
////				cout << "값은 0 이상이여야 됨" << endl;
////				loop = 1;
////			}
////		}
////
////	}
////}
////int Max(int number[], int i, int last)
////{
////	if (i < last)
////	{
////		int MaxN = Max(number, i + 1, last);
////
////		if (number[i] >= MaxN)
////		{
////			return (number[i]);
////		}
////		else
////		{
////			return (MaxN);
////		}
////	}
////
////	else
////	{
////		return(number[i]);
////	}
////}
////int MaxPos(int number[], int i, int last)
////{
////	if (i < last)
////	{
////		int j = MaxPos(number, i + 1, last);
////
////
////		if (number[i] >= number[j])
////		{
////			return(i);
////		}
////		else
////		{
////			return(j);
////		}
////	}
////	else
////	{
////		return(i);
////	}
////
////}
////void PrintArray(int number[], int resultIndex, int resultNumber)
////{
////	int counter = 0;
////
////	cout << "현재 배열에 저장된 값" << endl;
////
////	while (counter < MAX_SIZE)
////	{
////		cout << number[counter] << endl;
////		++counter;
////	}
////	cout << "최댓값은 " << resultNumber << "이다" << endl;
////}
//
////int s = 0;
////
////int Bonus1(int n) {
////	int c = 0;
////
////	if (n < 10)
////	{
////		c = n;
////		s += n;
////		return s;
////	}
////	else
////	{
////		c = n % 10;
////		s += c;
////		return Bonus1(n / 10);
////	}
////}
//
////int Bonus2(int num, int num2)
////{
////	if (num <= 9) {
////		
////		cout << num << "*" << num2 << "=" << num * num2 << endl;
////		if (num2 < 9) {
////			Bonus2(num, num2 + 1);
////		}
////		else {
////			return Bonus2(num + 1, 1);
////		}
////	}
////}
//
////필수문제 
//int NMinus(int n) {
//	cout << n << endl;
//	if (n == 2) {
//		return 1;
//	}
//	else {
//		return NMinus(n - 1);
//	}
//}
////보너스문제
//int Bonus(int a, int b) {
//	if (a < b) {
//		if (a % 2 != 0) {
//
//			if (a < b - 2) {
//				cout << a + 2 << endl;
//				return Bonus(a + 2, b);
//			}
//			else {
//				return a;
//			}
//		}
//		else {
//			a++;
//			cout << a << endl;
//			if (a < b - 2) {
//				cout << a + 2 << endl;
//				return Bonus(a + 2, b);
//			}
//			else {
//				return a;
//			}
//		}
//	}
//	else {
//		if (b % 2 != 0) {
//
//			if (b < a - 2) {
//				cout << b + 2 << endl;
//				return Bonus(a, b+2);
//			}
//			else {
//				return b;
//			}
//		}
//		else {
//			b++;
//			cout << b << endl;
//			if (b < a - 2) {
//				cout << b + 2 << endl;
//				return Bonus(a, b+2);
//			}
//			else {
//				return b;
//			}
//		}
//	}
//	
//}
////보너스문제 2
//int Bonus2(int a, int b) {
//	if (a < b) {
//		if (a % 2 == 0) {
//
//			if (a < b - 2) {
//				cout << a + 2 << endl;
//				return Bonus2(a + 2, b);
//			}
//			else {
//				return a;
//			}
//		}
//		else {
//			a++;
//			cout << a << endl;
//			if (a < b - 2) {
//				cout << a + 2 << endl;
//				return Bonus2(a + 2, b);
//			}
//			else {
//				return a;
//			}
//		}
//	}
//	else {
//		if (b % 2 == 0) {
//			if (b < a - 2) {
//				cout << b + 2 << endl;
//				return Bonus2(a, b + 2);
//			}
//			else {
//				return a;
//			}
//		}
//		else {
//			b++;
//			cout << b << endl;
//			if (b < a - 2) {
//				cout << b + 2 << endl;
//				return Bonus2(a, b + 2);
//			}
//			else {
//				return b;
//			}
//		}
//	}
//	
//}
//
//
//int main() {
//
//	#pragma region 주민등록번호관련
//	/*//주민등록번호관련
//
//	//000000-0000000
//	char arr[14];
//	int arr2[11] = { 8,12,15,18,25,34,39,47,54,66,90 };
//
//	cout << "주민등록번호 -빼고 작성" << endl;
//	cin >> arr;
//
//	//성별
//	if (arr[6] % 2 == 0)
//	{
//		cout << "여자" << endl;
//	}
//	else
//	{
//		cout << "남자" << endl;
//	}
//
//	//나이,출생연도
//	int year = (arr[0] - 48) * 10 + (arr[1] - '0');
//	year += arr[6] <= '2' ? 1900 : 2000;
//	cout << year << endl;
//	cout << 2021 - year + 1 << endl;
//
//	//출생지역
//	string t;
//	int b = (arr[7] - 48) * 10 + (arr[8] - '0');
//	for (int i = 0; i < 11; i++)
//	{
//		if (b <= arr2[i])
//		{
//			if (i == 0) t = "서울";
//			else if (i == 1) t == "부산";
//			else if (i == 2) t == "인천";
//			else if (i == 3) t = "경기도 주요 도시";
//			else if (i == 4) t = "그 밖의 경기도";
//			else if (i == 5) t = "강원도";
//			else if (i == 6) t = "충청북도";
//			else if (i == 7) t = "충청남도";
//			else if (i == 8) t = "전라북도";
//			else if (i == 9) t = "전라남도";
//			else if (i == 10) t = "경상도";
//			break;
//		}
//	}
//	cout << t << endl;
//
//	//유효성 검사
//	const int tab[] = { 2,3,4,5,6,7,8,9,2,3,4,5 };
//	int M = 0;
//	int c;
//	for (int i = 0; i < 12; i++)
//	{
//		M += (arr[i] - '0') * tab[i];
//	}
//
//
//	int d = (arr[12] - '0');
//	if ((11 - (M % 11)) % 10 == d)
//	{
//		cout << "유효" << endl;
//	}
//	else
//	{
//		cout << "유효하지않음" << endl;
//	}*/
//	#pragma endregion 
//	
//	#pragma region 파스칼의 삼각형
//	/*
//	//파스칼의 삼각형
//	int a[10][10] = { 0, };
//	int i, j;
//	for (i = 0; i < 10; i++)
//	{
//		a[i][0] = 1;
//
//		for ( i = 0; i < 10; i++)
//		{
//			for (j = 0; j < 10; j++)
//			{
//				if (j > 0 && i > 0)
//					a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//				if (a[i][j] > 0)
//					cout << a[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	*/
//#pragma endregion
//	
//	#pragma region 문자열 거꾸로 출력
//	/*//보너스 문제 -다차원배열 이용 문자열 3개이상 입력받아 문자열 거꾸로 출력
//
//	char s[2][2];
//	for (int k = 0; k < 2; k++)
//	{
//		for (int l = 0; l < 2; l++)
//		{
//			cin >> s[k][l];
//		}
//	}
//	for (int k = 1; k >= 0; k--)
//	{
//		for (int l = 1; l >= 0; l--)
//		{
//			cout << s[k][l] << endl;
//		}
//	}
//	*/
//#pragma endregion
//
//	//cout << Gauss(100) << endl;	
//
//	/*int n = 0;
//	cin >> n;
//	cout << "1부터 n까지의 곱 : " << Factorial(n);*/
//
//
//	//cout << NoGauss(100);
//
//	/*int max = 0;
//	cin >> max;
//	cout << NoFactorial(max);*/
//
//	/*int a = 0;
//	cin >> a;
//	cout << NoGauss2(a);*/
//
//	/*int d = 0;
//	cin >> d;
//	cout << Bonus2(d);*/
//
//	/*int i;
//	for (i = 1; i < 16; i++)
//	{
//		cout << Fibonacci(i) << endl;
//	}*/
//
//	//HanoiTower(3, 'A', 'B', 'C');
//
//	/*int number[MAX_SIZE] = { 0 };
//	int counter = 0;
//
//	int resultNumber = 0;
//	int resultIndex = 0;
//
//
//	GetNumbers(number);
//
//	resultNumber = Max(number, 0, MAX_SIZE);
//
//	resultIndex = MaxPos(number, 0, MAX_SIZE);
//
//	PrintArray(number, resultIndex, resultNumber);*/
//	/*int b;
//	cin >> b;
//	if (b > 999)
//		cout << Bonus1(b);
//	else
//		cout << "4자리수 이상의 수를 입력해주세요" << endl;*/
//
//	/*int i = 2, j = 1;
//	cout << Bonus2(i, j) << endl;*/
//
//	/*int a;
//	cin >> a;
//	cout << NMinus(a);*/
//	
//	/*int a, b;
//	cin >> a;
//	cin >> b;
//	Bonus(a, b);*/
//
//	int a, b;
//	cin >> a;
//	cin >> b;
//	Bonus2(a,b);
//
//	return 0;
//}
#pragma endregion



