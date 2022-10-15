# INFO4017_22_23_UYI
Repository for TPE and TP coding

## INFO4017_22_23_UYI 
### project structure

    .INFO4017_22_23_UYI
    ├── DATA                                  # DATA FILE TASKS IMPLEMENTATION
    ├── FUNCTIONS                             # FUNCTION FILE TASKS IMPLEMENTATION
    ├── INCLUDES                              # HEADER FILE TASKS IMPLEMENTATION
    ├── LIBRARIES                             # USEFULL LIBRARIES
    ├── LICENCE                               # LICENCE DECLARATION OF CODE BASED IMPLEMENTATION
    ├── README.md                             # documentation file
    ├── Makefile                              # EXECUTION SCRIPTS FOR PRODUCTION
    ├── *.cpp                                 # TASKS GUI ENTRY POINT
    ├── setup                                 # EXECUTABLE GUI ENTRY POINT
    └── setup.cpp                             # MAIN GUI ENTRY POINT


### Tasks

* [x] ``strassen.cpp`` implementation of matrix mult within DPR paradigm
* [x] ``lcs.cpp`` implementation of LCS problem solving with PD paradigm
* [x] ``setup.cpp`` implementation of user gui
* [ ] ``globalSequenceAlignment.cpp`` implementation of sequence global alignment within DP paradigm
* [ ] ``karatsuba.cpp`` implementation of polynom mult within DPR paradigm
* [ ] ``sac_a_dos.cpp`` implementation of whole backpack problem within PD paradigm
* [ ] ``tree.cpp`` implementation of tree methods such as pre-fixed, post-fixed and in-fixed, deep route, ...
* [ ] ``graph.cpp`` implementation of tree methods such as prim, kuuskal, ...
* [ ] ``knn.cpp`` implementation of k nearest neighbors method, for k 2,3, ...
* [ ] ``sort.cpp`` implementation of sort method, such as fusion sort, bubble sort, ...
* [ ] ``fibonacci.cpp`` implementation of fibonacci method
* [ ] ``market_traveling.cpp`` implementation of market traveling problem
* [ ] ``sequence_alignment.cpp`` implementation of sequence alignment problem in genetic, ...

### Scripts d'installation

**clone project**
* _https link_ 
```{bash}
git clone https://github.com/VictorNico/INFO4017_22_23_UYI.git
```
* _ssh link_ 
```{bash}
git clone git@github.com:VictorNico/INFO4017_22_23_UYI.git
```
* _github command_
```{bash}
gh repo clone VictorNico/INFO4017_22_23_UYI
```
**change directory of task**
```{bash}
cd INFO4017_22_23_UYI/task
```
**usage**
* _reset_
```{bash}
make clean
```
* _compile_
```{bash}
make
```
* _execute_

___without debugging flag___
```{bash}
./setup
```
___with debugging flags___
```{bash}
./setup -g 
```

__``Notice``__ : -g is use to show some methods 
progression along the time execution.