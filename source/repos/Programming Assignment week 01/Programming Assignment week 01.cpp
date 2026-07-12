#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <windows.h>
#include <fstream>
using namespace std;

void MenuDisplay(int percent, double price);
void ChangeConsoleColor();


// ------------------- MEMBERSHIP STRUCT -------------------
struct clubMembership {
    string name;
    int number;
    double memberDonation;
};

// ------------------- ENUM FOR HOBBY DIFFICULTY -------------
enum Difficulty { EASY, INTERMEDIATE, HARD };

// ------------------- STITCH SESSION STRUCT -------------------
struct stitchSession {
    string date;
    int stitches;
    Difficulty level;
};

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

// ------------------ FUNCTION FOR STRUCT ------------------ 
void FillSession(stitchSession& session)
{
    cout << "Enter session date: ";
    cin >> session.date;

    cout << "Enter stitch completed: ";
    cin >> session.stitches;

    int lvl;
    cout << "Enter difficulty (0=Easy, 1=Intermediate, 2=Hard): ";
    cin >> lvl;

    session.level = static_cast<Difficulty>(lvl);
}

void PrintSession(const stitchSession& session)
{
    cout << "Date: " << session.date << endl;
    cout << "Stitches: " << session.stitches << endl;

    cout << "Difficulty: ";
    switch (session.level)
    {
    case EASY:
        cout << "Easy";
        break;
    case INTERMEDIATE:
        cout << "Intermediate";
        break;
    case HARD:
        cout << "Hard";
        break;
    }
}

double AverageSessionStitches(const stitchSession sessions[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
        total += sessions[i].stitches;

    return static_cast<double>(total) / size;
}

// ------------------- CLASS -------------------
class CrossStitchTracker
{
private:
    static const int SESSION_COUNT = 3;
    stitchSession sessions[SESSION_COUNT];
    int sessionIndex;

    static const int PRICE_COUNT = 5;
    double priceArray[PRICE_COUNT];

public:
    // Constructor
    CrossStitchTracker()
    {
        sessionIndex = 0;
        for (int i = 0; i < SESSION_COUNT; i++)
        {
            sessions[i].date = "";
            sessions[i].stitches = 0;
            sessions[i].level = EASY;
        }
        for (int i = 0; i < PRICE_COUNT; i++)
            priceArray[i] = 0.0;
    }

    // Add a stitching session
    void addSession()
    {
        if (sessionIndex >= SESSION_COUNT)
        {
            cout << "Session limit reached!" << endl;
            return;
        }

        cout << "\n--- Enter Stitching Session " << (sessionIndex + 1) << " ---\n";
        FillSession(sessions[sessionIndex]);
        sessionIndex++;
    }

    // Display all sessions
    void showSessions() const
    {
        cout << "\n--- Stitching Session Summary ---\n";
        for (int i = 0; i < sessionIndex; i++)
        {
            PrintSession(sessions[i]);
            cout << endl;
        }
    }

    // Compute average stitches
    double computeAverageStitches() const
    {
        if (sessionIndex == 0)
            return 0.0;

        return AverageSessionStitches(sessions, sessionIndex);
    }

    // Fill price array
    void fillPriceArray()
    {
        cout << "\nLet's record the last " << PRICE_COUNT << " thread prices you paid.\n";
        fillPrices(priceArray, PRICE_COUNT);
    }

    double computeAveragePrice() const
    {
        return averagePrices(priceArray, PRICE_COUNT);
    }

    // Show menu
    void showMenu(int percent, double price)
    {
        MenuDisplay(percent, price);
    }

    // Change console color
    void changeColor()
    {
        ChangeConsoleColor();
    }

    // Save report to file
    void saveReportToFile(const string& filename) const
    {
        ofstream out(filename);
        if (!out)
        {
            cout << "Error opening file!" << endl;
            return;
        }

        out << "--- Cross Stitch Report ---\n\n";

        for (int i = 0; i < sessionIndex; i++)
        {
            out << "Session " << (i + 1) << ":\n";
            out << "Date: " << sessions[i].date << "\n";
            out << "Stitches: " << sessions[i].stitches << "\n";

            out << "Difficulty: ";
            switch (sessions[i].level)
            {
            case EASY: out << "Easy"; break;
            case INTERMEDIATE: out << "Intermediate"; break;
            case HARD: out << "Hard"; break;
            }
            out << "\n\n";
        }

        out << "Average stitches per session: " << computeAverageStitches() << "\n";

        out.close();
        cout << "Report saved to " << filename << endl;
    }
};

//function to display banner
bool PrintBanner()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "Welcome! This program was created to help keep track of information related to cross stitching as a hobby!" << endl;

    bool hasMembership;
    cout << "Do you have a membership? (1=true, 0=false): ";
    cin >> hasMembership;

    if (hasMembership)
    {
        clubMembership member;
        cout << "Enter name: ";
        cin >> member.name;
        cout << "Enter phone number: ";
        cin >> member.number;
        cout << "Enter donation amount: ";
        cin >> member.memberDonation;

        cout << "Thanks for being a member, " << member.name << "!" << endl;
    }
    else
    {
        char choice;
        cout << "Would you like to create a membership? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            clubMembership newMember;
            cout << "Enter your name: ";
            cin >> newMember.name;
            cout << "Enter your phone number: ";
            cin >> newMember.number;
            cout << "Enter donation amount: ";
            cin >> newMember.memberDonation;

            cout << "Thank you for becoming a member, " << newMember.name << "!" << endl;
        }
        else
        {
            cout << "No problem, enjoy the program!" << endl;
        }
    }

    SetConsoleTextAttribute(h, 13);
    return hasMembership;
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

