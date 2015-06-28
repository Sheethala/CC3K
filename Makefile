CXX = g++
CXXFLAGS = -Wall -MMD -g -O0
EXEC = cc3k
OBJECTS = cc3k.o output.o cell.o attack.o attackgoto.o ba.o bd.o brain.o chambercells.o character.o commandtranslator.o dragon.o dragonhoard.o dragontranslator.o effect.o enemies.o enemiestranslator.o enemycreator.o floorplangenerator.o goblin.o goto.o gotoitem.o hoard.o item.o itemgenerator.o merchant.o move.o normalhoard.o ph.o phoenix.o playeroption.o playertranslator.o potion.o readfile.o rh.o smallhoard.o troll.o useitem.o vampire.o wa.o wd.o werewolf.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
