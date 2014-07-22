#include <cassert>
#include <string>
#include <iostream>
#include <vector>

typedef unsigned int UINT;

UINT calculate(std::string const&& str)
{
    UINT max = 0;
    UINT len = str.length();
    for(int i = 0 ; i != len - 1 ; ++i)
    {
        if(str.substr(0 , i + 1) == str.substr(len - i - 1))
            if(max < i + 1)
                max = i + 1;
    }
    return max;
}

void generatePartialMatchTable(std::string const& pattern,
                               std::vector<UINT>& table)
{
    assert(!pattern.empty() && table.size() == 0);

    for(int i = 0 ; i != pattern.size() ; ++i)
        table.push_back( calculate( pattern.substr(0 , i + 1) ) );
}

int KMP(std::string const& text , std::string const& pattern)
{
    UINT pText = 0;
    UINT pPattern = 0;
    std::vector<UINT> table;
    generatePartialMatchTable(pattern , table);
    for( ; pText != text.length() ; ++pText)
    {
        if(text[pText] == pattern[pPattern])
        {
            if(pPattern != pattern.length() - 1)
                ++pPattern;
            else
            {
                return pText - pPattern;
            }
        }
        else
        {
            if(pPattern > 0)
            {
                pPattern = table[pPattern - 1];
                --pText;
            }
            else
            {
                pPattern = 0;
            }
        }

    }
    return -1;
}

int main(int argc , char* argv[])
{
    std::string text = "ABC ABCDAB ABCDABCDABDE";
    std::string pattern = argv[1];
    int bingo = KMP(text , pattern);
    std::cout << bingo << "\n";
    return 0;
}