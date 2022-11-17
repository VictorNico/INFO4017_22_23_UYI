/*
 * tsp_f.cpp
 */

#include "../includes/tsp.h"

////////////////////////////////////////////////////////////////////////////////
/// TSPInstance
////////////////////////////////////////////////////////////////////////////////

void TSPInstance::createRandom(int n)
{
    // We generate cities on a 1000x1000 pixel plane
    mt19937 generator(random_device{}());
    uniform_real_distribution<float> distribution(0.0f, 999.0f);

    for (int i = 0; i < n; i++)
    {
        // Create a random city
        City city = make_pair(distribution(generator), distribution(generator));
        // Add the city
        addCity(city);
    }
}



void TSPInstance::calcDistanceMatrix()
{
    // Get the number of cities
    int n = static_cast<int>(cities.size());

    // Allocate the new one
    distances = Matrix(n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // The distance matrix is symmetric
            distances.setVal(i, j, dist(cities[i], cities[j]));
            distances.setVal(j, i, dist(cities[i], cities[j]));
        }
    }
}

float TSPInstance::calcTourLength(const vector<int> &tour)
{
    assert(tour.size() == cities.size());

    float result = 0.0f;
    // Calculate the length of the chain
    for (size_t i = 0; i < tour.size() - 1; i++)
    {
        result += distances.getVal(tour[i], tour[i + 1]);
    }
    // Close the loop
    result += distances.getVal(tour[tour.size() - 1], tour[0]);

    return result;
}

////////////////////////////////////////////////////////////////////////////////
/// Optimizer
////////////////////////////////////////////////////////////////////////////////

void Optimizer::optimize(TSPInstance &instance, vector<int> &result)
{
    // Get the number of cities
    int n = static_cast<int>(instance.getCities().size());

    assert(n > 0);
    // There has to be at least one move for the optimization to work
    assert(moves.size() > 0);

    // Set up the runtime configuration
    Config config;

    // Set up some initial tour
    config.state.resize(n);
    config.bestState.resize(n);
    for (int i = 0; i < n; i++)
    {
        config.state[i] = i;
    }

    // Shuffle the array randomly
    srand(unsigned(time(0)));
    random_shuffle(config.state.begin() + 1, config.state.end());

    config.energy = instance.calcTourLength(config.state);

    config.bestEnergy = config.energy;

    config.temp = coolingSchedule->initialTemp();

    mt19937 g(random_device{}());
    // Set up an initial distribution over the possible moves
    uniform_int_distribution<int> moveDist(0, static_cast<int>(moves.size()) - 1);
    // A uniform distribution for the acceptance probability
    uniform_real_distribution<float> uniformDist(0.0f, 1.0f);

    // Set up the mover service
    Optimizer::MoveService *service = new Optimizer::MoveService(n);
    for (size_t i = 0; i < moves.size(); i++)
    {
        moves[i]->setMoveService(service);
    }

    // The current proposal/neighbor
    vector<int> proposal;

    // A total loop counter for the notification cycle
    int loopCounter = 0;

    // Start the optimization
    for (config.outer = 0; config.outer < outerLoops; config.outer++)
    {
        // Determine the next temperature
        config.temp = coolingSchedule->nextTemp(config);

        // Simulate the markov chain
        for (config.inner = 0; config.inner < innerLoops; config.inner++)
        {
            proposal = config.state;

            // Propose a new neighbor according to some move
            // Choose the move
            int m = moveDist(g);
            moves[m]->propose(proposal);

            // Get the energy of the new proposal
            const float energy = instance.calcTourLength(proposal);
            const float delta = energy - config.energy;

            // Did we decrease the energy?
            // intensification
            if (delta <= 0)
            {
                // Accept the move
                /* cout << "inside 1" << endl; */
                config.state = proposal;
                config.energy = energy;
            }
            else
            {
                // Accept the proposal with a certain probability
                // exploration
                float u = uniformDist(g);
                if (u <= exp(-1 / config.temp * delta))
                {
                    config.state = proposal;
                    config.energy = energy;
                }
            }

            // Is this better than the best global optimum?
            // set the new as best path
            /* cout << energy << " < " << config.bestEnergy << " = " << energy << endl;  */
            if (energy < config.bestEnergy)
            {
                // It is
                /* cout << "inside" << endl; */
                config.bestEnergy = energy;
                config.bestState = proposal;
            }

            // Should we notify the observers?
            // compare the current loupcounter with the hyper-parameter of runtine for notification
            if ((loopCounter % notificationCycle) == 0)
            {
                // Yes, we should
                for (size_t i = 0; i < observers.size(); i++)
                {
                    observers[i]->notify(instance, config);
                }
            }
            loopCounter++;
        }
    }

    // Unregister the move service
    DELETE_PTR(service);
    for (size_t i = 0; i < moves.size(); i++)
    {
        moves[i]->setMoveService(0);
    }

    result = config.bestState;

    // Do the final notification
    config.terminated = true;
    config.state = config.bestState;
    config.energy = config.bestEnergy;
    for (size_t i = 0; i < observers.size(); i++)
    {
        observers[i]->notify(instance, config);
    }
}

