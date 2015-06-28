#ifndef __PLAYEROPTION_H__
#define __PLAYEROPTION_H__
#include"character.h"
#include<iostream>
#include<string>

class PlayerTranslator;

class PlayerOption:public Character{
    public:
    	int hoard;
	PlayerTranslator *in;
	char option;
	static PlayerOption *player_inst;
	static void cleanup();
	PlayerOption(int health_points,int attack,int defense,int x,int y,char option,int character_number);
	char get_option();
	void change_info();
	void set_hoard(int hd);
	int get_hoard();
	static PlayerOption *get_inst();
	static std::string char_to_option(char c);
	virtual ~PlayerOption() = 0;
};

class Elf:public PlayerOption{
	public:
	Elf(int x,int y,int character_number);
	~Elf();
};

class Dwarf:public PlayerOption{
	public:
	~Dwarf();
	Dwarf(int x,int y,int character_number);
};


class Human:public PlayerOption{
	public:
	~Human();
	Human(int x,int y,int character_number);
	};

class Orc:public PlayerOption{
	public:
	Orc(int x,int y,int character_number);
	~Orc();
};
#endif

	

