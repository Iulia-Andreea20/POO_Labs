#include <stdio.h>
#include <iostream>
#include<cstring>
#include<string.h>

using namespace std;

class Volume
{
    public:

        //Message
        void volume()
        {
            cout << "\nExista mai multe metode de calculat volume" << endl;
        }

        //Cube
        void volume(int l)
        {
            cout << "Volumul cubului este: " << l * l * l << endl;
        }

        //Sphere
        void volume(string r)
        {
            float aux = stoi(r);
            
            cout << "Volumul sferei este: " << (float)(aux * aux * aux * 3.14 * 4)/3 << endl;
        }

        //Pyramid
        void volume(int l, int h)
        {
            cout << "Volumul piramidei patrulatere este: " << (float)(l * l * h)/3 << endl;
        }
};

int main()
{
    Volume cub, sfera, piramida;

    cub.volume();
    cub.volume(2);
    sfera.volume("2");
    piramida.volume(2, 4);


    return 0;
}