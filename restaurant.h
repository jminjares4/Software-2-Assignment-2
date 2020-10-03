//Author:   Jesus Minjares BSEE
//Assignment 2
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream> //cout 
#include <string.h> //string 
#include <vector> //vector
#include <iomanip> //fixed and setprecsion 
#include <fstream> //output stream
using namespace std; //std::
//Burger class
class Burger{
    private:
        bool cheese,bacon,lettuce,tomato; //ingredients 
    public:
    /*default constructor*/
    Burger();
    /*parameterized constructor*/
    Burger(bool, bool, bool, bool);
    /*add all ingredients*/
    void withAll();
    /*add an ingredient to the burger*/
    void add(int);
    //return string of the order 
    string toString();
    //deconstructor
    ~Burger();
};
//Fries class
class Fries{
    private:
        bool cheese, bacon, ketchup; //ingredients
    public:
        //default constructors
        Fries();
        //parameterized constructor
        Fries(bool, bool, bool);
        //add ingredients
        void add(int);
        //convert the order to a string 
        string toString();
        //deconstructor 
        ~Fries();
};
//Salad class
class Salad{
    public:
        //constructor
        Salad();
        //deconstructor
        ~Salad();
        //convert order to a string 
        string toString();
};
//Hot Dog class 
class Hotdog{
    private:
        bool cheese, bacon, ketchup, mustard, chilliBeans; //ingredient
    public:
        //default constructor
        Hotdog();
        //paramaterized constructor
        Hotdog(bool, bool, bool, bool, bool);
        //add individual ingredients
        void add(int);
        //convert the order to a string 
        string toString();
        //deconstructor
        ~Hotdog();
};
//Drink class
class Drink{
    private:
        bool cherryFlavor, alcoholShot; //ingredients
    public:
        //default constructor
        Drink();
        //paramaterized constructor
        Drink(bool, bool);
        //add individual ingredients
        void add(int);
        //convert order to a string
        string toString();
        //deconstructor
        ~Drink();
};
//Menu class 
class Menu{
    private:
        //vectors for each class 
        vector<Burger> burgers;
        vector<Fries> fries;
        vector<Hotdog> hotdogs;
        vector<Salad> salads;
        vector<Drink> drinks;
        double balance; //balalance
        //constant prices of the items in the menu
        const double burgerPrice = 1.99;
        const double friesPrice =  0.99;
        const double saladPrice =  1.50;
        const double hotdogPrice = 1.45;
        const double drinkPrice =  0.80;
    public:
        //default constructor
        Menu();
        //add a burger to the user order
        void addBurger(bool, bool, bool, bool);
        //add fries to the user order
        void addFries(bool, bool, bool);
       //add salad to the user order 
        void addSalad();
        //add hotdog to the user order
        void addHotdog(bool, bool, bool, bool, bool);
        //add drink to the user order
        void addDrink(bool,bool);
        //remove an item from the vector with a provided index 
        void remove(char, int);
        //print the current order
        void print();
        //iterate over the vector and print the orders
        void printBurgers();
        //iterate over the vector and print the orders
        void printFries();
        //iterate over the vector and print the orders
        void printHotdogs();
        //iterate over the vector and print the orders
        void printSalads();
        //iterate over the vector and print the orders
        void printDrinks();
        //return the current balance of the orders
        double getBalance();
        //write to a file 
        //iterate over the vector and print the orders to the file
        void printReceipt(string filename);
        //print the menu
        void printMenu();
        //clear the vectors
        ~Menu();
};
#endif