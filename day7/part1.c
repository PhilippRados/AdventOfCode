// Turns out I misunderstood the challenge and used hashTables for no reason
// but I really don't want to restart this little challenge so I'll just
// roll with it -> at least I learned a lot about hashing and dynamic memory :)

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define LINE_LENGTH 100
#define FILE_NAME "./inputs.txt"
#define FILE_LENGTH 595
#define TABLE_LENGTH (2 * FILE_LENGTH)

// a hash-map is probably most convenient way to search for an element
typedef struct bagInfo{
	char* holding_bag;
	char** bags_contained;
	struct bagInfo *next;
} bagInfo;

bagInfo *hashTable[TABLE_LENGTH];

 int hashFunction(char *str)
{
	unsigned int hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash % TABLE_LENGTH;
}

int lookup(char* holding_bag){
	return hashFunction(holding_bag);
}

void insert(bagInfo *bag){
	bagInfo *root = hashTable[hashFunction(bag->holding_bag)];
	if (hashTable[hashFunction(bag->holding_bag)] != NULL){
		bagInfo *ptr = hashTable[hashFunction(bag->holding_bag)];
		while (ptr->next != NULL){
			ptr = ptr->next;	
		}
		ptr->next = bag;
		hashTable[hashFunction(bag->holding_bag)] = root;
	} else {
		hashTable[hashFunction(bag->holding_bag)] = (bagInfo*)malloc(sizeof(*bag)+1);
		memcpy(hashTable[hashFunction(bag->holding_bag)],bag, sizeof(*bag)+1);
	}
}

char** splitFile(FILE* file_to_read){
    rewind(file_to_read);
	int len = FILE_LENGTH;
    char **element_arr = malloc(sizeof(char*)*(len+1));
    char str[200];
    int i = 0;
    int j = 0;
    
    while(fgets(str,200, file_to_read) != NULL){
            element_arr[i] = (char*)malloc(sizeof(char) * (strlen(str)+1));
            strcpy(element_arr[i],str);
            i++;
    }
	fclose(file_to_read);
    return element_arr;
}

struct multiple_returns{
	char first[100];
	char second[100];
};

struct multiple_returns* splitStringAtWord(char* input,char* delim){
	struct multiple_returns *results;
	results = (struct multiple_returns*)malloc(sizeof(input)-2);
	char first[100] = ""; //this variable already has a value even if its not been initialized (weird)
	char second[100];
	char* left = first;
	char* right = second;
	
	int pos = strstr(input,delim) - input;
	for (int i = 0; i < pos && (*left++ = *input++) ;i++)
		;
	input += strlen(delim);
	strcpy(right,input);
	
	strcpy(results->first,first);
	strcpy(results->second, second);

	return results;
}

bagInfo splitArrayIntoBagInfo(struct multiple_returns *bag){
	char *ptr = strtok(bag->second,",");
	int len = 0;
	bagInfo single_bag;
	single_bag.holding_bag = bag->first;
	single_bag.next = NULL;
	single_bag.bags_contained = malloc(sizeof(char*) * (strlen(bag->second)+1));
	
	single_bag.bags_contained[0] = ptr;
	for (int i = 1; ptr != NULL;i++){
		ptr = strtok(NULL,",");
		single_bag.bags_contained[i] = ptr;
	}
	return single_bag;
}

void checkTable(int pos){
	bagInfo *ptr = hashTable[pos];
	while (ptr != NULL){
		printf("%s -> ",ptr->holding_bag);
		ptr = ptr->next;
	}
	printf("\n");
}

int countContainedBags(char* bag_color,int sum){
	int helper = 0;

	for (int i = 0; i < TABLE_LENGTH;i++){
		bagInfo *ptr = hashTable[i];
		while (ptr != NULL){
			for (;*(ptr->bags_contained) != NULL;(ptr->bags_contained)++)
				if (strstr(*(ptr->bags_contained),bag_color) != NULL){
					sscanf(*(ptr->bags_contained),"%d",&helper);
					sum += helper;
					countContainedBags(ptr->holding_bag,sum);
				}
			ptr = ptr->next;
		}
	}
	return sum;
}

int main(){
	FILE* file = fopen(FILE_NAME,"r");

	char** element_arr = splitFile(file);
	struct multiple_returns *bag;
	bagInfo splitted_bag;

	for (int i = 0; i < FILE_LENGTH-1;i++){
		bag = splitStringAtWord(*element_arr, " bags contain ");
		splitted_bag = splitArrayIntoBagInfo(bag);
		insert(&splitted_bag);
		element_arr++;
	}
	int result = countContainedBags("shiny gold",0);
	printf("part1: %d\n",result);
}
