//
//  main.cpp
//  Playing with Numbers
//
//  Created by Damien Hosea on 11/19/18.
//  Copyright © 2018 Damien Hosea. All rights reserved.
//
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    bool evenbool = 0;
    bool oddbool = 0;
    string digits;
    int evenLength = 0;
    int oddLength = 0;
    int counter = 0;
    int strlength = 0;
    string username;
    string continu = "y";
    ofstream outputFile;
    
    cout << " Please Enter Your Name \n";
    getline(cin, username);
    username.length();
    
    while(counter < username.length() || username.length() == 0)
    {
        if(!isalpha(username[counter]) ) {
            
            cout << " That's not a proper name, please try again!"<<endl;
            getline(cin, username);
            username.length();
            counter = 0;
        }
        else
        {
            counter ++;
        }
    }
    
    outputFile.open(username);
    // loop for program to optionally keep running.
    while (continu == "Y" || continu == "y")
    {
        cout << "Please Enter some positive integers " << endl;
        getline(cin,digits);
        // validation.
        while (counter < digits.length() || digits.length() == 0)
        {
            if (!isdigit(digits[counter]))
            {
                cout << "We talked about this, Positive Integers *Only*." << endl;
                getline(cin,digits);
                counter = 0;
            }
            else
            {
                counter++;
            }
        }
        // output the original number.
        cout << "\nThe original number(s) were... ";
        outputFile << "\nThe original number ";
        for (counter = 0; counter < digits.length(); counter++)
        {
            cout << digits[counter] << " ";
            outputFile << digits[counter] << " ";
        }
        // output the number in reverse order.
        cout << "\nThe number(s) in reverse are... ";
        outputFile << "\nThe number reversed is ";
        for (counter = digits.length() - 1; counter != -1; counter--)
        {
            cout << digits[counter] << " ";
            outputFile << digits[counter] << " ";
        }
        // check for even numbers
        for (counter = 0; counter < digits.length(); counter++)
        {
            if (digits[counter] % 2 == 0)
            {
                evenLength += 1;
            }
        }
        // if none, then state that, if there are then output them.
        if (evenLength == 0)
        {
            cout << "\nThere are no even number(s)... ";
            outputFile << evenLength <<endl;
        }
        else
        {
            cout << "\nThe even number(s) are... ";
            outputFile << evenLength <<endl;
            for (counter = 0; counter < digits.length(); counter++)
            {
                if (digits[counter] % 2 == 0)
                {
                    cout << digits[counter] << " ";
                    outputFile << digits[counter] << " ";
                }
            }
        }
        // check for odd numbers present.
        for (counter = 0; counter < digits.length(); counter++)
        {
            if (digits[counter] % 2 == 1)
            {
                oddLength += 1;
            }
        }
        // out them if any or state that there are none.
        if (oddLength == 0)
        {
            cout << "\nThere are no odd number(s) ";
            outputFile << oddLength <<endl;
        }
        else
        {
            cout << "\nThe odd numbers are ";
            outputFile << oddLength << endl;
            for (counter = 0; counter < digits.length(); counter++)
            {
                if (digits[counter] % 2 == 1)
                {
                    cout << digits[counter] << " ";
                    outputFile << digits[counter] << " ";
                }
            }
        }
        // give user option to quit.
        cout << "\n y/Y to continue, any other char to exit" << endl;
        getline(cin, continu);
        // if user chooses to contine, reset variables.
        if(continu=="y" || continu=="Y")
        {
            oddbool = 0;
            evenbool = 0;
            evenLength = 0;
            oddLength = 0;
            counter = 0;
            strlength = 0;
        }
    }
    outputFile.close();
    cout << "done" << endl;
    return 0;
}

