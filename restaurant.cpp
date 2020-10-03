//Author:   Jesus Minjares BSEE
//Assignment 2
#include "restaurant.h"
//------------Burger Class------------
Burger::Burger():cheese(false),bacon(false),lettuce(false),tomato(false){} //default 
/*parameterized constructor*/
Burger::Burger(bool c, bool b, bool l, bool t): cheese(c), bacon(b), lettuce(l), tomato(t){}//customized
/*add all ingredients*/
void Burger::withAll(){ cheese = bacon = lettuce = tomato = true;} //with all ingredients
/*add an ingredient to the burger*/
void Burger::add(int ingredient){
    switch(ingredient){
        case 0: cheese = true; break;
        case 1: bacon = true; break;
        case 2: lettuce = true; break;
        case 3: tomato = true; break;
        default: break;
    }
}
//return string of the order 
string Burger::toString(){
    string order = "burger: ";
    if(cheese)  order += "cheese ";
    if(bacon)   order += "bacon ";
    if(lettuce) order += "lettuce ";
    if(tomato)  order += "tomato ";
    if(!cheese && !bacon && !lettuce && !tomato)
    order += "plain ";
    return order;
}  
Burger::~Burger(){} //deconstructor
//------------Fries Class------------
Fries::Fries():cheese(false), bacon(false),ketchup(false){} //default constructors
Fries::Fries(bool c, bool b, bool k) : cheese(c), bacon(b), ketchup(k){} //parameterized constructor
//add ingredients
void Fries::add(int ingredient){
    switch(ingredient){
        case 0: cheese = true; break;
        case 1: bacon = true; break;
        case 2: ketchup = true; break;
        default: break;
    }
}
//convert the order to a string 
string Fries::toString(){
    string order = "fries: ";//create an empty string!
    if(cheese)  order += "cheese ";
    if(bacon)   order += "bacon ";
    if(ketchup) order += "ketchup ";
    if(!cheese && !bacon && !ketchup)
        order += "plain";
    return order;
    } 
