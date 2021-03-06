#include "benchmark.h"
#include <utility>
#include <ext/hash_map>
#include <string.h>

using namespace std;
using namespace __gnu_cxx;

struct eqstr {
	inline bool operator()(const char *s1, const char *s2) const {
		return strcmp(s1, s2) == 0;
    }
};

typedef hash_map<unsigned, int, __gnu_cxx::hash<unsigned> > inthash;
typedef hash_map<const char*, int, __gnu_cxx::hash<const char*>, eqstr> strhash;


int test_int(int N, const unsigned *data)
{
	int i, ret;
	inthash *h = new inthash;
	for (i = 0; i < N; ++i) {
		pair<inthash::iterator, bool> p = h->insert(pair<unsigned, int>(data[i], i));
		if (p.second == false) h->erase(p.first);
	}
	ret = h->size();
	delete h;
	return ret;
}

int test_str(int N, char * const *data)
{
	int i, ret;
	strhash *h = new strhash;
	for (i = 0; i < N; ++i) {
		pair<strhash::iterator, bool> p = h->insert(pair<const char*, int>(data[i], i));
		if (p.second == false) h->erase(p.first);
	}
	ret = h->size();
	delete h;
	return ret;
}

int main(int argc, char *argv[])
{
	return udb_benchmark(argc, argv, test_int, test_str);
}
