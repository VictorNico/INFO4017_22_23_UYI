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

|n*m| word 1 (n) | word 2 (m)| solution | time ms| number of alignments|
|:----------------:|:------:|:-----:|:--------:|:---:|:---:|
|4*4|[here](data/gsa/a.data)|[here](data/gsa/b.data)|[here](data/gsa/ab.data)|0|3|
|10*4|[here](data/gsa/arn_10.data)|[here](data/gsa/a.data)|[here](data/gsa/arn_10_4.data)|0|17|
|15*4|[here](data/gsa/arn_15.data)|[here](data/gsa/b.data)|[here](data/gsa/arn_15_4.data)|0|18|
|15*10|[here](data/gsa/arn_15.data)|[here](data/gsa/arn_10.data)|[here](data/gsa/arn_15_10.data)|0|54|
|20*4|[here](data/gsa/arn_20.data)|[here](data/gsa/a.data)|[here](data/gsa/arn_20_4.data)|0|31|
|20*10|[here](data/gsa/arn_20.data)|[here](data/gsa/arn_10.data)|[here](data/gsa/arn_20_10.data)|0|45|
|20*15|[here](data/gsa/arn_20.data)|[here](data/gsa/arn_15.data)|[here](data/gsa/arn_20_15.data)|25000|3114|
|25*4|[here](data/gsa/arn_15.data)|[here](data/gsa/b.data)|[here](data/gsa/arn_25_4.data)|0|4|
|25*10|[here](data/gsa/arn_25.data)|[here](data/gsa/arn_10.data)|[here](data/gsa/arn_25_10.data)|0|39|
|25*15|[here](data/gsa/arn_25.data)|[here](data/gsa/arn_15.data)|[here](data/gsa/arn_25_15.data)|1000|59|
|25*20|[here](data/gsa/arn_25.data)|[here](data/gsa/arn_20.data)|[here](data/gsa/arn_25_20.data)|26000|1691|
|30*4|[here](data/gsa/arn_30.data)|[here](data/gsa/a.data)|[here](data/gsa/arn_30_4.data)|1000|33|
|30*10|[here](data/gsa/arn_30.data)|[here](data/gsa/arn_10.data)|[here](data/gsa/arn_30_10.data)|0|14|
|30*15|[here](data/gsa/arn_30.data)|[here](data/gsa/arn_15.data)|[here](data/gsa/arn_30_15.data)|1000|479|
|30*20|[here](data/gsa/arn_30.data)|[here](data/gsa/arn_20.data)|[here](data/gsa/arn_30_20.data)|0|84|
|30*25|[here](data/gsa/arn_30.data)|[here](data/gsa/arn_25.data)|[here](data/gsa/arn_30_25.data)|4000|140|
|45*50|[here](data/gsa/arn_45.data)|[here](data/gsa/arn_50.data)|[here](data/gsa/arn_45_50.data)|137000|1520|

* [x] ``pgcb.cpp`` implementation of the most big white square

```pascal
fonction PGCB(n)
 pour x = 1 à n
    pour y = 1 à n
        si (x,y) est noir
           pgcb[x,y] = 0
        sinon si x = 1 ou y = 1
            pgcb[x,y] = 1
        sinon
           pgcb[x,y] = 1 + min{pgcb(x-1,y-1),pgcb(x,y-1),pgcb(x-1,y)}

```

```pascal

Programme PGCB
    données:    A matrice binaire représentant l'image chromatique
                n la taille de la matrice binaire
    resultats: (_c,_x,_y) 
    variables:  _pgcb un tableau,
                _c,_x,_y des d'entier
Debut
    // cette version de l'algorithme de pgcb retourne à la fois la taille _c des plus grand carré blanc 
    // et deux vecteur _x,_y représentation conjointement les différentes position de pixels
    // en bas à droit de ses grand carré blanc

    // tout d'abord redimensionner _pgcd suivant la taille de l'image prise en paramètre
    redim(_pgcb,n);

    // initialisons la taille maximal du plus grand carré
    _c = -1;

    // contruction
    pour i de 1 à n faire
        pour j de 1 à n faire 
            _pgcb[i][j] = 0
        finpour
    finpour
    // remplissage du tableau de programmation dynamique
    pour i de 1 à n faire
        pour j de 1 à n faire 
            si A[i][j] == 0 alors // où 0 matérialise le blanc dans notre image chromatique
                si i == 0 ou j == 0 alors
                    _pgcb[i][j] = 1
                    si _c < 1 alors
                        vider(_x)
                        vider(_y)
                        _c = 1
                        _x.ajouter(i)
                        _y.ajouter(j)
                    sinon
                        si _c == 1 alors 
                            _x.ajouter(i)
                            _y.ajouter(j)
                        finsi
                    finsi
                sinon
                    _pgcb[i][j] = min(_pgcb[i-1][j-1],min(_pgcb[i][j-1],_pgcb[i-1][j]))
                    si _c < _pgcb[i][j] alors
                        vider(_x)
                        vider(_y)
                        _c = _pgcb[i][j]
                        _x.ajouter(i)
                        _y.ajouter(j)
                    sinon
                        si _c == _pgcb[i][j] alors 
                            _x.ajouter(i)
                            _y.ajouter(j)
                        finsi
                    finsi
                finsi
            finsi
        finpour
    finpour
    // retourner la solution
    retourner (_c,_x,_y)
fin

```
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