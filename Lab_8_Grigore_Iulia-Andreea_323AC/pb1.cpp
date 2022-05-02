#include <iostream>
#include<ctype.h>
#include <string>
#include <string.h>


using namespace std;

template <class Type1, class Type2>

class MyVariables
{
    Type1 a;
    Type2 b;
    public:
        MyVariables(Type1 first, Type2 second)
                                                    
        {
            a = first;
            b = second;
        }

        void concatenation(char a, char b)
        {
            
            string ab = std::string(1,a) + b;
            cout << "Sirul concatenat este: " << ab << endl;
        }

    void seeType()
    {
    
        if((isdigit(a) || isalpha(a)) && (isdigit(b) || isalpha(b)))
        {
            concatenation(a, b);

        }
        else if(!isdigit(a) && !isdigit(b))
        {
            char a_ch, b_ch;
            
            a_ch = '0' + a;
            b_ch = '0' + b;
            concatenation(a_ch, b_ch);
            
        }
        else if(!isdigit(a) && isdigit(b))
        {
            char a_ch;
            
            a_ch = '0' + a;
            concatenation(a_ch, b);   
        }
        else if((isdigit(a) || isalpha(a)) && (!isdigit(b) || !isalpha(b)))
        {
            char b_ch;
            
            b_ch = '0' + b;
            concatenation(a, b_ch);
        }

    }
    
};

int main()
{
    MyVariables <char, char> test1('1', '2');
    MyVariables <int, int> test2(1, 2);
    MyVariables <int, char> test3(1, '2');
    MyVariables <char, int> test4('1', 2);

    cout << "Cazul <char, char>: \n\t";
    test1.seeType();

    cout << "Cazul <int, int>: \n\t";
    test2.seeType();

    cout << "Cazul <int, char>: \n\t";
    test3.seeType();

    cout << "Cazul <char, int>: \n\t";
    test4.seeType();

    return 0;

}