Fries::~Fries(){} //deconstructor 
//------------Salad Class------------
Salad::Salad(){} //constructor
Salad::~Salad(){} //deconstructor
//convert order to a string 
string Salad::toString(){ return "salad ";}
//------------Hotdog Class------------
Hotdog::Hotdog():cheese(false),bacon(false),ketchup(false), mustard(false), chilliBeans(false){} //default constuctor
//paramaterized constructor
Hotdog::Hotdog(bool c, bool b, bool k, bool m, bool ch):cheese(c), bacon(b), ketchup(k), mustard(m), chilliBeans(ch){}
//add individual ingredients
void Hotdog::add(int ingredient){
    switch(ingredient){
        case 0: cheese = true; break;
        case 1: bacon = true; break;
        case 2: ketchup = true; break;
        case 3: mustard = true; break;
        case 4: chilliBeans = true; break;
        default: break;
    }
}
//convert the order to a string 
string Hotdog::toString(){
    string order = "hotdog: ";
    if(cheese)  order += "cheese ";
    if(bacon)   order += "bacon ";
    if(ketchup) order += "ketchup ";
    if(mustard) order += "mustard ";
    if(chilliBeans) order += "chilli beans ";
    if(!cheese && !bacon && !ketchup && !mustard && !chilliBeans)
        order += "plain";
    return order;
}
Hotdog::~Hotdog(){} //deconstructor
//------------Drink Class------------
Drink::Drink():cherryFlavor(false), alcoholShot(false){} //default constructor
Drink::Drink(bool cherry, bool alcohol):cherryFlavor(cherry),alcoholShot(alcohol){} //paramaterized constructor
//add individual ingredients
void Drink::add(int ingredient){
    switch(ingredient){
        case 0: cherryFlavor = true; break;
        case 1: alcoholShot = true; break;
        default: break;
    }
}
//convert order to a string
string Drink::toString(){
    string order = "drink: ";
    if(cherryFlavor) order += "cherry flavor ";
    if(alcoholShot)  order += "alcohol shot ";
    if(!cherryFlavor && !alcoholShot) order += "regular ";
    return order;
}
Drink::~Drink(){} //deconstructor
//------------Menu Class------------
Menu::Menu():balance(0.0){} //default constructor
//add a burger to the user order
void Menu::addBurger(bool cheese, bool bacon, bool lettuce, bool tomato){
    //create a burger object with the paramaters 
    Burger myBurger = Burger(cheese,bacon,lettuce, tomato);
    //add the burger to the vector
    burgers.push_back(myBurger);
}
//add fries to the user order
void Menu::addFries(bool cheese, bool bacon, bool ketchup){
    //create a fries objects with the parameters
    Fries myFries = Fries(cheese,bacon,ketchup);
    //add the object to the vector
    fries.push_back(myFries);
}
//add salad to the user order 
void Menu::addSalad(){
    //create a salad object 
    Salad mySalad = Salad();
    //add the objet to the vector
    salads.push_back(mySalad);
}
//add hotdog to the user order
void Menu::addHotdog(bool cheese, bool bacon, bool ketchup, bool mustard, bool chilliBeans){
    //create an hotdog object with its specifed ingredients
    Hotdog myHotdog = Hotdog(cheese, bacon, ketchup,mustard,chilliBeans);
    //add the hotdog to the vector
    hotdogs.push_back(myHotdog);
}
//add drink to the user order
void Menu::addDrink(bool cherry,bool alcohol){
    //create a drink object with its parameters 
    Drink myDrink = Drink(cherry,alcohol);
    //add the drink object to the vector
    drinks.push_back(myDrink);
}
//remove an item from the vector with a provided index 
void Menu::remove(char item, int index){
    //delete the item of the vector with vectorName.erase(vectorName.begin() + theIndex)
    switch(item){
        case 'b': burgers.erase(burgers.begin() + index); break;
        case 'f': fries.erase(fries.begin() + index);   break;
        case 'h': hotdogs.erase(hotdogs.begin() + index); break;
        case 's': salads.pop_back();  break;
        case 'd': drinks.erase(drinks.begin() + index);  break;
        default: break;
    }
}
//print the current order
void Menu::print(){
    cout <<  "-------------------------------Receipt-------------------------------\n";
    printBurgers();
    printFries();
    printHotdogs();
    printSalads();
    printDrinks();
    cout <<  "---------------------------------------------------------------------\n";
    cout << "Balance: $" <<fixed << setprecision(2)  << getBalance() << "\n";
}
//iterate over the vector and print the orders
void Menu::printBurgers(){
    for(int i = 0; i < burgers.size(); i++) 
        cout << i << ": " << burgers[i].toString() << endl;
}
//iterate over the vector and print the orders
void Menu::printFries(){
    for(int i = 0; i < fries.size(); i++) 
        cout << i << ": " << fries[i].toString() << endl;
}
//iterate over the vector and print the orders
void Menu::printHotdogs(){
    for(int i = 0; i < hotdogs.size(); i++) 
        cout << i << ": " << hotdogs[i].toString() << endl;
}
//iterate over the vector and print the orders
void Menu::printSalads(){
    for(int i = 0; i < salads.size(); i++) 
        cout << i << ": " << salads[i].toString() << endl;
}
//iterate over the vector and print the orders
void Menu::printDrinks(){ 
    for(int i = 0; i < drinks.size(); i++) 
        cout << i << ": " << drinks[i].toString() << endl;
}
//return the current balance of the orders
double Menu::getBalance(){
    balance =  burgerPrice*burgers.size() + friesPrice*fries.size() + hotdogPrice*hotdogs.size();
    balance += saladPrice*salads.size() +drinkPrice * drinks.size();
    return balance;
}
//write to a file 
//iterate over the vector and print the orders to the file
void Menu::printReceipt(string filename){
//create a ofstream object     
ofstream file(filename, ios::trunc);
    file <<  "-------------------------------Receipt-------------------------------\n";
    for(Burger i : burgers) file << i.toString() << "\n";
    for(Fries i : fries)   file << i.toString() << "\n";
    for(Hotdog i : hotdogs) file << i.toString() << "\n";
    for(Salad i : salads)   file << i.toString() << "\n";
    for(Drink i : drinks)  file << i.toString() << "\n";
    file <<  "---------------------------------------------------------------------\n";
    file << "Balance: $" <<fixed << setprecision(2)  << getBalance() << "\n";
    file.close(); //close the file object 
}
//print the menu
void Menu::printMenu(){
    //print the menu and how to order 
    cout <<  " ---------------\n"
    "|Burger - $"<< burgerPrice << "|\n"
    "|Fries - $" << friesPrice <<  "|\n"
    "|Salad - $" << saladPrice <<  "|\n"
    "|Hot Dog- $" << hotdogPrice <<"|\n"
    "|Drink - $" << drinkPrice <<  "|\n"
    " --------------" << endl;
    cout <<  "----------------\n" 
    << "|b for burger    |\n"
    << "|f for fries     |\n" 
    << "|s for salad     |\n"
    << "|h for hotdog    |\n"
    << "|d for drink     |\n"
    << "|e to end order  |\n"
    << "|x to remove item|\n"
    <<  "----------------" << endl; 
}
//clear the vectors
Menu::~Menu(){
    burgers.clear();
    fries.clear();
    hotdogs.clear();
    salads.clear();
    drinks.clear();
}