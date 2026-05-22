//including iostream for input/output, including string to store user's input, using namespace std; to make code cleaner
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //first question, get pattern
    string pattern;
    cout << "What cross stitch pattern are you currently working on? ";
    cin >> pattern;
    cout << endl;

    //second question, ask amount of days
    string days;
    cout << "How many days have you been working on that pattern? ";
    cin >> days;
    cout << endl;

    //third question, ask for number of stitches
    string stitch;
    cout << "How many stitches have you made so far? ";
    cin >> stitch;
    cout << endl;

    cout << "You have been working on a " << pattern
        << " pattern for " << days
        << " days and have made " << stitch
        << " stitches so far. Nice work!" << endl;
}