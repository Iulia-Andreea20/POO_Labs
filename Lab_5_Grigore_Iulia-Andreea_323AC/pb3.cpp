#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

class SecretWords
{
    private:
        string word1;
        string word2;
        string aux;
    
    public:
        SecretWords()
        {
            this->word1 = "Black";
            this->word2 = "Friday";
        }
        void operator +()
        {
            this->aux = this->word1 + this->word2;
        }

        void getWords()
        {
            cout << "\nCuvintele separate sunt: " << this->word1 << " si " << this->word2 << endl;
        }
        void getFinalString()
        {
            cout << "Cuvintele concatenate sunt: " << this->aux << endl;
        }

};

int main()
{
    SecretWords cuv;

    cuv.getWords();
    +cuv;
    cuv.getFinalString();


    return 0;
}