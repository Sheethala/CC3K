#ifndef __CHARACTER_H__
#define __CHARACTER_H__
class GoTo;

class Character{
	static int no_of_characters;
    public:
    int health_points;
	int attack;
	int defense;
	int xcoord;
	int ycoord;
	int character_number;//to know how many characters got created.
	int new_health_points;//These new things represent the health after an attack or consumption of a potion.
	int new_attack;
	int new_defense;
	virtual ~Character() = 0;
	static int generate_character_number();
	Character(int health,int attack,int defense,int xcoord,int ycoord,int character_number);
	void dec_health(int n);
	void set_coord(int x, int y);
	virtual int take(GoTo &g);
	int get_coord(char c);
	void change_defense(int change);
	void change_health(int change);
	void change_attack(int change);
};

#endif
