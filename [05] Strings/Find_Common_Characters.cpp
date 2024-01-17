#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// From bing
#include <iostream>
#include <vector>
using namespace std;

vector<string> findCommonChar(vector<string> &words)
{
    vector<int> commonChar(26, INT_MAX);
    vector<string> result;

    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];
        vector<int> charCount(26, 0);
        for (int j = 0; j < word.length(); j++)
        {
            charCount[word[j] - 'a']++;
        }
        for (int j = 0; j < 26; j++)
        {
            commonChar[j] = min(commonChar[j], charCount[j]);
        }
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < commonChar[i]; j++)
        {
            result.push_back(string(1, 'a' + i));
        }
    }

    return result;
}

int main()
{
    vector<string> words = {"bella", "label", "roller"};

    vector<string> result = findCommonChar(words);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}

// int findCommonChar(string *words, int totalWords, int *commonChar) {

//     for(int i = 0; i < totalWords; i++) {
//         string word = words[i];
//         for(int i = 0; i < word.length(); i++) {
//             if(commonChar[word[i] - 'a'] > (i + 1))
//                 continue;
//             else 
//                 commonChar[word[i] - 'a']++;
//         }
//     }

//     return 26;
// }

// int main() {
//     string words[3] = {"bella","label","roller"};
//     int commonChar[26] = {0};

//     int ansLength = findCommonChar(words, 3, commonChar);

//     for(int i = 0; i < ansLength; i++) 
//         cout << commonChar[i] << " ";
//     cout << endl;

//     return 0;
// }