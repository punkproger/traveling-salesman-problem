# traveling-salesman-problem

#### Build
```
git clone git@github.com:punkproger/traveling-salesman-problem.git
cd traveling-salesman-problem
make
```

#### Run test file
```
./tsp test/tsp_example_1.txt -i 20 -a christofides -o cities.bmp
```

##### Flags
`./tsp [FILE] [-i ITERATIONS]...  [-a ALGORITHM]... [-o FILE]...`

| Flag          | Meaning       | Values|
| ------------- |:-------------:| -----:|
| -i            | Optimization iterations count | unsigned int |
| -a            | algorithm |   {brute_force, christofides}, default: christofides |
| -o            | output image name      |    <name.bmp> |
