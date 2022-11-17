/*
 * TSP.cpp
 */

#include "./includes/tsp.h"

void TSPLauncher()
{

    // welcome menu
    cout << "  WELCOME TO TSP USING SA " << endl;
    cout << "  YOU'RE ABLE TO FIND OUT THE BEST PATH INSIDE TSP PROBLEM WITHING SA META-HEURISTIC " << endl;
    cout << "  YOU JUST NEED TO ENTER NUMBER OF CITIES OF YOUR DESIRED TSP INSTANCE " << endl;
    cout << "  LET'S START " << endl;

    // variables and constant declaration
    // Set up a random problem instance
    TSPInstance instance;
    int _nbCities = -1, flag = 0;


    TSPActionOption(_nbCities,instance,flag);
}

void TSPActionMenu()
{
    cout << "\n\n  HIT THE NUMBER BEHIND THE ACTION TO LAUNCH " << endl;
    cout << "  1) ENTER CITIES NUMBER " << endl;
    cout << "  2) PRINT CITIES  " << endl;
    cout << "  3) LAUNCH TSP WITH SA OPTIMIZER " << endl;
    cout << "  0) EXIT " << endl;
}

void TSPActionOption(int &_nbCities, TSPInstance &instance, int &flag)
{
    int option = -1;
    string action;
    do
    {
        // always show action option to users
        TSPActionMenu();

        // get users option from command line
        // gettng path
        do
        {

            cout << "\n  CHOOSE YOUR ACTION " << endl;
            action = getInputUser();
            // cout << tryParse(action, option) << option << endl;
        } while (TryParse(action, option, 4, 0) == false);

        // custom action for each action choose
        switch (option)
        {
        case 0:
            // Exiting message
            cout << " THANKS FOR YOUR RELIABILITY AND GOOD BYE " << endl;
            break;
        case 1:
            TSPGetNumCities(_nbCities); 
            break;
        case 2:
            // print cities
            if (_nbCities == -1)
            {
                cout << "\n please first enter the number of cities" << endl;
                break;
            }
            cout << "cities generated are " << endl;
            for (size_t i = 0; i < instance.getCities().size(); i++)
            {
                cout << "city_" << i << " with x = " << instance.getCities()[i].first << ", y = " << instance.getCities()[i].second << endl;
            }
            break;
        case 3:
        {
            // code print 1
            if (_nbCities == -1)
            {
                cout << "\n please first enter the number of cities" << endl;
                break;
            }
            instance.createRandom(_nbCities);
            instance.calcDistanceMatrix();

            // Set up the optimizer
            Optimizer optimizer;

            // Register the moves
            ChainReverseMove move1;
            SwapCityMove move2;
            RotateCityMove move3;
            optimizer.addMove(&move1);
            optimizer.addMove(&move2);
            optimizer.addMove(&move3);

            // Register the GUIDot
            RuntimeGUIDot gui;
            optimizer.addObserver(&gui);

            // Choose a cooling schedule
            GeometricCoolingSchedule schedule(150, 1e-2, 0.95);
            optimizer.coolingSchedule = &schedule;

            // Optimizer loop counts
            optimizer.outerLoops = 100;
            optimizer.innerLoops = 5000;
            // Update the GUI every 2000 iterations
            optimizer.notificationCycle = 1000;

            // Run the program
            vector<int> result;
            optimizer.optimize(instance, result);
            flag = 1;
            break;
            }
        default:
            // code default
            break;
        }

    } while (option != 0);

    // Exiting message
}

void TSPGetNumCities(int& num)
{
    string input;
    do
    {
        cout << "\n  PLEASE HIT THE NUMBER CITIES " << endl;
        input = getInputUser();
    } while (TryParse(input, num, 10000, 1) == false);

    cout << " PROCESS COMPLETED\n";
}

