GPP = g++ -Wall
SRC = ./src
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

# La cible "compilAttack" est exécutée en tapant la commande "make compilAttack"
compilAttack :
	@echo Compilation Attack
	$(GPP) $(SRC)/Attaque.cpp -o $(BIN)/attaque.o -c

# La cible "compilMain" est exécutée en tapant la commande "make compilMain"
compilMain : deleteAll compilUtil compilAttack
	@echo Compilation de main
	$(GPP) $(SRC)/main.cpp $(BIN)/*.o -o $(BIN)/main.bin

# La cible "launchMain" est exécutée en tapant la commande "make launchMain"
launchMain :
	@echo Lancement de main
	$(BIN)/main.bin

# La cible "start" est exécutée en tapant la commande "make start"
start : compilMain launchMain