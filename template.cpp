/**
 * Program explanation here
 * @author Your Name Here
 * @version Date Last Modified Here
 */

#include <iostream>

using namespace std;

/**
 * documentation here
 */
size_t hashx(const string& key, size_t table_size);

int main()
{
  int foo[99173];
  for (int k = 0; k < 99173; k++)
    {
      foo[k] = 0;
    }



  //cout << "The sum is " << sum1 << endl;
  
  string word;
  size_t hash_val;
  while (getline(cin, word))
  {
    hash_val = hashx(word, 99173);
    //cout << hash_val << endl;
  
   
      foo[hash_val] = foo[hash_val] + 1;
    // cout << foo[hash_val] << endl;
    // do something with the word
    // cout << word << endl;
    }

  int sum = 0;
  for (int i=0; i < 99173; i++)
    {
      if (foo[i] > 0)
	{
	  foo[i] = foo[i] - 1;
	}
      sum += foo[i];
    }

    cout << "The sum is " << sum << endl;
  
  return 0;
}

size_t hashx(const string& key, size_t table_size)
{
  size_t hash_val {0};
  for (auto character : key)
  {
    hash_val = 37 * hash_val + static_cast<unsigned char>(character);
  }
  return hash_val % 99173;
}
      
