#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

// while using unordered_map TC = O(1)
// while using map TC = O(logn)

int main()
{
    // creation
    unordered_map<string, int> m;

    // Insertion O(1)
    // method-1
    pair<string, int> p = make_pair("shreyash", 3);
    m.insert(p);

    // method-2
    pair<string, int> pair2("name", 2);
    m.insert(pair2);

    // method-3
    m["my"] = 1;

    // Searching O(1)
    cout << m["name"] << endl;
    cout << m.at("shreyash") << endl;
    cout << m["unknown"] << endl; // maps an unknown entry to 0
    cout << m.at("unknown") << endl; // if we call this directly it gives out of range instance

    // size
    cout << m.size() << endl;

    // is present?
    cout << m.count("love") << endl;;

    // erase
    m.erase("name");
    cout << m.size() << endl;

    // iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}