////////////////////////////////////////////////////////////////////////////////
/// RuntimeGUIDot
////////////////////////////////////////////////////////////////////////////////

double round_up(double value, int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    return std::ceil(value * multiplier) / multiplier;
}

void RuntimeGUIDot::notify(TSPInstance &instance, const Optimizer::Config &config)
{
    // digraph hamiltonian string content plot as LR
    string hamiltonian = "";
    // add header
    hamiltonian.append("digraph minimize_min_ {\n\trankdir=\"LR\";\n\t// States (");
    hamiltonian.append(to_string((int)instance.getCities().size()));
    hamiltonian.append(")");

    // add all nodes
    for (size_t i = 0; i < instance.getCities().size(); i++)
    {
        hamiltonian.append("\n\tnode [shape=circle];       Q_");
        hamiltonian.append(to_string((int)i));
        hamiltonian.append(" [label=\"");
        hamiltonian.append(to_string((int)i));
        hamiltonian.append("\n(");
        hamiltonian.append(to_string(instance.getCities()[i].first));
        hamiltonian.append(",");
        hamiltonian.append(to_string(instance.getCities()[i].second));
        hamiltonian.append(")\"];");
    }

    // add status details
    hamiltonian.append("\n\tstat1 [\n\n\t\tshape=plaintext\n\t\tlabel=<");
    hamiltonian.append("\n\t\t\t<table border='0' cellborder='1' color='blue' cellspacing='0'>");
    hamiltonian.append("\n\t\t\t\t<tr>");
    hamiltonian.append("\n\t\t\t\t\t<td></td>");
    hamiltonian.append("\n\t\t\t\t\t<td>Value</td>");
    hamiltonian.append("\n\t\t\t\t</tr>");
    hamiltonian.append("\n\t\t\t\t<tr>");
    hamiltonian.append("\n\t\t\t\t\t<td>temperature</td>");
    hamiltonian.append("\n\t\t\t\t\t<td>");
    hamiltonian.append(to_string(round_up(config.temp,2)));
    hamiltonian.append("</td>");
    hamiltonian.append("\n\t\t\t\t</tr>");
    hamiltonian.append("\n\t\t\t\t<tr>");
    hamiltonian.append("\n\t\t\t\t\t<td>outer</td>");
    hamiltonian.append("\n\t\t\t\t\t<td>");
    hamiltonian.append(to_string(round_up(config.outer,2)));
    hamiltonian.append("</td>");
    hamiltonian.append("\n\t\t\t\t</tr>");
    hamiltonian.append("\n\t\t\t\t<tr>");
    hamiltonian.append("\n\t\t\t\t\t<td>inner</td>");
    hamiltonian.append("\n\t\t\t\t\t<td>");
    hamiltonian.append(to_string(round_up(config.inner,2)));
    hamiltonian.append("</td>");
    hamiltonian.append("\n\t\t\t\t</tr>");
    hamiltonian.append("\n\t\t\t\t<tr>");
    hamiltonian.append("\n\t\t\t\t\t<td>energy</td>");
    hamiltonian.append("\n\t\t\t\t\t<td>");
    hamiltonian.append(to_string(round_up(config.energy,2)));
    hamiltonian.append("</td>");
    hamiltonian.append("\n\t\t\t\t</tr>");
    hamiltonian.append("\n\t\t\t\t<tr>");
    hamiltonian.append("\n\t\t\t\t\t<td>best energy</td>");
    hamiltonian.append("\n\t\t\t\t\t<td>");
    hamiltonian.append(to_string(round_up(config.bestEnergy,2)));
    hamiltonian.append("</td>");
    hamiltonian.append("\n\t\t\t\t</tr>");
    hamiltonian.append("\n\t\t\t</table>\n\t\t>\n\t];");


    // add transition for hamiltonian tour
    hamiltonian.append("\n\n");

    // add the best path
    for (size_t i = 0; i < config.state.size(); i++)
    {
        hamiltonian.append("\n\tQ_");
        /* cout << (int) config.bestState[i] << endl;
        cout << (int) config.bestState[i+1] << endl; */
        hamiltonian.append(to_string((int)config.bestState[i % config.state.size()]));
        hamiltonian.append("->");
        hamiltonian.append("Q_");
        hamiltonian.append(to_string((int)config.bestState[(i + 1) % config.state.size()]));
        hamiltonian.append(" [color=red];");
    }
    hamiltonian.append("\n");
    // add the current path
    for (size_t i = 0; i < config.state.size(); i++)
    {
        hamiltonian.append("\n\tQ_");
        hamiltonian.append(to_string((int)config.state[i % config.state.size()]));
        hamiltonian.append("->");
        hamiltonian.append("Q_");
        hamiltonian.append(to_string((int)config.state[(i + 1) % config.state.size()]));
        hamiltonian.append(" [style=dashed, color=grey];");
    }
    hamiltonian.append("\n}");
    string path = "";
    path.append("test_");
    path.append(to_string(round_up(config.temp, 2)));
    path.append(".dot");
    writeStream(hamiltonian, path);
    /* exit(0); */
}

