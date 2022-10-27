# INFO4017_22_23_UYI
Repository for TPE and TP coding

## INFO4017_22_23_UYI 
### project structure

    .INFO4017_22_23_UYI
    ├── DATA                                  # DATA FILE TASKS IMPLEMENTATION
    ├── FUNCTIONS                             # FUNCTION FILE TASKS IMPLEMENTATION
    ├── INCLUDES                              # HEADER FILE TASKS IMPLEMENTATION
    ├── LIBRARIES                             # USEFULL LIBRARIES
    ├── LOGS                                  # LOGS DIRECTORY
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
* [x] ``globalSequenceAlignment.cpp`` implementation of sequence global alignment within DP paradim


```pascal
Program: GSA
    entries: X, Y string
            PD table de programmation dynamique orientée
    outputs: _GSA vector of alignment
begin:
    a := {(len(X),len(Y))}
    _X := {}
    _Y := {}
    while a != empty do
        local_X := {}
        local_Y := {}
        local_a := {}
        for all (i,j) in a do
            if exists only one arrows in (i,j) cell then
                if match or mismatch then 
                    for all xi in _X do 
                        local_X := local_X U X[i] +  xi 
                    endfor
                    for all yi in _Y do 
                        local_Y := local_Y U Y[j] +  yi 
                    endfor
                    local_a := local_a U (i-1,j-1)
                else if vertical gap then
                    for all xi in _X do 
                        local_X := local_X U '_' + xi 
                    endfor
                    for all yi in _Y do 
                        local_Y := local_Y U Y[j] + yi 
                    endfor
                    local_a := local_a U (i,j-1)
                else if horizontal gap then
                    for all xi in _X do 
                        local_X := local_X U X[i] +  xi 
                    endfor
                    for all yi in _Y do 
                        local_Y := local_Y U '_' +  yi 
                    endfor
                    local_a := local_a U (i-1,j)
                else 
                    if i == 0 and j > 0 then
                        for all xi in _X do 
                            local_X := local_X U '_' +  xi 
                        endfor
                        for all yi in _Y do 
                            local_Y := local_Y U Y[j] +  yi 
                        endfor
                    else if j == 0 and i > 0 then
                        for all xi in _X do 
                            local_X := local_X U X[i] +  xi 
                        endfor
                        for all yi in _Y do 
                            local_Y := local_Y U '_' +  yi 
                        endfor
                    sinon 
                        for all xi in _X do 
                            local_X := local_X U xi 
                        endfor
                        for all yi in _Y do 
                            local_Y := local_Y U yi 
                        endfor
                    endif
                endif
            else
                if exists more than one arrows in (i,j) cell then
                    if match or mismatch then 
                        for all xi in _X do 
                            local_X := local_X U X[i] +  xi 
                        endfor
                        for all yi in _Y do 
                            local_Y := local_Y U Y[j] +  yi 
                        endfor  
                        local_a := local_a U (i-1,j-1)
                    endif
                    if vertical gap then
                        for all xi in _X do 
                            local_X := local_X U '_' + xi 
                        endfor
                        for all yi in _Y do 
                            local_Y := local_Y U Y[j] + yi 
                        endfor
                        local_a := local_a U (i,j-1)
                    endif
                    if horizontal gap then
                        for all xi in _X do 
                            local_X := local_X U X[i] +  xi 
                        endfor
                        for all yi in _Y do 
                            local_Y := local_Y U '_' +  yi 
                        endfor
                        local_a := local_a U (i-1,j)
                    endif
                endif
            endif
        endfor
        _X := local_X
        _Y := local_Y
        a := local_a
    endwhile
endprog
```

|n*m| word 1 (n) | word 2 (m)| solution | time ms|
|:----------------:|:------:|:-----:|:--------:|:---:|
|4*4|[here](data/gsa/a.data)|[here](data/gsa/b.data)|[here](data/gsa/ab.data)||
|10*4|[here](data/gsa/arn_10.data)|[here](data/gsa/a.data)|[here](data/gsa/arn_10_4.data)||
|15*4|[here](data/gsa/arn_15.data)|[here](data/gsa/b.data)|[here](data/gsa/arn_15_4.data)||
|15*10|[here](data/gsa/arn_15.data)|[here](data/gsa/arn_10.data)|[here](data/gsa/arn_15_10.data)||
|20*4|[here](data/gsa/arn_20.data)|[here](data/gsa/a.data)|[here](data/gsa/arn_20_4.data)||
|20*10|[here](data/gsa/arn_20.data)|[here](data/gsa/arn_10.data)|[here](data/gsa/arn_20_10.data)||
|20*15|[here](data/gsa/arn_20.data)|[here](data/gsa/arn_15.data)|[here](data/gsa/arn_20_15.data)||
|25*4|[here](data/gsa/arn_15.data)|[here](data/gsa/b.data)|[here](data/gsa/arn_25_4.data)||
|25*10|[here](data/gsa/arn_25.data)|[here](data/gsa/arn_10.data)|[here](data/gsa/arn_25_10.data)||
|25*15|[here](data/gsa/arn_25.data)|[here](data/gsa/arn_15.data)|[here](data/gsa/arn_25_15.data)||
|25*20|[here](data/gsa/arn_25.data)|[here](data/gsa/arn_20.data)|[here](data/gsa/arn_25_20.data)||
|30*4|[here](data/gsa/arn_30.data)|[here](data/gsa/a.data)|[here](data/gsa/arn_30_4.data)||
|30*10|[here](data/gsa/arn_30.data)|[here](data/gsa/arn_10.data)|[here](data/gsa/arn_30_10.data)||
|30*15|[here](data/gsa/arn_30.data)|[here](data/gsa/arn_15.data)|[here](data/gsa/arn_30_15.data)||
|30*20|[here](data/gsa/arn_30.data)|[here](data/gsa/arn_20.data)|[here](data/gsa/arn_30_20.data)||
|30*25|[here](data/gsa/arn_30.data)|[here](data/gsa/arn_25.data)|[here](data/gsa/arn_30_25.data)||
|45*50|[here](data/gsa/arn_45.data)|[here](data/gsa/arn_50.data)|[here](data/gsa/arn_45_50.data)||
|70*50|[here](data/gsa/arn_70.data)|[here](data/gsa/arn_50.data)|[here](data/gsa/arn_70_50.data)||

* [ ] ``pgcb.cpp`` implementation of the most big white square
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