#include<iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Money
{
    public:
        static int AmountOver50Count;
        int Amount;
    //!!Sumele sunt generate random la fiecare rulare a programului, de aceea,
    //  datele din screenshot n-o sa corespunda cu datele de la o rulare ulterioara
    Money()
    {
        this->Amount = rand()%101;
        
        if( Amount > 50)
            AmountOver50Count++;
    }

    static int getCount()
    {
        return AmountOver50Count;
    }
};

int Money::AmountOver50Count = 0;

int main()
{

    cout << "Valoarea contorului initial: " << Money::getCount() << endl << "\n";

    srand(time(0));
    Money amount1;
    Money amount2;
    Money amount3;
    Money amount4;
    Money amount5;


    cout << "Prima suma: " << amount1.Amount<<endl;
    cout << "A doua suma: " << amount2.Amount<<endl;
    cout << "A treia suma: " << amount3.Amount<<endl;
    cout << "A patra suma: " << amount4.Amount<<endl;
    cout << "A cincea suma: " << amount5.Amount<<endl;

    cout <<"\nTotalul sumelor peste 50: "<< Money::getCount() << endl;



    return 0;
}