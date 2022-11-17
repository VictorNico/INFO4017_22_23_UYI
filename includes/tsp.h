/*
 * tsp.h
 */

#ifndef __TSP_H__
#define __TSP_H__

#include <cstdarg>
#include <cstddef>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <numeric>
#include <complex>
#include <list>
#include <map>
#include <set>
#include <valarray>
#include <memory>
#include <algorithm>
#include <functional>
#include <typeinfo>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cassert>

#include "matrix.h"

#define DELETE_PTR(p) \
    if ((p) != 0)     \
    {                 \
        delete (p);   \
        (p) = 0;      \
    }
#define DELETE_PTRA(p) \
    if ((p) != 0)      \
    {                  \
        delete[](p);   \
        (p) = 0;       \
    }

/**
 * A city is just a point in the 2D plane
 */
typedef pair<float, float> City;

/**
 * This is a TSP problem instance. It defines the number of cities and the 
 * pairwise distances. 
 */
class TSPInstance
{
public:
    /**
     * Adds a single point to the list of cities
     */
    void addCity(const pair<float, float> &city)
    {
        cities.push_back(city);
    }

    /**
     * Creates a random TSP instance of n nodes
     */
    void createRandom(int n);

    /**
     * Sets up the distance matrix
     */
    void calcDistanceMatrix();

    /**
     * Calculates the length of a tour
     */
    float calcTourLength(const vector<int> &tour) ;

    /**
     * Returns the distance between cities i and j
     */
    float dist(int i, int j)
    {
        return distances.getVal(i, j);
    }

    /**
     * Returns the distance between two cities
     */
    float dist(const City &c1, const City &c2) const
    {
        const float temp1 = c1.first - c2.first;
        const float temp2 = c1.second - c2.second;
        return sqrt((temp1 * temp1 + temp2 * temp2));
    }

    /**
     * Returns the cities
     */
    const vector<City> &getCities()
    {
        return cities;
    }

private:
    /**
     * The positions of the cities
     */
    vector<City> cities;
    /**
     * The distance matrix
     */
    Matrix distances;
};

/**
 * This is the optimizer. It implements the basic simulated annealing algorithm
 * and several neighborhood moves. 
 */
class Optimizer
{
public:
    /**
     * The runtime configuration of the algorithm
     */
    class Config
    {
    public:
        Config() : temp(0), outer(0), inner(0), energy(0), bestEnergy(0), terminated(false) {}
        /**
         * The current temperature
         */
        float temp;
        /**
         * The current outer loop
         */
        int outer;
        /**
         * The current inner loop
         */
        int inner;
        /**
         * The current objective
         */
        float energy;
        /**
         * The currently best energy found
         */
        float bestEnergy;
        /**
         * Current state
         */
        vector<int> state;
        /**
         * The best state observed so far
         */
        vector<int> bestState;
        /**
         * Whether or not the system has terminated
         */
        bool terminated;
    };

    /**
     * This class implements an observer for the optimizer. The observers can 
     * watch the optimization process
     */
    class Observer
    {
    public:
        /**
         * This method is called by the optimizer
         */
        virtual void notify(TSPInstance &instance, const Config &config){};
    };

    /**
     * This class defines a cooling schedule
     */
    class CoolingSchedule
    {
    public:
        /**
         * Calculates the next temperature
         */
        virtual float nextTemp(const Config &config) const = 0;
        /**
         * Returns the initial temperature
         */
        virtual float initialTemp() const = 0;
    };

    /**
     * This is a move service class that allows the random sampling of cities
     */
    class MoveService
    {
    public:
        /**
         * Constructor
         */
        MoveService(int numCities) : generator(random_device{}()),
                                     distribution(1, numCities - 1) {}

        /* {
            generator = mt19937(random_device{}());
            distribution = uniform_int_distribution<int>(1, numCities - 1);
        } */

        /**
         * Returns a random city
         */
        int sample()
        {
            return distribution(generator);
        }

    private:
        /**
         * The random number generator
         */
        mt19937 generator;
        /**
         * The distribution over the cities
         */
        uniform_int_distribution<int> distribution;
    };

