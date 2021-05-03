#include<stdio.h>
#include<errno.h> // perror function and errno variable.
#include<stdlib.h> // exit function
#include<string.h> // strncpy function

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address
{
	int id; // the row number in a 100 row table
	int set; // a flag to show whether this row has been filled.
	char name[MAX_DATA]; // provide fixed size so the memory can be correctly allocated.
	char email[MAX_DATA];
};

struct Database
{
	struct Address all_rows[MAX_ROWS]; // fixed size for memory allocation
};

struct Connection
{
	FILE *file;
	struct Database* database;
};

void die(char* msg);
void printAddress (struct Address* addr); // print the address on the screen.
void loadFile2Database(struct Connection* conn);
struct Connection* setupConnection(const char* filename, char mode);
void closeConnection(struct Connection* conn);
void writeDatabaseToFile(struct Connection* conn);
void initDatabase(struct Connection* conn);
void insertDatabaseRecord(struct Connection * conn, int id, const char* name, const char* email);
void printDatabaseRecord(struct Connection * conn, int id);
void deleteDatabaseRecord(struct Connection * conn, int id);
void listDatabase(struct Connection * conn);

int main(int argc, char * argv[] )
{
	if (argc < 3)
	{
		die("Usage : ex17 <dbfile> <action> [action parmaeter]");
	}

	char* filename = argv[1];
	char mode = argv[2][0];

	// if argv is bigger than 3. then 3rd place must be the id
	int id = 0;
	if (argc > 3) id = atoi(argv[3]);
	if (id >= MAX_ROWS) die("the row overflow the bounds\n");

	struct Connection * conn = setupConnection(filename, mode);

	if (mode == 'c')
	{
		initDatabase(conn);
		writeDatabaseToFile(conn);
	}
	else if (mode == 'i')
	{
		if (argc != 6)
		{
			die ("Usage : ex17 <dbfile> i id name email");
		}
		insertDatabaseRecord(conn, id, argv[4], argv[5]);
		writeDatabaseToFile(conn);
	}
	else if (mode == 'p')
	{
		if (argc != 4)
		{
			die ("Usage : ex17 <dbfile> g id");
		}
		printDatabaseRecord(conn, id);
	}
	else if (mode == 'd')
	{
		if (argc != 4)
		{
			die ("Usage : ex17 <dbfile> d id");
		}
		deleteDatabaseRecord(conn, id);
		writeDatabaseToFile(conn);
		printf("delete record in row %d\n", id);
	}
	else if (mode == 'l')
	{
		if (argc != 3)
		{
			die ("Usage : ex17 <dbfile> l");
		}
		listDatabase(conn);
	}
	else
	{
		die("Invalid action : c=create i=insert p=print d=delete l=list");
	}

	closeConnection(conn);
	return 0;
}


void die(char * msg)
{
	if (errno)
	{
		perror(msg);
	}
	else
	{
		printf("function die : %s\n", msg);
	}
	exit(1);
}

void printAddress(struct Address* addr)
{
	printf("printing data record\n");
	printf("\tid : %d\n", addr->id);
	printf("\tset : %d\n", addr->set);
	printf("\tname : %s\n", addr->name);
	printf("\temail : %s\n", addr->email);
}

void loadFileToDatabase(struct Connection* conn)
{
	int r_count = fread(conn->database, 1, sizeof(struct Database), conn->file);
	int f_count = sizeof(struct Database);
	if (r_count != f_count)
	{
		die("Load file to Database failed\n");
	}
}

struct Connection * setupConnection(const char * filename, char mode)
{
	// set up the memory for the connection
	struct Connection* conn = malloc(sizeof(struct Connection));

	if (!conn)
	{
		die("memory error.");
	}
	
	// assign memory for the database
	conn->database = malloc(sizeof(struct Database));

	if (!conn -> database)
	{
		die("memory error.");
	}

	// open file stream in the correct privileages
	if (mode == 'c')
	{
		conn->file = fopen(filename, "w");
		// Mode "w" : Creates an empty file for writing.
		// If a file with the same name already exists.
		// Its content is erased and the file is considered as a new empty file.
	}
	else
	{
		conn->file = fopen(filename, "r+");
		if (conn->file)
		{
			loadFileToDatabase(conn);
		}
	}

	if (!conn->file)
	{
		die("Failed to open the file and build the connection");
	}

	return conn;
}

void closeConnection(struct Connection* conn)
{
	if(conn)
	{
		if(conn->file)
		{
			fclose(conn->file);
		}

		if(conn->database)
		{
			free(conn->database);
		}

		free(conn);
	}
}
void writeDatabaseToFile(struct Connection* conn)
{
	rewind(conn->file);
	int r_count = fwrite(conn->database, sizeof(struct Database), 1, conn->file);

	if (r_count != 1)
	{
		die("cannot write to the file");
	}

	r_count = fflush(conn->file);

	if (r_count == -1)
	{
		die("cannot flush to the file");
	}

}

void initDatabase(struct Connection* conn)
{
	int i = 0;
	for (i = 0; i < MAX_ROWS; i++)
	{
		struct Address addr = {.id = i, .set = 0};
		conn->database->all_rows[i] = addr;
	}
}

void insertDatabaseRecord(struct Connection * conn, int id, const char* name, const char* email)
{
	struct Address* addr = &(conn->database->all_rows[id]);

	if (addr->set)
	{
		die("record already set, delete it first");
	}

	addr->set = 1;
	char* cp = strncpy(addr->name, name, MAX_DATA);
	if (!cp)
		die("copy name failed");
	cp = strncpy(addr->email, email, MAX_DATA);
	if (!cp)
		die("copy email failed");
}

void printDatabaseRecord(struct Connection * conn, int id)
{
	struct Address* addr = &(conn->database->all_rows[id]);
	if (addr->set)
	{
		printAddress(addr);
	}
	else
	{
		die("empty data record, not initalized.");
	}
}
void deleteDatabaseRecord(struct Connection * conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->database->all_rows[id] = addr;
}

void listDatabase(struct Connection * conn)
{
	int i = 0;
	for (i = 0; i < MAX_ROWS; i++)
	{
		if (conn->database->all_rows[i].set)
		{
			printDatabaseRecord(conn, i);
		}
	}
}
