//20211 손환주
#include <iostream>

using namespace std;

//int a = 0;

#pragma region 팩토리얼
/*int Factorial(int n) {

	if (n == 0) {
		return 1;
	}
	else {
		return (n * Factorial(n - 1));
	}
	
}*/
#pragma endregion


#pragma region 가우스
/*int Gauss(int max) {
	return ((1 + max) * max) / 2;
}*/
#pragma endregion


/*int NoGauss(int sum) {

	a += sum;
	sum--;

	if (sum == 0) {
		return a;
	}
	else {
		return NoGauss(sum);
	}
}*/

#pragma region 피보나치
int Fibonacci(int n) {
	if(n == 1 || n == 2) {
		return 1;
	}
	else {
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}

}
#pragma endregion

#pragma region 하노이탑
void HanoiTower(int num, char from, char by, char to) {
	if (num == 1) {
		cout << "원반 1을" << from << "에서" << to << "로 이동" << endl;
	}
	else {
		HanoiTower(num - 1, from, to, by);

		cout << "원반" << num << "을" << from << "에서" << to << "로 이동" << endl;

		HanoiTower(num - 1, by, from, to);
	}
}
#pragma endregion


/*int NoGauss2(int sum) {

	a += sum;
	sum--;

	if (sum == 0) {
		return a;
	}
	else {
		return NoGauss2(sum);
	}
}*/

//int c = 1;

/*int Bonus2(int a)
{
	//ex: 258 -> 852
	if (a == 0) {
		return 0;
	}
	else {
		int b = Bonus2(a / 10) + (a % 10) * c;
		c *= 10;
		return b;
	}
}*/

/*int NoFactorial(int max) {
	// cin >> n --> 1-n까지의 곱  cin >> 4    1*2*3*4
	int b = 1;

	for (int i = 1; i < max + 1; i++)
	{
		b = b * i;
	}
	return b;

}*/


//#define MAX_SIZE 5
//
//void GetNumbers(int number[MAX_SIZE])
//{
//	int counter = 0;
//	int numberInput = 0;
//	int loop = 1;
//
//	while (counter < MAX_SIZE)
//	{
//		loop = 1;
//
//		while (loop == 1)
//		{
//			cout << "배열에 저장할 " << counter + 1 << " 번째 정수를 입력하시오" << endl;
//			fflush(stdin);
//
//			cin >> numberInput;
//
//			if (numberInput >= 0)
//			{
//				number[counter] = numberInput;
//				++counter;	loop = 0;
//			}
//			else
//			{
//				cout << "값은 0 이상이여야 됨" << endl;
//				loop = 1;
//			}
//		}
//
//	}
//}
//int Max(int number[], int i, int last)
//{
//	if (i < last)
//	{
//		int MaxN = Max(number, i + 1, last);
//
//		if (number[i] >= MaxN)
//		{
//			return (number[i]);
//		}
//		else
//		{
//			return (MaxN);
//		}
//	}
//
//	else
//	{
//		return(number[i]);
//	}
//}
//int MaxPos(int number[], int i, int last)
//{
//	if (i < last)
//	{
//		int j = MaxPos(number, i + 1, last);
//
//
//		if (number[i] >= number[j])
//		{
//			return(i);
//		}
//		else
//		{
//			return(j);
//		}
//	}
//	else
//	{
//		return(i);
//	}
//
//}
//void PrintArray(int number[], int resultIndex, int resultNumber)
//{
//	int counter = 0;
//
//	cout << "현재 배열에 저장된 값" << endl;
//
//	while (counter < MAX_SIZE)
//	{
//		cout << number[counter] << endl;
//		++counter;
//	}
//	cout << "최댓값은 " << resultNumber << "이다" << endl;
//}

//int s = 0;
//
//int Bonus1(int n) {
//	int c = 0;
//
//	if (n < 10)
//	{
//		c = n;
//		s += n;
//		return s;
//	}
//	else
//	{
//		c = n % 10;
//		s += c;
//		return Bonus1(n / 10);
//	}
//}

//int Bonus2(int num, int num2)
//{
//	if (num <= 9) {
//		
//		cout << num << "*" << num2 << "=" << num * num2 << endl;
//		if (num2 < 9) {
//			Bonus2(num, num2 + 1);
//		}
//		else {
//			return Bonus2(num + 1, 1);
//		}
//	}
//}

//필수문제 
int NMinus(int n) {
	cout << n << endl;
	if (n == 2) {
		return 1;
	}
	else {
		return NMinus(n - 1);
	}
}
//보너스문제
int Bonus(int a, int b) {
	if (a < b) {
		if (a % 2 != 0) {

			if (a < b - 2) {
				cout << a + 2 << endl;
				return Bonus(a + 2, b);
			}
			else {
				return a;
			}
		}
		else {
			a++;
			cout << a << endl;
			if (a < b - 2) {
				cout << a + 2 << endl;
				return Bonus(a + 2, b);
			}
			else {
				return a;
			}
		}
	}
	else {
		if (b % 2 != 0) {

			if (b < a - 2) {
				cout << b + 2 << endl;
				return Bonus(a, b+2);
			}
			else {
				return b;
			}
		}
		else {
			b++;
			cout << b << endl;
			if (b < a - 2) {
				cout << b + 2 << endl;
				return Bonus(a, b+2);
			}
			else {
				return b;
			}
		}
	}
	
}
//보너스문제 2
int Bonus2(int a, int b) {
	if (a < b) {
		if (a % 2 == 0) {

			if (a < b - 2) {
				cout << a + 2 << endl;
				return Bonus2(a + 2, b);
			}
			else {
				return a;
			}
		}
		else {
			a++;
			cout << a << endl;
			if (a < b - 2) {
				cout << a + 2 << endl;
				return Bonus2(a + 2, b);
			}
			else {
				return a;
			}
		}
	}
	else {
		if (b % 2 == 0) {
			if (b < a - 2) {
				cout << b + 2 << endl;
				return Bonus2(a, b + 2);
			}
			else {
				return a;
			}
		}
		else {
			b++;
			cout << b << endl;
			if (b < a - 2) {
				cout << b + 2 << endl;
				return Bonus2(a, b + 2);
			}
			else {
				return b;
			}
		}
	}
	
}


