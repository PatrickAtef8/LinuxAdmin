#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_KEY 1234

// Shared memory structure
struct shared_data {
    char buffer[256];
};

int main() {
    // Create shared memory
    int shm_id = shmget(SHM_KEY, sizeof(struct shared_data), IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }

    // Attach shared memory
    struct shared_data *shm_ptr = (struct shared_data *)shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Write data to shared memory
    printf("Writing to shared memory...\n");
    snprintf(shm_ptr->buffer, sizeof(shm_ptr->buffer), "Hello from writer!");

    // Wait for user input before detaching (simulating time for reader to read)
    printf("Writer: Press Enter to detach...\n");
    getchar();

    // Detach shared memory
    shmdt(shm_ptr);

    return 0;
}

