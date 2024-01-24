#include "std_lib_facilities.h"

// Funksjonen heter 'add', den tar inn to heltall, legger sammen
// tallene og returnerer resultatet, som er et heltall
int add(int a, int b)
{
    return a + b;
}

// Funksjonen tar ikke inn noe og returnerer ingenting
// Input kommer fra brukeren av programmet: cin,
// og output skrives til brukeren av programmet: cout.
void inputIntegersAndPrintProduct()
{
    int x = 0;
    int y = 0;
    cout << "Skriv inn to heltall: ";
    cin >> x;
    cin >> y;
    int product = x * y;
    cout << x << " * " << y << " = " << product << endl;
}

// oppgave b
void inputAndPrintIntager()
{
    int x;
    cout << "Skriv inn et heltall: ";
    cin >> x;
    cout << "Du skrev: " << x << endl;
}

// oppgave c
int inputIntager()
{
    int x;
    cout << "Skriv inn et heltall: ";
    cin >> x;
    return x;
}

// opppgave d
void inputIntagersAndPrintSum()
{
    int x = inputIntager();
    int y = inputIntager();
    int sum = x + y;
    cout << "Summen av tallene er:" << sum << endl;
}

// oppgave e
// I deloppgave d) valgte vi å bruke inputInteger i stedet for inputAndPrintInteger fordi vi trenger å bruke de innskrevne tallene for å beregne summen. inputInteger returnerer det innskrevne tallet, noe som gjør det mulig å lagre og videre bruke disse verdiene noe InputAndPrintIntager ikke gjør.

// oppgave f
bool isOdd(int number)
{
    return number % 2 != 0;
}

int main()
{
    cout << "Velg oppgave (b-e): ";
    char option;
    cin >> option;

    bool runAll = false;
    cout << "Vil du kjøre alle oppgaver fra valgt oppgave? (ja/nei): ";
    string response;
    cin >> response;
    if (response == "ja")
    {
        runAll = true;
    }

    switch (option)
    {
    case 'b':
    {
        cout << " ------ Oppgave b ------" << endl;
        inputAndPrintIntager();
        if (!runAll)
            break;
    }
    case 'c':
    {
        cout << " ------ Oppgave c ------" << endl;
        int x = inputIntager();
        cout << "Du skrev: " << x << endl;
        if (!runAll)
            break;
    }
    case 'd':
    {
        cout << " ------ Oppgave d ------" << endl;
        inputIntagersAndPrintSum();
        if (!runAll)
            break;
    }
    case 'e':
    {
        cout << " ------ Oppgave e ------" << endl;
        for (int i = 0; i < 16; i++)
        {
            cout << (isOdd(i) ? "true" : "false") << endl;
        }
        if (!runAll)
            break;
    }
    default:
    {
        cout << "Ugyldig valg" << endl;
        break;
    }
    }

    // int sumOfOneAndTwo = add(1, 2);
    // cout << "1 + 2 = " << sumOfOneAndTwo << endl;
    // cout << "2 + 2 = " << add(2, 2) << endl;
    // inputIntegersAndPrintProduct();
    return 0;
}
