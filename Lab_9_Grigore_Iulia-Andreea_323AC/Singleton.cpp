#include <iostream>

using namespace std;

/*Pros and Cons
Pros:
    -> Instantiere lenesa, memoria va fi alocata doar la primul apel al functiei getInstance()
    -> Clasa Singleton poate fi derivata si este usor derivabila pentru o aplicatie cu o instanta a clasei derivate

Cons:
    -> Solutia este buna cand avem nevoie doar de o instanta, dar nu si cand avem nevoie de mai multe
    -> Subclasele nu pot beneficia de polimorfism, deoarece metodele statice nu pot fi virtuale


*/
class Singleton
{
    static Singleton *instance;
    int data;

    Singleton()
    {
        data = 0;
    }

    public:
        static Singleton *getInstance()
        {
            if(!instance)
            {
                instance = new Singleton; 
            }

            return instance;
        }

        int getData()
        {
            return this->data;
        }

        void setData(int data)
        {
            this->data = data;
        }
};

Singleton *Singleton::instance = 0;

int main()
{
    Singleton *client = client->getInstance();
    
    cout << "Logging in: " << client->getData() << " %" << endl;

    client->setData(100);

    cout << "Logging in: " << client->getData() << " %" << endl;


    return 0;
}