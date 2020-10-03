/*
   Author:   Jesus Minjares BSEE
   Assignment 2:  
 */
#include <iostream>
#include "restaurant.h"
using namespace std;
int main(int argc, char **argv){
    if(argc < 2){
        cout << "Usage: ./executable filename.txt\n";
        return EXIT_FAILURE;
    }
    bool option[5]; //boolean array to hold user option for the items
    char userinput; //character to get userinput 
    //create an menu object 
    Menu menu = Menu();
    menu.printMenu(); //use the print method 
    //prompt to enter a letter and store letter 
    cout << "Enter letter: "; 
    cin >> userinput;
    if(userinput == 'e' || userinput == 'x'){ //exit if 'e' or 'x'
        cout << "thank you!\n";
        return EXIT_SUCCESS;
    }
    while(userinput != 'e'){ 
        /*
        Check the userinput, if the user enter 's','f','s','h', and 'd'
        add the item to the order by using the .add()
        */
        if(userinput == 'b'){
            cout << "Burger - cheese, bacon, lettuce, tomato\n";
            cin >> option[0] >> option[1] >> option[2] >> option[3]; //get option
            menu.addBurger(option[0], option[1], option[2], option[3]); //add burger
        }
        else if(userinput == 'f'){
            cout << "Fries - cheese, bacon, ketchup\n";
            cin >> option[0] >> option[1] >> option[2]; //get options
            menu.addFries(option[0], option[1], option[2]); //add fries
        }
        else if(userinput == 's'){
            cout << "Salad\n";
            menu.addSalad();//add salad 
        }
        else if(userinput == 'h'){
           cout << "Hot Dog -  cheese, bacon, ketchup, mustard, chill beans\n";
           cin >> option[0] >> option[1] >> option[2] >> option[3] >> option[4]; //get options
           menu.addHotdog(option[0], option[1], option[2],option[3], option[4]); //add hotdog
        }
        else if(userinput == 'd'){
            cout << "Drink - cherry flavor, alcohol shot\n";
            cin >> option[0] >> option[1]; //get options
            menu.addDrink(option[0], option[1]); //add drink 
        }
        //if user enters x
        //it will proceed to remove an item in the vectors 
        else if(userinput == 'x'){
            int index;
            menu.print(); //print the current order
            cout << "Enter the item you want to remove: ";
            cin >> userinput; //get user option 
            //print the vector of the item to be removed 
            switch(userinput){ 
                case 'b': menu.printBurgers(); break;
                case 'f': menu.printFries();   break;
                case 'h': menu.printHotdogs(); break;
                case 's': menu.printSalads();  break;
                case 'd': menu.printDrinks();  break;
                default: break;
            }
            cout << "Enter the element to delete: 0-end\n";
            cin >> index; //get index 
            menu.remove(userinput, index);//remove the item from the vector at the index
        }
        else 
            cout << "Enter the correct letter...\n";
        cout << "\n\n";
        menu.print(); //print order
        cout << "\n\n";
        menu.printMenu(); //print menu 
        cout << "Enter letter: ";
        cin >> userinput; //get user input 
    }
    cout << "Receipt...\n";
    menu.print(); //display the order 
    //use argv[1] as file  name
    menu.printReceipt(argv[1]); //write to the file 
    return 0;
}
