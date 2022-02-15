
#include <bits/stdc++.h>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

// function for printing the elements in a map
// 3rd part of task
void print_Map(map<int, string> v)
{
    map<int, string>::iterator it;
    for (it = v.begin(); it != v.end(); ++it)
        cout << it->first << " " << it->second << "\n";
    cout << "\n";
}
int main()
{
    map<int, string> m;

    //1sr part-  Inserting Elements in Random order
    m.insert(pair<int, string>(6, "Map"));
    m.insert(pair<int, string>(3, "Iterator"));
    m.insert(pair<int, string>(8, "pair"));
    m.insert(pair<int, string>(1, "coders"));
    m.insert(pair<int, string>(9, "algorithm"));
    m.insert(pair<int, string>(2, "begin"));
    m.insert(pair<int, string>(5, "end"));

    // 2nd part- printing map
   print_Map(m);

    // 4th part of Task
    // Find an element as key from this map
    auto itr = m.find(3);
    cout << "\nitr is poiting to \n"
         << itr->first << " " << itr->second << " \n";

    // 5th part- Assigning one map to another
    map<int, string> copyMap = m;
    cout << "\nPrinting copyMap \n";
   print_Map(copyMap);

    // 6th part- Deleting a key from map
    cout << "\nDeleting a key-value from copyMap : 9 algorithm\n";
    copyMap.erase(9);
    cout << "\nPrinting map After deleting key = 9 from it\n";
   print_Map(copyMap);

    // 7th part- Finding size and max size of map
    cout << "\nSize of the map is : " << copyMap.size()
         << "\t maxSize of map is : " << copyMap.max_size() << "\n";

    // 8th part-  Checking a map is empty or not
    cout << "\nChecking map is empty or not after : ";
    if (copyMap.empty())
        cout << "Map is empty\n";
    else
        cout << "Map is not empty\n";

    // 9th part- Clearing a map
    copyMap.clear();
    cout << "\nPrinting a Map after Clearing it : "<<"\n"<<endl;
   print_Map(copyMap);

    return 0;
}
