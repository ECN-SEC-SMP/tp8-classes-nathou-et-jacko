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
	@echo "Suppression du contenu du répertoire $(BIN)"
	rm -f $(BIN)/*.o $(BIN)/*.bin

# La cible "compilUtil" est exécutée en tapant la commande "make compilUtil"
compilUtil :
	@echo "Compilation Util"
	$(GPP) -c $(SRC)/util.cpp -o $(BIN)/util.o

# La cible "compilAttack" est exécutée en tapant la commande "make compilAttack"
compilAttack : compilUtil
	@echo "Compilation Attack"
	$(GPP) -c $(SRC_CLASS)/Attaque.cpp -o $(BIN)/Attaque.o


# La cible "compilAttack" est exécutée en tapant la commande "make compilAttack"
compilAnimal : compilAttack
	@echo "Compilation Attack"
	$(GPP) -c $(SRC_CLASS)/Animal.cpp $(BIN)/Attaque.o -o $(BIN)/Animal.o

# La cible "compilAttack" est exécutée en tapant la commande "make compilAttack"
compilLion: compilAnimal
	@echo "Compilation Attack"
	$(GPP) -c $(SRC_CLASS)/Lion.cpp $(BIN)/Animal.o -o $(BIN)/Lion.o

compilPierre: compilAnimal
	@echo "Compilation Attack"
	$(GPP) -c $(SRC_CLASS)/Pierre.cpp $(BIN)/Animal.o -o $(BIN)/Pierre.o

compilLoup: compilAnimal
	@echo "Compilation Attack"
	$(GPP) -c $(SRC_CLASS)/Loup.cpp $(BIN)/Animal.o -o $(BIN)/Loup.o

compilOurs: compilAnimal
	@echo "Compilation Attack"
	$(GPP) -c $(SRC_CLASS)/Ours.cpp $(BIN)/Animal.o -o $(BIN)/Ours.o

# La cible "compilGame" est exécutée en tapant la commande "make compilGame"
compilGame : compilAnimal compilLion compilLoup compilPierre compilOurs
	@echo "Compilation Game"
	$(GPP) -c $(SRC_CLASS)/Game.cpp -o $(BIN)/Game.o

# La cible "compilMain" est exécutée en tapant la commande "make compilMain"
compilMain : deleteAll compilGame
	@echo "Compilation de main"
	$(GPP) $(SRC)/main.cpp $(BIN)/*.o -o $(BIN)/main.bin

# La cible "launchMain" est exécutée en tapant la commande "make launchMain"
launchMain :
	@echo "Lancement de main"
	$(BIN)/main.bin

# La cible "start" est exécutée en tapant la commande "make start"
start : compilMain launchMain
