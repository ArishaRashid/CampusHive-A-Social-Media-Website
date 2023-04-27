#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 6 // size of each dimension of the array

int main(int argc, char** argv) {
    int rank, size;
    int dims[3] = {0, 0, 0}; // dimensions of the cartesian grid
    int periods[3] = {0, 0, 0}; // periodicity of the cartesian grid
    int coords[3] = {0, 0, 0}; // coordinates of this process in the cartesian grid
    int neighbors[6]; // neighbors of this process
    int blocksize; // size of the block that this process will work on
    int array[N][N][N]; // the 3-D array
    int sum = 0; // the sum of all elements in the array
    MPI_Comm cart_comm; // the cartesian communicator

    // initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // check that we have the right number of processes
    if (size != 27) {
        printf("Error: Must run with 27 processes\n");
        MPI_Finalize();
        return 1;
    }

    // create the cartesian communicator
    MPI_Dims_create(size, 3, dims);
    MPI_Cart_create(MPI_COMM_WORLD, 3, dims, periods, 0, &cart_comm);
    MPI_Cart_coords(cart_comm, rank, 3, coords);
    MPI_Cart_shift(cart_comm, 0, 1, &neighbors[0], &neighbors[1]);
    MPI_Cart_shift(cart_comm, 1, 1, &neighbors[2], &neighbors[3]);
    MPI_Cart_shift(cart_comm, 2, 1, &neighbors[4], &neighbors[5]);

    // initialize the array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                array[i][j][k] = i * N * N + j * N + k;
            }
        }
    }

    // calculate the block size for this process
    blocksize = N / dims[0] * N / dims[1] * N / dims[2];

    // calculate the sum of elements in this process's block
    int blocksum = 0;
    for (int i = coords[0] * N / dims[0]; i < (coords[0] + 1) * N / dims[0]; i++) {
        for (int j = coords[1] * N / dims[1]; j < (coords[1] + 1) * N / dims[1]; j++) {
            for (int k = coords[2] * N / dims[2]; k < (coords[2] + 1) * N / dims[2]; k++) {
                blocksum += array[i][j][            k];
        }
    }
}

// sum the blocksums from all processes
MPI_Reduce(&blocksum, &sum, 1, MPI_INT, MPI_SUM, 0, cart_comm);

// print the result from process 0
if (rank == 0) {
    printf("The sum of all elements in the array is %d\n", sum);
}

// finalize MPI
MPI_Finalize();

return 0;
