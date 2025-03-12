GPP = g++ -Wall
SRC = ./src
SRC_CLASS = ./src/class
INC = ./src
INC_CLASS = ./src/class
INCLUDE = -I$(INC) -I$(INC_CLASS)
BIN = ./bin

all: start

# La cible "deleteAll" est exécutée en tapant la commande "make deleteAll"
deleteAll :
	@echo suppression du contenu du répertoire ../bin
	rm -f $(BIN)/*.o $(BIN)/*.bin

# La cible "compilUtil" est exécutée en tapant la commande "make compilUtil"
compilUtil :
	@echo Compilation Util
	$(GPP) $(SRC)/util.cpp -o $(BIN)/util.o -c

# La cible "compilAnimal" est exécutée en tapant la commande "make compilAnimal"
compilAnimal :
	@echo Compilation Animal
	$(GPP) $(SRC_CLASS)/Animal.cpp -o $(BIN)/Animal.o -c

# La cible "compilGame" est exécutée en tapant la commande "make compilGame"
compilGame : compilAnimal
	@echo Compilation Game
	$(GPP) $(SRC_CLASS)/Game.cpp $(INCLUDE) $(BIN)/Animal.o -o $(BIN)/Game.o -c

# La cible "compilAttack" est exécutée en tapant la commande "make compilAttack"
compilAttack : compilUtil
	@echo Compilation Attack
	$(GPP) $(SRC_CLASS)/Attaque.cpp $(INCLUDE) $(BIN)/util.o -o $(BIN)/attaque.o -c

# La cible "compilMain" est exécutée en tapant la commande "make compilMain"
compilMain : deleteAll compilGame compilAttack
	@echo Compilation de main
	$(GPP) $(SRC)/main.cpp $(INCLUDE) $(BIN)/*.o -o $(BIN)/main.bin

# La cible "launchMain" est exécutée en tapant la commande "make launchMain"
launchMain :
	@echo Lancement de main
	$(BIN)/main.bin

# La cible "start" est exécutée en tapant la commande "make start"
start : compilMain launchMain