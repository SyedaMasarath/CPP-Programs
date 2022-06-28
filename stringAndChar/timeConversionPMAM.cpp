#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
   int hh = ((s[0]-'0') * 10) + (s[1]-'0');
    
    // If hour is 12, convert to 0
    if (hh == 12) {
        hh = 0;
    }
    
    // If the format is PM, add 12 hours
    if (s[8] == 'P') {
        hh += 12;
    }
    
    // Change the hours in <s> to the current hour
    s[0] = (char)((hh/10) + '0');
    s[1] = (char)((hh%10) + '0');
    
    // Remove last two characters (PM or AM)
    s.pop_back(); s.pop_back();
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}