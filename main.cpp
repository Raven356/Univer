#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

bool end_of_Program();
double get_Arguments();
double get_Table(double x);
double get_E();
void print_on_screen(double x1, double x2, double e, double dx);
double check_Argument();
int main()
{
    double x1{}, x2{};
    do
    {
        system("cls");
        cout << "Enter x1 (-1 < x1 < 1)\n";
        do
        {
            x1 = get_Arguments();
            if(x1 == 1)
               cout << "Please enter numbers in allowed interval\n";
        }
        while (x1 == 1);
        cout << "Enter x2(-1 < x2 <= 1 and x2 should be greater than x1)\n";
        do
        {
            x2 = get_Arguments();
            if(x2 <= x1)
                cout << "Please enter x2 that would be greater x1\n";
        }
        while(x2 <= x1);
        cout << "Enter e( 1e-6 <= e <= 1e-3)\n";
        double e{};
        e = get_E();
        double dx{(x2 - x1) / 10};
        cout << "x\t\tAccurate\tBy formula\tAmount of itterations\tDifference\n";
        int cycle{};
        do
        {
            print_on_screen(x1, x2, e, dx);
            x1 += dx;
            cycle++;
        }
        while(x1 <= x2);
        if(cycle != 11)
            print_on_screen(x1, x2, e, dx);
    }
    while(end_of_Program());
    return 0;
}

bool end_of_Program()
{
    cout << "Press y to continue and n to end program\n";
    char choice;
    do
    {
    cin >> choice;
    if(choice != 'y' && choice != 'n')
        cout << "Please choose y or n\n";
    }
    while(choice != 'y' && choice != 'n');
        return choice == 'y';
}

double get_Arguments()
{
    do
    {
        double x{check_Argument()};
        if(x <= -1 || x > 1)
            cout << "Please enter numbers in allowed interval\n";
        else if(x > -1 && x <= 1)
            return x;
    }
    while(true);
}
double get_Table(double x) {return log(x+1);}

double get_E()
{
    do
    {
        double e{check_Argument()};
        if(e < 1e-6 || e > 1e-3)
            cout << "Please enter numbers in allowed interval\n";
        else
            return e;
    }while(true);
}

void print_on_screen(double x1, double x2, double e, double dx)
{
            double n{1};
            double sum{}, form{};
            do
            {
                sum = pow((-1), n + 1) * pow(x1, n) / n;
                n++;
                form += sum;
            }while((fabs(get_Table(x1) - form) > e));
            if(x1 < 0)
                {
                    if(n >= 10)
                    cout << fixed << setprecision(5) << x1 << "\t" << get_Table(x1) << "\t" << form << "\t"
                    << n << "\t\t" << get_Table(x1) - form << endl;
                    else if(x1 < 0 && x1 > -1e-4)
                    cout << fixed << setprecision(5) << x1 << "\t" << get_Table(x1) << "\t\t" << form << "\t"
                    << n << "\t\t\t" << get_Table(x1) - form << endl;
                    else
                    cout << fixed << setprecision(5) << x1 << "\t" << get_Table(x1) << "\t" << form << "\t"
                    << n << "\t\t\t" << get_Table(x1) - form << endl;
                }
            else if(n >= 10)
                    cout << fixed << setprecision(5) << x1 << "\t\t" << get_Table(x1) << "\t\t" << form << "\t\t"
                    << n << "\t\t" << get_Table(x1) - form << endl;
                else
                    cout << fixed << setprecision(5) << x1 << "\t\t" << get_Table(x1) << "\t\t" << form << "\t\t"
                    << n << "\t\t\t" << get_Table(x1) - form << endl;
}
double check_Argument()
{
    double x;
    char c[256];
    do
    {
        cin >> x;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "You entered wrong symbol\n";
            continue;
        }
        fgets(c, 256, stdin);
        if(strlen(c) > 1)
        {
            cout << "There were some wrong symbols , try again please\n";
            continue;
        }
        return x;
    }while(true);
}
