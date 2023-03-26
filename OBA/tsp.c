// TSP using branch and  bound
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10

int n;
int cities[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];
int current_path[MAX_CITIES];
int best_path[MAX_CITIES];
int current_cost;
int best_cost = INT_MAX;

void tsp_branch_and_bound(int city, int start) {
    if (city == n && cities[current_path[city-1]][start] != 0) {
        if (current_cost + cities[current_path[city-1]][start] < best_cost) {
            best_cost = current_cost + cities[current_path[city-1]][start];
            for (int i = 0; i < n; i++) {
                best_path[i] = current_path[i];
            }
            best_path[n] = start;
        }
        return;
    }

    // Calculate lower bound
    int lb = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int min_cost = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && cities[i][j] < min_cost) {
                    min_cost = cities[i][j];
                }
            }
            lb += min_cost;
        }
    }

    if (current_cost + lb >= best_cost) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            current_path[city] = i;
            current_cost += cities[current_path[city - 1]][i];
            tsp_branch_and_bound(city + 1, start);
            current_cost -= cities[current_path[city - 1]][i];
            visited[i] = 0;
        }
    }
}

int main() {
    // Read input
	printf("Enter the number of cities : ");
    scanf("%d", &n);

	printf("Enter the cost matrix : \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cities[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Start from first city
    visited[0] = 1;
    current_path[0] = 0;

    // Solve TSP using branch and bound
    tsp_branch_and_bound(1, 0);

    // Print results
    printf("Best path: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", best_path[i]);
    }
    printf("\nBest cost: %d\n", best_cost);

    return 0;
}

/*

Enter the number of cities : 4
Enter the cost matrix : 
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Best path: 0 1 3 2 0 
Best cost: 80     

*/
