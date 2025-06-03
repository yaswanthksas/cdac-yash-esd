# C++ 
## Pair 
<pre>
    ```
        Pair<DataType1, DataType2> variableName; // Declaration
        variableName.first = value1; // Assigning a value to the first element
        variableName.second = value2; // Assigning a value to the second element
    ```
</pre>


### Example: 

''' 
#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, double> myPair = {42, 3.14159};  // pair with int and double data types
    pair<int, char> myPair1 = {0, 'a'};  // pair with int and char data types
    pair<int, string> myPair2 = {21, "Hello World"};  // pair with int and string data types

    // Printing the elements
    cout << "1st Pair First Element: " << myPair.first << ", 1st Pair Second Element: " << myPair.second << endl;
    cout << "2nd Pair First Element: " << myPair1.first << ", 2nd Pair Second Element: " << myPair1.second << endl;
    cout << "3rd Pair First Element: " << myPair2.first << ", 3rd Pair Second Element: " << myPair2.second << endl;
    
    // pair with multiple elements
    pair<int, pair<int, int>> nestedPair = {0, {10, 20}};
    cout << "First: " << nestedPair.first << ", Second 1: " << nestedPair.second.first << ", Second 2: " << nestedPair.second.second << endl;
    
    // array of pairs
    pair<int, string> pairs[] = {{1, "One"},{2, "Two"},{3, "Three"}};
    cout << "2nd Pair in Array: First Element: "<< pairs[1].first << "Second Element: " << pairs[1].second << endl;
    
    return 0;
}
'''

![image](https://github.com/user-attachments/assets/6ed5e76a-683e-41cb-a231-a23bc436a87d)

# Vector : 
![image](https://github.com/user-attachments/assets/32648e2e-200b-4bd2-b211-0d46af51e913)

'''
#include <iostream>
#include <vector>
// or use #include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. Simple Vector Declaration
    vector<int> v;
    // 2. Vector Initialization with Size and Default Value
    vector<int> v1(5, 20);
    // 3. Vector Initialization with Size Only
    vector<int> v2(5);
    // 4. Copying One Vector to Another
    vector<int> v3(v1);
    return 0;
}

![image](https://github.com/user-attachments/assets/414ca9c7-bbd0-4b56-8452-d84bbb7f6281)

'''
#include <iostream>
#include <vector> // or use #include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(10); 
    v.emplace_back(20);
    cout << v[0] << " " << v[1] << endl; // Output - 10 20
    return 0;
}

'''

![image](https://github.com/user-attachments/assets/d1c8689e-5444-4384-b9e7-07b044560102)

### Vector of Pairs : 
'''

#include <iostream>
#include <vector> // or use #include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> pairs;
    pairs.push_back({10,20});
    pairs.emplace_back(30,40);
    cout << pairs[0].first << " " << pairs[0].second << endl; // Output - 10 20
    cout << pairs[1].first << " " << pairs[1].second << endl; // Output - 30 40
    return 0;
}
'''
![image](https://github.com/user-attachments/assets/7060ad97-b766-471d-b25b-4ca3376447bf)

# Iterators : 
'''
#include <iostream>
#include <vector> // or use #include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    
    // 1. Initialize a vector iterator
    vector<int>::iterator it = v.begin();
    vector<int>::iterator it1 = v.end();
    
    cout << "First element: " << *it << endl; // Output - First element: 10
    cout << "Last element: " << *(--it1) << endl; // Output - Last element: 50
    
    // 2. Using rbegin() and rend() for reverse iteration
    vector<int>::reverse_iterator rIt = v.rbegin();
    vector<int>::reverse_iterator rEndIt = v.rend();

    cout << "First element using reverse iterator: " << *rIt << endl; // Output - First element: 50
    cout << "Last element using reverse iterator: " << *(--rEndIt) << endl; // Output - Last element: 10
    
    
    // 3. Access the last element using v.back()
    int lastElement = v.back();
    // Print the last element
    cout << "Last element using v.back(): " << lastElement << endl; // Output - Last element using v.back(): 50
    
    cout << endl;
    return 0;
}

'''

![image](https://github.com/user-attachments/assets/2c8d73dd-a241-4e10-b28d-f29cd80936c8)


### Printing Vector : 
''' 
#include <iostream>
#include <vector> // or use #include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    // 1. Printing Vector Using a For Loop
    cout << "Using a for loop:" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // 2. Printing Vector Using Auto with Iterators
    cout << "Using auto with iterators:" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // 3. Printing Vector Using Range-Based For Loop
    cout << "Using a range-based for loop:" << endl;
    for (int k : v) {
        cout << k << " ";
    }
    cout << endl;
    // 4. Printing Vector Using Auto with Range-Based For Loop
    cout << "Using auto with range-based for loop:" << endl;
    for (auto k : v) {
        cout << k << " ";
    }
    cout << endl; // Output - 10 20 30 40 50 
    return 0;
}

'''


### Insert Function : 
''' 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 4, 5, 6};
    // 1. Insert at the beginning of vector
    v.insert(v.begin(), 10); // v = {10, 1, 4, 5, 6}
    // 2. Insert a single value (3) at a specified position (second position)
    v.insert(v.begin() + 2, 3); // v = {10, 1, 3, 4, 5, 6}
    // 3. Insert multiple values (two 8s) at a specified position (second position)
    v.insert(v.begin() + 2, 2, 8); // v = {10, 1, 8, 8, 3, 4, 5, 6}
    // 4. Create another vector to demonstrate inserting a range of elements
    vector<int> v1 = {20, 25};
    // 5. Insert elements from v1 into the original vector at the beginning
    v.insert(v.begin(), v1.begin(), v1.end()); // v = {20, 25, 10, 1, 8, 8, 3, 4, 5, 6}
    // 6. Printing Vector After Inserting Elements from v1
    for (int element : v) {
        cout << element << " ";
    } // Output - 20 25 10 1 8 8 3 4 5 6 
    cout << endl;
    return 0;
}

''' 
# ![image](https://github.com/user-attachments/assets/b39557da-c937-461c-bb8b-736613f67300)


### Deletion Functions : 
''' 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    // Removing the third element (index 2)
    v.erase(v.begin() + 2); // v = {10, 20, 40, 50}
    // Removing elements from index 1 to 2 (excluding 3)
    v.erase(v.begin() + 1, v.begin() + 3); // v = {10, 50}
    // Printing the vector after second erase
    for (int element : v) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
''' 
### size(),pop_back(),swap(),clear(),empty() 
''' 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    // Get the vector size
    cout << "Vector size: " << v.size() << endl; // Output - 5
    // Remove the last element
    v.pop_back(); // v = {10, 20, 30, 40}
    // Swap two vectors
    vector<int> v1 = {100, 200, 300};
    v.swap(v1); // v = {100, 200, 300}, v1 = {10, 20, 30, 40}
    // Clear the vector
    v1.clear(); // v1 = {}
    // Check if the vector is empty
    cout << "Is v1 empty? " << v1.empty() << endl;  // Output - Is v1 empty? 1
    // Print the modified vectors
    cout << "v: ";
    for (int element : v) {
        cout << element << " ";
    }
    cout << endl; // Output - 100 200 300 
    return 0;
}

'''

# ![image](https://github.com/user-attachments/assets/7dc43b9b-5a33-4c6f-8388-eaec05ab9466)

