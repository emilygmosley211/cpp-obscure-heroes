#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Constants
const int SIZE = 10;

// Parallel Arrays: Store names, powers, weaknesses
string names[SIZE] = {
    "Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Matter-Eater Lad", "Bouncing Boy",
    "Color Kid", "Doorman", "Zeitgeist", "Gin Genie", "Dogwelder"
};

string powers[SIZE] = {
    "Control Squirrels", "Detachable Limbs", "Super Strength", "Eat Anything",
    "Bounce Power", "Color Manipulation", "Teleportation", "Acid Vomit",
    "Seismic Alcohol Bursts", "Welding Dogs to Enemies"
};

string weaknesses[SIZE] = {
    "Time Limits", "Heavy Objects", "Poor Judgment", "Digestive Problems",
    "Puncture Vulnerability", "Bright Light", "Needs Doors", "Self Doubt",
    "Sobriety", "Ethical Concerns"
};

// Multidimensional Array: year introduced and comic universe
string info[SIZE][2] = {
    {"1992", "Marvel"}, {"1989", "DC"}, {"1986", "Other"}, {"1962", "DC"},
    {"1961", "DC"}, {"1966", "DC"}, {"1989", "Marvel"}, {"2001", "Marvel"},
    {"2001", "Marvel"}, {"1997", "DC"}
};