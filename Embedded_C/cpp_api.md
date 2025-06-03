# CPP API's 

### In standard template libraries 

# PAIR : 
##### pair<int,int> x  : {1,2}
##### pair<int,pair<int,string>> x :   {1,{1,"hello"}} 
##### pair<int,int> p =  make_pair(1,2) 
##### x.first,x.second   (To access it) 


# VECTOR : 
##### vector <int> v = {1,2,3,4,5} 
##### v.push_back(6);
##### v.push_back(7);
##### v.emplace_back(8);
##### v.pop_back();
##### vector<int> :: iterator iter_b = v.begin();                  // access *(iter_b) 
##### vector<int> :: iterator iter_e = v.end();                    // access *(--iter_b)  or *(iter_b-1) 
##### vector <int> :: reverse_iterator r_iter_b = v.rbegin();      //  access *(r_iter_b) 
##### vector <int> :: reverse_iterator r_iter_e = v.end();         // access *(--r_iter_e)
##### v.size()   //length of vector 

##### v.insert(position,that_start , that_end); 
##### v.back(); 
##### v.erase(v.begin()+1,v.begin()+3);                         // 1,2 indexes are deleted 
##### v.clear();

