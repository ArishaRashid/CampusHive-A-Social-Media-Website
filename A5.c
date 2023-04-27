#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



// Function to print a matrix
void print_matrix(double** matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%f ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to calculate the determinant of a matrix
double determinant(double** matrix, int n) {
  double det = 0.0;
  double** sub_matrix = (double**) malloc(n * sizeof(double*));
  for (int i = 0; i < n; i++) {
    sub_matrix[i] = (double*) malloc(n * sizeof(double));
  }
  if (n == 1) {
    det = matrix[0][0];
  } else if (n == 2) {
    det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  } else {
    for (int k = 0; k < n; k++) {
      int sub_i = 0;
      for (int i = 1; i < n; i++) {
        int sub_j = 0;
        for (int j = 0; j < n; j++) {
          if (j != k) {
            sub_matrix[sub_i][sub_j] = matrix[i][j];
            sub_j++;
          }
        }
        sub_i++;
      }
      det += matrix[0][k] * pow(-1.0, k) * determinant(sub_matrix, n - 1);
    }
  }
  for (int i = 0; i < n; i++) {
    free(sub_matrix[i]);
  }
  free(sub_matrix);
  return det;
}

int main(int argc, char** argv) {
  MPI_Init(&argc, &argv);

  // Create the communicator
  MPI_Comm comm = MPI_COMM_WORLD;

  // Create the groups
  MPI_Group mult_group, det_group;
  MPI_Comm_group(comm, &mult_group);
  MPI_Comm_group(comm, &det_group);

  // Determine the rank and size of the communicator
  int rank, size;
  MPI_Comm_rank(comm, &rank);
  MPI_Comm_size(comm, &size);

  // Define the matrix dimensions
  int n = 4;
  int m = 4;

  // Allocate memory for the matrix
  double** matrix = (double**) malloc(n * sizeof(double*));
  for (int i = 0; i < n; i++) {
    matrix[i] = (double*) malloc(m * sizeof(double));
    for (int j = 0; j < m; j++) {
      matrix[i][j] = i * m + j + 1; // Fill the matrix with some values
      printf("%f ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Divide the matrix and distribute it among the processes in the multiplication group
  int rows_per_process = n / size;
  double* sub_matrix = (double*) malloc(rows_per_process * m * sizeof(double));
  MPI_Scatter(matrix[0], rows_per_process * m, MPI_DOUBLE, sub_matrix, rows_per_process * m, MPI_DOUBLE, 0, comm);


// Each process performs the multiplication on its sub-matrix
double* result = (double*) malloc(rows_per_process * m * sizeof(double));
for (int i = 0; i < rows_per_process; i++) {
  for (int j = 0; j < m; j++) {
    result[i * m + j] = 0.0;
    for (int k = 0; k < n; k++) {
      result[i * m + j] += sub_matrix[i * n + k] * matrix[k][j];
    }
  }
}

// Gather the results from all the processes
double* result_all = (double*) malloc(n * m * sizeof(double));
MPI_Allgather(result, rows_per_process * m, MPI_DOUBLE, result_all, rows_per_process * m, MPI_DOUBLE, comm);


// Print the result
if (rank == 0) {
  printf("Matrix multiplication result:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%f ", result_all[i * m + j]);
    }
    printf("\n");
  }
}

// Free the memory
free(sub_matrix);
free(result);
free(result_all);
for (int i = 0; i < n; i++) {
  free(matrix[i]);
}
free(matrix);

MPI_Finalize();
}

