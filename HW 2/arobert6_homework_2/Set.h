#ifndef SET_H_
#define SET_H_

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <exception>


using namespace std;

template <typename T>
class Set
{
    

    private:
        vector<T> data; /*!< Vector storing actual set */

        vector<T> getData() const;
        /**************************************************************
        * Description:  Getter for functions data
        * Parameters:   No parameters required
        * Return Value: Templated Vector
        **************************************************************/
    public:
        Set();
        /**************************************************************
        * Description:  Default constructor
        * Parameters:   No parameters required
        * Return Value: New set
        **************************************************************/
        Set(T a);
        /**************************************************************
        * Description:  Overloaded constructor
        * Parameters:   Templated data that becomes the first member of 
        *               set
        * Return Value: New set
        **************************************************************/
        Set(vector<T> a);
        /**************************************************************
        * Description:  Overloaded constructor
        * Parameters:   Vector containing templated data that 
        *               becomes the set
        * Return Value: New set
        **************************************************************/
        void add(T a);
        /**************************************************************
        * Description:  Add function that verifies originality and adds
        *               to data
        * Parameters:   Vector containing templated data that 
        *               becomes the set
        * Return Value: Void
        **************************************************************/
        void print(); 
        /**************************************************************
        * Description:  Prints the contents of the data vector
        * Parameters:   No parameters required
        * Return Value: Void
        **************************************************************/     
        bool membership(T a);
        /**************************************************************
        * Description:  Verifies paramaters presence in data
        * Parameters:   Templated data
        * Return Value: Bool
        **************************************************************/ 
        void remove(T a);
        /**************************************************************
        * Description:  Removes paramater from data
        * Parameters:   Templated data
        * Return Value: Void
        **************************************************************/ 
        bool subSet(Set<T> a);
        /**************************************************************
        * Description:  Verifies paramaters presence in current Set
        * Parameters:   Set of Templated data
        * Return Value: Bool
        **************************************************************/ 
        int cardinality();
        /**************************************************************
        * Description:  Returns count of elements in set
        * Parameters:   No parameters required
        * Return Value: Int
        **************************************************************/ 
        Set<T> join(Set<T> a);
        /**************************************************************
        * Description:  Creates a union of current set and parameter
        * Parameters:   Set of Templated data
        * Return Value: New set
        **************************************************************/ 
        Set<T>& operator=(const Set& a) const;
        /**************************************************************
        * Description:  Overload of "="'s operator for copying
        * Parameters:   Set of Templated data
        * Return Value: New set
        **************************************************************/

};

template <typename T>
Set<T>::Set()
{
}
template <typename T>
Set<T>::Set(T a)
{
    data.push_back(a);
}
template <typename T>
Set<T>::Set(vector<T> a)
{
    //
    for (T x : a){
        this->add(x);
    }
}
template <typename T>
vector<T> Set<T>::getData() const
{
    //basic getter
    return data;
}
template <typename T>
void Set<T>::add(T a)
{   
    //verify a is NOT part of set
    if( !this->membership(a) )
    {
        //inserts "a" into set
        data.push_back(a);
    }
        
}
template <typename T> 
void Set<T>::print()
{   
    //loop printing data
    for (T x : data){
        cout << x << " ";
    }
    cout << endl;
}

template <typename T>
bool Set<T>::membership(T a)
{   

    bool result = false;
    //loops checking if vector element is same as "a"
    for(int i = 0; i != data.size(); i++){
        if (data[i] == a)
        {
            result = true;
        }
    }  
    return result;
}
template <typename T>
void Set<T>::remove(T a)
{
    //verifies "a" is part of set
    if( !this->membership(a))
    {
        cout << "not a member" << endl;
        return;
    }
    //if "a" is only element in array, delete
    if(this->cardinality() == 1) { data.erase(data.begin() + 0); }
    //Otherwise it finds data location
    else{
        for(int i = 0; i != data.size(); i++){
            if (data[i] == a)
            {
                data.erase(data.begin() + i);
            }
        } 
    }

}
template <typename T>
bool Set<T>::subSet(Set<T> a)
{
    vector<T> sub1 = a.getData();
    bool result = false;

        //cycles object vector
    for (typename vector<T>::const_iterator i = data.begin(); i != data.end(); i++)
    {
        bool found = false;
        //cylces subsets vector
        for (typename vector<T>::const_iterator j = sub1.begin(); j != sub1.end(); j++)
        {
            if (*i == *j)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            return false;
        }
    }

    return true;
}
template <typename T>
int Set<T>::cardinality()
{
        int result = data.size();

    return result;
}
template <typename T>
Set<T> Set<T>::join(Set<T> a)
{
        vector<T> sub1 = a.getData();
        vector<T> AB;

        //populates new vector with both vectors
        AB.insert( AB.end(), data.begin(), data.end() );
        AB.insert( AB.end(), sub1.begin(), sub1.end() );
        

    return Set(AB);
}
template <typename T>
Set<T>& Set<T>::operator=(const Set& a) const
{
    //copies full data to pass to new array
    vector<T> AB = a.getData();

    return *Set(AB);
}

#endif