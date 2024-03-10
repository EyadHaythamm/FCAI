#include <iostream>
#include <string>
using namespace std;

int main() {
    string message;
    string morse = "";
    cout << "Please enter your message: ";
    getline(cin, message);
    for (char c : message) {
        if (c == 'a' || c == 'A')
            morse += ".- ";
        else if (c == 'b' || c == 'B')
            morse += "-... ";
        else if (c == 'c' || c == 'C')
            morse += "-.-. ";
        else if (c == 'd' || c == 'D')
            morse += "-.. ";
        else if (c == 'e' || c == 'E')
            morse += ". ";
        else if (c == 'f' || c == 'F')
            morse += "..- ";
        else if (c == 'g' || c == 'G')
            morse += "--. ";
        else if (c == 'h' || c == 'H')
            morse += ".... ";
        else if (c == 'i' || c == 'I')
            morse += ".. ";
        else if (c == 'j' || c == 'J')
            morse += ".--- ";
        else if (c == 'k' || c == 'K')
            morse += "-.- ";
        else if (c == 'l' || c == 'L')
            morse += ".-.. ";
        else if (c == 'm' || c == 'M')
            morse += "-- ";
        else if (c == 'n' || c == 'N')
            morse += "-. ";
        else if (c == 'o' || c == 'O')
            morse += "--- ";
        else if (c == 'p' || c == 'P')
            morse += ".--. ";
        else if (c == 'q' || c == 'Q')
            morse += "--.- ";
        else if (c == 'r' || c == 'R')
            morse += ".-. ";
        else if (c == 's' || c == 'S')
            morse += "... ";
        else if (c == 't' || c == 'T')
            morse += "- ";
        else if (c == 'u' || c == 'U')
            morse += "..- ";
        else if (c == 'v' || c == 'V')
            morse += "...- ";
        else if (c == 'w' || c == 'W')
            morse += ".-- ";
        else if (c == 'x' || c == 'X')
            morse += "-..- ";
        else if (c == 'y' || c == 'Y')
            morse += "-.-- ";
        else if (c == 'z' || c == 'Z')
            morse += "--.. ";
    }
    cout << "Morse code: " << morse << endl;
    return 0;
}