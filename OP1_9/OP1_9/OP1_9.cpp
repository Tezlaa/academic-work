﻿#include <iostream>
using namespace std;

int main()
{
    int i, hm;

    cout << "Write how many elements you want in the array:"; cin >> hm;

    float* a = new float[hm];

    for (i = 0; i < hm; i++)
    {
        a[i] = -20 +rand() % 30;
        cout << a[i] << " ";
    }
    
    for (i = 0; i < hm; i++) 
    {
        if (a[i] > 0)
        {
            for (;i < hm; i++)
            {
                a[i] = a[i] - 0.5;
                cout << endl << i << ": " << a[i] << " ";
            }
            break;
        }
        
    }

    return 0;
}
