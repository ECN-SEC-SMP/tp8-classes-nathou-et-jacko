GPP = g++ -Wall
SRC = ./src
BIN = ./bin

all: start

# La cible "deleteAll" est exécutée en tapant la commande "make deleteAll"
deleteAll :
	@echo suppression du contenu du répertoire ../bin
	rm -f $(BIN)/*.o $(BIN)/*.bin

# La cible "compilPoint" est exécutée en tapant la commande "make compilPoint"
compilPoint :
	@echo Compilation Point
	$(GPP) $(SRC)/Point.cpp -o $(BIN)/Point.o -c


# La cible "compilMain" est exécutée en tapant la commande "make compilMain"
compilMain : deleteAll compilPoint
	@echo Compilation de main
	$(GPP) ./main.cpp $(BIN)/Point.o -o $(BIN)/main.bin

# La cible "launchMain" est exécutée en tapant la commande "make launchMain"
launchMain :
	@echo Lancement de main
	$(BIN)/main.bin

# La cible "start" est exécutée en tapant la commande "make start"
start : compilMain launchMain