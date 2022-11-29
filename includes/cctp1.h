/*
 * cctp1.h
 */

#ifndef __CCTP_H__
#define __CCTP_H__

#include "./utils.h"

/**
 * @brief 
 * This is an implementation of entity Clocks
 */
class Clocks
{
public:
    /**
     * @brief 
     * default contructor
     */
    Clocks(){
        minute = -1;
        hour = -1;
        p = 0;
    }

    /**
     * @brief 
     * construct an instance of a graph
     * @param m int, representing the init minutes of the Clocks
     * @param h int, representing the init hour of the Clocks
     */
    Clocks(int h, int m) : minute(m),hour(h),p(0) {}

    /**
     * @brief 
     * construct an instance of a graph
     * @param w Clocks, representing the init clone of the Clocks
     */
    Clocks(Clocks &w) : minute(w.getM()), hour(w.getH()),p(0) {}

    /**
     * @brief getter for minute
     */
    int getM(){
        return minute;
    }

    /**
     * @brief getter for hour
     */
    int getH()
    {
        return hour;
    }

    /**
     * @brief getter for p
     */
    int getP()
    {
        return p;
    }

    /**
     * @brief 
     * Method to add minute to the Clocks
     */
    void addM(){
        if(minute + 1 == 60){
            if(hour +1 == 24){
                hour = 0;
                minute = 0;
            }else{
                hour++;
                minute = 0;
            }
        }else{
            minute++;
        }
    }

    /**
     * @brief 
     * Method to print the details of the clocks
     */
    string printClocks(){
        stringstream ss;
        ss << hour << "H" << minute << endl;
        return ss.str();
    }

    /**
     * @brief 
     * method to link a person to a clock
     * 
     */
    void setP(int state){
        p = state;
    }

private:
    // clock details attributes
    int minute, hour;

    // attribute which show if the attribute has been already assign
    // 0 if the clock it asssign to a person
    // 1 else

    int p;
};

/**
 * @brief 
 * This is an implementation of entity Person
 */
class Person
{
public:
    /**
     * @brief Destroy the Person object
     * 
     */
    ~Person(){}

    /**
     * @brief 
     * construct an instance of a graph
     * @param n string, representing the init name of the person
     * @param c Clocks, representing the init clock of the person
     */
    Person(string n, Clocks &c) : name(n),
    montre(c)
    {
        montre.setP(1);
    }

    /**
     * @brief 
     * construct an instance of a graph
     * @param n string, representing the init name of the person
     */
    Person(string n) : name(n), montre() {}

    /**
     * @brief 
     * method to add clock to a person
     */
    void AddClock(Clocks &c)
    {
        if (montre.getH() == -1 && c.getP() == 0)
        {
            c.setP(1);
            montre = c;
        }
        else{
            cout << "already have clock or clock is already assign" << endl;
        }
    }

    /**
     * @brief 
     * method to remove the clock of the personne
     */
    void removeClock()
    {
        if ((montre.getH() != -1) && (montre.getP() == 1))
        {
            montre.setP(0);
            montre = Clocks();
        }
        else
        {
            cout << "not have clock" << endl;
        }
    }

    /**
     * @brief 
     * Method to print the details of the clocks
     */
    string askHour()
    {
        if (montre.getH() != -1)
        {
            stringstream ss;
            ss << name << " say, it's " << montre.printClocks();
            return ss.str();
        }
        else{
            return "";
        }
    }

private:
    // adj matrix variable
    string name;
    Clocks montre;
};
void CCTPLauncher(); 
void CCTPActionMenu();
void CCTPActionOption(vector<Clocks> &, vector<Person> &);
void CreateClocks(vector<Clocks> &);
void CloneClocks(vector<Clocks> &); 
void PrintAClocks(vector<Clocks> &);
void PrintAllClocks(vector<Clocks> &);

#endif