/**
 * Name: Jake Billings
 * Date: 11/09/2017
 * Class: CSCI 1411-001
 * Description: skills practice file copied from lab document
 * Status: compiles and runs on VS, Clion, and csegrid
 */
#include <iostream>
#include <string>

namespace Example
{
    struct string
    {
        char * dynamicArray;
        int size =0;
    };
}

using namespace std;
int main()
{
    Example::string myString;
    /*Use the Example:: to differentiate.  By saying using namespace std we say if we don't specify assume the std string.  If we want to specify, we use the name of the namespace with a ::*/
    string string1, string2;
    cout << "Type a string that you want converted to a C String:\n";
    getline (cin, string1);
    myString.size = string1.size()+ 1;
//String class size does not count the '/n'
    myString.dynamicArray = new char[(myString.size)];
    for (int i=0; i<string1.size(); i++)
    {
        myString.dynamicArray[i] = string1[i];
    }
    myString.dynamicArray[myString.size -1] = '\0'; //Backslash Zero
    cout << "The string input was:\n" << string1<<endl;
    string2 = string(myString.dynamicArray);
    cout << "The string, converted to a dynamic array, then coverted back to a string is \n";
    cout << string2 <<endl;
    return 0;
}
