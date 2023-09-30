#include <iostream>
#include <vector>
#include <string>
#include "set.h"

using namespace std;

template<class T>
Set<T>::Set()
{}

template<class T>
void Set<T>::add(T newItem)
{

    bool found = false;
    int i;

    for(i=0;(i<data.size() && (found==false)); i++)
    {
        if(data[i] == newItem)
        {
            found = true;
        }
    }

    if(!found)
    {
        data.push_back(newItem);
    }
}

template<class T>
int Set<T>::getSize()
{
    return data.size();
}

template<class T>
T* Set<T>::getArray()
{

    T* dataArray = new T[data.size()];
    int i;

    for(i=0;i<data.size();i++)
    {
        dataArray[i] = data[i];
    }

    return dataArray;

}