//function to collect and validate input
void PatternProgress()
{
    string pattern;
    cout << "What cross stitch pattern are you currently working on? ";
    cin >> pattern;
    cout << endl;

    string days;
    cout << "How many days have you been working on that pattern? ";
    cin >> days;
    cout << endl;

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
        cout << "Invalid option. Please choose an option A, B, or C." << endl;
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
    CrossStitchTracker tracker;

    PrintBanner();
    tracker.changeColor();
    PatternProgress();

    // Add stitching sessions
    for (int i = 0; i < 3; i++)
        tracker.addSession();

    tracker.showSessions();

    cout << "Average stitches per session: "
        << tracker.computeAverageStitches() << endl;

    tracker.fillPriceArray();
    tracker.saveReportToFile("CrossStitchReport.txt");

    // Input section 
    int progress;
    cout << "How many pieces are you currently working on? ";
    cin >> progress;

    string favorite;
    cout << "What is your favorite pattern you have completed so far? ";
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    getline(cin, favorite);

    string time;
    cout << "About how long has it been since you first started cross stitching? ";
    getline(cin, time);

    double price;
    cout << "How much do you currently pay for each skein of thread? ";
    cin >> price;
    cout << endl;

    // Summary table 
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
    if (own >= 10 && amount >= 10)
        cout << "You have too many embroidery hoops! Make a list of what sizes you have before buying more and ending up with duplicates." << endl;
    else
        cout << "You probably have a reasonable amount of embroidery hoops." << endl;

    ExactPercentage();

    //second if/else block
    int percent;
    cout << "How far into your current project are you percentage-wise? ";
    cin >> percent;
    if (percent > 50)
        cout << "You are more than halfway through your project! Keep up the great work :)" << endl;
    else if (percent == 50)
        cout << "You are exactly halfway through your project!" << endl;
    else
        cout << "You are less than halfway through your project. Keep going, and before you know it, it will start to come together!" << endl;

    cout << "\n";

    tracker.showMenu(percent, price);

    // Stitches per day function
    int StitchesInADay;
    int StitchesInAWeek = 0;
    int stitchArray[7];

    enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };
    string dayNames[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

    for (int day = MON; day <= SUN; day++)
    {
        cout << "Enter the number of stitches you completed " << dayNames[day] << ": ";
        cin >> StitchesInADay;

        StitchesInAWeek += StitchesInADay;
        stitchArray[day] = StitchesInADay;
    }

    for (int i = MON; i <= SUN; i++)
    {
        cout << dayNames[i] << ": " << stitchArray[i] << endl;
    }

    cout << "On average, you complete " << StitchesInAWeek / 7 << " stitches a day." << endl;

    // Average price from class
    double avgPrice = tracker.computeAveragePrice();

    cout << "\nAverage thread price: $" << fixed << setprecision(2) << avgPrice << endl;

    // ENUM based on avgPrice
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
    } while (answer == "yes");
    cout << "You completed " << ColorCompleted << " colors total." << endl;

    return 0;
}
