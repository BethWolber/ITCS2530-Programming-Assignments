//including iostream for input/output, including string to store user's input, using namespace std; to make code cleaner
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    //new banner
    cout << "Welcome! This program was created to help keep track of information related to cross stitching as a hobby!" << endl;


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

    //new input #1
    int progress;
    cout << "How many pieces are you currently working on? ";
    cin >> progress;
    cout << endl;

    //new input #2
    double price;
    cout << "How much do you currently pay for each skein of thread? ";
    cin >> price;
    cout << endl;

    //new input #3
    string favorite;
    cout << "What is your favorite pattern you have completed so far? ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, favorite);
    cout << endl;

    //new input #4, derived value
    string time;
    cout << "About how long has it been since you first started cross stitching? ";
    getline (cin, time);
    cout << endl;

    //creating a summary table to display inputs just given
    cout << setw(1) << "favorite pattern: ";
    cout << setw(2) << favorite << endl;
    cout << setw(3) << "number of pieces currently working on: ";
    cout << setw(4) << progress << endl;
    cout << setw(5) << "cost of skein: ";
    cout << setw(6) << price << endl;
    cout << setw(7) << "how long you've been doing cross stitching: ";
    cout << setw(8) << time << endl;
}