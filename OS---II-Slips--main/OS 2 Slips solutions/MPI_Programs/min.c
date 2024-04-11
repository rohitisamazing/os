// Write an MPI program to find the min number from randomly generated 1000 numbers
// (stored in array) on a cluster (Hint: Use MPI_Reduce)
// Slip 11, 16, 27, 30


// #include <stdio.h>
// #include <stdlib.h>
// #include <mpi.h>

// #define ARRAY_SIZE 1000

// int main(int argc, char** argv) {
//     MPI_Init(&argc, &argv);

//     int world_size, world_rank;
//     MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//     MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

//     int* array = NULL;
//     int min_local = INT_MAX;
//     int min_global = INT_MAX;

//     if (world_rank == 0) {
//         // Master process generates random numbers
//         array = (int*)malloc(ARRAY_SIZE * sizeof(int));
//         for (int i = 0; i < ARRAY_SIZE; ++i)
//             array[i] = rand() % 1000;
//     }

//     // Broadcast array to all processes
//     MPI_Bcast(array, ARRAY_SIZE, MPI_INT, 0, MPI_COMM_WORLD);

//     // Each process finds local minimum
//     for (int i = world_rank * (ARRAY_SIZE / world_size); i < (world_rank + 1) * (ARRAY_SIZE / world_size); ++i)
//         if (array[i] < min_local)
//             min_local = array[i];

//     // Reduce all local minima to find global minimum
//     MPI_Reduce(&min_local, &min_global, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

//     if (world_rank == 0)
//         printf("Min number: %d\n", min_global);

//     MPI_Finalize();
//     return 0;
// }