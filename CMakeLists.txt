cmake_minimum_required(VERSION 3.5)
project(code)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    dp/fixedsum.cpp
    dp/levinshtein.cpp
    "dp/NOVP NxM.cpp"
    "dp/NVP NlogN.cpp"
    "dp/psp dp.cpp"
    "dp/psp k.cpp"
    geometry/area_triangle.cpp
    geometry/basic_geom.cpp
    geometry/check_point_segment.cpp
    "geometry/intersection of segments.cpp"
    geometry/mnogoug-perebor-convexhull.cpp
    geometry/segment-dist.cpp
    geometry/tangent.cpp
    GOPSTOP/BIGINT.cpp
    GOPSTOP/fastreadwrite.cpp
    GOPSTOP/TL.cpp
    "graph/bfs on special grid.cpp"
    graph/bfs.cpp
    graph/bfs01.cpp
    "graph/components rebernoy dvusvyaz.cpp"
    graph/cut-points.cpp
    graph/cutpoints.cpp
    "graph/dfs + bfs on grid.cpp"
    "graph/dfs emaxx.cpp"
    "graph/dfs on grid.cpp"
    graph/dijkstra_fast.cpp
    graph/dijkstra_nlogn.cpp
    "graph/fast bfs on grid.cpp"
    graph/find_bridges.cpp
    graph/find_comps.cpp
    "graph/ford_bellman emaxx.cpp"
    "graph/heavy-light decomposition.cpp"
    graph/LCA.cpp
    "graph/top sort emaxx.cpp"
    "INNOPOLIS AUTUMN/DAY 1 DA или NE?/B/B.cpp"
    "INNOPOLIS AUTUMN/DAY 1 DA или NE?/C/C.cpp"
    "INNOPOLIS AUTUMN/DAY 1 DA или NE?/D/D.cpp"
    "INNOPOLIS AUTUMN/DAY 1 DA или NE?/E/E.cpp"
    "INNOPOLIS AUTUMN/DAY 1 DA или NE?/statements.pdf"
    "INNOPOLIS AUTUMN/DAY 2 Деревянный/A/A.cpp"
    "INNOPOLIS AUTUMN/DAY 2 Деревянный/B/B.cpp"
    "INNOPOLIS AUTUMN/DAY 2 Деревянный/C/C.cpp"
    "INNOPOLIS AUTUMN/DAY 2 Деревянный/D/D.cpp"
    "INNOPOLIS AUTUMN/DAY 2 Деревянный/E/E.cpp"
    "INNOPOLIS AUTUMN/DAY 2 Деревянный/F/F.cpp"
    "INNOPOLIS AUTUMN/DAY 2 Деревянный/G/G.cpp"
    "INNOPOLIS AUTUMN/DAY 2 Деревянный/H/H.cpp"
    "INNOPOLIS AUTUMN/DAY 2 Деревянный/I/I.cpp"
    "INNOPOLIS AUTUMN/DAY 2 Деревянный/J/J.cpp"
    "INNOPOLIS AUTUMN/DAY 3 Джон и его друзья/A/A.cpp"
    "INNOPOLIS AUTUMN/DAY 3 Джон и его друзья/B/B.cpp"
    "INNOPOLIS AUTUMN/DAY 3 Джон и его друзья/C/C.cpp"
    "INNOPOLIS AUTUMN/DAY 3 Джон и его друзья/E/E.cpp"
    "INNOPOLIS AUTUMN/DAY 4 Хороший контест/A/A.cpp"
    "INNOPOLIS AUTUMN/DAY 4 Хороший контест/B/B.cpp"
    "INNOPOLIS AUTUMN/DAY 4 Хороший контест/C/C.cpp"
    "INNOPOLIS AUTUMN/DAY 4 Хороший контест/D/D.cpp"
    "INNOPOLIS AUTUMN/DAY 4 Хороший контест/F/F NECKLACE.cpp"
    "INNOPOLIS AUTUMN/DAY 5 Своя поисковая система/A/main.cpp"
    "INNOPOLIS AUTUMN/DAY 5 Своя поисковая система/B/main.cpp"
    "INNOPOLIS AUTUMN/DAY 5 Своя поисковая система/D/main.cpp"
    "INNOPOLIS DAYS/Занятие. 2016-11-02/statements.pdf"
    "INNOPOLIS DAYS/Занятие. 2016-11-16/statements (1).pdf"
    "INNOPOLIS DAYS/Занятие. 2016-11-19/statements.pdf"
    "INNOPOLIS DAYS/Занятие. 2016-11-23/statements (1).pdf"
    "INNOPOLIS DAYS/Занятие. 2016-11-30/statements.pdf"
    "INNOPOLIS DAYS/Занятие. 2016-12-14/statements (1).pdf"
    "INNOPOLIS DAYS/Занятие. 2016-12-17/statements.pdf"
    "INNOPOLIS DAYS/Занятие. 2016-12-21/statements (1).pdf"
    "INNOPOLIS DAYS/Занятие. 2016-12-24/statements.pdf"
    "INNOPOLIS DAYS/Занятие. 2017-01-11/statements (1).pdf"
    "INNOPOLIS DAYS/Занятие. 2017-01-14/A/main.cpp"
    "INNOPOLIS DAYS/Занятие. 2017-01-14/B/main.cpp"
    "INNOPOLIS DAYS/Занятие. 2017-01-14/C/main.cpp"
    "INNOPOLIS DAYS/Занятие. 2017-01-14/statements.pdf"
    "LKSH/day 10/day10.pdf"
    "LKSH/day 10/day11.pdf"
    "LKSH/day 10/day12.pdf"
    "LKSH/day 10/minonpath.cpp"
    "LKSH/day 10/power.cpp"
    "LKSH/day 6/day06-dp.pdf"
    "LKSH/day 6/ravnoprav.cpp"
    "LKSH/day 6/razrezanie grafa.cpp"
    "LKSH/day 7/cubes.cpp"
    "LKSH/day 7/day7.pdf"
    "LKSH/day 8/day8.pdf"
    "LKSH/day 8/permutation.cpp"
    "LKSH/day 8/rmq naoborot.cpp"
    "LKSH/day 8/windows.cpp"
    "LKSH/day 9/alga.cpp"
    "LKSH/day 9/day9.pdf"
    "LKSH/day 9/snowmen.cpp"
    "LKSH/day 9/strike back.cpp"
    LKSH/day1/A.cpp
    LKSH/day1/day1.pdf
    "LKSH/day1/k-i null.cpp"
    LKSH/day1/kubiki.cpp
    LKSH/day1/mnogoug-perebor-convexhull.cpp
    "LKSH/day1/robot in server.cpp"
    "LKSH/day1/securet set.cpp"
    LKSH/day2/day2.pdf
    "LKSH/day2/minimum cyclik sdvig.cpp"
    LKSH/day2/obmen.cpp
    "LKSH/day2/snova v kosmos.cpp"
    LKSH/day2/substr.cpp
    LKSH/day3/day3.pdf
    "LKSH/day3/netochnoe sovpadenie.cpp"
    LKSH/day3/pod-bor.cpp
    "LKSH/day3/vasya and ciclik sdvig.cpp"
    "LKSH/day3/virus ahokoras.cpp"
    LKSH/day4/day4.pdf
    LKSH/day4/suffmasnloglogn.cpp
    LKSH/day5/aviaperelety.cpp
    "LKSH/day5/components rebernoy dvusvyaz.cpp"
    LKSH/day5/day5.pdf
    "LKSH/day5/magnitnye podushky.cpp"
    LKSH/day5/razbienie.cpp
    "LKSH/day5/traktorist 01bfs.cpp"
    LKSH/apple.cpp
    LKSH/nitochky.cpp
    "LKSH/party troiky.cpp"
    "LKSH B/DAY 3 DD/A.cpp"
    "LKSH B/DAY 3 DD/B.cpp"
    "LKSH B/DAY 3 DD/C.cpp"
    "LKSH B/DAY 3 DD/D.cpp"
    "LKSH B/DAY 3 DD/E.cpp"
    "LKSH B/main 2.cpp"
    "LKSH B/main.cpp"
    "LKSH WINTER AH/DAY1/A/main.cpp"
    "LKSH WINTER AH/DAY1/B/main.cpp"
    "LKSH WINTER AH/DAY1/C/main.cpp"
    "LKSH WINTER AH/DAY1/E/main.cpp"
    "LKSH WINTER AH/DAY1/F/main.cpp"
    "LKSH WINTER AH/DAY1/day1.pdf"
    "LKSH WINTER AH/DAY2/A/main.cpp"
    "LKSH WINTER AH/DAY2/B/main.cpp"
    "LKSH WINTER AH/DAY2/C/main.cpp"
    "LKSH WINTER AH/DAY2/E/main.cpp"
    "LKSH WINTER AH/DAY2/day2.pdf"
    "LKSH WINTER AH/DAY3/A/main.cpp"
    "LKSH WINTER AH/DAY3/B/main.cpp"
    "LKSH WINTER AH/DAY3/C/main.cpp"
    "LKSH WINTER AH/DAY3/D/main.cpp"
    "LKSH WINTER AH/DAY3/E/main.cpp"
    "LKSH WINTER AH/DAY3/F/main.cpp"
    "LKSH WINTER AH/DAY3/G/main.cpp"
    "LKSH WINTER AH/DAY3/day3.pdf"
    "LKSH WINTER AH/DAY4/A/main.cpp"
    "LKSH WINTER AH/DAY4/B/main.cpp"
    "LKSH WINTER AH/DAY4/C/main.cpp"
    "LKSH WINTER AH/DAY4/day4.pdf"
    "LKSH WINTER AH/DAY5/day6.pdf"
    "LKSH WINTER AH/DAY6/day6 (1).pdf"
    "LKSH WINTER AH/DAY7/day7.pdf"
    "LKSH WINTER AH/DAY8/A/main.cpp"
    "LKSH WINTER AH/DAY8/day8.pdf"
    "LKSH WINTER AH/зачет/A/main.cpp"
    "LKSH WINTER AH/зачет/B/main.cpp"
    "LKSH WINTER AH/зачет/D/main.cpp"
    "LKSH WINTER AH/зачет/E/main.cpp"
    "LKSH WINTER AH/зачет/H/main.cpp"
    "LKSH WINTER AH/зачет/I/main.cpp"
    "LKSH WINTER AH/зачет/J/main.cpp"
    "LKSH WINTER AH/зачет/problems-exam.pdf"
    math/BIGINT.cpp
    math/binpow.cpp
    math/convexhull.cpp
    math/DATE.cpp
    math/eratosthenes_sieve.cpp
    math/fft.cpp
    "math/point in polygon.cpp"
    "math/polygon area.cpp"
    math/prime.cpp
    parse/calculator.cpp
    "SHOP 2017 winter/DAY1/A.cpp"
    "SHOP 2017 winter/DAY1/B.cpp"
    "SHOP 2017 winter/DAY1/C.cpp"
    "SHOP 2017 winter/DAY1/D.cpp"
    "SHOP 2017 winter/DAY1/E.cpp"
    "SHOP 2017 winter/DAY1/statements.pdf"
    "SHOP 2017 winter/DAY3/A.cpp"
    "SHOP 2017 winter/DAY3/B.cpp"
    "SHOP 2017 winter/DAY3/C.cpp"
    "SHOP 2017 winter/DAY3/D.cpp"
    "SHOP 2017 winter/DAY3/F.cpp"
    "SHOP 2017 winter/DAY3/statements (1).pdf"
    "SHOP 2017 winter/DAY7/A.cpp"
    "SHOP 2017 winter/DAY7/statements.pdf"
    "SHOP 2017 winter/ПОТОКИ/A.cpp"
    "SHOP 2017 winter/ПОТОКИ/statements.pdf"
    string/ANTIHASH.cpp
    string/Hashone.cpp
    string/Hashtwo.cpp
    string/KMP.cpp
    "string/netochnoe sovpadenie.cpp"
    string/prefix-function.cpp
    string/sufarray.cpp
    "string/suffarray nloglogn.cpp"
    string/suffix_automaton.cpp
    string/suffmasnloglogn.cpp
    "string/virus ahokoras.cpp"
    string/z-function.cpp
    "struct/k-i null.cpp"
    struct/oneminbug.cpp
    struct/onesum.cpp
    struct/segment-emaxx.cpp
    struct/segment-tree-max.cpp
    struct/sqrt.cpp
    "struct/struct dodelai.cpp"
    struct/yavn.cpp
    "ZKSH/day 0/A.cpp"
    "ZKSH/day 0/B.cpp"
    "ZKSH/day 0/C.cpp"
    "ZKSH/day 0/D.cpp"
    "ZKSH/day 0/E.cpp"
    "ZKSH/day 0/F.cpp"
    "ZKSH/day 0/problems-r (5).pdf"
    "ZKSH/day 1/A.cpp"
    "ZKSH/day 1/B.cpp"
    "ZKSH/day 1/C.cpp"
    "ZKSH/day 1/D.cpp"
    "ZKSH/day 1/E.cpp"
    "ZKSH/day 1/F.cpp"
    "ZKSH/day 1/problems-r (4).pdf"
    "ZKSH/day 2/A.cpp"
    "ZKSH/day 2/B.cpp"
    "ZKSH/day 2/C.cpp"
    "ZKSH/day 2/D.cpp"
    "ZKSH/day 2/E.cpp"
    "ZKSH/day 2/G.cpp"
    "ZKSH/day 2/problems-r (7).pdf"
    "ZKSH/day 3/B.cpp"
    "ZKSH/day 3/C.cpp"
    "ZKSH/day 3/D.cpp"
    "ZKSH/day 3/E.cpp"
    "ZKSH/day 3/problems-r (23).pdf"
    "ZKSH/day 4/B.cpp"
    "ZKSH/day 4/C.cpp"
    "ZKSH/day 4/problems-r (17).pdf"
    "ZKSH/day 5/B.cpp"
    "ZKSH/day 5/C.cpp"
    "ZKSH/day 5/problems-r (24).pdf"
    "ZKSH/day 6/B.cpp"
    "ZKSH/day 6/C.cpp"
    "ZKSH/day 6/E.cpp"
    "ZKSH/day 6/problems-r (25).pdf"
    ZKSH/Парсоч/A.cpp
    ZKSH/Парсоч/B.cpp
    "ZKSH/Парсоч/problems-r (16).pdf"
    "ДП по профилю/Шоколадка.cpp"
    1.cpp
    5.cpp
    6.cpp
    bigint.cpp
    fastreadwrite.cpp)

add_executable(code ${SOURCE_FILES})