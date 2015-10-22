//Name:Diego Medina
//Date:10-23-15
//Descripition:Programming HW - 22 Oct

#include <iostream> //cin cout
#include <fstream> //fin fout
#include <string> 
#include <cstdlib> //exit()
#include <iomanip> //setw()
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
        
    string firstName, lastName, highestScore;
    
    char fileName[12];
    
    double score1, score2, score3, score4, score5, score6, avg, highAvg = 0, sum = 0;
    
    cout << "Enter the file name you want to use:" << endl;
    cin >> fileName;
    
    fin.open(fileName);
    fout.open("results.txt");
    
    if( fin.fail() || fout.fail() )
    {
        cout << "Error opening stream" << endl;
        exit(1);
    }
    
    while(fin >> firstName >> lastName >> score1 >> score2 >> score3 >> score4 >> score5 >> score6)
    {
        // sets 2 numbers after the decimal point
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);
        fout.precision(1);
        //left justified
        fout.setf(ios::left);
        
        avg = (score1 + score2 + score3 + score4 + score5) / 5.0;
        
        //determines highest average
        if(avg > highAvg)
        {
            highAvg = avg;
            
            highestScore = firstName + " " + lastName;
        }
        
        //displays first name, last name, scores 1 - 6, average
        fout << setw(10) << firstName << setw(12) << lastName << setw(8) << score1 << setw(8) << score2 
             << setw(8) << score3 << setw(8) << score4 << setw(8) << score5 
             << " Average: ";
             
        fout.precision(2);
        
        fout << setw(8) << avg << endl;
    }

    fout << endl << "Highest score: " << highestScore;
    
    fin.close();
    fout.close();


    return 0;
}
