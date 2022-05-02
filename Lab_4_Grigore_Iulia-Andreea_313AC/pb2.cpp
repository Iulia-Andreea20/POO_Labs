#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

class Tiger
{
    public:
        static string dad;
        Tiger()
        {
            cout << "Tata este " << dad;
        }
};
class Lion
{
    public:
        static string mom;
        Lion()
        {
            cout << " si mama este " << mom << "!";
        }
};

class Liger: public Tiger, public Lion 
{
    public:
        Liger()
        {
            cout << " Sunt un ligru!" << endl;
        }
};

string Tiger::dad = "tigru";
string Lion::mom = "leu";
int main()
{

    Liger liger1;

    cout << "Sunt copilul unui ";
    cout<< liger1.dad << " si al unui "<< liger1.mom << "." << endl;

    return 0;
}