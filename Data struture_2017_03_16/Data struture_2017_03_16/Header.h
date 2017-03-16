#pragma once

#define MAX 100
typedef struct {
	char name[10];
	int id;
	char grade[4];
} StudentRecord;

StudentRecord r[MAX]; // Student record: name, id, grade
int num_record = 0; // Total # of records read from file
char *fname = "grade.txt"; // Grade file name
void read_record(char *fname);
void print_record();
void search_record();
void change_record();
void write_record(char *fname);