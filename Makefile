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

# La cible "compilAnimals" est exécutée en tapant la commande "make compilAnimals"
compilAnimals : compilAttack $(BIN)/Animal.o $(BIN)/Loup.o $(BIN)/Lion.o $(BIN)/Ours.o $(BIN)/Pierre.o

$(BIN)/Animal.o : $(SRC_CLASS)/Animal.cpp
	@echo "Compilation Animal.cpp"
	$(GPP) -c $< -o $@

$(BIN)/Lion.o : $(SRC_CLASS)/Lion.cpp
	@echo "Compilation Lion.cpp"
	$(GPP) -c $< -o $@

$(BIN)/Ours.o : $(SRC_CLASS)/Ours.cpp
	@echo "Compilation Ours.cpp"
	$(GPP) -c $< -o $@

$(BIN)/Pierre.o : $(SRC_CLASS)/Pierre.cpp
	@echo "Compilation Pierre.cpp"
	$(GPP) -c $< -o $@

$(BIN)/Loup.o : $(SRC_CLASS)/Loup.cpp
	@echo "Compilation Loup.cpp"
	$(GPP) -c $< -o $@

# La cible "compilGame" est exécutée en tapant la commande "make compilGame"
compilGame : compilAnimals
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
