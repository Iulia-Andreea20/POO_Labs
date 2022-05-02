#include<iostream>
#include<ctime>

using namespace std;

class Time
{
    public:
        time_t now;
        struct tm *my_time;
        Time();
        ~Time();
                
};

Time::Time()
    {
        now = time(0);
        my_time = localtime(&now);
    }

Time::~Time()
{
    delete [] my_time;
}


int main()
{
    Time time_obj;


    cout << "Data: "<< time_obj.my_time->tm_mday << "/";
    cout << 1 + time_obj.my_time->tm_mon << "/";
    cout << 1900 + time_obj.my_time->tm_year << endl;
    cout << "Ora: "<< time_obj.my_time->tm_hour << ":";
    cout << time_obj.my_time->tm_min << ":";
    cout << time_obj.my_time->tm_sec << endl;


    return 0;
}