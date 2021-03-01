#include "benchmark.h"
#include "HashMap.h"
#include <cstring>
#include <string_view>

using namespace rigtorp;

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

struct hasher
{  
  size_t operator () (char * key) { return std::hash<std::string_view>()(std::string_view(key, std::strlen(key))); }
};


struct equaler
{
  inline bool operator () (char * s1, char * s2) { return ! strcmp (s1, s2); }
};


typedef rigtorp::HashMap<unsigned, unsigned>                hashtable_int_t;
typedef rigtorp::HashMap<char *, unsigned, hasher, equaler> hashtable_str_t;

int test_int(int N, const unsigned *data)
{
  /* Create a HashMap with n buckets and -1 as the empty key */
  hashtable_int_t * ht = new hashtable_int_t (N, -1);
  int i;
  unsigned count;

  for (i = 0; i < N; i ++)
    {
      hashtable_int_t::iterator hit = ht -> find (data [i]);
      if (hit != ht -> end ())
	ht -> erase (hit);
      else
	ht -> insert ({data [i], i});
    }

  count = ht -> size ();

  delete ht;

  return count;
}


int test_str(int N, char * const *data)
{
  /* Create a HashMap with n buckets and "" as the empty key */
  hashtable_str_t * ht = new hashtable_str_t (N, (char *)"");
  int i;
  unsigned count;

  for (i = 0; i < N; i ++)
    {
      hashtable_str_t::iterator hit = ht -> find (data [i]);
      if (hit != ht -> end ())
	ht -> erase (hit);
      else
	ht -> insert ({data [i], i});
    }

  count = ht -> size ();

  delete ht;

  return count;
}

int main(int argc, char *argv[])
{
	return udb_benchmark(argc, argv, test_int, test_str);
}

