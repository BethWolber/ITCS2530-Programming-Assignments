//including iostream for input/output, including string to store user's input, using namespace std; to make code cleaner
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <windows.h>
using namespace std;
 
// ------------------- MEMBERSHIP STRUCT -------------------
struct clubMembership {
    string name;
    int number;
    double memberDonation;
}

// ------------------- ENUM FOR HOBBY DIFFICULTY -------------------
enum Difficulty { EASY, INTERMEDIATE, HARD };

// ------------------- FUNCTION USING ARRAY -------------------
double averagePrices(const double prices[], int size)
{
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += prices[i];
    }
    return total / size;
}

// Grab user input for array 
void fillPrices(double prices[], int size)
{
    for (int i = 0; i < size; i++)
    {
        double value;
        cout << "Enter price #" << (i + 1) << ": ";

        while (!(cin >> value) || value <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid price. Enter a positive number: ";
        }

        prices[i] = value;
    }
}

//function to display banner
void PrintBanner()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    //new banner
    SetConsoleTextAttribute(h, 13);
    cout << "Welcome! This program was created to help keep track of information related to cross stitching as a hobby!" << endl;

    cout << "\n";
}

//function to change console color
void ChangeConsoleColor()
{
    int color;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "If you would like to change the color of the text, please enter your preferred color number here 1-15 (current color is 13): " << endl;
    cin >> color;
    SetConsoleTextAttribute(h, color);
}

//function to collect and validate inout
void PatternProgress()
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

    cout << "\n";

}

//function to display the menu
void MenuDisplay(int percent, double price)
{
    char menu{};
    cout << "Please choose an option- A: a list of unfinished patterns, B: current progress, or C: how much you currently spend on each skein of thread." << endl;
    cin >> menu;
    switch (menu)
    {
    case 'A':
        cout << "Patterns that you have started but not yet finished include: cats, flowers, a stack of books, and a tiger." << endl;
        break;
    case 'B':
        cout << "You are currently " << percent << "% through your current project." << endl;
        break;
    case 'C':
        cout << "You are currently paying $" << price << " for each skein of thread." << endl;
        break;
    default:
        cout << "Please choose an option A, B, or C." << endl;
    }
}

//function for a calculation
void ExactPercentage()
{
    double CompletedStitches;
    double TotalStitches;
    double PercentCompleted;
    cout << "How many stitches have you completed so far?" << endl;
    cin >> CompletedStitches;
    cout << "How many stitches are there total in the pattern?" << endl;
    cin >> TotalStitches;
    PercentCompleted = (CompletedStitches * 100) / TotalStitches;
    cout << "You are exactly " << PercentCompleted << "% of the way through your pattern." << endl;
}

int main()
{
    PrintBanner();

    ChangeConsoleColor();

    PatternProgress();

    //new input #1
    int progress;
    cout << "How many pieces are you currently working on? ";
    cin >> progress;
    cout << endl;

    //new input #3
    string favorite;
    cout << "What is your favorite pattern you have completed so far? ";
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    getline(cin, favorite);
    cout << endl;

    //new input #4, derived value
    string time;
    cout << "About how long has it been since you first started cross stitching? ";
    getline (cin, time);
    cout << endl;

    //new input #2, moved down to use with if/else block
    double price;
    cout << "How much do you currently pay for each skein of thread? ";
    cin >> price;
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

    cout << "\n";

    //first if/else block
    int amount;
    cout << "How many embroidery hoops do you buy in a year? ";
    cin >> amount;
    int own;
    cout << "How many embroidery hoops do you already have at home? ";
    cin >> own;
    if (own>=10 && amount >= 10)
        cout << "You have too many embroidery hoops! Make a list of what sizes you have before buying more and ending up with duplicates." << endl;
    else
        cout << "You probably have a reasonable amount of embroidery hoops." << endl;

    cout << "\n";

    ExactPercentage();

    //second if/else block
    int percent;
    cout << "How far into your current project are you percentage-wise? ";
    cin >> percent;
    if (percent > 50)
        cout << "You are more than halfway through your project! Keep up the great work :)" << endl;
    else
        if (percent == 50)
            cout << "You are exactly halfway through your project!" << endl;
        else
            cout << "You are less than halfway through your project. Keep going, and before you know it, it will start to come together!" << endl;

    cout << "\n";

    MenuDisplay(percent, price);

    int StitchesInADay;
    int StitchesInAWeek = 0;
    int stitchArray[7];

    for (int day = 1; day <= 7; day++)
    {
        cout << "Enter the number of stitches you completed today: ";
        cin >> StitchesInADay;
        cout << endl;

        StitchesInAWeek += StitchesInADay;
        stitchArray[day - 1] = StitchesInADay;

        cout << "Stored: " << stitchArray[day - 1] << endl;
    }

    enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };

    for (int i = MON; i <= SUN; i++)
    {
        cout << "Day " << (i + 1) << ": " << stitchArray[i] << endl;
    }

    cout << "On average, you complete " << StitchesInAWeek / 7 << " stitches a day." << endl;

    // ------------------- NEW ARRAY FEATURE -------------------
    const int PRICE_COUNT = 5;
    double priceArray[PRICE_COUNT];

    cout << "\nLet's record the last " << PRICE_COUNT << " thread prices you paid.\n";
    fillPrices(priceArray, PRICE_COUNT);

    double avgPrice = averagePrices(priceArray, PRICE_COUNT);

    cout << "\nAverage thread price: $" << fixed << setprecision(2) << avgPrice << endl;

    // ------------------- ENUM -------------------
    Difficulty level;

    if (avgPrice < 2.00)
        level = EASY;
    else if (avgPrice < 4.00)
        level = INTERMEDIATE;
    else
        level = HARD;

    cout << "\nBased on your average thread price, your hobby difficulty level is: ";

    switch (level)
    {
    case EASY:
        cout << "Easy (budget-friendly hobby!)" << endl;
        break;
    case INTERMEDIATE:
        cout << "Intermediate (moderate cost)" << endl;
        break;
    case HARD:
        cout << "Hard (premium materials!)" << endl;
        break;
    }

    //while loop, condition based
    string status;

    cout << "What is the status of your current project? " << endl;
    cin >> status;

    while (status != "completed")
    {
        cout << "Hopefully, you will finish soon!" << endl;
        cout << "What is the status of your current project? " << endl;
        cin >> status;
    }

    cout << "Yay! You have finished your current project! Time to start a new one :)" << endl;

    //do...while loop, until quit
    int ColorCompleted;
    string answer;

    ColorCompleted = 0;

    do
    {
        cout << "Have you completed a new color?" << endl;
        cin >> answer;

        if (answer == "yes")
        {
            ColorCompleted = ColorCompleted + 1;
            cout << "You have completed " << ColorCompleted << " colors so far." << endl;
        }
    } 
    while (answer == "yes");
    cout << "You completed " << ColorCompleted << " colors total." << endl;
    // ------------------- STORED MEMBERSHIP DATA -------------------
    const int MAX_MEMBERS = 3;
    
    // ------------------- MEMBERSHIP -------------------
    clubMembership member1;
    cout << "Enter name: " << endl;
    cin >> member1.name;
    cout << "Enter phone number: " << endl;
    cin >> member1.number;
    cout << "Make a donation. Enter donation amount: " << endl;
    cin >> member1.memberDonation;
 }