    /**
     * This class implements a single neighborhood move
     */
    class Move
    {
    public:
        /**
         * Computes a random neighbor according to some move strategy
         */
        virtual void propose(vector<int> &state) const = 0;

        /**
         * Sets the move service
         */
        void setMoveService(MoveService *_service)
        {
            service = _service;
        }

    protected:
        /**
         * The move service
         */
        MoveService *service;
    };

    /**
     * Constructor
     */
    Optimizer() : coolingSchedule(0),
                  outerLoops(100),
                  innerLoops(1000),
                  notificationCycle(250) {}

    /**
     * The cooling schedule
     */
    CoolingSchedule *coolingSchedule;
    /**
     * The number of outer iterations
     */
    int outerLoops;
    /**
     * The number of inner iterations
     */
    int innerLoops;
    /**
     * The notification cycle. Every c iterations, the observers are notified
     */
    int notificationCycle;

    /**
     * Runs the optimizer on a specific problem instance
     */
    void optimize(TSPInstance &instance, vector<int> &result);

    /**
     * Adds an observer
     */
    void addObserver(Observer *observer)
    {
        observers.push_back(observer);
    }

    /**
     * Adds a move
     */
    void addMove(Move *move)
    {
        moves.push_back(move);
    }

private:
    /**
     * A list of observers
     */
    vector<Observer *> observers;
    /**
     * A list of move classes
     */
    vector<Move *> moves;
};

/**
 * This is a geometric cooling schedule
 */
class GeometricCoolingSchedule : public Optimizer::CoolingSchedule
{
public:
    /**
     * Constructor
     */
    GeometricCoolingSchedule(float initialTemp, float endTemp, float alpha) : iTemp(initialTemp),
                                                                              eTemp(endTemp),
                                                                              alpha(alpha) {}

    /**
     * Calculates the next temperature
     */
    virtual float nextTemp(const Optimizer::Config &config) const
    {
        return max(config.temp * alpha, eTemp);
    }

    /**
     * Returns the initial temperature
     */
    virtual float initialTemp() const
    {
        return iTemp;
    }

private:
    /**
     * The initial temperature
     */
    float iTemp;
    /**
     * End temperature
     */
    float eTemp;
    /**
     * alpha -> Decreasing constant
     */
    float alpha;
};

/**
 * This move reverses the order of a chain
 */
class ChainReverseMove : public Optimizer::Move
{
public:
    /**
     * Computes a random neighbor according to some move strategy
     */
    virtual void propose(vector<int> &state) const
    {
        // Sample two random cities and reverse the chain
        reverse(state.begin() + service->sample(), state.begin() + service->sample());
    }
};

/**
 * This move exchanges two cities in the current path
 */
class SwapCityMove : public Optimizer::Move
{
public:
    /**
     * Computes a random neighbor according to some move strategy
     */
    virtual void propose(vector<int> &state) const
    {
        swap(state[service->sample()], state[service->sample()]);
    }
};

/**
 * This move rotates the current path
 */
class RotateCityMove : public Optimizer::Move
{
public:
    /**
     * Computes a random neighbor according to some move strategy
     */
    virtual void propose(vector<int> &state) const
    {
        vector<int> c({service->sample(), service->sample(), service->sample()});
        sort(c.begin(), c.end());

        rotate(state.begin() + c[0],
                    state.begin() + c[1],
                    state.begin() + c[2]);
    }
};

/**
 * This is the runtime GUI that let's you watch what happens during the 
 * optimization procedure
 */
class RuntimeGUIDot : public Optimizer::Observer
{
public:
    /**
     * Constructor
     */
    RuntimeGUIDot(){}

    /**
     * Destructor
     */
    ~RuntimeGUIDot(){}

    /**
     * Paint the gui
     */
    virtual void notify(TSPInstance &instance, const Optimizer::Config &config);
};

void TSPActionOption(int &, TSPInstance &, int &);
void TSPActionMenu();
void TSPLauncher();
void TSPGetNumCities(int &num);
double round_up(double, int);

#endif