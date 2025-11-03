#include <iostream> // Needed for standard input/output (like 'cout')
#include <fstream>  // Needed for file input/output (like 'ifstream' and 'ofstream')
#include <string>   // Needed for using the string data type

using namespace std; // Allows us to use standard names like 'cout', 'endl', and 'string'

// --- Function Prototypes ---
bool isVowel(char ch);                  // Checks if a character is a vowel (including 'y')
string rotate(string pStr, int len);    // Moves the first character of a string to the end
string pigLatinString(string pStr);     // Translates a single word to Pig Latin
void getNextWord(ifstream& inF, char& ch, string& word); // Reads the next word from the file

int main()
{
    string str; // Variable to hold the word being processed (the current word)
    char ch;    // Variable to hold the current character read from the file

    // File stream objects for input and output
    ifstream infile;
    ofstream outfile;

    // --- File Setup ---
    infile.open("Ch7_Ex3Data.txt"); // Tries to open the input file
    if (!infile) // Checks if the file failed to open
    {
        cout << "Cannot open input file. Program terminates." << endl;
        return 1; // Returns an error code
    }

    outfile.open("Ch7_Ex3Out.txt"); // Opens the output file

    // Reads the first character of the input file
    infile.get(ch);

    // Main loop: continues as long as there is data in the input file
    while (infile)
    {
        // Inner loop: processes characters until a newline is found (processes one line)
        while (ch != '\n')
        {
            if (ch == ' ')
            {
                // If the character is a space, write it directly to the output
                outfile << ch;
                infile.get(ch); // Read the next character
            }
            else
            {
                // If the character is the start of a word
                getNextWord(infile, ch, str); // Reads the entire word into 'str'
                outfile << pigLatinString(str); // Translates and writes the Pig Latin word
            }
        }

        // Once a newline is found, write a newline to the output file
        outfile << endl;
        infile.get(ch); // Read the character following the newline to restart the outer loop
    }

    // --- Cleanup ---
    infile.close();  // Close the input file
    outfile.close(); // Close the output file

    return 0; // Signals successful execution
}

// --- Function to check for Vowel ---
// Checks if the given character is a vowel (A, E, I, O, U, Y, and their lowercase versions)
bool isVowel(char ch)
{
    switch (ch)
    {
    case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
    case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
        return true;
    default:
        return false;
    }
}

// --- Function to check for Punctuation ---
// Checks if the given character is a common punctuation mark
bool isPunctuation(char ch)
{
    switch (ch)
    {
    case ',': case '.': case '?': case ';': case ':':
        return true;
    default:
        return false;
    }
}

// --- Function to Rotate the string ---
// Moves the first character of the string to the end
string rotate(string pStr, string::size_type len)
{
    string rStr;

    // substr(1, len) gets everything EXCEPT the first character
    // + pStr[0] adds the first character to the end
    rStr = pStr.substr(1, len) + pStr[0];

    return rStr;
}

// --- Function to Translate a Word to Pig Latin ---
string pigLatinString(string pStr)
{
    string::size_type len = pStr.length(); // Get the length of the word

    bool foundVowel = false; // Flag to track if a vowel is found

    // Check if the last character is punctuation
    bool isPunct = isPunctuation(pStr[len - 1]);
    char puncMark;

    string::size_type counter;

    // --- Punctuation Handling ---
    if (isPunct)
    {
        puncMark = pStr[len - 1]; // Store the punctuation mark
        len = len - 1;            // Reduce the effective length to ignore punctuation for translation
    }

    // --- Pig Latin Rule 1: Starts with a Vowel ---
    if (isVowel(pStr[0]))
        // Append "-way" to the end (ignoring the last character if it was punctuation)
        pStr = pStr.substr(0,len) + "-way";
    // --- Pig Latin Rule 2: Starts with a Consonant ---
    else
    {
        // Temporarily add a hyphen to the end (before rotation)
        pStr = pStr.substr(0,len) + '-';

        // Rotate the first consonant to the end of the word
        pStr = rotate(pStr, len);

        len = pStr.length(); // Update length to include the added hyphen
        foundVowel = false;

        // Loop to check characters and rotate until a vowel is the first letter
        // Loop stops 1 character before the end to avoid checking the hyphen
        for (counter = 1; counter < len - 1; counter++)
            if (isVowel(pStr[0])) // Check if the new first letter is a vowel
            {
                foundVowel = true;
                break; // Exit the loop if a vowel is found
            }
            else
                // If still a consonant, rotate again
                pStr = rotate(pStr, len);

        // After the loop, apply the final Pig Latin ending
        if (!foundVowel)
            // If no vowel was found (e.g., "rhythm"), use the entire word (minus hyphen) and add "-way"
            pStr = pStr.substr(1,len) + "-way";
        else
            // If a vowel was found, just replace the initial hyphen with "ay" (e.g., "e-ll-hay" -> "ell-hayay")
            pStr = pStr + "ay"; // Note: The hyphen is already included in pStr
    }

    // --- Re-attach Punctuation ---
    if (isPunct)
        pStr = pStr + puncMark;

    return pStr;
}

// --- Function to read the next word from the file ---
void getNextWord(ifstream& inF, char& ch, string& word)
{
    word = ch; // Start the word with the current character ('ch' already holds the first letter)

    // Loop until a space or newline is encountered
    while (ch != ' ' && ch != '\n')
    {
        inF.get(ch); // Read the next character

        if (ch != ' ' && ch != '\n')
            // If it's part of the word, append it
            word = word + ch;
    }
    // Note: When the function exits, 'ch' holds the character that terminated the word (space or newline).
}