int main() {

	#pragma region 주민등록번호관련
	/*//주민등록번호관련

	//000000-0000000
	char arr[14];
	int arr2[11] = { 8,12,15,18,25,34,39,47,54,66,90 };

	cout << "주민등록번호 -빼고 작성" << endl;
	cin >> arr;

	//성별
	if (arr[6] % 2 == 0)
	{
		cout << "여자" << endl;
	}
	else
	{
		cout << "남자" << endl;
	}

	//나이,출생연도
	int year = (arr[0] - 48) * 10 + (arr[1] - '0');
	year += arr[6] <= '2' ? 1900 : 2000;
	cout << year << endl;
	cout << 2021 - year + 1 << endl;

	//출생지역
	string t;
	int b = (arr[7] - 48) * 10 + (arr[8] - '0');
	for (int i = 0; i < 11; i++)
	{
		if (b <= arr2[i])
		{
			if (i == 0) t = "서울";
			else if (i == 1) t == "부산";
			else if (i == 2) t == "인천";
			else if (i == 3) t = "경기도 주요 도시";
			else if (i == 4) t = "그 밖의 경기도";
			else if (i == 5) t = "강원도";
			else if (i == 6) t = "충청북도";
			else if (i == 7) t = "충청남도";
			else if (i == 8) t = "전라북도";
			else if (i == 9) t = "전라남도";
			else if (i == 10) t = "경상도";
			break;
		}
	}
	cout << t << endl;

	//유효성 검사
	const int tab[] = { 2,3,4,5,6,7,8,9,2,3,4,5 };
	int M = 0;
	int c;
	for (int i = 0; i < 12; i++)
	{
		M += (arr[i] - '0') * tab[i];
	}


	int d = (arr[12] - '0');
	if ((11 - (M % 11)) % 10 == d)
	{
		cout << "유효" << endl;
	}
	else
	{
		cout << "유효하지않음" << endl;
	}*/
	#pragma endregion 
	
	#pragma region 파스칼의 삼각형
	/*
	//파스칼의 삼각형
	int a[10][10] = { 0, };
	int i, j;
	for (i = 0; i < 10; i++)
	{
		a[i][0] = 1;

		for ( i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (j > 0 && i > 0)
					a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
				if (a[i][j] > 0)
					cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	*/
#pragma endregion
	
	#pragma region 문자열 거꾸로 출력
	/*//보너스 문제 -다차원배열 이용 문자열 3개이상 입력받아 문자열 거꾸로 출력

	char s[2][2];
	for (int k = 0; k < 2; k++)
	{
		for (int l = 0; l < 2; l++)
		{
			cin >> s[k][l];
		}
	}
	for (int k = 1; k >= 0; k--)
	{
		for (int l = 1; l >= 0; l--)
		{
			cout << s[k][l] << endl;
		}
	}
	*/
#pragma endregion

	//cout << Gauss(100) << endl;	

	/*int n = 0;
	cin >> n;
	cout << "1부터 n까지의 곱 : " << Factorial(n);*/


	//cout << NoGauss(100);

	/*int max = 0;
	cin >> max;
	cout << NoFactorial(max);*/

	/*int a = 0;
	cin >> a;
	cout << NoGauss2(a);*/

	/*int d = 0;
	cin >> d;
	cout << Bonus2(d);*/

	/*int i;
	for (i = 1; i < 16; i++)
	{
		cout << Fibonacci(i) << endl;
	}*/

	//HanoiTower(3, 'A', 'B', 'C');

	/*int number[MAX_SIZE] = { 0 };
	int counter = 0;

	int resultNumber = 0;
	int resultIndex = 0;


	GetNumbers(number);

	resultNumber = Max(number, 0, MAX_SIZE);

	resultIndex = MaxPos(number, 0, MAX_SIZE);

	PrintArray(number, resultIndex, resultNumber);*/
	/*int b;
	cin >> b;
	if (b > 999)
		cout << Bonus1(b);
	else
		cout << "4자리수 이상의 수를 입력해주세요" << endl;*/

	/*int i = 2, j = 1;
	cout << Bonus2(i, j) << endl;*/

	/*int a;
	cin >> a;
	cout << NMinus(a);*/
	
	/*int a, b;
	cin >> a;
	cin >> b;
	Bonus(a, b);*/

	int a, b;
	cin >> a;
	cin >> b;
	Bonus2(a,b);

	return 0;
}