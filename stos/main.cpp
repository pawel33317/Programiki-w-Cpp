#include <stack>
#include <iostream>
#include <conio.h>

int main()
{
    std::stack < int > stosLiczb;

    int liczba = 0;
    do
    {
        std::cout << "Podaj liczbe (0 - konczy wprowadzanie liczb): ";
        liczba = 0;
        std::cin >> liczba;
        if( liczba != 0 ) stosLiczb.push( liczba );

    } while( liczba != 0 );

    std::cout << "Liczby zdjete ze stosu: ";
    while( stosLiczb.empty() == false )
    {
        std::cout << stosLiczb.top() << ", ";
        stosLiczb.pop();
    }

    getch();
    return 0;
}
