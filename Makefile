GPP = g++ -Wall
SRC = ./src
SRC_CLASS = ./src/class
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
	$(GPP) $(SRC_CLASS)/Game.cpp $(BIN)/Animal.o -o $(BIN)/Game.o -c


# La cible "compilMain" est exécutée en tapant la commande "make compilMain"
compilMain : deleteAll compilUtil compilGame
	@echo Compilation de main
	$(GPP) $(SRC)/main.cpp $(BIN)/*.o -o $(BIN)/main.bin

# La cible "launchMain" est exécutée en tapant la commande "make launchMain"
launchMain :
	@echo Lancement de main
	$(BIN)/main.bin

# La cible "start" est exécutée en tapant la commande "make start"
start : compilMain launchMain