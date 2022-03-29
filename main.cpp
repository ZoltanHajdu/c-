#include <iostream>
#import <cmath>
#include "Read.h"

using namespace std;

int main()
{
    string fileName;
    bool ok = false;
    do
    {
        cout << "Filename: ";
        cin >> fileName;
        cout << endl;

        try
        {
            Read enor (fileName);

            double sumBeforeNeg = 0;
            double countBeforeNeg = 0;
            double average;
            bool remainsNegative = true;
            int lowestTemp;

            for (enor.first(); enor.current() >= 0;enor.next())
            {
                lowestTemp = enor.current();
                sumBeforeNeg += enor.current();
                countBeforeNeg++;
            }

            average = ceil((sumBeforeNeg/countBeforeNeg)*100.0)/100.0;

            cout << "Average temperature before the first negative: " << average << endl;

            for (;!enor.end();enor.next())
            {
                if (enor.current() < lowestTemp)
                {
                    lowestTemp = enor.current();
                }

                if(enor.current() >= 0)
                {
                    remainsNegative = false;
                }
            }

            if (remainsNegative)
            {
                cout << "It stays negative after the first negative temperature value." << endl;
            } else {
                cout << "It does not stay negative after the first negative temperature value." << endl;
            }

            cout << "The lowest temperature is: " << lowestTemp << " celsius." << endl;
            ok = true;
        } catch (Read::NoExistingFileException exc)
        {
            cout << fileName << " was not found\n";
            ok = false;
        }
    } while(!ok);
}
