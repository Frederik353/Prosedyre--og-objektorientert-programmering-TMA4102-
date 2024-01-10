#include <iostream>
#include <string>

using namespace std;

// oppgave a
int maxOfTwo(int a, int b)
{
    if (a > b)
    {
        cout << "A is greater than B" << endl;
        return a;
    }
    else
    {
        cout << "B is greater than or equal to A" << endl;
        return b;
    }
}

// oppgave c
int fibonacci(int n)
{
    int a = 0;
    int b = 1;
    cout << "The first " << n << " fibbonacci numbers:" << endl;
    for (int x = 1; x < n + 1; x++)
    {
        cout << x << ":" << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "-----" << endl;
    return b;
}

// oppgave d
int squareNumverSum(int n)
{
    int totalSum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        totalSum += i * i;
        cout << i * i << endl;
    }
    cout << totalSum << endl;
    return totalSum;
}

// oppgave e
void triangleNumbersBelow(int n)
{
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while (acc < n)
    {
        cout << acc << endl;
        acc += num;
        num++;
    }
    cout << endl;
}

// oppgave f
bool isPrime(int n)
{
    for (int j = 2; j < n; j++)
    {
        if (n % j == 0)
        {
            return false;
        }
    }
    return true;
}

// oppgave g
void naivePrimeNumberSearch(int n)
{
    for (int number = 2; number < n; number++)
    {
        if (isPrime(number))
        {
            cout << number << " is prime" << endl;
        }
    }
}

// oppgave h
void inputANdPrintNameAndAge()
{
    string name;
    int age;
    cout << "Skriv inn et navn: ";
    cin >> name;

    cout << "skriv inn alderen til " << name << ": ";
    cin >> age;
    cout << name << " er " << age << " aar gammel.";
}

int main()
{
    // oppgave a-c
    cout << "Oppgave) a-c" << endl;
    cout << maxOfTwo(5, 6) << endl;
    cout << endl;

    // oppgave c
    cout << "Oppgave) c" << endl;
    fibonacci(10);
    cout << endl;

    // oppgave d
    cout << "Oppgave) d" << endl;
    cout << squareNumverSum(6) << endl;
    cout << endl;

    // oppgave e
    cout << "Oppgave) e" << endl;
    triangleNumbersBelow(20);

    // oppgave f
    cout << "Oppgave) f" << endl;
    int num = 13;
    cout << num << endl;
    if (isPrime(num))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << endl;

    // oppgave g
    cout << "Oppgave) g" << endl;
    naivePrimeNumberSearch(20);
    cout << endl;

    // oppgave h
    cout << "Oppgave) h" << endl;
    inputANdPrintNameAndAge();

    return 0;
}