/**
 * Program to calculate collisions when standard input is hashed
 * @author Deepson Shrestha
 * @version 11.6.2019
 */

#include <iostream>

using namespace std;

const size_t m {99173};  // m = hash table size

/**
 * find the corresponding hash value for the given string
 * @param key the const. ref. to the string whose index is to be found
 * @param table_size the size of the hash table i.e m
 */
size_t hashx(const string& key, size_t table_size);

int main()
{
  unsigned foo[m];       // an array for holding collision count 

  // Loop for initializing all positions to 0
  for (size_t k = 0; k < m; k++)
  {
    foo[k] = 0;
  }
  
  string word;           // holding word from each line
  size_t hash_val;       // variable for holding hash_val to be returned

  // loop for counting the number of keys in each index (hash_val)
  while (getline(cin, word))
  {
    hash_val = hashx(word, m); //call hashx function to find array index
    foo[hash_val] = foo[hash_val] + 1; //increase the count in index by 1
    cout << word << endl;
  }

  unsigned sum = 0;
  // loop for calculating total collisions
  for (size_t i = 0; i < m; i++)
  {
    // if there is at least one key associated with the hash value, then
    // set the number of collisions in that index position to one less
    // than the total number of keys in that index
    if (foo[i] > 0)
    {
      foo[i] = foo[i] - 1;
    }

    // sum all the collisions
    sum += foo[i];
  }

  cout << "The total number of collisions is " << sum << endl;
  
  return 0;
}

size_t hashx(const string& key, size_t table_size)
{
  size_t hash_val {0};
  for (auto character : key)
  {
    hash_val = 37 * hash_val + static_cast<unsigned char>(character);
  }
  return hash_val % table_size;
}
      
