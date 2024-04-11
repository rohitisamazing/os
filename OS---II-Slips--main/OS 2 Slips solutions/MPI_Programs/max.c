// Write an MPI program to find the max number from randomly generated 1000 numbers
// (stored in array) on a cluster (Hint: Use MPI_Reduce)
//Slip 5, 20, 


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
//     int max_local = 0;
//     int max_global = 0;

//     if (world_rank == 0) {
//         // Master process generates random numbers
//         array = (int*)malloc(ARRAY_SIZE * sizeof(int));
//         for (int i = 0; i < ARRAY_SIZE; ++i)
//             array[i] = rand() % 1000;
//     }

//     // Broadcast array to all processes
//     MPI_Bcast(array, ARRAY_SIZE, MPI_INT, 0, MPI_COMM_WORLD);

//     // Each process finds local maximum
//     for (int i = world_rank * (ARRAY_SIZE / world_size); i < (world_rank + 1) * (ARRAY_SIZE / world_size); ++i)
//         if (array[i] > max_local)
//             max_local = array[i];

//     // Reduce all local maxima to find global maximum
//     MPI_Reduce(&max_local, &max_global, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

//     if (world_rank == 0)
//         printf("Max number: %d\n", max_global);

//     MPI_Finalize();
//     return 0;
// }