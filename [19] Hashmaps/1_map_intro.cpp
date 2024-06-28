#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {

    // --> creation
    unordered_map<string, int> mp;

    // --> insertion
    //      method 1 
    pair<string, int> p = make_pair("taehyung", 30);
    mp.insert(p);

    //      method 2
    pair<string, int> p2("jaeyong", 23);
    mp.insert(p2);

    // when you insert 1st time then insertion happens but when you insert again it updates the existing value
    // for each corresponding key there exist only one entry
    mp["taehyung"] = 7;

    // --> search
    cout << mp["taehyung"] << endl;
    cout << mp.at("jaeyong") << endl;

    // --> when you access unknown value (not inserted / not exist in map) then?
    // cout << mp.at("unknown") << endl; // it will give you an error as the value doesn't exist in map
    cout << mp["unknown"] << endl; // it will create new entry in map with value 0
    cout << mp.at("unknown") << endl; // now this will not give you an error as above line created an entry

    // --> size
    cout << mp.size() << endl;

    // --> to check presence
    cout << mp.count("hey") << endl; // key absent: 0
    cout << mp.count("jaeyong") << endl; // key present: 1

    // --> erase
    mp.erase("unknown");
    cout << mp.size() << endl;

    // printing map
    cout << "key\t--> value" << endl;
    for(auto i: mp) 
        cout << i.first << " --> " << i.second << endl;
    cout << endl;

    // --> iterator
    unordered_map<string, int> :: iterator it = mp.begin(); // iterator it starts from 1st entry

    while(it != mp.end()) {
        cout << it -> first << " --> " << (*it).second << endl;
        it++;
    }

    return 0;
}