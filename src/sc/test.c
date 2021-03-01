#include "benchmark.h"

#include "sc_map.h"

int test_int(int N, const unsigned *data)
{
  struct sc_map_32 map;
  
  sc_map_init_32(&map, 0, 0);
  
  unsigned i;
  unsigned count;
  unsigned val;

  for (i = 0; i < N; i ++)
    {
    	if (sc_map_get_32(&map, data[i], &val))
    	  sc_map_del_32(&map, data[i], NULL);
    	else
    	  sc_map_put_32(&map, data[i], data[i]);
    }

  count = sc_map_size_32(&map);
  
  sc_map_term_32(&map);

  return count;
}
int test_str(int N, char * const *data)
{
  struct sc_map_s32 map;
  
  sc_map_init_s32(&map, 0, 0);
  
  unsigned i;
  unsigned count;
  uint32_t val;

  for (i = 0; i < N; i ++)
    {
    	if (sc_map_get_s32(&map, data[i], &val))
    	  sc_map_del_s32(&map, data[i], NULL);
    	else
    	  sc_map_put_s32(&map, data[i], i);
    }

  count = sc_map_size_s32(&map);
  
  sc_map_term_s32(&map);

  return count;
}

int main(int argc, char *argv[])
{
	return udb_benchmark(argc, argv, test_int, test_str);
}
