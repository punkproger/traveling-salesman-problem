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
| -i            | Optimization iterations count | unsigned int, default: while can optimize |
| -a            | algorithm |   {brute_force, christofides}, default: christofides |
| -o            | output image name      |    <name.bmp> |

First argument is always path to file with coordinates of city

### test/tsp_example_0.txt:
![Image of test/tsp_example_0.txt](https://github.com/punkproger/traveling-salesman-problem/blob/commivoyager_problem_issue_implementing/images/cities_0.bmp)

### test/tsp_example_1.txt:
![Image of test/tsp_example_1.txt](https://github.com/punkproger/traveling-salesman-problem/blob/commivoyager_problem_issue_implementing/images/cities_1.bmp)

### test/tsp_example_2.txt:
![Image of test/tsp_example_1.txt](https://github.com/punkproger/traveling-salesman-problem/blob/commivoyager_problem_issue_implementing/images/cities_2.bmp)
