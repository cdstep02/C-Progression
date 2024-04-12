#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <dirent.h>

struct thread_data {
	
}
struct Node
{
	int key = 0;
	int value = 0;
	int instances = 0;
	struct Node *next;
	struct Node *prev;
};

struct List
{
	struct Node *head;
	struct Node *tail;
	
};

struct Node *create_node(int k, int v) {
  struct Node *node = malloc(sizeof(struct Node));
  if (node == NULL) {
    fprintf (stderr, "%s: Couldn't create memory for the node; %s\n", "linkedlist", strerror(errno));
    exit(-1);
  }
  node->word = strdup(words);
  node->wordNum = wordNumber;
  node->next = NULL;
  node->prev = NULL;
  return node;
}
struct List *create_list() {
  struct List *list = malloc(sizeof(struct List));
  if (list == NULL) {
    fprintf (stderr, "%s: Couldn't create memory for the list; %s\n", "linkedlist", strerror (errno));
    exit(-1);
  }
  
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void insert_tail(struct Node *node, struct List **list) {
  if (list->head == NULL && list->tail == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
  }
}
void destroy_list(struct List **list) {
  struct Node *ptr = list->head;
  struct Node *tmp;  
  while (ptr != NULL) {
    free(ptr->word);
    tmp = ptr;
    ptr = ptr->next;
    free(tmp);
  }
  free(list);
}


int main(int argc, char *argv[]) {
	FILE *stream;
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	char *directory = argv[3];
	char *outFile = argv[4];
	int v = atoi(argv[5]);
	int filecount = 0;
	char **fileNames;
	DIR* dirp = opendir(directory);
	struct dirent *input;
	struct List **list = malloc(n * sizeof(struct List*));
	for(int i = 0; i < n; ++i) {
		list[i] = create_list();
	}
	if(dirp == NULL) {
		printf("The directory is empty");
	}
	while((input = readdir(dirp)))
	{
		filecount += 1;
	}
	
	//number of threads
	pthread_t threads[filecount];
	for(int x = 0; x < n; ++x) {
		list[i] = destroy_list();
	}
	//creating mmutex locks
	for(int y = 0; y < k; ++y) {
		pthread_mutex_init(&lock_x, NULL);
	}
		
	closedir(dirp);
	return 0;
}
