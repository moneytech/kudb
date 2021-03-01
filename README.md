# Overview
Benchmark of C and C++ hashmaps.  

C++ has a detailed benchmark here : https://martin.ankerl.com/2019/04/01/hashmap-benchmarks-01-overview/  
Unfortunately, it is not easy to add C hashmaps to that benchmark. So, this repository is for C and C++ hashmap benchmarks.

# tl;dr

These hashmaps perform better than others :
- [rigtorp_hashmap (C++)](https://github.com/rigtorp/HashMap)
- [sc (C)](https://github.com/tezc/sc)
- [khash (C)](https://github.com/attractivechaos/klib)
- [rdestl (C++)](https://github.com/msinilo/rdestl)

# Results for the impatients

<pre>
Integer test results sorted by CPU Time
=========================================================
Implementation        | CPU (secs) | Memory (kB) |    #
 1| rigtorp_hashmap   |      0.140 |  283128.000 | 625792
 2| sc                |      0.150 |  224688.000 | 625792
 3| rdestl            |      0.230 |  260920.000 | 625792
 4| khash             |      0.270 |  229164.000 | 625792
 5| stb_hash          |      0.570 |  233288.000 | 625792
 6| _qt_qhash         |      0.720 |  248196.000 | 625792
 7| sgi_hash_map      |      0.730 |  243364.000 | 625792
 8| _glib_hash        |      0.870 |  253364.000 | 625792
 9| _boost_hash       |      1.180 |  243264.000 | 625792
10| uthash            |      1.190 |  274100.000 | 625792
11| htable            |      1.250 |  297928.000 | 625792
12| stx_btree         |      1.370 |  226716.000 | 625792
13| kbtree            |      1.840 |  225124.000 | 625792
14| TN_rbtree         |      2.830 |  247020.000 | 625792
15| libavl_rb_cpp2    |      2.890 |  237040.000 | 625792
16| sgi_map           |      3.250 |  247044.000 | 625792
17| NP_rbtree         |      3.560 |  245648.000 | 625792
18| libavl_avl_cpp    |      3.740 |  246972.000 | 625792
19| JE_rb_new         |      4.300 |  235900.000 | 625792
20| JE_trp_prng       |      4.330 |  245560.000 | 625792
21| JE_trp_hash       |      4.340 |  235848.000 | 625792
22| sglib_rbtree      |      4.460 |  245572.000 | 625792
23| libavl_prb        |      4.750 |  265192.000 | 625792
24| NP_splaytree      |      5.000 |  235916.000 | 625792
25| libavl_avl        |      5.090 |  265192.000 | 625792
26| libavl_rb         |      5.420 |  265220.000 | 625792
27| JG_btree          |      5.610 |  257004.000 | 625792
28| _glib_tree        |      6.090 |  271528.000 | 625792
29| libavl_bst        |      6.870 |  255324.000 | 625792
30| _qt_qmap          |      7.530 |  240232.000 | 625792

String test results sorted by CPU Time
=========================================================
Implementation        | CPU (secs) | Memory (kB) |    #
 1| rdestl            |      0.540 |  291432.000 | 625792
 2| sc                |      0.760 |  240192.000 | 625792
 3| rigtorp_hashmap   |      0.800 |  348480.000 | 625792
 4| khash             |      0.890 |  235248.000 | 625792
 5| _glib_hash        |      1.140 |  249088.000 | 625792
 6| _qt_qhash         |      1.230 |  257052.000 | 625792
 7| htable            |      1.280 |  298080.000 | 625792
 8| sgi_hash_map      |      1.310 |  243156.000 | 625792
 9| stb_hash          |      1.490 |  249768.000 | 625792
10| uthash            |      1.730 |  273160.000 | 625792
11| _boost_hash       |      1.790 |  255300.000 | 625792
12| stx_btree         |      5.060 |  232040.000 | 625792
13| kbtree            |      5.880 |  233532.000 | 625792
14| libavl_avl_cpp    |      6.870 |  247024.000 | 625792
15| NP_rbtree         |      7.430 |  255440.000 | 625792
16| libavl_rb_cpp2    |      7.670 |  246812.000 | 625792
17| _glib_tree        |      7.770 |  271600.000 | 625792
18| sglib_rbtree      |      8.430 |  245572.000 | 625792
19| TN_rbtree         |      8.520 |  256756.000 | 625792
20| libavl_avl        |      8.750 |  265192.000 | 625792
21| libavl_prb        |      9.180 |  265236.000 | 625792
22| sgi_map           |      9.300 |  256664.000 | 625792
23| libavl_rb         |      9.840 |  265240.000 | 625792
24| JG_btree          |     10.280 |  256908.000 | 625792
25| NP_splaytree      |     11.360 |  245656.000 | 625792
26| libavl_bst        |     11.580 |  255432.000 | 625792
27| _qt_qmap          |     11.960 |  249108.000 | 625792
28| JE_trp_prng       |     12.340 |  245580.000 | 625792
29| JE_trp_hash       |     13.070 |  245700.000 | 625792

Integer test results sorted by Memory
=========================================================
Implementation        | CPU (secs) | Memory (kB) |    #
 1| sc                |      0.150 |  224688.000 | 625792
 2| kbtree            |      1.840 |  225124.000 | 625792
 3| stx_btree         |      1.370 |  226716.000 | 625792
 4| khash             |      0.270 |  229164.000 | 625792
 5| stb_hash          |      0.570 |  233288.000 | 625792
 6| JE_trp_hash       |      4.340 |  235848.000 | 625792
 7| JE_rb_new         |      4.300 |  235900.000 | 625792
 8| NP_splaytree      |      5.000 |  235916.000 | 625792
 9| libavl_rb_cpp2    |      2.890 |  237040.000 | 625792
10| _qt_qmap          |      7.530 |  240232.000 | 625792
11| _boost_hash       |      1.180 |  243264.000 | 625792
12| sgi_hash_map      |      0.730 |  243364.000 | 625792
13| JE_trp_prng       |      4.330 |  245560.000 | 625792
14| sglib_rbtree      |      4.460 |  245572.000 | 625792
15| NP_rbtree         |      3.560 |  245648.000 | 625792
16| libavl_avl_cpp    |      3.740 |  246972.000 | 625792
17| TN_rbtree         |      2.830 |  247020.000 | 625792
18| sgi_map           |      3.250 |  247044.000 | 625792
19| _qt_qhash         |      0.720 |  248196.000 | 625792
20| _glib_hash        |      0.870 |  253364.000 | 625792
21| libavl_bst        |      6.870 |  255324.000 | 625792
22| JG_btree          |      5.610 |  257004.000 | 625792
23| rdestl            |      0.230 |  260920.000 | 625792
24| libavl_avl        |      5.090 |  265192.000 | 625792
25| libavl_prb        |      4.750 |  265192.000 | 625792
26| libavl_rb         |      5.420 |  265220.000 | 625792
27| _glib_tree        |      6.090 |  271528.000 | 625792
28| uthash            |      1.190 |  274100.000 | 625792
29| rigtorp_hashmap   |      0.140 |  283128.000 | 625792
30| htable            |      1.250 |  297928.000 | 625792

String test results sorted by Memory
=========================================================
Implementation        | CPU (secs) | Memory (kB) |    #
 1| stx_btree         |      5.060 |  232040.000 | 625792
 2| kbtree            |      5.880 |  233532.000 | 625792
 3| khash             |      0.890 |  235248.000 | 625792
 4| sc                |      0.760 |  240192.000 | 625792
 5| sgi_hash_map      |      1.310 |  243156.000 | 625792
 6| sglib_rbtree      |      8.430 |  245572.000 | 625792
 7| JE_trp_prng       |     12.340 |  245580.000 | 625792
 8| NP_splaytree      |     11.360 |  245656.000 | 625792
 9| JE_trp_hash       |     13.070 |  245700.000 | 625792
10| libavl_rb_cpp2    |      7.670 |  246812.000 | 625792
11| libavl_avl_cpp    |      6.870 |  247024.000 | 625792
12| _glib_hash        |      1.140 |  249088.000 | 625792
13| _qt_qmap          |     11.960 |  249108.000 | 625792
14| stb_hash          |      1.490 |  249768.000 | 625792
15| _boost_hash       |      1.790 |  255300.000 | 625792
16| libavl_bst        |     11.580 |  255432.000 | 625792
17| NP_rbtree         |      7.430 |  255440.000 | 625792
18| sgi_map           |      9.300 |  256664.000 | 625792
19| TN_rbtree         |      8.520 |  256756.000 | 625792
20| JG_btree          |     10.280 |  256908.000 | 625792
21| _qt_qhash         |      1.230 |  257052.000 | 625792
22| libavl_avl        |      8.750 |  265192.000 | 625792
23| libavl_prb        |      9.180 |  265236.000 | 625792
24| libavl_rb         |      9.840 |  265240.000 | 625792
25| _glib_tree        |      7.770 |  271600.000 | 625792
26| uthash            |      1.730 |  273160.000 | 625792
27| rdestl            |      0.540 |  291432.000 | 625792
28| htable            |      1.280 |  298080.000 | 625792
29| rigtorp_hashmap   |      0.800 |  348480.000 | 625792

</pre>
