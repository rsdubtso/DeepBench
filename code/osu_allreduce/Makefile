
CC=gcc
CC_FLAGS= -c -O2 -pthread -Wall -march=native

MPI_PATH?=/tools/openmpi-1.10.2-sm-gcc48-cuda7.5.18-slurm14.11.7
CUDA_PATH?=/tools/cuda_7.5.18
MKDIR=mkdir -p
BIN_DIR?=bin

.PHONY= coll all_reduce build clean

all: build

build: coll allreduce
	$(CC) -o $(BIN_DIR)/osu_allreduce -pthread -Wl,--enable-new-dtags -Wl,-rpath=$(CUDA_PATH)/lib64 -Wl,-rpath=$(MPI_PATH)/lib $(BIN_DIR)/osu_allreduce.o $(BIN_DIR)/osu_coll.o -L$(CUDA_PATH)/lib64 -L$(MPI_PATH)/lib -lstdc++ -lmpi_cxx -lmpi -lcuda

coll:
	$(MKDIR) $(BIN_DIR)
	$(CC) -o $(BIN_DIR)/osu_coll.o $(CC_FLAGS) -I$(CUDA_PATH)/include -I$(MPI_PATH)/include  osu_coll.c

allreduce:
	$(CC) -o $(BIN_DIR)/osu_allreduce.o $(CC_FLAGS) -I$(CUDA_PATH)/include -I$(MPI_PATH)/include osu_allreduce.c

clean:
	rm -rf $(BIN_DIR)

rebuild: clean build
