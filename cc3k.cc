#include "brain.h"
#include <iostream>
#include "enemies.h"
#include "playertranslator.h"
#include "floorplangenerator.h"
#include "character.h"
#include "item.h"
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    Brain *the_game = Brain::getBrain();
	cout<<"Hello, what is your name?"<<endl;
	string name;
	cin>>name;
	cout<<"Welcome to CC3k, "<<name<<endl;
	cout<<"Type help to view the instructions or c to continue"<<endl;
	string option;
	cin >> option;
	if(option == "help"){
		cout<<"INSTRUCTIONS FOR CC3K"<<endl;
		cout<<"You are the player character,represented by the @ symbol"<<endl;
		cout<<"To move use the following commands"<<endl;
		cout<<"South:so"<<endl;
		cout<<"North:no"<<endl;
		cout<<"East:ea"<<endl;
		cout<<"West:we"<<endl;
		cout<<"Northeast:ne"<<endl;
		cout<<"Southeast:se"<<endl;
		cout<<"Northwest:nw"<<endl;
		cout<<"Southwest:sw"<<endl;
		cout<<"ITEMS"<<endl;
		cout<<"As you go through the room,you will be able to pick up the following:"<<endl;
		cout<<"Gold- These can be of different values"<<endl;
		cout<<"Potions-They are of the following type:"<<endl;
		cout<<"RH:Restores health"<<endl;
		cout<<"BA:Increases attack by 5"<<endl;
		cout<<"BD:Increases defense by 5"<<endl;
		cout<<"PH:Poisons health(Reduces health by 10)"<<endl;
		cout<<"WA:Wounds Attack(Decreases attack by 5)"<<endl;
		cout<<"WD:Wounds Defense(Decreases defense by 5)"<<endl;
		cout<<"COMMANDS"<<endl;
		cout<<"To use a potion: u<direction>"<<endl;
		cout<<"To attack an enemy:a<direction>"<<endl;
		cout<<"-----------------------------------"<<endl;
}
	cout<<"Lets start playing!"<<endl;
	cout<<"Do you want to select a race (y/n)"<<endl;
	char answer;
	cin >> answer;
    //cout << "Select Race: h(human), o(orc), d(dwarf), elf(e)" << endl; 
    char race; 
	if(answer == 'n'){
		race = 'h';
	}
	else{
		cout<<"Select a Race: h(Human), o(Orc), d(Dwarf), e(Elf)"<<endl;
		cin >> race;
	}
    the_game->choose_playertype(race);
    if (argc >= 2){
        string f = argv[1];
        the_game->set_board(f);
    }
    the_game->set_all();
    the_game->output_allfloors();
    while (true){
        the_game->user_command();
        if (the_game->brain_done()){
            cout << "Game Over!" << endl;
            break;
            the_game->output_allfloors();
        } else {
            the_game->output_allfloors();
        }
    }
}
    

