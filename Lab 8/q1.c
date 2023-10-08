// Graph Algorithms - Graph traversal

// Aim of the program: Consider an undirected graph where each edge weights 2 units. Each of the nodes is labeled consecutively from 1 to n. The user will input a list of edges for describing an undirected graph. After representation of the graph, from a given starting position
// ● Display the breadth-first search traversal.
// ● Determine and display the shortest distance to each of the other nodes using the breadth- first search algorithm. Return an array of distances from the start node in node number order. If a node is unreachable, return -1 for that node.

// Input Format:

// The first line contains two space-separated integers ‘n’ and ‘m’, the number of nodes and edges in the graph.
// Each line ‘i’ of the ‘m’ subsequent lines contains two space-separated integers ‘u’ and ‘v’, that describe an edge between nodes ‘u’ and ‘v’.
// The last line contains a single integer ‘s’, the node number to start from.

// Output Format:

// The first line shows the result of the BFS traversal.
// The last line shows an array of distances from node ‘s’ to all other nodes.

// Input:
// 5 4
// 1 2
// 1 4
// 4 5
// 2 5
// 1

// Output:
// BFS Traversal: 1 2 4 5
// Distance [2 -1 2 4]

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 1000

typedef struct {
    int data[MAX_NODES];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
        exit(EXIT_FAILURE);
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    int value = q->data[q->front];
    q->front++;
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return value;
}

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} LinkedListQueue;

void initLinkedListQueue(LinkedListQueue *q) {
    q->front = q->rear = NULL;
}

bool isLinkedListQueueEmpty(LinkedListQueue *q) {
    return q->front == NULL;
}

void linkedListEnqueue(LinkedListQueue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int linkedListDequeue(LinkedListQueue *q) {
    if (isLinkedListQueueEmpty(q)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    int value = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL)
        q->rear = NULL;
    return value;
}

typedef struct {
    int numNodes;
    LinkedListQueue *adjacencyList;
} Graph;

Graph createGraph(int numNodes) {
    Graph graph;
    graph.numNodes = numNodes;
    graph.adjacencyList = (LinkedListQueue *)malloc(numNodes * sizeof(LinkedListQueue));
    for (int i = 0; i < numNodes; i++) {
        initLinkedListQueue(&graph.adjacencyList[i]);
    }
    return graph;
}

void addEdge(Graph *graph, int u, int v) {
    linkedListEnqueue(&graph->adjacencyList[u - 1], v);
    linkedListEnqueue(&graph->adjacencyList[v - 1], u);
}

void breadthFirstSearch(Graph *graph, int startNode, int *distance) {
    bool visited[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = false;
        distance[i] = -1;
    }

    visited[startNode - 1] = true;
    distance[startNode - 1] = 0;

    Queue q;
    initQueue(&q);
    enqueue(&q, startNode);

    while (!isEmpty(&q)) {
        int currentNode = dequeue(&q);

        Node *temp = graph->adjacencyList[currentNode - 1].front;
        while (temp != NULL) {
            int adjacentNode = temp->data;
            if (!visited[adjacentNode - 1]) {
                visited[adjacentNode - 1] = true;
                distance[adjacentNode - 1] = distance[currentNode - 1] + 2;
                enqueue(&q, adjacentNode);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    Graph graph = createGraph(n);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }

    int startNode;
    printf("Enter the start node: ");
    scanf("%d", &startNode);

    int distance[MAX_NODES];
    breadthFirstSearch(&graph, startNode, distance);

    printf("BFS Traversal: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }

    printf("\nDistance [");
    for (int i = 0; i < n; i++) {
        printf("%d", distance[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("]\n");

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        Node *temp = graph.adjacencyList[i].front;
        while (temp != NULL) {
            Node *prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(graph.adjacencyList);

    return 0;
}
