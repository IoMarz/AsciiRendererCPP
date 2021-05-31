#include <iostream>
#include <fstream>

using namespace std;

/*
* Hi thanks for checking out my crappy ascii renderer in C++! <3
* -Skyler/IoMarz
*/

class ascii
{
private:
    // This is the character that will be drawn in the console
    string renderChar = "# ";
public:
    // Rendering a square/rectangle
    void boxRender(int sx, int sy)
    {
        // Set the position values 
        int y = 0, x = 0;
        // Start
        while (x < sx)
        {
            // Draw the Character, by default its "#"
            cout << renderChar;
            // Increase the XPos
            x++;
            // Start the next line
            if (x >= sx && y < sy - 1)
            {
                // Increase the YPos
                y++;
                // Set the XPos to 0
                x = 0;
                // Start new line
                cout << endl;
            }
        }
        // End
        cout << endl;
    }

    // Rendering a hollow square/rectangle
    void hollowBoxRender(int sx, int sy)
    {
        // Set the position values
        // These are for mainly keeping track of the middle part of the box
        int y = 0, x = 0;
        // Start
        // Draw top layer
        for (int i = 0; i < sx; i++)
        {
            cout << renderChar;
        }
        // Make next line
        cout << endl;
        // Set the YPos to the correct position
        y = 1;
        // Draw the middle part
        while (x < sx && y < sy - 1)
        {
            // Draw the first character
            cout << renderChar;
            // Increase the XPos
            x++;
            // Draw the blank characters
            for (int i = 0; i < sx - 2; i++)
            {
                cout << "  ";
                // Increase the XPos again
                x++;
            }
            // Draw the last character
            cout << renderChar;
            // Reset the XPos
            x = 0;
            // Increase the YPos
            y++;
            // Start the next line
            cout << endl;
        }
        // Draw bottom layer
        for (int i = 0; i < sx; i++)
        {
            cout << renderChar;
        }
        // End
        cout << endl;
    }

    void textReader(string file)
    {
        fstream fsfile;
        // Open the file
        fsfile.open(file, ios::in);
        string tex;
        // Check if the file exists
        if (fsfile)
        {
            // Read the file
            while (getline(fsfile, tex))
            {
                // Print
                cout << tex << endl;
            }
        }
        // Close
        fsfile.close();
    }
};

int main()
{
    // Create an object of the ascii class
    ascii asc;
    // Draw a box (10x10) 
    asc.boxRender(10, 10);
    cout << endl;
    // Draw a hollow box (10x10)
    asc.hollowBoxRender(10, 10);
    cout << endl;
    // Draw a rectangle (10x5)
    asc.boxRender(10, 5);
    cout << endl;
    // Draw a hollow rectangle (10x5)
    asc.hollowBoxRender(10, 5);
    // Draw from a text file
    cout << endl;
    asc.textReader("ReadFromThis.txt");
    return 0;
}