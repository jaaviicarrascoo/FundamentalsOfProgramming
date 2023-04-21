#include <iostream>
using namespace std;

int main()
{
    int seconds, hours, minutos, seg_remain;
    cout << "Input seconds: ";
    cin >> seconds;

    hours = seconds / 3600; // 1 hora = 3600 segundos
    seg_remain = seconds % 3600;
    minutos = seg_remain / 60; // 1 minuto = 60 segundos
    seg_remain = seg_remain % 60;

    cout << "The time is: " << hours << " hours, " << minutos << " minutes, " << seg_remain << " seconds." << endl;

    return 0;
}
