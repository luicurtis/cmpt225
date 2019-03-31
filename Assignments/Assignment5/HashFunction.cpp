/*
 * HashFunction.cpp
 *
 * Class Definition:    Tests a hashing for student numbers given a data file 
 *                      containing 150 instances of indexing keys
 *
 * Created on: 	March 2019
 * Author: 		Curtis Lui
 * 
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const unsigned int SIZE_HASH_TABLE = 150;

int hashFunction1(string studentNum);

int main()
{
    ifstream dataFile("IndexingKeys.txt");

    if (!dataFile.is_open())
    {
        cout << "ERROR: File could not be opened" << endl;
        return 1;
    }

    // Initialize variables
    string str_studentNum = "\0";
    unsigned int hashCounter[SIZE_HASH_TABLE] = {0};

    while(dataFile.peek() != EOF)
    {
        getline(dataFile,str_studentNum);
        int hashKey = hashFunction1(str_studentNum);
        hashCounter[hashKey]++;
    }

    // Print out hashtable frequency line by line
    for (int i = 0; i < SIZE_HASH_TABLE; i++)
    {
        cout << "INDEX " << i << " - " << hashCounter[i] << endl;
    }

    return 0;
} // main()

int hashFunction1(string studentNum)
{
    int hashCode = 0;

    // Convert studentNum to int
    int int_studentNum = stoi(studentNum);

    // Produce hashCode
    // 1. Take first 3 digits, mod with 6, them multiply by 100
    int num1 = ((int_studentNum / 100000) % 10) * 100;

    // 2. Take digits 4 to 7 and mod with 6, then multiply by 10
    int num2 = (((int_studentNum / 100000) / 10) % 6) * 10;

    // 3. Take the last digit and add num1, num2, and last digit together
    int finalCode = num1 + num2 + (int_studentNum % 10);

    hashCode = finalCode % SIZE_HASH_TABLE;
    
    return hashCode;
}