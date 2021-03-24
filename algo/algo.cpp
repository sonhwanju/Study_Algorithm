//20211 손환주
#include <iostream>

using namespace std;

int a = 0;

//필수 문제
int Factorial(int n) {

	if (n == 0) {
		return 1;
	}
	else {
		return (n * Factorial(n - 1));
	}
	
}



//보너스 문제 1
int Gauss(int max) {
	return ((1 + max) * max) / 2;
}

//보너스 문제 2
int NoGauss(int sum) {

	a += sum;
	sum--;

	if (sum == 0) {
		return a;
	}
	else {
		return NoGauss(sum);
	}
}

//보너스 문제 3
int NoFactorial(int max) {
	// cin >> n --> 1-n까지의 곱  cin >> 4    1*2*3*4
	int b = 1;

	for (int i = 1; i < max + 1; i++)
	{
		b = b * i;
	}
	return b;

}

int main() {

	/*
	//주민등록번호관련

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
	}
	*/
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

	//보너스 문제 -다차원배열 이용 문자열 3개이상 입력받아 문자열 거꾸로 출력

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
	*/


	//cout << Gauss(100) << endl;	

	/*int n = 0;
	cin >> n;
	cout << "1부터 n까지의 곱 : " << Factorial(n);*/


	//cout << NoGauss(100);

	int max = 0;
	cin >> max;
	cout << NoFactorial(max);


	return 0;
}