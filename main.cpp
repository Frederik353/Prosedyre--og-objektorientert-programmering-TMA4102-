#include "std_lib_facilities.h"
#include <iostream>
#include <vector>
#include <sstream>

// oppgave a

int sumArray(const int *arr, size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

std::vector<int> inputIntagers()
{
    std::vector<int> intagers;
    std::string input;
    int value;

    cout << "skriv inn heltall separert med mellomrom: ";

    std::getline(std::cin, input);

    std::istringstream iss(input);
    while (iss >> value)
    {
        intagers.push_back(value);
    }

    return intagers;
}

int inputAndSumIntagers()
{
    std::vector<int> intagers = inputIntagers();
    cout << "du skrev inn:";
    for (std::vector<int>::size_type i = 0; i < intagers.size(); i++)
    {
        cout << intagers[i] << " ";
    }
    cout << endl;
    int sum = sumArray(intagers.data(), intagers.size());
    cout << "summen av tallene er: " << sum << endl;

    return sum;
}

// oppgave b
int inputAndSumIntagers2()
{
    int sum = 0;
    int input;
    bool run = true;
    while (run)
    {
        cout << "skriv inn et heltall: ";
        cin >> input;
        if (input == 0)
        {
            run = false;
        }
        else
        {
            sum += input;
        }
    }
    cout << "summen av tallene er: " << sum << endl;

    return sum;
}

// oppgave d
double inputDouble()
{
    double value;
    cout << "skriv inn et desimaltall: ";
    cin >> value;

    return value;
}

// oppgave e
double convertCurrency(double conversionRate, double value)
{
    return value * conversionRate;
}

double inputEuroToNOKandPrint()
{
    double value = inputDouble();
    double res = convertCurrency(9.75, value);
    cout << value << " euro er " << res << " NOK" << endl;
    return res;
}

int main()
{
    // oppgave a
    // gjorde en litt annen løsning enn det som var i oppgaven
    cout << " ------ Oppgave a ------" << endl;
    inputAndSumIntagers();

    // oppgave b
    cout << " ------ Oppgave b ------" << endl;
    inputAndSumIntagers2();

    // oppgave c
    // hvis man vet på forhånd hvor mange tall man skal summere funker for loop bra hvis ikke er while loop bedre

    // oppgave d
    cout << " ------ Oppgave b ------" << endl;
    inputEuroToNOKandPrint();

    // oppgave f
    // fordi valutta regninger ofte inneholder desimaltall, det sagt foretrekker banker og finansinstitusjoner bb ofte å bruke heltall for pengeverdier av grunner knyttet til nøyaktighet og sikkerhet. Heltallsaritmetikk er nøyaktig og unngår rundingsfeil som kan oppstå med flyttall, noe som er avgjørende for å forebygge svindel og feil i finansielle transaksjoner. I tillegg gjør bruk av heltall sporing og revisjon av finansielle operasjoner mer håndterbart, siden det gir en mer direkte og forutsigbar måte å representere pengeverdier på. Dette speiler også hvordan fysiske valutaenheter, som cent eller øre, fungerer, og bidrar til konsistens i håndteringen av penger både i digitale og fysiske formater.

    return 0;
}