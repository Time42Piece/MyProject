CC=g++ -std=c++11 -I./ -o
SERD=./server/
SERD1=shmChatServer/
DIS=./bin/dis
SER1H=$(SERD)$(SERD1)shmChatServer.h
SER1C=$(SERD)$(SERD1)shmChatServer.cpp
SER1O=$(SERD)$(SERD1)shmChatServer.o
FD=./src/common/
FO=$(FD)framework.o
FC=$(FD)framework.cpp

$(DIS): $(FO) $(SER1O)
	$(CC) $@ $^
$(FO): $(FC)
	$(CC) $@ -c $<
$(SER1O): $(SER1C) $(SER1H)
	$(CC) $@ -c $<
.PHONY: clean
clean:
	rm -rf $(DIS) $(SER1O) $(FO)