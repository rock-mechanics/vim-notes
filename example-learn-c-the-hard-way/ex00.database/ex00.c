#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<assert.h> //missed

#define MAX_SIZE 512
#define MAX_ROWS 100

struct Record
{
	int id;
	int is_set;
	char name[MAX_SIZE];
	char email[MAX_SIZE];
};

struct Table
{
	struct Record records[MAX_ROWS];
};

// the above is the stack structure which does not use pointers.

struct Connection
{
	FILE* file;
	struct Table* table;
};

// prototype for the functions
void die(const char* msg);
void writeFileToDatabase(struct Connection* conn);


void printRecord(struct Record* r)
{
	printf("printing records : id : %d , name : %s, email : %s\n", r->id, r->name, r->email);
}

struct Connection* openConnection(const char* filename, char action)
{
	struct Connection * conn = malloc(sizeof(struct Connection));

	if (!conn) die("Memory error, fail to allocate memeory for connection"); //missed

	conn->table = malloc(sizeof(struct Table));

	if (!conn->table) die("Memory error, fail to allocate memeory for connection->table"); //missed

	if (action == 'c')
	{
		conn->file = fopen(filename, "w");
	}
	else
	{
		conn->file = fopen(filename, "r+");
		if (conn->file) writeFileToDatabase(conn); //missed
	}

	if (!conn->file) die("fail to open file");

	return conn;
};

void die(const char* msg)
{
	if (errno)
	{
		perror(msg);
	}
	else
	{
		printf("Error : %s\n", msg);
	}
	// exit will exit the entire program.
	// function provided by stdlib.h
	exit(1);
}

void initDatabase(struct Connection* conn)
{
	int i = 0;
	for (i = 0; i < MAX_ROWS; i++)
	{
		struct Record r = {.id = i, .is_set = 0 };
		conn->table->records[i] = r;
	}
}

void writeDatabaseToFile(struct Connection* conn)
{
	// move the file position to the beginning of the file
	rewind(conn->file);
	int rc = fwrite(conn->table, sizeof(struct Table), 1, conn->file);
	if (rc != 1) die("fail to write database to file");
	rc = fflush(conn->file);
	if (rc == -1) die("fail to flush to the file");
}

void writeFileToDatabase(struct Connection* conn)
{
	int rc = fread(conn->table, sizeof(struct Table), 1 , conn->file);
	if (rc != 1) die("fail to write file to database");
}

void closeConnection(struct Connection * conn)
{
	if(conn)
	{
		if (conn->table) free(conn->table);
		if (conn->file) fclose(conn->file);
		free(conn);
	}
}
void insertDatabaseRecord(struct Connection* conn, int id, const char* name, const char* email)
{
	struct Record* r = &(conn->table->records[id]);
	if (r->is_set) die("id is set, delete it first");
	r->is_set = 1;
	char* cp = strncpy(r->name, name, MAX_SIZE);
	if (!cp) die("copy name failed.");
	cp = strncpy(r->email, email, MAX_SIZE);
	if (!cp) die("copy email failed.");
}
void deleteDatabaseRecord(struct Connection* conn, int id)
{
	struct Record r = {.id = id, .is_set = 0};
	conn->table->records[id] = r;
}
void printDatabaseRecord(struct Connection* conn, int id)
{
	struct Record* r = &(conn->table->records[id]);
	if (!r->is_set) die("id is not set");
	printRecord(r);
}
void listDatabase(struct Connection* conn)
{
	int i = 0;
	for (i = 0; i < MAX_ROWS; i++)
	{
		struct Record* r = &(conn->table->records[i]);
		if (r->is_set)
		{
			printDatabaseRecord(conn, i);
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		die("Usage : ./rundb <dbfile> <action> [action params]");
	}
	char * filename = argv[1];
	char action = argv[2][0];

	int id = 0;
	if (argc > 3)
	{
		id = atoi(argv[3]);
		if (id >= MAX_ROWS)
		{
			die("Overflow the maximum capacity");
		}
	}

	struct Connection* conn = openConnection(filename, action);

	switch (action)
	{
		case 'c' : 
			initDatabase(conn);
			writeDatabaseToFile(conn);
			break;
		case 'p' : 
			if (argc != 4) die("Usage : rundb <db-file> p <id>");
			printRecord(&(conn->table->records[id]));
			break;
		case 'i' : 
			if (argc != 6) die("Usage : rundb <db-file> i <id> <name> <email>");
			insertDatabaseRecord(conn, id, argv[4], argv[5]);
			writeDatabaseToFile(conn);
			break;
		case 'l' : 
			listDatabase(conn);
			break;
		case 'd' : 
			if (argc != 4) die("Usage : rundb <db-file> d <id>"); //missed
			deleteDatabaseRecord(conn, id);
			writeDatabaseToFile(conn);
			break;
		default : 
			die("Usage : c=create, p=print, l=list, i=insert, d=delete");
	}
	closeConnection(conn);
}
